class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size();
        int num=0; 
        vector<vector<int>> arr(2, vector<int>(size, 0)); 
        for(int i=0;i<size;i++){
        	for(int j=0;j<=num;j++){
        			if(j==num){
        				num++;
					arr[0][j]=nums[i];
					arr[1][j]=1;
					break;
				}
        		if(nums[i]==arr[0][j]){
        				arr[1][j]++;
        				break;
				}
			}
			
		}
	
	int ptr=0;
	int max=arr[1][0];
	for(int i=0;i<num;i++){
		if(arr[1][i]>=max){
max=arr[1][i];
		ptr=i;
        }
		
	}
	return arr[0][ptr];
		
		
		         
    }
};

//1.刚开始用二维数组，arr[1][1000000]超范围，应该用长度可变的
//2.两个for循环里面的逻辑不好， 
  bool found = false;
            for (int j = 0; j < num; j++) {
                if (nums[i] == arr[0][j]) {
                    arr[1][j]++;  // 增加该元素出现的次数
                    found = true;
                    break;
                }
            }
            if (!found) {  // 如果该元素没有找到，加入新元素
                arr[0][num] = nums[i];
                arr[1][num] = 1;
                num++;
            } 

