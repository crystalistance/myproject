# C++

## 四大类型转换

### static_cast
功能：完成编译器认可的隐式类型转换

```
格式type1 a;
type2 b = staic_cast<type1>(a);将type1的类型转化为type2的类型；

使用范围：
（1）基本数据类型之间的转换，如int->double；

int a = 6;
double b = static_cast<int>(a);

（2）派生体系中向上转型：将派生类指针或引用转化为基类指针或引用（向上转型）；

class base{       ….     }
class derived : public base{      ….     }
base *b;
derived *d = new derived();
b = static_cast<base *>(d);

```

### dynamic_cast

功能：执行派生类指针或引用与基类指针或引用之间的转换。

格式：
（1）      其他三种都是编译时完成的，dynamic_cast是运行时处理的，运行时要进行运行时类型检查；
（2）      基类中要有虚函数，因为运行时类型检查的类型信息在虚函数表中，有虚函数才会有虚函数表；
（3）      可以实现向上转型和向下转型，前提是必须使用public或protected继承；

例子：
向上转型：

```
class base{       …      };
class derived : public base{      …      };
int main()
{
    base *pb;
    derived *pd = new derived();
    pb = dynamic_cast<base *>(pd);
    return 0;
}
```

向下转型：

```
class base{       virtualvoid func(){}           };
class derived : public base{      void func(){}      };
int main()
{
    base *pb = new base();
    derived *pd = dynamic_cast<derived *>(pb);//向下转型
    return 0;
}
```

一般用于向下转换，因为向上转换直接用虚函数就可以实现。

### const_cast

只能对指针或者引用去除或者添加const属性，对于变量直接类型不能使用const_cast；不能用于不同类型之间的转换，只能改变同种类型的const属性。
如：

```
const int a= 0;
int b = const_cast<int>(a);//不对的
const int *pi = &a;
int * pii = const_cast<int *>pi;//去除指针中的常量性，也可以添加指针的常量性;
```

const_cast的用法：
（1）常用于函数的形参是一个非const的引用，我想要穿进去一个const的引用，可以使用const_cast<Type&>para;去除实参的常量性，以便函数能够接受这个参数。
（2）一个const对象，我们想要调用该对象中的非const函数，可以使用const_cast去除对象的常量性；

### reinterpret_cast

也就是说对任意两个类型之间的变量我们都可以个使用reinterpret_cast在他们之间相互转换，无视类型信息。
