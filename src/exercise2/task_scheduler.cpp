#include <iostream>
#include <functional>
#include <vector>
#include <string>

using namespace std;

// 定义三种任务类型
// 1. 打印消息任务（无参数）
void printMessage() {
    cout << "执行打印消息任务" << endl;
}

// 2. 计算两数之和任务
int addNumbers(int a, int b) {
    int result = a + b;
    cout << "计算两数之和任务: " << a << " + " << b << " = " << result << endl;
    return result;
}

// 3. 计算数字平方任务
double squareNumber(double x) {
    double result = x * x;
    cout << "计算数字平方任务: " << x << " 的平方 = " << result << endl;
    return result;
}

// 任务管理器类
class TaskManager {
private:
    vector<function<void()>> tasks;  // 存储所有任务

public:
    // 添加无参数任务
    void addTask(function<void()> task) {
        tasks.push_back(task);
    }
    
    // 添加计算两数之和任务（绑定参数）
    void addAddTask(function<void(int, int)> task, int a, int b) {
        tasks.push_back(bind(task, a, b));
    }
    
    // 添加计算数字平方任务（绑定参数）
    void addSquareTask(function<void(double)> task, double x) {
        tasks.push_back(bind(task, x));
    }
    
    // 执行所有任务
    void executeAllTasks() {
        cout << "开始执行所有任务..." << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "执行任务 " << (i + 1) << ":" << endl;
            tasks[i]();
        }
        cout << "所有任务执行完毕。" << endl;
    }
};

int main() {
    cout << "=== 简单任务调度系统 ===" << endl;
    
    // 创建任务管理器
    TaskManager manager;
    
    // 添加打印消息任务
    manager.addTask(printMessage);
    
    // 添加计算两数之和任务
    manager.addAddTask(addNumbers, 15, 25);
    
    // 添加计算数字平方任务
    manager.addSquareTask(squareNumber, 3.5);
    
    // 执行所有任务
    manager.executeAllTasks();
    
    return 0;
}