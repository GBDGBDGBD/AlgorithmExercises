class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int c:nums){
            cout<<c<<endl;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
         sum+=nums[i];
         if(sum>=target)
         return i+1;
        }
        return 0;
    }

}; //错误原因 字数组意味着不能排序 
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       if(nums.size()==0)
       return 0;
       int i=0;
       int j=0;
       int ans=9999999;
       int sum=0;
       while(j<=nums.size()-1){
        sum+=nums[j];
        cout<<"j:"<<j<<endl;
        j++;
        while(sum>=target){
            cout<<"i:"<<i<<endl;
            sum-=nums[i]; 
             i++;
           ans=min(j-i+1,ans);
             cout<<"ans内:"<<ans<<endl;
                    
            
               cout<<"sum内:"<<sum<<endl;
             cout<<"______________________________"<<endl;
        }
         cout<<"ans:"<<ans<<endl;
         cout<<"sum:"<<sum<<endl;
       }
       if(ans==9999999)
       return 0;
       else
       return ans;
    }

};
