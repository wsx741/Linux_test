#include <iostream>
#include <cstring>

using namespace std;

// 基本数据类型的函数模板
template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// 针对const char*类型的特化版本
template<>
const char* max<const char*>(const char* a, const char* b) {
    // 使用strcmp进行字典序比较
    if (strcmp(a, b) > 0) {
        return a;
    } else {
        return b;
    }
}

// 定义Person类
class Person {
public:
    char name[32];
    int age;
    
    Person(const char* n, int a) {
        strcpy(name, n);
        age = a;
    }
    
    // 用于显示人员信息
    void display() const {
        cout << "姓名: " << name << ", 年龄: " << age;
    }
};

// 针对Person类的特化版本
template<>
Person max<Person>(Person a, Person b) {
    return (a.age > b.age) ? a : b;
}

int main() {
    int int1 = 10, int2 = 20;
    cout << "较大的整数: " << max(int1, int2) << endl;
    
    double double1 = 3.14, double2 = 2.71;
    cout << "较大的浮点数: " << max(double1, double2) << endl;

    const char* str1 = "apple";
    const char* str2 = "banana";
    cout << "字典序较大的字符串: " << max(str1, str2) << endl;
    
    Person p1("张三", 25);
    Person p2("李四", 30);
    
    Person older = max(p1, p2);
    cout << "年龄较大的人员: ";
    older.display();
    cout << endl;
    
    return 0;
}