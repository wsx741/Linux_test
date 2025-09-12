#include <iostream>
#include <string>
using namespace std;

class A{
    public:
        string name;
        static string school;
};

string A::school = "山西农业大学";

int main(){
    A a,b,c;
    a.name = "张三";
    b.name = "李四";
    c.name = "王五";
    cout << A::school << endl;
    cout << a.name << " " << a.school << " "
         << b.name << " " << b.school << " " 
         << c.name << " " << c.school << endl;
    return 0;
}




