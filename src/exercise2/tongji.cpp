#include <iostream>
#include <vector>
using namespace std;

enum class Gender{
    Male,
    Female
};

class Student{
    public:
        Gender gender;
};

void addStudent(vector<Student> &students){
    for(int i=0;i<100;i++){
        if(i%3==0){
            Student s;
            s.gender = Gender::Male;
            students.push_back(s);
        }else{
            Student s;
            s.gender = Gender::Female;
            students.push_back(s);
        }
    }
}

int main(){ 
    int count_male = 0;
    int count_female = 0;
    vector<Student> students;
    addStudent(students);
    for(auto s:students){
        switch(s.gender){
            case Gender::Male:
                count_male++;
                break;
            case Gender::Female:
                count_female++;
                break;
        }
    }
    cout << "male:" << count_male << endl;
    cout << "female:" << count_female << endl;
}