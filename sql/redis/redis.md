# redis设计与实现

## 字符串

### 内部数据结构 sds(simple dynamic string)

```struct sdshdr {

    int len;

    int free;

    char buf[];
}```

### 优点

1) 常数复杂度获取字符串长度
2) 杜绝缓冲区溢出
3) 减少修改字符串长度时所需的内存重新分配次数 小于1m时，free和len相等，大于1m时，多分配1m
4) 二进制安全 不会因为有\0之类的截断数据，按照二进制进行存储
5) 兼容部分c字符串函数


## 链表

### 内部数据结构

    typedef struct listNode {
        struct listNode *prev;
        struct listNode *next;

        void *value;
    }listNode;

    typedef struct list {
        listNode *head;
        listNode *tail;

        unsigned long len;

        //节点复制函数
        void (*dup)(void *ptr);

        //节点值释放函数
        void (*free)(void *ptr);

        //节点值对比函数
        void (*match)(void *ptr, void *key);

    }list;

### 特性

1) 双端
2) 无环
3) 带表头指针和表尾指针
4) 带链表长度计数器
5) 多态 不同类型节点都可以有各自的dup free match
