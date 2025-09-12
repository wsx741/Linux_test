#include <iostream>
using namespace std;
//虚基类
class Base{
    public:
        Base(int i) : i(i) {}
        void f1(){
            cout << "f1" << endl;
        }
    protected:
        int i;
};

class A : virtual public Base{
    public:
        A(int i, int x) : Base{i}, x(x) {}
        void disp()
        {
            cout << x << endl;
        }
    protected:
        int x;
};

class B : virtual public Base{
    public:
        B(int i, double y) : Base{i}, y(y) {}
        void disp()
        {
            cout << y << endl;
        }
    protected:
        double y;
};

class AB : public A, public B{
    public:
        AB(int i1, int i2, int i3, int x, double y, bool z)
            : A{i1, x}, B{i2, y}, Base{i3}, z(z)
        {}
        void disp()
        {
            cout << x << " " << y << " " << z << " " << i << endl;
        }
    protected:
        bool z;
};

int main()
{
    AB ab1(1, 2, 3, 1, 2.2, true);
    ab1.A::disp();
    ab1.B::disp();
    ab1.disp();
    ab1.A::f1();
    ab1.B::f1();
    return 0;
}










