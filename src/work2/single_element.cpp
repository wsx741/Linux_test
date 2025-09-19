#include <iostream>
#include <vector>

using namespace std;
int findSingleElement(vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    // 测试用例1
    vector<int> nums1 = {2, 3, 2, 4, 4};
    cout << "数组: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;
    cout << "只出现一次的元素是: " << findSingleElement(nums1) << endl;
    return 0;
}