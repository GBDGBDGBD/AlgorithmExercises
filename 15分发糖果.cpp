
//逻辑太复杂，根本改不对 
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	
    int candy(vector<int>& ratings) {
    	int n=ratings.size();
    vector<int> big(n,-1);
    //	int ratings[0]=1;
    	vector<int> candy(n,1);
    	int can=1;
        for(int i=1;i<n;i++){
        	if(ratings[i]<=ratings[i-1])
        	{
        		big[i]=0;
        
			}
        	
        	else{
        		big[i]=1;
			}
		} 
		
		for(int i=1;i<n;i++){
			if(big[i]==1){
candy[i]=candy[i-1]+1;
			can+=candy[i];
            }
			
			else
			{
				int num=0;
				for(int j=i;j<n;j++){
					if(big[j]==0)
					num++;
					else
					break;
				} 
			
				int num1=num;
				for(int j=i-1;j<=num1;j++){
					candy[j]=num+1;
					can+=candy[i];
					num--;
				
				}
                
			}
		}
	
	

		return can;
    }
};
int main() {
    Solution solution;
 vector<int> ratings1 = {1, 0, 2};
   solution.candy(ratings1);
  

    return 0;
}

//
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);  // 初始化每个孩子的糖果数为1

        // 从左到右遍历，确保右边评分更高的孩子获得更多的糖果
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }

        // 从右到左遍历，确保左边评分更高的孩子获得更多的糖果
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        // 计算总糖果数
        int totalCandy = 0;
        for (int i = 0; i < n; i++) {
            totalCandy += candy[i];
        }

        return totalCandy;
    }
}; 
