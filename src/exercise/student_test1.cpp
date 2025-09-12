#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
        void setName(string n);
        void setId(string i);
        void setAge(int a);
        void disp()
        {
            cout << "name: " << name
                 << "id: " << id
                 << "age: " << age 
                 << endl;
        }

    private:
        int age;
        string name;
        string id;
};


void Student::setName(string n)
{
    name = n;
}
void Student::setId(string i)
{
    id = i;
}
void Student::setAge(int a)
{
    age = a;
}

int main()
{
    Student zhangsan;
    zhangsan.setName("张三");
    zhangsan.setId("123125");
    zhangsan.setAge(18);
    
    zhangsan.disp();
    return 0;
}










