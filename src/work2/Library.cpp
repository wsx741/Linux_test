#include <iostream>
#include <string>
using namespace std;

// 基类 Book（图书）
class Book {
private:
    string title;  // 书名
    double price;  // 价格

public:
    // 构造函数
    Book(string title, double price) : title(title), price(price) {}
    
    // 公共方法：getTitle() 返回书名
    string getTitle() {
        return title;
    }
    
    // 公共方法：getPrice() 返回价格
    double getPrice() {
        return price;
    }
};

// 派生类 Novel（小说），继承自 Book
class Novel : public Book {
private:
    string author;  // 作者

public:
    // 构造函数
    Novel(string title, double price, string author) 
        : Book(title, price), author(author) {}
    
    // 公共方法：getAuthor() 返回作者
    string getAuthor() {
        return author;
    }
    
    // 公共方法：getNovelInfo() 打印小说信息
    void getNovelInfo() {
        cout << "小说：" << getTitle() << "，作者：" << author << "，价格：" << getPrice() << endl;
    }
};

// 派生类 Textbook（教科书），继承自 Book
class Textbook : public Book {
private:
    string subject;  // 学科

public:
    // 构造函数
    Textbook(string title, double price, string subject) 
        : Book(title, price), subject(subject) {}
    
    // 公共方法：getSubject() 返回学科
    string getSubject() {
        return subject;
    }
    
    // 公共方法：getTextbookInfo() 打印教科书信息
    void getTextbookInfo() {
        cout << "教科书：" << getTitle() << "，学科：" << subject << "，价格：" << getPrice() << endl;
    }
};

// 主函数
int main() {
    // 创建 Novel 对象
    Novel novel("三国演义", 39.9, "罗贯中");
    
    // 创建 Textbook 对象
    Textbook textbook("高等数学", 45.0, "数学");
    
    // 调用各自的信息打印方法
    novel.getNovelInfo();
    textbook.getTextbookInfo();
    
    return 0;
}