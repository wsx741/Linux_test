#include <iostream>
using namespace std;

class A{
    friend void disp(A &a);
    friend class B;
    private:
        int d = 5;
};

class B{
    public:
        void disp(A &a){
            cout << a.d << endl;
        }
};

void disp(A &a){
    cout << a.d << endl;
}

int main(){
    A a;
    disp(a);
    B b;
    b.disp(a);
    return 0;
}




