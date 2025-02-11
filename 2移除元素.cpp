class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size=nums.size();
        int deleted[size+1];
        int p=0;
        for(int i=0;i<size;i++){
           
            if(nums[i]!=val)
            
            deleted[p++]=nums[i];

        }
        for(int i=0;i<p;i++){
            nums[i]=deleted[i];
        }
        return p;
    }
};
