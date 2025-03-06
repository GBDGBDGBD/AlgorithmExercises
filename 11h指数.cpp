class Solution {
public:
    int hIndex(vector<int>& citations) {
    	int num=0;
    	int csize=citations.size();
        for(int i= csize;i>0;i--){
        	for(int j=0;j<csize;j++){
        		if(citations[j]>=i){
        			num++;
				}
			}
			if (num>=i){
				return i;
			}
			num=0;
		}
        return 0;
    }
};
