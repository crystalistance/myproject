# 智能指针

## shared_ptr

###创建shared_ptr的三种方式 借助构造函数或者辅助函数实现

1.
    std::shared_ptr<int> p1 = std::shared_ptr<int>(new int(2));
2.
    std::shared_ptr<int> p2 = make_shared<int>(2);
3.
    std::shared_ptr<int> p3;
    p3.reset(new int(2));
