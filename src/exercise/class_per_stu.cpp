#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
        Person(string name, int age)
            : name(name), age(age)
        {
            cout << "Person" << endl;
        }
        ~Person()
        {
            cout << "~Person" << endl;
        }
        void disp()
        {
            cout << "Personr " << name << endl;
        }
    protected:
        string name;
        int age;
};

class PC{
    public:
        PC(string name)
            : name(name)
        {
            cout << "PC" << endl;
        }
        ~PC()
        {
            cout << "~PC" << endl;
        }
    protected:
        string name;
};


class Student : public Person{
    public:
        Student(string name, int age, string pc_name, string id)
            : Person{name, age}, pc{pc_name}, id(id)
        {
            cout << "Student" << endl;
        }
        ~Student()
        {
            cout << "~Student" << endl;
        }
        void disp()
        {
            cout << "Student " << name << " " << id << endl;
        }
    protected:
        string id;
        PC pc;
};

int main()
{
    Student zs("张三", 18, "lenovo", "123433");
    zs.Person::disp();  //调用基类的成员函数
    zs.disp();          //调用派生类的成员函数
    return 0;
}








