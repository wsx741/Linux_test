#include <iostream>
#include <string>
using namespace std;

class A{
    public:
        A(string name)
            :name(name)
        {}
        static void setSchool(string newSchool){
            school = newSchool;
        }
        void disp(){
            cout << name << " " << school << endl;
        }
    private:
        string name;
        static string school;
};

string A::school = "山西农业大学";

int main(){
    A a("张三");
    A b("李四");
    A c("王五");
    a.disp();
    b.disp();
    A::setSchool("山西大学");
    c.disp();
    return 0;
}




