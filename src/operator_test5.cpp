#include <iostream>
using namespace std;

class Time{
    friend ostream &operator<<(ostream &o, Time &t);
    public:
        //++a
        Time operator++(){
            s++;
            if(s >= 60){
                m++;
                s = 0;
                if(m >= 60){
                    h++;
                    m = 0;
                }
            }
            return *this;
        }
        Time operator++(int){
            Time t = *this;
            s++;
            if(s >= 60){
                m++;
                s = 0;
                if(m >= 60){
                    h++;
                    m = 0;
                }
            }
            return t;
        }
    private:
        int h = 0,m = 0,s = 0;
};

ostream &operator<<(ostream &o, Time &t){
    o << t.h << ":" << t.m << ":" << t.s;
    return o;
}

int main(){
    Time t1;
    Time t2 = ++t1;
    Time t3 = t1++;
    cout << t1 << " " << t2 << " " << t3 << endl;
    return 0;
}











