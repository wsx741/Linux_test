#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <memory>

// 抽象基类 Shape（图形）
class Shape {
protected:
    std::string color;  // 颜色

public:
    // 构造函数
    Shape(const std::string& c = "unknown") : color(c) {}
    
    // 虚析构函数
    virtual ~Shape() {}
    
    // 获取颜色
    std::string getColor() const { return color; }
    
    // 设置颜色
    void setColor(const std::string& c) { color = c; }
    
    // 纯虚函数 area() 用于计算面积
    virtual double area() const = 0;
    
    // 纯虚函数 perimeter() 用于计算周长
    virtual double perimeter() const = 0;
};

// 派生类 Polygon（多边形）
class Polygon : virtual public Shape {
protected:
    int num_sides;  // 边数

public:
    // 构造函数
    Polygon(int sides, const std::string& c = "unknown") 
        : Shape(c), num_sides(sides) {}
    
    // 获取边数
    int getSides() const { return num_sides; }
};

// 派生类 Circle（圆形）
class Circle : virtual public Shape {
private:
    double radius;  // 半径

public:
    // 构造函数
    Circle(double r, const std::string& c = "unknown") 
        : Shape(c), radius(r) {}
    
    // 获取半径
    double getRadius() const { return radius; }
    
    // 设置半径
    void setRadius(double r) { radius = r; }
    
    // 实现 area() 方法
    double area() const override {
        return M_PI * radius * radius;
    }
    
    // 实现 perimeter() 方法
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

// 派生类 Rectangle（矩形）
class Rectangle : virtual public Polygon {
private:
    double width;   // 宽度
    double height;  // 高度

public:
    // 构造函数
    Rectangle(double w, double h, const std::string& c = "unknown")
        : Polygon(4, c), width(w), height(h) {}
    
    // 获取宽度
    double getWidth() const { return width; }
    
    // 获取高度
    double getHeight() const { return height; }
    
    // 设置宽度
    void setWidth(double w) { width = w; }
    
    // 设置高度
    void setHeight(double h) { height = h; }
    
    // 实现 area() 方法
    double area() const override {
        return width * height;
    }
    
    // 实现 perimeter() 方法
    double perimeter() const override {
        return 2 * (width + height);
    }
};

// 派生类 Square（正方形）
class Square : public Rectangle {
public:
    // 构造函数
    Square(double side, const std::string& c = "unknown")
        : Rectangle(side, side, c), Polygon(4, c) {}
};

int main() {
    // 创建各种图形对象，通过基类指针数组实现多态调用
    std::vector<std::unique_ptr<Shape>> shapes;
    
    // 添加圆形
    shapes.push_back(std::make_unique<Circle>(5.0, "红色"));
    
    // 添加矩形
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0, "蓝色"));
    
    // 添加正方形
    shapes.push_back(std::make_unique<Square>(3.0, "绿色"));
    
    // 计算并输出所有图形的面积和周长
    std::cout << "图形面积和周长计算结果：" << std::endl;
    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "图形 " << (i+1) << "：" << std::endl;
        std::cout << "  面积: " << shapes[i]->area() << std::endl;
        std::cout << "  周长: " << shapes[i]->perimeter() << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}