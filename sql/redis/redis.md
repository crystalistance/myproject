# redis设计与实现

## 字符串

内部数据结构 sds(simple dynamic string)

`struct sdshdr {

    int len;

    int free;

    char buf[];
}`
