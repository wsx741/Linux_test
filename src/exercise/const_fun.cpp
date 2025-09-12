#include <iostream>
using namespace std;

class A{
    public:
        void f1() const{
            //a = 3;
            cout << "这是一个常函数" << endl;
        }
        void f2(){
            //a = 3;
            cout << "这是一个普通函数" << endl;
        }

    private:
        int a = 0;
};

int main()
{
    A a;
    a.f1();
    a.f2();
    const A b;
    b.f1();
    //b.f2();
    return 0;
}











