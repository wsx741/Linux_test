#include <iostream>
#include <vector>

using namespace std;
void moveZeros(vector<int>& nums) {
    int index = 0; // 记录非零元素应插入的位置
    
    // 遍历数组，将非零元素移到前面
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[index++] = nums[i];
        }
    }
    
    // 将剩余位置全部填0
    while (index < nums.size()) {
        nums[index++] = 0;
    }
}

int main() {
    vector<int> nums(10);
    
    cout << "请输入10个数字：";
    for (int i = 0; i < 10; i++) {
        cin >> nums[i];
    }
    
    moveZeros(nums);
    
    cout << "处理后数组为：";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}