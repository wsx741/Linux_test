#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Book类
class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(const string& title, const string& author, const string& isbn)
        : title(title), author(author), isbn(isbn) 
        {}
    ~Book() {}
    // Getter方法
    const string& getTitle() const { return title; }
    const string& getAuthor() const { return author; }
    const string& getIsbn() const { return isbn; }

    // 显示图书信息
    void display() const {
        cout << "书名: 《" << title << "》 作者: " << author << " ISBN: " << isbn << endl;
    }
};

// 图书馆类，使用unique_ptr管理图书所有权
class Library {
private:
    vector<unique_ptr<Book>> books;
public:
    Library() {}
    ~Library() {}

    // 添加图书 - 接受unique_ptr，表示转移所有权给图书馆
    void addBook(unique_ptr<Book> book) {
        books.push_back(move(book));
        cout << "图书已添加到图书馆" << endl;
    }

    // 添加图书 - 直接创建新图书
    void addBook(const string& title, const string& author, const string& isbn) {
        books.push_back(make_unique<Book>(title, author, isbn));
        cout << "图书已添加到图书馆" << endl;
    }

    // 删除图书 - 根据ISBN删除
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
            cout << "图书馆暂无图书" << endl;
        } else {
            for (const auto& book : books) {
                book->display();
            }
        }
    }

    // 获取图书数量
    size_t getBookCount() const {
        return books.size();
    }
    
    // 获取图书（不转移所有权，仅用于查看）
    Book* getBook(const string& isbn) const {
        for (const auto& book : books) {
            if (book->getIsbn() == isbn) {
                return book.get();
            }
        }
        return nullptr;
    }
};

// 读者类，使用shared_ptr共享图书
class Reader {
private:
    string name;
    vector<shared_ptr<Book>> borrowedBooks;

public:
    Reader(const string& name) : name(name) {
        cout << "读者 " << name << " 注册" << endl;
    }

    ~Reader() {
        cout << "读者 " << name << " 注销" << endl;
    }

    // 借阅图书 - 使用shared_ptr共享图书所有权
    void borrowBook(shared_ptr<Book> book) {
        borrowedBooks.push_back(book);
        cout << "读者 " << name << " 借阅了 《" << book->getTitle() << "》" << endl;
        cout << "《" << book->getTitle() << "》当前引用计数: " << book.use_count() << endl;
    }

    // 显示借阅的图书
    void displayBorrowedBooks() const {
        cout << "\n=== 读者 " << name << " 借阅的图书 ===" << endl;
        if (borrowedBooks.empty()) {
            cout << "暂无借阅图书" << endl;
        } else {
            for (const auto& book : borrowedBooks) {
                book->display();
            }
        }
        cout << "=========================" << endl;
    }
};

// 演示unique_ptr的使用
void demonstrateUniquePtr() {
    cout << "\n=== 演示unique_ptr使用 ===" << endl;
    
    // unique_ptr确保唯一所有权
    auto book = make_unique<Book>("《C++ Primer Plus》", "Stephen Prata", "978-0321928429");
    cout << "创建了图书: 《" << book->getTitle() << "》" << endl;
    
    // 转移所有权
    unique_ptr<Book> another_owner = move(book);
    if (!book) {
        cout << "所有权已转移，原指针为空" << endl;
    }
    
    cout << "新所有者管理的图书: 《" << another_owner->getTitle() << "》" << endl;
    cout << "离开作用域时自动清理资源" << endl;
    cout << "=== unique_ptr演示结束 ===" << endl;
}

// 演示shared_ptr的使用
void demonstrateSharedPtr() {
    cout << "\n=== 演示shared_ptr使用 ===" << endl;
    
    // shared_ptr允许多个所有者共享资源
    auto book = make_shared<Book>("《Effective Modern C++》", "Scott Meyers", "978-1491903995");
    cout << "创建图书: 《" << book->getTitle() << "》" << endl;
    cout << "初始引用计数: " << book.use_count() << endl;
    
    {
        // 在新作用域中创建更多shared_ptr
        auto another_owner1 = book;
        auto another_owner2 = book;
        
        cout << "创建了额外的shared_ptr..." << endl;
        cout << "当前引用计数: " << book.use_count() << endl;  // 应该是3
        
        cout << "离开内部作用域..." << endl;
    }
    
    cout << "离开内部作用域后引用计数: " << book.use_count() << endl;  // 应该是1
    cout << "=== shared_ptr演示结束 ===" << endl;
}

int main() {
    cout << "=== 图书管理系统演示 ===" << endl;
    
    // 演示unique_ptr和shared_ptr的基本使用
    demonstrateUniquePtr();
    demonstrateSharedPtr();
    
    // 创建图书馆和读者
    Library library;
    Reader reader("张三");
    
    // 添加图书到图书馆
    cout << "\n--- 添加图书到图书馆 ---" << endl;
    library.addBook(make_unique<Book>("《C++程序设计语言》", "Bjarne Stroustrup", "978-0321563842"));
    library.addBook(make_unique<Book>("《重构》", "Martin Fowler", "978-0201485677"));
    library.addBook("《设计模式》", "GoF", "978-0201633610");
    
    // 显示图书馆所有图书
    library.displayAllBooks();
    
    // 创建shared_ptr以便读者借阅
    cout << "\n--- 创建可共享的图书 ---" << endl;
    auto sharedBook = make_shared<Book>("《C++并发编程实战》", "Anthony Williams", "978-1933988771");
    
    // 读者借阅图书
    cout << "\n--- 读者借阅图书 ---" << endl;
    reader.borrowBook(sharedBook);
    
    // 显示读者借阅的图书
    reader.displayBorrowedBooks();
    
    // 图书馆添加shared_ptr管理的图书（演示两种智能指针的结合使用）
    cout << "\n--- 图书馆添加shared_ptr管理的图书 ---" << endl;
    // 为了添加到图书馆，我们需要用unique_ptr包装shared_ptr管理的对象
    // 但这里有个问题 - 我们不能直接这么做，因为这样会破坏shared_ptr的共享语义
    // 正确的做法是图书馆和读者都应该使用shared_ptr管理需要共享的图书
    // 为了演示，我们创建一个新的图书实例添加到图书馆
    library.addBook(make_unique<Book>("《现代操作系统》", "Andrew Tanenbaum", "978-0133591620"));
    
    // 显示图书馆所有图书
    library.displayAllBooks();
    
    // 删除图书
    cout << "\n--- 删除图书 ---" << endl;
    library.removeBook("978-0321563842");
    
    // 再次显示图书馆所有图书
    library.displayAllBooks();
    
    cout << "\n=== 程序结束 ===" << endl;
    
    return 0;
}