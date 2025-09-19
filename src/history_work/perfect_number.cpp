#include <iostream>
#include <vector>

using namespace std;

// 判断一个数是否为完全数
bool isPerfectNumber(int num) {
    // 完全数必须是大于1的正整数
    if (num <= 1) {
        return false;
    }
    
    int sum = 0;
    vector<int> factors;
    
    // 查找所有因数（除了数字本身）
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
            factors.push_back(i);
        }
    }
    
    // 输出因数分解过程（用于验证）
    cout << num << " 的因数有: ";
    for (size_t i = 0; i < factors.size(); i++) {
        cout << factors[i];
        if (i < factors.size() - 1) {
            cout << " + ";
        }
    }
    cout << " = " << sum << endl;
    
    // 判断是否为完全数
    return sum == num;
}

int main() {
    int number;
    cout << "请输入一个正整数: ";
    cin >> number;
    if (number <= 0) {
        cout << "错误：请输入一个正整数！" << endl;
        return 1;
    }
    if (isPerfectNumber(number)) {
        cout << number << " 是完全数。" << endl;
    } else {
        cout << number << " 不是完全数。" << endl;
    }
    return 0;
}