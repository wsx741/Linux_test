#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // 未找到目标值
}
// 打印数组元素
void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    cout << "数组内容: ";
    printArray(arr);
    
    // 测试多个查找值
    vector<int> targets = {7, 1, 19, 4, 20};
    
    cout << "\n=== 迭代方式二分查找 ===" << endl;
    for (int target : targets) {
        int result = binarySearch(arr, target);
        if (result != -1) {
            cout << "找到了 " << target << "，位置: " << result << endl;
        } else {
            cout << "未找到 " << target << endl;
        }
    }
    return 0;
}