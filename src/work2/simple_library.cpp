#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    // 存储图书信息（键为图书 ID，值为包含书名和作者的pair）
    map<int, pair<string, string>> books;
    
    // 存储所有图书分类标签（确保分类不重复）
    set<string> categories;
    
    // 存储图书借阅记录（键为图书 ID，值为借阅人姓名）
    multimap<int, string> borrowRecords;
    
    // 添加图书
    books[1] = make_pair("C++ Primer", "Stanley Lippman");
    books[2] = make_pair("算法导论", "Thomas Cormen");
    books[3] = make_pair("设计模式", "GoF四人组");
    
    cout << "添加图书完成" << endl;
    
    // 添加分类
    categories.insert("计算机科学");
    categories.insert("数学");
    categories.insert("文学");
    categories.insert("计算机科学"); // 重复插入测试
    
    cout << "添加分类完成" << endl;
    
    // 记录借阅
    borrowRecords.insert(make_pair(1, "张三"));
    borrowRecords.insert(make_pair(1, "李四"));
    borrowRecords.insert(make_pair(2, "王五"));
    borrowRecords.insert(make_pair(3, "赵六"));
    borrowRecords.insert(make_pair(1, "钱七"));
    
    cout << "记录借阅完成" << endl;
    
    // 查询图书信息
    cout << "\n图书信息查询：" << endl;
    for (const auto& book : books) {
        cout << "ID: " << book.first 
             << ", 书名: " << book.second.first 
             << ", 作者: " << book.second.second << endl;
    }
    
    // 查询图书借阅记录
    cout << "\n图书ID为1的借阅记录：" << endl;
    auto range = borrowRecords.equal_range(1);
    for (auto it = range.first; it != range.second; ++it) {
        cout << "借阅人: " << it->second << endl;
    }
    
    // 显示所有分类
    cout << "\n所有图书分类：" << endl;
    for (const auto& category : categories) {
        cout << category << endl;
    }
    
    return 0;
}