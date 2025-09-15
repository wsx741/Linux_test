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
    
    void accessB() {
        if (b_ptr) {
            cout << "从A访问B" << endl;
        }
    }
};

class B {
public:
    weak_ptr<A> a_ptr;  // 使用weak_ptr打破循环引用
    
    B() {
        cout << "B对象已构造" << endl;
    }
    
    ~B() {
        cout << "B对象已析构" << endl;
    }
    
    void accessA() {
        // 安全访问weak_ptr
        shared_ptr<A> a_shared = a_ptr.lock();
        if (a_shared) {
            cout << "从B访问A" << endl;
        } else {
            cout << "A不可用" << endl;
        }
    }
};

int main() {
    {
        cout << "=== 创建对象 ===" << endl;
        shared_ptr<A> a = make_shared<A>();
        shared_ptr<B> b = make_shared<B>();
        
        cout << "=== 创建循环引用 ===" << endl;
        a->b_ptr = b;
        b->a_ptr = a;
        
        cout << "=== 访问对象 ===" << endl;
        a->accessB();
        b->accessA();
        
        cout << "=== 退出作用域 ===" << endl;
    }
    
    cout << "=== 已退出作用域 ===" << endl;
    
    return 0;
}