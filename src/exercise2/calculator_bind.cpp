#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

// 基本计算函数，接收两个操作数和一个操作符
double calculate(double a, double b, char op) {
    switch(op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                cout << "错误：除零操作！" << endl;
                return 0;
            }
        default:
            cout << "错误：不支持的操作符 '" << op << "'" << endl;
            return 0;
    }
}

int main() {
    // 使用bind和placeholders创建四个绑定函数
    auto add = bind(calculate, _1, _2, '+');
    auto subtract = bind(calculate, _1, _2, '-');
    auto multiply = bind(calculate, _1, _2, '*');
    auto divide = bind(calculate, _1, _2, '/');

    // 测试数据
    double x = 10.0;
    double y = 5.0;

    cout << x << " + " << y << " = " << add(x, y) << endl;
    cout << x << " - " << y << " = " << subtract(x, y) << endl;
    cout << x << " * " << y << " = " << multiply(x, y) << endl;
    cout << x << " / " << y << " = " << divide(x, y) << endl;

    return 0;
}