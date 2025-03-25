class Solution {
public:
    int lengthOfLastWord(string s) {
    	int n=0;
    	int m=0;
        for(int i=s.length()-1;i>=0;i--) {
        	if(s[i]==' '&&n==1)
        	return m;
        	if(s[i]!=' '){
        		n=1;
        		m++;
			}
		}
        return m;
    }
};
