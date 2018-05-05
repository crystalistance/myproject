#include <iostream>
#include <memory>
#include <iostream>
#include <vector>

void DeletePtr(int *ptr) {
    delete ptr;
    std::cout << "deleteptr" << std::endl;
}

int main() {

    std::shared_ptr<int> p(new int(1));
    std::shared_ptr<int> p2 = p;
    std::shared_ptr<int> ptr = std::make_shared<int>(2);
    ptr.reset(new int(1));


    std::cout << p.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;
    std::cout << ptr.use_count() << std::endl;

    std::shared_ptr<int> p3(new int, DeletePtr);
    std::shared_ptr<int> p4(new int, [](int *p){delete p;std::cout << "lamabda" << std::endl;});

    std::shared_ptr<std::vector<int>> p5(new std::vector<int>{10,20});
    std::cout << (*p5)[1] << std::endl;
    return 0;
}
