#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class LibraryManagement {
private:
    // 存储图书信息（键为图书 ID，值为包含书名和作者的pair）
    map<int, pair<string, string>> books;
    
    // 存储所有图书分类标签（确保分类不重复）
    set<string> categories;
    
    // 存储图书借阅记录（键为图书 ID，值为借阅人姓名）
    multimap<int, string> borrowRecords;

public:
    // 添加图书
    void addBook(int id, const string& title, const string& author) {
        books[id] = make_pair(title, author);
        cout << "图书添加成功！ID: " << id << ", 书名: " << title << ", 作者: " << author << endl;
    }
    
    // 添加分类
    void addCategory(const string& category) {
        categories.insert(category);
        cout << "分类添加成功: " << category << endl;
    }
    
    // 记录借阅
    void recordBorrow(int bookId, const string& borrower) {
        // 检查图书是否存在
        if (books.find(bookId) != books.end()) {
            borrowRecords.insert(make_pair(bookId, borrower));
            cout << "借阅记录添加成功！图书ID: " << bookId << ", 借阅人: " << borrower << endl;
        } else {
            cout << "错误：图书ID " << bookId << " 不存在！" << endl;
        }
    }
    
    // 按图书 ID 查询图书信息
    void queryBookInfo(int bookId) {
        auto it = books.find(bookId);
        if (it != books.end()) {
            cout << "图书信息查询结果：" << endl;
            cout << "ID: " << it->first 
                 << ", 书名: " << it->second.first 
                 << ", 作者: " << it->second.second << endl;
        } else {
            cout << "未找到图书ID为 " << bookId << " 的图书信息！" << endl;
        }
    }
    
    // 查询图书借阅记录
    void queryBorrowRecords(int bookId) {
        auto range = borrowRecords.equal_range(bookId);
        if (range.first != range.second) {
            cout << "图书ID " << bookId << " 的借阅记录：" << endl;
            for (auto it = range.first; it != range.second; ++it) {
                cout << "借阅人: " << it->second << endl;
            }
        } else {
            cout << "图书ID " << bookId << " 没有借阅记录！" << endl;
        }
    }
    
    // 显示所有图书信息
    void displayAllBooks() {
        if (books.empty()) {
            cout << "暂无图书信息！" << endl;
            return;
        }
        
        cout << "所有图书信息：" << endl;
        for (const auto& book : books) {
            cout << "ID: " << book.first 
                 << ", 书名: " << book.second.first 
                 << ", 作者: " << book.second.second << endl;
        }
    }
    
    // 显示所有分类
    void displayCategories() {
        if (categories.empty()) {
            cout << "暂无分类信息！" << endl;
            return;
        }
        
        cout << "所有图书分类：" << endl;
        for (const auto& category : categories) {
            cout << category << endl;
        }
    }
};

int main() {
    LibraryManagement library;
    int choice;
    
    do {
        cout << "\n======= 图书管理系统 =======\n";
        cout << "1. 添加图书\n";
        cout << "2. 添加分类\n";
        cout << "3. 记录借阅\n";
        cout << "4. 查询图书信息\n";
        cout << "5. 查询借阅记录\n";
        cout << "6. 显示所有图书\n";
        cout << "7. 显示所有分类\n";
        cout << "0. 退出系统\n";
        cout << "请选择操作: ";
        
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int id;
                string title, author;
                cout << "请输入图书ID: ";
                cin >> id;
                cout << "请输入书名: ";
                cin.ignore();
                getline(cin, title);
                cout << "请输入作者: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;
            }
            case 2: {
                string category;
                cout << "请输入分类名称: ";
                cin.ignore();
                getline(cin, category);
                library.addCategory(category);
                break;
            }
            case 3: {
                int bookId;
                string borrower;
                cout << "请输入图书ID: ";
                cin >> bookId;
                cout << "请输入借阅人姓名: ";
                cin.ignore();
                getline(cin, borrower);
                library.recordBorrow(bookId, borrower);
                break;
            }
            case 4: {
                int bookId;
                cout << "请输入要查询的图书ID: ";
                cin >> bookId;
                library.queryBookInfo(bookId);
                break;
            }
            case 5: {
                int bookId;
                cout << "请输入要查询借阅记录的图书ID: ";
                cin >> bookId;
                library.queryBorrowRecords(bookId);
                break;
            }
            case 6: {
                library.displayAllBooks();
                break;
            }
            case 7: {
                library.displayCategories();
                break;
            }
            case 0: {
                cout << "退出图书管理系统！" << endl;
                break;
            }
            default: {
                cout << "无效选择，请重新输入！" << endl;
                break;
            }
        }
    } while (choice != 0);
    
    return 0;
}