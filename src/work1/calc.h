#ifndef CALC_H_
#define CALC_H_

using namespace std;

class Calc{
public:
//计算器类加操作函数声明
float operator_jia(float a,float b);
//计算机类减操作声明
float operator_jian(float a,float b);
//计算机类乘操作声明
float operator_chen(float a,float b);
//计算机类除操作声明
float operator_chu(float a,float b);
};

#endif