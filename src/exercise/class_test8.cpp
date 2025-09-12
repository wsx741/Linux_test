
class Base{
    public:
        virtual ~Base() = default;
        virtual void f1() = 0;
        virtual void f2() = 0;
        virtual int f3() = 0;
        virtual void f4(int a) = 0;
        virtual void f5() = 0;
};

class Device : public Base{
    public:
        Device(int x)
            : x(x)
        {}
        ~Device()
        {}
        void f1(){}
        void f2(){}
        int f3(){return x;}
        void f4(int a){}
        void f5(){}
    protected:
        int x;
};

int main(){
    Base *pb = new Device(5);
    delete pb;
    return 0;
}






