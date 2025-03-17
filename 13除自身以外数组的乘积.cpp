class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1); // 初始化答案数组，大小为n
        vector<int> L(n, 1);      // 左侧乘积数组
        vector<int> R(n, 1);      // 右侧乘积数组

        // 计算左侧乘积
        for (int i = 1; i < n; i++) {
            L[i] = L[i - 1] * nums[i - 1];
        }

        // 计算右侧乘积
        for (int i = n - 2; i >= 0; i--) {
            R[i] = R[i + 1] * nums[i + 1];
        }

        // 计算最终答案
        for (int i = 0; i < n; i++) {
            answer[i] = L[i] * R[i];
        }

        return answer;
    }
};
//双指针解法
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size(); // 获取数组长度
    vector<int> ans(n, 1); // 初始化输出数组，所有元素为1

    int beforeSum = 1; // 前缀乘积
    int afterSum = 1; // 后缀乘积

    for (int i = 0, j = n - 1; i < n; i++, j--) {
        ans[i] *= beforeSum; // 更新前缀乘积
        ans[j] *= afterSum; // 更新后缀乘积
        beforeSum *= nums[i]; // 更新前缀乘积变量
        afterSum *= nums[j]; // 更新后缀乘积变量
    }

    return ans;
} 
