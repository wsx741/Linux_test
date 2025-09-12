#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
        Student(int a)
            : age(new int(a)){
            cout << "构造函数" << endl;
        }
        Student(const Student &s)
            : age(new int(*s.age)){
            cout << "拷贝构造函数" << endl;
        }
        Student(Student &&s)
            : age(s.age){
            s.age = nullptr;
            cout << "移动构造函数" << endl;
        }
        ~Student()
        {
            cout << "析构函数" << endl;
            if(age){
                delete age;
                age = nullptr;
            }
        }
        int getAge(){
            return *age;
        }

    private:
        int *age = nullptr;
};

Student getStu()
{
    Student s(18);
    cout << s.getAge() << endl;
    return s;
}
int main()
{
    Student s1 = getStu();
    Student s2 = move(s1);
    return 0;
}







