#include <iostream>
#include <string>
using namespace std;

class Student{
    public:
        Student(string name, int a)
            : name(name), age(new int(a))
        {}
        Student(const Student &s)
            : name(s.name), age(new int(*s.age))
        {}
        ~Student()
        {
            if(age){
                delete age;
                age = nullptr;
            }
        }
        void setAge(int a)
        {
            *age = a;
        }
        int getAge()
        {
            return *age;
        }

    private:
        string name;
        int *age = nullptr;
};

int main()
{
    Student zs("张三", 20);
    Student ls(zs);
    cout << zs.getAge() << " " << ls.getAge() << endl;
    return 0;
}







