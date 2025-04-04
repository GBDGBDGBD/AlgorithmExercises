class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.size()<=1)
        return s.size();
        int i=0;int j=0;
        int ans=0;
        string s1="";
        for(int i=0;i<s.size();i++){
            s1+=s[0];
              
        }
        if(s1==s)
        return 1;
       
        while(j<s.size()-1){
            j++;
            for(int n=i;n<j;n++){
                if(s[j]==s[n]){
                    i=n+1;
                    break;
                }
            }
            ans=max(ans,j-i+1);
        }
        cout<<"i:"<<i<<endl;
        cout<<"j:"<<j<<endl;
        return ans;
    }
};
//难点：特殊情况考虑 
