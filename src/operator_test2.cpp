#include <iostream>
using namespace std;

class A{
    public:
        A(int x, double y)
            : x(x), y(y)
        {}
        A operator-(){
            return A(-x, -y);
        }

    private:
        int x;
        double y;
};

int main()
{
    A a1(32, 954.9);
    A a2 = -a1;
    return 0;
}





