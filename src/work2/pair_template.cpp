#include <iostream>
#include <string>

using namespace std;

// Pair模板类定义
template<typename T, typename U>
class Pair {
private:
    T first;
    U second;

public:
    // 构造函数
    Pair(const T& f, const U& s) : first(f), second(s) {}
    
    // 默认构造函数
    Pair() : first(T()), second(U()) {}
    
    // Getter方法
    T getFirst() const {
        return first;
    }
    
    U getSecond() const {
        return second;
    }
    
    // Setter方法
    void setFirst(const T& f) {
        first = f;
    }
    
    void setSecond(const U& s) {
        second = s;
    }
    
    // swap成员函数，交换两个值的位置
    void swap() {
        if constexpr (is_same_v<T, U>) {
            T temp = first;
            first = second;
            second = temp;
        }
    }
    
    // 静态成员函数create，用于创建Pair对象
    static Pair<T, U> create(const T& f, const U& s) {
        return Pair<T, U>(f, s);
    }
    
    // 用于显示Pair内容的辅助函数
    void display() const {
        cout << "first: " << first << ", second: " << second << endl;
    }
};

int main() {
    cout << "测试存储(int, string)类型的Pair对象:" << endl;
    Pair<int, string> pair1(1, "hello");
    pair1.display();
    
    // 测试setter方法
    pair1.setFirst(2);
    pair1.setSecond("world");
    cout << "修改后: ";
    pair1.display();
    
    // 测试getter方法
    cout << "使用getter获取值: first=" << pair1.getFirst() 
         << ", second=" << pair1.getSecond() << endl;
    
    // 测试静态create方法
    auto pair1_created = Pair<int, string>::create(3, "created");
    cout << "通过create方法创建: ";
    pair1_created.display();
    
    cout << "\n测试存储(double, char)类型的Pair对象:" << endl;
    Pair<double, char> pair2(3.14, 'A');
    pair2.display();
    
    pair2.setFirst(2.71);
    pair2.setSecond('B');
    cout << "修改后: ";
    pair2.display();
    
    cout << "使用getter获取值: first=" << pair2.getFirst() 
         << ", second=" << pair2.getSecond() << endl;
    
    auto pair2_created = Pair<double, char>::create(1.41, 'C');
    cout << "通过create方法创建: ";
    pair2_created.display();
    
    cout << "\n测试存储(string, bool)类型的Pair对象:" << endl;
    Pair<string, bool> pair3("test", true);
    pair3.display();
    
    pair3.setFirst("example");
    pair3.setSecond(false);
    cout << "修改后: ";
    pair3.display();
    
    cout << "使用getter获取值: first=" << pair3.getFirst() 
         << ", second=" << pair3.getSecond() << endl;
    
    auto pair3_created = Pair<string, bool>::create("created", true);
    cout << "通过create方法创建: ";
    pair3_created.display();
    
    // 测试同类型Pair的swap功能
    cout << "\n测试同类型Pair的swap功能:" << endl;
    Pair<int, int> pair4(10, 20);
    cout << "swap前: ";
    pair4.display();
    pair4.swap();
    cout << "swap后: ";
    pair4.display();
    
    return 0;
}