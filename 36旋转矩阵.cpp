class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       vector<vector<int>> mat=matrix;
       int x=matrix.size();
       int y=matrix[0].size()-1;

       for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
         matrix[j][y]=mat[i][j];
        }
        y--;
      
       }
    }
};
//方法2 自己实现的 转置加列调转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       vector<vector<int>> mat=matrix;
       int x=matrix.size();
     for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            if(i<j)
            swap(matrix[i][j],matrix[j][i]);
        }
     }
     for(int i=0;i<x;i++){
        for(int j=0;j<x/2;j++){
           
            swap( matrix[i][j],matrix[i][x-j-1]);
        }
     }
    }
}; 
