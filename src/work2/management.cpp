#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Employee类定义
class Employee {
private:
    string name;
    int age;
    double salary;

public:
    // 构造函数
    Employee(string name, int age, double salary) : name(name), age(age), salary(salary) {
        if (age < 0 || age > 150) {
            throw invalid_argument("Age must be between 0 and 150");
        }
        if (salary < 0) {
            throw invalid_argument("Salary cannot be negative");
        }
    }

    // Getter方法
    string getName() { return name; }
    int getAge() { return age; }
    double getSalary() { return salary; }

    // 计算年薪
    virtual double getAnnualSalary() {
        return salary * 12;
    }

    // 显示员工信息
    virtual void displayInfo() {
        cout << "员工信息:" << endl;
        cout << "姓名: " << name << endl;
        cout << "年龄: " << age << endl;
        cout << "月薪: " << salary << endl;
        cout << "年薪: " << getAnnualSalary() << endl;
        cout << "------------------------" << endl;
    }
};

// Manager类定义，公有继承自Employee
class Manager : public Employee {
private:
    double bonus;

public:
    // 构造函数
    Manager(string name, int age, double salary, double bonus) 
        : Employee(name, age, salary) {
        this->bonus = bonus;
    }

    // Getter方法
    double getBonus() { return bonus; }

    // 重写getAnnualSalary方法
    double getAnnualSalary() override {
        return Employee::getSalary() * 12 + bonus;
    }

    // 重写displayInfo方法
    void displayInfo() override {
        cout << "经理信息:" << endl;
        cout << "姓名: " << getName() << endl;
        cout << "年龄: " << getAge() << endl;
        cout << "月薪: " << getSalary() << endl;
        cout << "奖金: " << bonus << endl;
        cout << "年薪: " << getAnnualSalary() << endl;
        cout << "------------------------" << endl;
    }
};

// 主函数
int main() {
    // 创建一个普通员工对象
    Employee employee("Zhang San", 30, 8000.0);
    
    // 创建一个经理对象
    Manager manager("Li Si", 35, 12000.0, 30000.0);
    
    // 调用displayInfo方法展示信息
    employee.displayInfo();
    manager.displayInfo();
    
    return 0;
}