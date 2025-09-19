#include <iostream>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual void showInfo() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    static const double PI;

public:
    Circle(double r) : radius(r) {}
    virtual double calculateArea() override {
        return PI * radius * radius;
    }
    virtual void showInfo() override {
        cout << "圆形，半径: " << radius << endl;
        cout << "面积: " << fixed << setprecision(2) << calculateArea() << endl;
    }
};

const double Circle::PI = 3.14159265359;

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    virtual double calculateArea() override {
        return length * width;
    }
    virtual void showInfo() override {
        cout << "矩形，长: " << length << "，宽: " << width << endl;
        cout << "面积: " << fixed << setprecision(2) << calculateArea() << endl;
    }
};

int main() {
    Shape* shapes[4];
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Circle circle2(3.0);
    Rectangle rectangle2(2.5, 8.0);
    shapes[0] = &circle;
    shapes[1] = &rectangle;
    shapes[2] = &circle2;
    shapes[3] = &rectangle2;
    for (int i = 0; i < 4; i++) {
        shapes[i]->showInfo();
    }
    double totalArea = 0;
    for (int i = 0; i < 4; i++) {
        totalArea += shapes[i]->calculateArea();
    }
    cout << "所有形状的总面积: " << fixed << setprecision(2) << totalArea << endl;
    return 0;
}