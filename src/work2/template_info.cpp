#include <iostream>
#include <string>

using namespace std;

void info_helper(ostream& os) {
    os << "}";
}

template<typename T, typename... Args>
void info_helper(ostream& os, const string& key, const T& value, Args... args) {
    os << key << ": " << value;
    
    // 如果还有更多参数，添加逗号和空格
    if constexpr (sizeof...(args) > 0) {
        os << ", ";
        info_helper(os, args...);
    } else {
        os << "}";
    }
}

template<typename T, typename... Args>
void info(const string& key, const T& value, Args... args) {
    cout << "信息汇总: {";
    info_helper(cout, key, value, args...);
    cout << endl;
}

int main() {
    info("姓名", "张三");
    info("姓名", "李四", "年龄", 25);
    info("姓名", "王五", "年龄", 30, "成绩", 95.5);
    info("课程", "C++程序设计", "学分", 3, "教师", "赵老师", "学期", 2023);
    
    return 0;
}