class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int ans=0;
    	int tmp=prices[0];
        for(int i=0;i<prices.size();i++){
        	if(prices[i]<prices[i+1]){
        		ans+=prices[i+1]-tmp;
                tmp=prices[i+1];
			}
			else
			tmp=prices[i+1];
		}
        return ans;
    }
};
