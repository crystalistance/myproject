#include <iostream>
#include <memory>
#include <functional>

int main() {
    std::unique_ptr<int> p1(new int);
    std::unique_ptr<int> p2 = std::move(p1);

    std::unique_ptr<int[]> p3(new int[10]);
    p3[9] = 9;

//    std::unique_ptr<int> p4(new int, [](int *p){delete p;}); //错误
    std::unique_ptr<int, void(*)(int*)> p5(new int, [](int*p){delete p;});//需要指定删除函数的类型

   // std::unique_ptr<int, void(*)(int*)> p6(new int, [&](int*p){delete p;});//错误 捕获变量的lambda不能转换成函数指针

    std::unique_ptr<int, std::function<void(int *)>> p7(new int, [&](int *p){delete p;});//正确

    return 0;
}
