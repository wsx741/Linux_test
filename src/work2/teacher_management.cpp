#include <iostream>
#include <cstring>

using namespace std;

// 定义地址结构体
struct Addr {
    char province[32]; // 省份
    char city[32];     // 城市
    char district[32]; // 区县
};

// 定义教师结构体
struct Teacher {
    char name[32];     // 姓名
    int age;           // 年龄
    Addr address;      // 地址信息
    
    // 结构体成员函数，用于遍历输出教师信息
    void print() const {
        cout << "姓名: " << name << ", 年龄: " << age 
             << ", 地址: " << address.province << "省 " 
             << address.city << "市 " << address.district << "区" << endl;
    }
};

// 通过指针为 Teacher 结构体赋值
void inputTeacher(Teacher* t) {
    cout << "请输入教师姓名: ";
    cin >> t->name;
    
    cout << "请输入教师年龄: ";
    cin >> t->age;
    
    cout << "请输入省份: ";
    cin >> t->address.province;
    
    cout << "请输入城市: ";
    cin >> t->address.city;
    
    cout << "请输入区县: ";
    cin >> t->address.district;
}

// 以友好的格式输出教师的信息
void printTeacher(const Teacher& t) {
    cout << "姓名: " << t.name << ", 年龄: " << t.age 
         << ", 地址: " << t.address.province << "省 " 
         << t.address.city << "市 " << t.address.district << "区" << endl;
}

int main() {
    // 定义一个包含 3 个元素的 Teacher 数组
    Teacher teachers[3];
    
    // 使用循环调用 inputTeacher() 输入每位教师的信息
    for (int i = 0; i < 3; i++) {
        cout << "请输入第" << (i+1) << "位教师的信息:" << endl;
        inputTeacher(&teachers[i]);
    }
    
    cout << "\n所有教师信息如下:" << endl;
    
    // 使用循环调用 printTeacher() 输出所有教师的信息
    for (int i = 0; i < 3; i++) {
        printTeacher(teachers[i]);
    }
    
    cout << "\n使用结构体成员函数遍历教师信息:" << endl;
    
    // 通过结构体成员函数的方式，实现遍历Teacher的功能
    for (int i = 0; i < 3; i++) {
        teachers[i].print();
    }
    
    return 0;
}