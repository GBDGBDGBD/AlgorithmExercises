class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int a=1000000;
    	int ptr=0;
    	int nsize=nums.size;
    	int arr[nsize];
    	int tmp;
        for(int i=1;i<nsize;i++){
        	if(nums[i]==nums[i-1]){
        		nums[i-1]=a;
			}
		} 
		for(int i=0;i<nsize;i++){
			if(nums[i]!=a){
				arr[ptr]=nums[i];
				ptr++;
			}
		}
		for(int i=0;i<ptr;i++){
			nums[i]=arr[i];
		}
		return ptr;
    }
};
//答案是双指针，很巧妙简单https://leetcode.cn/problems/remove-duplicates-from-sorted-array/solutions/728105/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-tudo/?envType=study-plan-v2&envId=top-interview-150 
