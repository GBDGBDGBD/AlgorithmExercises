class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x=matrix[0].size();
        int y=matrix.size();
        int direct_select[][]={{1,0},{0,1},{-1,0},{0,-1}};
        int direct=0;
        int sum=x*y;
         vector<int> res;
        vector<vector<int>> walked(x,vector<int>(y,0));//xy搞反了
		 
        int i=0;int j=0;
        for(int n=0;n<sum;n++){
            res.push_back(matrix[i][j]);
            walked[i][j]=1;
            i+=direct_select[direct][0];
            j+=direct_select[direct][1];
            if(i<0||i>=x||j<0||j>=y||walked[i][j]==1){
                i-=direct_select[direct][0];
                  j-=direct_select[direct][1];
                  direct=(direct+1)%4;
                   i+=direct_select[direct][0];
            j+=direct_select[direct][1];
            }

        }
        return res;
    }
};
//结果：
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int x=matrix[0].size();
        int y=matrix.size();
        int direct_select[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int direct=0;
        int sum=x*y;
         vector<int> res;
         vector<vector<int>> walked(y, vector<int>(x, 0));  
        int i=0;int j=0;
        for(int n=0;n<sum;n++){
            res.push_back(matrix[i][j]);
            walked[i][j]=1;
            i+=direct_select[direct][0];
            j+=direct_select[direct][1];
            if(i<0||i>=y||j<0||j>=x||walked[i][j]==1){
                i-=direct_select[direct][0];
                  j-=direct_select[direct][1];
                  direct=(direct+1)%4;
                   i+=direct_select[direct][0];
            j+=direct_select[direct][1];
            }

        }
        return res;
    }
}; 
