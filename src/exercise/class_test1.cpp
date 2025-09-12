#include <iostream>
using namespace std;

class Base{
    public:
        Base(int i)
            : i(i)
        {}
        void f1()
        {
            cout << "Base::f1 " << i << endl;
        }
    protected:
        int i;
};

class A : virtual public Base{
    public:
        A(int i, int x)
            : Base{i}, x(x)
        {}
        void disp()
        {
            cout << "A" << endl;
        }
    protected:
        int x;
};

class B : virtual public Base{
    public:
        B(int i, double y)
            : Base{i}, y(y)
        {}
        void disp()
        {
            cout << "B" << endl;
        }
    protected:
        double y;
};

class AB : public A , public B{
    public:
        AB(int i1, int i2, int i3, int x, double y, bool z)
            : Base{i3}, A(i1, x), B(i2, y), z(z)
        {}
        void disp()
        {
            cout << "AB" << endl;
        }
    protected:
        bool z;
};

int main(){
    AB ab1(1,2,3, 1, 2.2, true);
    ab1.B::disp();
    ab1.disp();
    ab1.f1();
    return 0;
}







