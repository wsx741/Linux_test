#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "请输入一个整数：" << endl;
    int a;
    cin>>a;
    cout << "十进制：" << a << endl;
    cout << "十六进制：" << hex << a << endl;
    cout << "八进制：" << oct << a << endl;

    cout << "请输入一个布尔值：" << endl;
    bool f1;
    cin>>f1;
    cout << f1 << endl;
    cout << f1 << boolalpha << f1 << endl;
   
    cout << "请输入一个浮点数：" << endl;
    double b;
    cin>>b;
    cout.precision(3);
    cout << "b = " << b << endl;
    cout << setprecision(6) << "b = " << b << endl;
    cout << fixed << setprecision(6) << "b = " << b << endl;
    return 0;
}