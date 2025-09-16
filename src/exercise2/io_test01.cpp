#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a;
    cin>>a;
    cout << "十进制：" << a << endl;
    cout << "十六进制：" << hex << a << endl;
    cout << "八进制：" << oct << a << endl;

    bool f1;
    cin>>f1;
    cout << f1 << endl;
    cout << f1 << boolalpha << f1 << endl;
   
    double b;
    cin>>b;
    cout.precision(3);
    cout << "b = " << b << endl;
    cout << setprecision(6) << "b = " << b << endl;
    cout << fixed << setprecision(6) << "b = " << b << endl;
    return 0;
}