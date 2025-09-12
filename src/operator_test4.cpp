#include <iostream>
using namespace std;

class A{
    friend ostream & operator<<(ostream &o, A &a);
    friend istream & operator>>(istream &i, A &a);
    public:
        A(int x, double y)
            : x(x), y(y)
        {}

    private:
        int x;
        double y;
};

ostream & operator<<(ostream &o, A &a){
    o << a.x << " + " << a.y;
    return o;
}
istream & operator>>(istream &i, A &a){
    i >> a.x >> a.y;
    return i;
}

int main(){
    A a(32, 435.2);
    cout << a << endl;
    cin >> a;
    cout << a << endl;
    return 0;
}








