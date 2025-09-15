#include <iostream>
#include <string>

// Vehicle基类
class Vehicle {
protected:
    int speed;  // 速度

public:
    // 构造函数
    Vehicle() : speed(0) {}
    
    // 虚析构函数，确保正确析构派生类对象
    virtual ~Vehicle() {}
    
    // 虚函数run()，默认输出"交通工具在行驶"
    virtual void run() {
        std::cout << "交通工具在行驶" << std::endl;
    }
    
    // speed的getter方法
    int getSpeed() const {
        return speed;
    }
    
    // speed的setter方法
    void setSpeed(int s) {
        speed = s;
    }
};

// Car派生类
class Car : public Vehicle {
public:
    // 重写run()方法
    void run() override {
        std::cout << "汽车以 " << speed << " km/h 的速度行驶" << std::endl;
    }
};

// Bicycle派生类
class Bicycle : public Vehicle {
public:
    // 重写run()方法
    void run() override {
        std::cout << "自行车以 " << speed << " km/h 的速度骑行" << std::endl;
    }
};

int main() {
    // 创建Car对象
    Car car;
    
    // 创建Bicycle对象
    Bicycle bicycle;
    
    // 创建基类指针指向Car对象
    Vehicle* vehiclePtr = &car;
    
    // 通过基类指针设置速度值
    vehiclePtr->setSpeed(60);
    
    // 通过基类指针调用run()方法，观察多态现象
    vehiclePtr->run();
    
    // 基类指针指向Bicycle对象
    vehiclePtr = &bicycle;
    
    // 通过基类指针设置速度值
    vehiclePtr->setSpeed(15);
    
    // 通过基类指针调用run()方法，观察多态现象
    vehiclePtr->run();
    
    return 0;
}