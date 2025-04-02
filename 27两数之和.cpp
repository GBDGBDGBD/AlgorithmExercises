class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	int i=0;int j=0;
        while(numbers[i]<=target&&i<=numbers.size()-2){
            cout<<"i:"<<i<<endl;
        	j=i+1;
        	while(j<=numbers.size()-1&&numbers[i]+numbers[j]<=target){
                  cout<<"j:"<<j<<endl;
        		if(numbers[i]+numbers[j]==target)
        		return {i+1,j+1};
        		else
        		j++;
			}
			i++;
		} 
		return{-1,-1};
    }
};
//超时了 原因 两层for
 class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target)
            return {i+1,j+1};
            else if(numbers[i]+numbers[j]>target)
            j--;
            else
            i++;
        }
  return {-1,-1};
    }
};
