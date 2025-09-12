#include <iostream>
using namespace std;

//class A final{
class A{
    public:
        A(){
            cout << "A" << endl;
        }
        virtual ~A(){
            cout << "~A" << endl;
        }
        //virtual void disp() final{
        virtual void disp(){
            cout << "A::disp" << endl;
        }
};

class B : public A{
    public:
        B(){
            cout << "B" << endl;
        }
        ~B(){
            cout << "~B" << endl;;
        }
        void disp() override{
            cout << "B::disp" << endl;
        }
};

int main(){
    A *pa = new B;
    pa->disp();
    delete pa;
    return 0;
}






