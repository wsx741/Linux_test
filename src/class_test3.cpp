#include <iostream>
#include <string>
using namespace std;
// 初识继承
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
        void disp(){
            cout << name << " " << age << endl;
        }
    protected:
        string name;
        int age;
};

class Phone{
    public:
        Phone(string id)
            : id(id) 
        {
            cout << "Phone" << endl;
        }
    protected:
        string id;
};

class Student : public Person{
    public:
        Student(string name, int age, string phone_id, string id)
            : Person{name, age}, p{phone_id}, id(id)
        {
            cout << "Student" << endl;
        }
        ~Student()
        {
            cout << "~Student" << endl;
        }
        void disp(){
            cout << name << " " << id << " " << age << endl;
        }
    protected:
        string id;
        Phone p;
};
int main()
{
    Student zs("张三", 18, "123454645", "34534");
    zs.disp();
    return 0;
}









