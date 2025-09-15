#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Book类，包含书名、作者和ISBN信息
class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(const string& title, const string& author, const string& isbn)
        : title(title), author(author), isbn(isbn) {
        cout << "创建图书: 《" << title << "》" << endl;
    }

    ~Book() {
        cout << "销毁图书: 《" << title << "》" << endl;
    }

    // Getter方法
    const string& getTitle() const { return title; }
    const string& getAuthor() const { return author; }
    const string& getIsbn() const { return isbn; }

    // 显示图书信息
    void display() const {
        cout << "书名: 《" << title << "》 作者: " << author << " ISBN: " << isbn << endl;
    }
};

// 图书馆类
class Library {
private:
    // 使用unique_ptr存储图书
    vector<unique_ptr<Book>> books;

public:
    Library() {
        cout << "图书馆系统启动" << endl;
    }

    ~Library() {
        cout << "图书馆系统关闭" << endl;
    }

    // 添加图书
    void addBook(unique_ptr<Book> book) {
        books.push_back(move(book));
        cout << "图书已添加" << endl;
    }

    // 删除图书
    bool removeBook(const string& isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->getIsbn() == isbn) {
                cout << "删除图书: 《" << (*it)->getTitle() << "》" << endl;
                books.erase(it);
                return true;
            }
        }
        cout << "未找到ISBN为 " << isbn << " 的图书" << endl;
        return false;
    }

    // 显示所有图书
    void displayAllBooks() const {
        cout << "\n=== 图书馆所有图书 ===" << endl;
        if (books.empty()) {
            cout << "暂无图书" << endl;
        } else {
            for (const auto& book : books) {
                book->display();
            }
        }
        cout << "====================" << endl;
    }
};

// 演示shared_ptr的使用
void demonstrateSharedPtr() {
    cout << "\n=== 演示shared_ptr ===" << endl;
    
    auto book1 = make_shared<Book>("《C++ Primer》", "Stanley Lippman", "978-0321714114");
    {
        auto book2 = book1;  // 共享所有权
        cout << "引用计数: " << book1.use_count() << endl;  // 输出2
    }
    cout << "引用计数: " << book1.use_count() << endl;  // 输出1
    cout << "离开作用域后自动清理" << endl;
}

int main() {
    // 创建图书馆
    Library library;
    // 使用unique_ptr添加图书
    library.addBook(make_unique<Book>("《C++程序设计》", "谭浩强", "978-7302132335"));
    library.addBook(make_unique<Book>("《数据结构》", "严蔚敏", "978-7302222222"));
    // 显示所有图书
    library.displayAllBooks();
    // 删除图书
    library.removeBook("978-7302132335");
    // 再次显示
    library.displayAllBooks();
    // 演示shared_ptr
    demonstrateSharedPtr();
    return 0;
}