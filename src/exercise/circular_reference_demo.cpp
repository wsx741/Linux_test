#include <iostream>
#include <memory>

using namespace std;

class B; // 前向声明

class A {
public:
    shared_ptr<B> b_ptr;
    
    A() {
        cout << "A对象已构造" << endl;
    }
    
    ~A() {
        cout << "A对象已析构" << endl;
    }
};

class B {
public:
    shared_ptr<A> a_ptr;
    
    B() {
        cout << "B对象已构造" << endl;
    }
    
    ~B() {
        cout << "B对象已析构" << endl;
    }
};

int main() {
    {
        // 创建A和B的对象
        shared_ptr<A> a = make_shared<A>();
        shared_ptr<B> b = make_shared<B>();
        
        // 建立循环引用
        a->b_ptr = b;
        b->a_ptr = a;
        
        cout << "即将退出作用域..." << endl;
    }
    
    cout << "已退出作用域" << endl;
    
    return 0;
}