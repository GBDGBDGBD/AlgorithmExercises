class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int size=nums.size();
    	int j=1;
        for(int i=1;i<size;i++){
        	if(nums[i]!=nums[j]||(nums[i]==nums[j]&&nums[j]!=nums[j-1])){
        		j++;
        		nums[j]=nums[i];
			}
		}
		return j+1;
    }
};
思路复杂了
只要前元素和新数组倒数第二个元素不相等，则可以添加到新数组中
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int size = nums.size();
        if (size < 2)
            return size;

        int j = 2;  // 从第三个元素开始处理
        for (int i = 2; i < size; i++) {
            // 如果当前元素和新数组倒数第二个元素不相等，则可以添加到新数组中
            if (nums[i] != nums[j - 2]) {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
}; 
