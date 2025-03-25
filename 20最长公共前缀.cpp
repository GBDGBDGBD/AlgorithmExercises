class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    //	string n=strs[0];
    int n=0;
        for(int i=strs[0].length();i>=0;i--){
        //	n=n.substr(0,i);
        n=0;
        	for(int j=0;j<strs.size();j++){
        		if(strs[j].substr(0,i)==strs[0].substr(0,i)){
        			n++;
				}
			}
			if(n==strs.size()){
				return strs[0].substr(0,i);
			}
           
		} 
		return "";
    }
};
