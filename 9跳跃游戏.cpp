class Solution {
public:
    bool canJump(vector<int>& nums) {
    int tag=0;
    	for(int i=0;i<nums.size();i++){
            if(nums.size()==1){
                return true;
            }
    		if(nums[i]==0){
    		
    		for(int j=i;j>=0;j--){
                if(nums[j]>=i-j&&i==nums.size()-1){
    				tag=1;
    					break;
				}
    			if(nums[j]>i-j){
    				tag=1;
    					break;
				}
    		
    			
			}
			if(tag==0){
				return false;
			}
			else
			tag=0;
			
			}
		}
		return true;
       
    }
};
//太复杂了 答案用贪心，维护一个基于当前位置的可到达最远的位置 
 class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i) {
            if (i <= rightmost) {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};


