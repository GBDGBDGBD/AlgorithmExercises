class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> res;
    	int n=0;
        for(int i=0;i<nums.size();i++){
        	for(int j=0;j<nums.size();j++){
        		for(int k=0;k<nums.size();k++){
        			if(nums[i]+nums[j]+nums[k]==0){
        				res[n]={nums[i],nums[j],nums[k]};
        				n++;
					}
				}
			}
		} 
		
    }
};
//改正后  仍超时 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> res;
    	//sort(nums.begin(),nums.end());
      //  auto it=unique(nums.begin(),nums.end());
       // nums.erase(it,nums.end());
        for(int i=0;i<nums.size();i++){
        	for(int j=i+1;j<nums.size();j++){
        		for(int k=j+1;k<nums.size();k++){
        			if(nums[i]+nums[j]+nums[k]==0){
        				res.push_back({nums[i],nums[j],nums[k]});
					}
				}
			}
		} 
      for(auto &row:res){
        sort(row.begin(),row.end());
      }
      sort(res.begin(),res.end());
      auto it=unique(res.begin(),res.end());
      res.erase(it,res.end());
		return res;
    }
};  
//最终 排序＋双指针
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;

        // 先排序，方便去重和双指针查找
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // 避免重复的起始元素
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});

                    // 跳过重复元素
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        return res;
    }
};
 
