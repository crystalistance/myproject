#include <iostream>
#include <memory>

using namespace std;

struct A;
struct B;

struct A {
    shared_ptr<B> ptr;
    ~A() {cout << "A is delete" << endl;}
};

/*
struct B {
    shared_ptr<A> ptr;
    ~B() {cout << "B is delete" << endl;}
};
*/

struct B {
    weak_ptr<A> ptr;
    ~B() {cout << "B is delete" << endl;}
};

int main() {

    shared_ptr<int> p(new int(10));

    weak_ptr<int> wp(p);

    cout << wp.use_count() << endl;

    shared_ptr<A> sa(new A);
    shared_ptr<B> sb(new B);

    sa->ptr = sb;
    cout << sa.use_count() << endl;
    cout << sb.use_count() << endl;
    
    sb->ptr = sa;

    cout << sa.use_count() << endl;
    cout << sb.use_count() << endl;

    return 0;
}
