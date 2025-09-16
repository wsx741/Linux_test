#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct Student {
    string name;
    string id;
    double grade_Chinese;
    double grade_math;
    double grade_English;
    double total;
    double average;
};

const int STUDENT_COUNT = 5;

// 函数声明
void inputStudents(vector<Student>& students, int count);
void saveToFile(const vector<Student>& students, const string& filename);
void loadFromFile(vector<Student>& students, const string& filename);
void calculateScores(vector<Student>& students);
void displayStudents(const vector<Student>& students);

int main() {
    vector<Student> students(STUDENT_COUNT);
    
    // 1. 从键盘输入5名学生的信息
    inputStudents(students, STUDENT_COUNT);
    
    // 2. 将学生信息保存到文本文件"students.txt"中
    saveToFile(students, "students.txt");
    
    // 3. 从文件中读取学生信息并计算每个学生的总分和平均分
    loadFromFile(students, "students.txt");
    calculateScores(students);
    
    // 4. 将包含总分和平均分的学生信息输出到屏幕上
    displayStudents(students);
    
    return 0;
}

// 从键盘输入学生信息
void inputStudents(vector<Student>& students, int count) {
    cout << "请输入" << count << "名学生的信息：" << endl;
    for (int i = 0; i < count; i++) {
        cout << "第" << (i+1) << "名学生：" << endl;
        cout << "姓名: ";
        cin >> students[i].name;
        cout << "学号: ";
        cin >> students[i].id;
        cout << "语文成绩: ";
        cin >> students[i].grade_Chinese;
        cout << "数学成绩: ";
        cin >> students[i].grade_math;
        cout << "英语成绩: ";
        cin >> students[i].grade_English;
        cout << endl;
    }
}

// 将学生信息保存到文件
void saveToFile(const vector<Student>& students, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "无法创建文件 " << filename << endl;
        return;
    }
    
    for (const auto& student : students) {
        outFile << student.name << " "
                << student.id << " "
                << student.grade_Chinese << " "
                << student.grade_math << " "
                << student.grade_English << endl;
    }
    outFile.close();
}

// 从文件中读取学生信息
void loadFromFile(vector<Student>& students, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "无法打开文件 " << filename << endl;
        return;
    }
    
    for (auto& student : students) {
        inFile >> student.name 
               >> student.id 
               >> student.grade_Chinese 
               >> student.grade_math 
               >> student.grade_English;
    }
    inFile.close();
}

// 计算每个学生的总分和平均分
void calculateScores(vector<Student>& students) {
    for (auto& student : students) {
        student.total = student.grade_Chinese + student.grade_math + student.grade_English;
        student.average = student.total / 3.0;
    }
}

// 显示学生信息
void displayStudents(const vector<Student>& students) {
    cout << "\n学生信息列表：" << endl;
    cout << left << setw(10) << "姓名" 
         << left << setw(12) << "学号" 
         << right << setw(8) << "语文" 
         << right << setw(8) << "数学" 
         << right << setw(8) << "英语" 
         << right << setw(8) << "总分" 
         << right << setw(8) << "平均分" << endl;
    cout << "----------------------------------------------------------------" << endl;
    
    for (const auto& student : students) {
        cout << left << setw(10) << student.name 
             << left << setw(12) << student.id 
             << right << setw(8) << fixed << setprecision(1) << student.grade_Chinese 
             << right << setw(8) << fixed << setprecision(1) << student.grade_math 
             << right << setw(8) << fixed << setprecision(1) << student.grade_English 
             << right << setw(8) << fixed << setprecision(1) << student.total 
             << right << setw(8) << fixed << setprecision(1) << student.average << endl;
    }
}