#include <iostream>
#include <vector>
using namespace std;

// 插入排序算法实现
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    // 从第二个元素开始，逐个插入到已排序序列中
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // 当前要插入的元素
        int j = i - 1;     // 已排序序列的最后一个元素索引
        
        // 将大于key的元素向后移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // 插入key到正确位置
        arr[j + 1] = key;
    }
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
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    cout << "排序前: ";
    printArray(arr);
    insertionSort(arr);
    cout << "排序后: ";
    printArray(arr);
    
    return 0;
}