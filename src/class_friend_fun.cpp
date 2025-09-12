#include <iostream>
using namespace std;

class A{
    friend void disp(A &a);
    private:
        int d = 5;
};

void disp(A &a){
    cout << a.d << endl;
}

int main(){
    A a;
    disp(a);
    return 0;
}




