#include <iostream>
using namespace std;

class A{
    public:
        A(int a)
            :age(a)
        {}

    private:
        int age;
};
class B{
    public:
        explicit B(int a)
            : age(a)
        {}

    private:
        int age;
};

int main(){
    A a = 5;
    B b = (B)5;
    return 0;
}




