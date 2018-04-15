//双检查锁机制的单例模式实现起来比较复杂，比如指令重排之类的

//C++11标准针规定了局部静态变量初始化需要保证线程安全,所以C++11之后是线程安全的
class Singleton {
public:
    static Singleton &Instance() {
        static Singleton instance;
        return instance;
    }

private:
    Singleton();
    ~Singleton();
    Singleton(const Singleton&);
    Singleton &operator=(const Singleton &);
};


//pthread_once方式比较好
pthread_once_t once = PTHREAD_ONCE_INIT;

class Singleton1 {
public:
    static Singleton1 &Instance() {
        pthread_once(&once, &Init);
        return *ps;
    }

    static void Init() {
        ps = new Singleton1;   
    }

private:
    Singleton1();
    ~Singleton1();
    Singleton1(const Singleton1 &);
    Singleton1 & operator=(const Singleton1 &);

    static Singleton1 *ps;
};

Singleton1 *Singleton1::ps = NULL;
