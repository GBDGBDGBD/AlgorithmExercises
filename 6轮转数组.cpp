class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	int size=nums.size();
    	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
         k = k % size; 
    	int arr[size+10];
        for(int i=0;i<k;i++) {
        	arr[i]=nums[size-k+i];
        	
        	
		}
		for(int i=0;i<size-k;i++){
			arr[i+k]=nums[i];
		}
		for(int i=0;i<size;i++){
			nums[i]=arr[i];
		}
    }
};
