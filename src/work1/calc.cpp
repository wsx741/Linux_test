#include<iostream>
#include "calc.h"
using namespace std;


//加操作实现，直接返回结果
float Calc::operator_jia(float a,float b)
{
return a+b;
}
//减操作实现，直接返回结果
float Calc::operator_jian(float a,float b)
{
return a-b;
}
//乘操作实现，直接返回结果
float Calc::operator_chen(float a,float b)
{
return a*b;
}
//除操作实现，直接返回结果
float Calc::operator_chu(float a,float b)
{
return a/b;
}
int main(){
//创建一个计算器对象
Calc calc;
float a=5,b=9;
//测试函数功能
cout << "=== 计算器运算结果 ===" << endl;
cout << "加法运算：" << a << " + " << b << " = " << calc.operator_jia(a,b) << endl;
cout << "减法运算：" << b << " - " << a << " = " << calc.operator_jian(b,a) << endl;
cout << "乘法运算：" << a << " * " << b << " = " << calc.operator_chen(a,b) << endl;
cout << "除法运算：" << b << " / " << a << " = " << calc.operator_chu(b,a) << endl;
cout << "=== 运算完成 ===" << endl;
cout<<"cgong"<<endl;
cout<<"cgong"<<endl;
}