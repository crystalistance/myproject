#include <iostream>
#include <memory>
#include <iostream>

int main() {

    std::shared_ptr<int> p(new int(1));
    std::shared_ptr<int> p2 = p;
    std::shared_ptr<int> ptr = std::make_shared<int>(2);
    ptr.reset(new int(1));


    std::cout << p.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;
    std::cout << ptr.use_count() << std::endl;

    return 0;
}
