#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 查找数组中的最大值和次大值
pair<int, int> findMaxAndSecondMax(const vector<int>& arr) {
    if (arr.size() < 2) {
        throw invalid_argument("数组中至少需要两个元素");
    }
    
    int maxVal = INT_MIN;
    int secondMaxVal = INT_MIN;
    
    // 遍历数组查找最大值和次大值
    for (int num : arr) {
        if (num > maxVal) {
            secondMaxVal = maxVal;  // 更新次大值
            maxVal = num;           // 更新最大值
        } else if (num > secondMaxVal && num < maxVal) {
            secondMaxVal = num;     // 更新次大值
        }
    }
    
    // 检查是否找到了有效的次大值
    if (secondMaxVal == INT_MIN) {
        throw invalid_argument("数组中没有两个不同的元素");
    }
    
    return make_pair(maxVal, secondMaxVal);
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
    cout << "]";
}

int main() {
    vector<int> arr1 = {3, 1, 4, 1, 5, 9, 2, 6};
    cout << "数组1: ";
    printArray(arr1);
    try {
        pair<int, int> result = findMaxAndSecondMax(arr1);
        cout << "\n最大值: " << result.first << ", 次大值: " << result.second << endl;
    } catch (const exception& e) {
        cout << "\n错误: " << e.what() << endl;
    }
    return 0;
}