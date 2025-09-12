#ifndef MYSTUDENT1_H_
#define MYSTUDENT1_H_

#include <string>
using namespace std;

class Student{
    public:
        Student(string n, string i, int a, int g);
        Student(string n, int a, int g);
        ~Student();
        void setName(string n);
        void setId(string i);
        void setAge(int a);
        void disp();

    private:
        string name;
        string id;
        const int gender;
        int age;
};

#endif
