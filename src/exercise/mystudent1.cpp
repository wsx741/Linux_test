#include <iostream>
#include "mystudent1.h"
using namespace std;

Student::Student(string n, string i, int a, int g)
    : name(n), id(i), age(a), gender(g)
{
    cout << name << "构造" << endl;
    /*name = n;
    id = i;
    age = a;
    gender = g;*/
}
Student::Student(string n, int a, int g)
    : Student(n, "24344", a, g)
    //: Student(n, createId(), a, g)
{
}
Student::~Student(){
    cout << name << "析构" << endl;
}
void Student::setName(string n){
    name = n;
}
void Student::setId(string i){
    id = i;
}
void Student::setAge(int a){
    age = a;
}
void Student::disp(){
    cout << "name: " << name 
         << " age: " << age
         << " id: " << id << endl;
}

