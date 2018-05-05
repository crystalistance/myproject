# 智能指针

## shared_ptr

### 创建shared_ptr的三种方式 借助构造函数或者辅助函数实现

1.
   ` std::shared_ptr<int> p1(new int(2));`
2.
   ` std::shared_ptr<int> p2 = make_shared<int>(2);`
3.
    `std::shared_ptr<int> p3;
     p3.reset(new int(2));`

### 构造函数创建和make_shared哪种方式更好？
#### 构造函数方式
  优点：
  1.支持用户自定义释放器
  std::shared_ptr<int> p4(new int, [](int *p){delete p;std::cout << "lamabda" << std::endl;});

  2.支持大括号初始化方式
  std::shared_ptr<std::vector<int>> p5(new std::vector<int>{10,20});
  std::cout << (*p5)[1] << std::endl;

  缺点
  1.不安全 (不要在实参中创建shared_ptr)
  function (std::shared_ptr<int>(new int), g())

  因为c++函数参数的计算顺序在不同的编译器不同的调用约定下可能是不一样的，所以如果先new int，然后调用g(),恰好g()发生异常，则shared_ptr还没有创建，就会发生内存泄露。
  正确的方式是先创建智能指针，再调用函数

  std::shared_ptr<int> p(new int());
  function(p, g());

  2.执行效率不高
  new的方式会涉及到两次动态内存分配，第一次是new int， 第二次是为控制块分配空间

#### make函数方式
  优点：
  1.执行效率高
  make_shared会为int和控制块一次性分配一块大的内存，提高了程序的执行效率
  2.安全
  将new操作和shared_ptr的构造放在一起执行，就不会出现内存泄漏问题了。

  缺点：
  1.不支持用户自定义释放器。由于make函数有自己的内存分配和析构规则，所以他不适用于那些有自定义分配器和释放器的对象。
  2.make函数不支持大括号初始化方式。对于下面这句代码：

  auto spv = std::make_shared<vector<int>>(10,20);

  意为spv指向一个vector,这个vector有10个元素，每个元素的值都为20。如果你想实现的是这个vector有两个元素，分别为10，20的话，你只能用new的方式。

  3.内存释放不够灵活。

  在使用new的方式中，有两块独立的堆内存，一块存放资源对象，一块存放控制块，当资源对象的引用计数为0的时候，资源对象会被销毁，它所占用的内存也会被随之销毁。

  在使用make函数的方式中，make函数一次性为资源对象和控制块分配了一块内存，当资源对象的引用计数为0是，对象被销毁，但是资源对象占用的内存却不会被销毁，只有当控制块占用的内存被销毁是才会将资源对象所占内存一并释放。那么，控制块内存什么时候被释放呢？这就涉及到控制块中另一个引用计数了，这个引用计数被称为“Weak Count”,其作用是用来计数指向该资源的weak_ptr的数量。当这个weak count的值为0时，控制块才会被释放。当资源对象非常庞大时，使用make函数的方式将造成不小的资源浪费。
