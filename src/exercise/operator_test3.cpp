#include <iostream>
using namespace std;

class A{
    friend bool operator>(A &a1, A &a2);
    friend bool operator<(A &a1, A &a2);
    friend bool operator==(A &a1, A &a2);
    friend bool operator>=(A &a1, A &a2);
    friend bool operator<=(A &a1, A &a2);
    public:
        A(int x, double y)
            : x(x), y(y)
        {}
    private:
        int x;
        double y;
};

bool operator>(A &a1, A &a2){
    if(a1.x > a2.x)
        return true;
    else if(a1.x == a2.x)
        return a1.y > a2.y;
    else
        return false;
}
bool operator<(A &a1, A &a2){
    if(a1.x < a2.x)
        return true;
    else if(a1.x == a2.x)
        return a1.y < a2.y;
    else
        return false;
}
bool operator==(A &a1, A &a2){
    if(a1.x == a2.x && a1.y == a2.y)
        return true;
    else
        return false;
}

bool operator>=(A &a1, A &a2){
    if(a1.x >= a2.x)
        return true;
    else
        return false;
}
bool operator<=(A &a1, A &a2){
    if(a1.x <= a2.x)
        return true;
    else 
        return false;
}

int main(){
    A a1(21,343.32), a2(32,4534);
    if(a2 > a1)
        cout << "a2 > a1" << endl;
    if(a1 < a2)
        cout << "a1 < a2" << endl;
    A a3(1,1), a4(1,1);
    if(a3 == a4)
        cout << "a3 == a4" << endl;
    return 0;
}






