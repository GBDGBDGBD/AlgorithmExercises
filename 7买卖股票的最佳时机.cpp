class Solution {
public:
   int maxProfit(vector<int>& prices) {
       int pre = prices[0], ans = 0;
       for (int i = 0; i < prices.size(); i++) {
           ans = max(ans, prices[i] - pre);
           pre = min(pre, prices[i]);
       }
       return ans;
   }
};
//方法一：粗暴遍历，超时；方法二：只遍历一遍，每次都假设在当天卖出。 
