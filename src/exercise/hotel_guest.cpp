#include <iostream>
#include <string>
using namespace std;

class Guest {
private:
    static int nextNum;
    int Num;
    string Name;
    double Fee;
    static int Count;
    static double Tallncome;

public:
    Guest(string name, double fee) : Name(name), Fee(fee) {
        Num = nextNum++;
        Count++;
        Tallncome += fee;
    }
    void Show() {
        cout << "编号: " << Num << endl;
        cout << "姓名: " << Name << endl;
        cout << "房费: " << Fee << endl;
    }
    static int GetCount() {
        return Count;
    }
    static double GetTallncome() {
        return Tallncome;
    }
    ~Guest() {
        Count--;
    }
};

int Guest::nextNum = 1;
int Guest::Count = 0;
double Guest::Tallncome = 0.0;
int main() {
    Guest guest1("zhangsan", 280.5);
    guest1.Show();
    Guest guest2("lisi", 350.0);
    guest2.Show();
    Guest guest3("wangwu", 199.9);
    guest3.Show();
    cout << "当前酒店入住人数: " << Guest::GetCount() << endl;
    cout << "当前酒店总收入: " << Guest::GetTallncome() << endl;
    return 0;
}