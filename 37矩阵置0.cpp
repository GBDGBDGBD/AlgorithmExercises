class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();//错误这是m*n 
        vector<vector<int>> iszero (n,vector<int>(n,0));
          for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                   iszero[i][j]=1;
                }
            }
        }
        if(iszero[0][3]==1)
        cout<<"dddddddddddddddd"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(iszero[i][j]==1){
                    fill(matrix[i].begin(),matrix[i].end(),0);
                    for(int q=0;q<n;q++){
                        matrix[q][j]=0;
                    }
                }
            }
        }
    }
};
// 
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size(); //行搞反 
        vector<vector<int>> iszero (n,vector<int>(n,0));//没改完 
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                   iszero[i][j]=1;
                }
            }
        }
        if(iszero[0][3]==1)
        cout<<"dddddddddddddddd"<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(iszero[i][j]==1){
                    fill(matrix[i].begin(),matrix[i].end(),0);
                    for(int q=0;q<n;q++){
                        matrix[q][j]=0;
                    }
                }
            }
        }
    }
};

、、
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size(); 
        vector<vector<int>> iszero (m,vector<int>(n,0));
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                   iszero[i][j]=1;
                }
            }
        }
    
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(iszero[i][j]==1){
                    fill(matrix[i].begin(),matrix[i].end(),0);
                    for(int q=0;q<m;q++){
                        matrix[q][j]=0;
                    }
                }
            }
        }
    }
}; 
