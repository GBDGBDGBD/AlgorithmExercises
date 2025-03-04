class Solution {
public:
    int jump(vector<int>& nums) {
        
    }
};
//本题没做出来
//动态规划 

方法	时间复杂度	空间复杂度	适用场景
动态规划 (DP)	O(n^2)	O(n)	适用于 n 较小的情况
贪心算法	O(n)	O(1)	适用于 n 较大的情况，推荐
 class Solution { 
public:     
    int jump(vector<int>& nums) {         
        vector<int> dp(nums.size(),1e9); // 初始化 dp 数组，每个位置默认设置为无穷大（1e9）         
        dp[0] = 0; // 起点不需要跳跃，所以跳跃次数为 0
        
        for(int i = 1; i < nums.size(); i++) {  // 遍历每个位置 i
            for(int k = 0; k < i; k++) {  // 遍历 i 之前的所有位置 k
                if(nums[k] + k >= i)  // 如果 k 能跳到 i
                    dp[i] = min(dp[i], dp[k] + 1);  // 更新到达 i 的最小步数
            }
        }
        
        return dp[nums.size() - 1];  // 返回到达最后一个位置的最小跳跃次数
    } 
};
//优化后：
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, maxReach = 0, lastJumpEnd = 0;
        
        for (int i = 0; i < n - 1; i++) {  // 不需要遍历到最后一个位置
            maxReach = max(maxReach, i + nums[i]);  // 更新最远可达位置
            
            if (i == lastJumpEnd) {  // 如果当前索引到达了上次跳跃的边界
                jumps++;  
                lastJumpEnd = maxReach;  // 更新跳跃的最远边界
                
                if (lastJumpEnd >= n - 1) break;  // 如果已经可以到达终点，提前结束
            }
        }
        
        return jumps;
    }
};


