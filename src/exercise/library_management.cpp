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

// Library类，管理图书集合
class Library {
private:
    // 使用unique_ptr存储图书，Library拥有图书的所有权
    vector<unique_ptr<Book>> books;

public:
    Library() {
        cout << "图书馆系统初始化" << endl;
    }

    ~Library() {
        cout << "图书馆系统关闭" << endl;
    }

    // 添加图书 - 使用unique_ptr表示Library拥有所有权
    void addBook(unique_ptr<Book> book) {
        books.push_back(move(book));
        cout << "图书已添加到图书馆" << endl;
    }

    // 添加图书 - 重载版本，接受书名、作者和ISBN参数
    void addBook(const string& title, const string& author, const string& isbn) {
        books.push_back(make_unique<Book>(title, author, isbn));
        cout << "图书已添加到图书馆" << endl;
    }

    // 删除图书 - 根据ISBN删除图书
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
        cout << "=====================" << endl;
    }

    // 查找图书 - 返回原始指针，仅供临时使用，不传递所有权
    Book* findBook(const string& isbn) const {
        for (const auto& book : books) {
            if (book->getIsbn() == isbn) {
                cout << "找到图书: 《" << book->getTitle() << "》" << endl;
                return book.get(); // 返回原始指针，不转移所有权
            }
        }
        cout << "未找到ISBN为 " << isbn << " 的图书" << endl;
        return nullptr;
    }

    // 借阅图书 - 创建shared_ptr以便在外部共享所有权
    shared_ptr<Book> borrowBook(const string& isbn) const {
        for (const auto& book : books) {
            if (book->getIsbn() == isbn) {
                cout << "借阅图书: 《" << book->getTitle() << "》" << endl;
                // 创建一个shared_ptr，但实际应用中这可能需要更复杂的逻辑
                // 这里仅用于演示shared_ptr的使用
                return shared_ptr<Book>(book.get(), [](Book*){ /* 自定义删除器，不实际删除 */ });
            }
        }
        cout << "未找到ISBN为 " << isbn << " 的图书" << endl;
        return nullptr;
    }

    // 获取图书数量
    size_t getBookCount() const {
        return books.size();
    }
};

// 演示shared_ptr的使用
void demonstrateSharedPtr() {
    cout << "\n=== 演示shared_ptr使用 ===" << endl;
    
    // 创建一些shared_ptr
    auto book1 = make_shared<Book>("《C++ Primer》", "Stanley Lippman", "978-0321714114");
    auto book2 = make_shared<Book>("《Effective C++》", "Scott Meyers", "978-0321334879");
    
    {
        // 创建另一个作用域，演示shared_ptr的引用计数
        auto another_ref1 = book1;
        auto another_ref2 = book2;
        
        cout << "在内部作用域中..." << endl;
        cout << "《" << book1->getTitle() << "》引用计数: " << book1.use_count() << endl;
        cout << "《" << book2->getTitle() << "》引用计数: " << book2.use_count() << endl;
    }
    
    cout << "离开内部作用域后..." << endl;
    cout << "《" << book1->getTitle() << "》引用计数: " << book1.use_count() << endl;
    cout << "《" << book2->getTitle() << "》引用计数: " << book2.use_count() << endl;
    
    cout << "=== shared_ptr演示结束 ===" << endl;
}

// 演示unique_ptr的使用
void demonstrateUniquePtr() {
    cout << "\n=== 演示unique_ptr使用 ===" << endl;
    
    // 创建unique_ptr
    unique_ptr<Book> book1 = make_unique<Book>("《C++ Primer Plus》", "Stephen Prata", "978-0321563842");
    
    // 转移所有权
    unique_ptr<Book> book2 = move(book1);
    
    // 此时book1为空，所有权已转移给book2
    if (!book1) {
        cout << "book1已失去所有权" << endl;
    }
    
    cout << "book2管理的图书: " << book2->getTitle() << endl;
    
    // unique_ptr可以自动释放资源
    cout << "unique_ptr即将离开作用域并自动释放资源" << endl;
    cout << "=== unique_ptr演示结束 ===" << endl;
}

int main() {
    cout << "=== 图书管理系统演示 ===" << endl;
    
    // 创建图书馆
    Library library;
    
    // 演示使用unique_ptr添加图书
    cout << "\n--- 添加图书 ---" << endl;
    library.addBook(make_unique<Book>("《C++程序设计语言》", "Bjarne Stroustrup", "978-0321563842"));
    library.addBook(make_unique<Book>("《重构》", "Martin Fowler", "978-0201485677"));
    library.addBook("《设计模式》", "GoF", "978-0201633610"); // 使用重载版本
    
    // 显示所有图书
    library.displayAllBooks();
    
    // 演示查找图书
    cout << "\n--- 查找图书 ---" << endl;
    Book* foundBook = library.findBook("978-0201633610");
    if (foundBook) {
        cout << "成功找到图书: " << foundBook->getTitle() << endl;
    }
    
    // 演示借阅图书（演示shared_ptr）
    cout << "\n--- 借阅图书 ---" << endl;
    auto borrowedBook = library.borrowBook("978-0201485677");
    if (borrowedBook) {
        cout << "成功借阅图书" << endl;
        cout << "《" << borrowedBook->getTitle() << "》引用计数: " << borrowedBook.use_count() << endl;
    }
    
    // 演示删除图书
    cout << "\n--- 删除图书 ---" << endl;
    library.removeBook("978-0321563842");
    
    // 再次显示所有图书
    library.displayAllBooks();
    
    // 演示unique_ptr使用
    demonstrateUniquePtr();
    
    // 演示shared_ptr使用
    demonstrateSharedPtr();
    
    cout << "\n=== 程序结束 ===" << endl;
    
    return 0;
}