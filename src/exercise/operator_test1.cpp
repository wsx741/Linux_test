#include <iostream>
using namespace std;

class A{
    friend A operator-(A &a1, A &a2);
    friend A operator+(int i, A &a);
    public:
        A(int x, double y)
            : x(x), y(y)
        {}
        A add(A &a2){
            return A(this->x + a2.x, this->y + a2.y);
        }
        A operator+(A &a2){
            return A(this->x + a2.x, this->y + a2.y);
        }
        A operator+(int i){
            return A(this->x + i, this->y);
        }

    private:
        int x;
        double y;
};
A operator-(A &a1, A &a2)
{
    return A(a1.x-a2.x, a1.y-a2.y);
}
A operator+(int i, A &a)
{
    return A(i + a.x, a.y);
}
int main()
{
    A a1(43, 32.5), a2(34, 59.4);
    //a1+a2;
    A a3 = a1.add(a2);
    A a4 = a1 + a2;
    A a5 = a1 - a2;
    A a6 = a1 + 3;
    A a7 = 3 + a1;
    return 0;
}













