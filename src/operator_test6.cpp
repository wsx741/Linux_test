#include <iostream>
using namespace std;

class A{
    public:
        A(int x1)
            : x(new int(x1))
        {}
        ~A()
        {
            if(x){
                delete x;
                x = nullptr;
            }
        }
        A &operator=(const A &a){
            if(x)
                *x = *a.x;
            else
                x = new int(*a.x);
            return *this;
        }
    private:
        int *x = nullptr;
};

int main()
{
    A a1(10);
    A a2(0);
    a2 = a1;

    return 0;
}







