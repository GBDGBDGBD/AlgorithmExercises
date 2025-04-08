class Solution {
public:
   unordered_map <char,int> cnt;
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                ++cnt[board[i][j]];
            }
            for(int n=1;n<=9;n++){
                if(cnt[n]>1)
                return false;
            }
            cnt.clear();
        }
         for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                ++cnt[board[j][i]];
            }
            for(int n=1;n<=9;n++){
                if(cnt[n]>1)
                return false;
            }
            cnt.clear();
        }

//
    for(int a=0;a<9;a+=3){
        for(int b=0;b<9;b+=3){
            for(int i=a;i<a+3;i++){
            for(int j=b;j<b+3;j++){
                ++cnt[board[j][i]];
            }
        }
        for(int n=1;n<=9;n++){
                if(cnt[n]>1)
                return false;
            }
            cnt.clear();
            
        }
    }
       
//
       return true; 
    }

}; 
//int和char没搞清

 class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 检查行
        for (int i = 0; i < 9; ++i) {
            unordered_map<char, int> cnt;
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                ++cnt[c];
                if (cnt[c] > 1) return false;
            }
        }

        // 检查列
        for (int j = 0; j < 9; ++j) {
            unordered_map<char, int> cnt;
            for (int i = 0; i < 9; ++i) {
                char c = board[i][j];
                if (c == '.') continue;
                ++cnt[c];
                if (cnt[c] > 1) return false;
            }
        }

        // 检查 3x3 宫格
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                unordered_map<char, int> cnt;
                for (int i = row; i < row + 3; ++i) {
                    for (int j = col; j < col + 3; ++j) {
                        char c = board[i][j];
                        if (c == '.') continue;
                        ++cnt[c];
                        if (cnt[c] > 1) return false;
                    }
                }
            }
        }

        return true;
    }
};
//数组模拟 哈希表
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};// 哈希表存储每一行的每个数是否出现过，默认初始情况下，每一行每一个数都没有出现过
        // 整个board有9行，第二维的维数10是为了让下标有9，和数独中的数字9对应。
        int col[9][10] = {0};// 存储每一列的每个数是否出现过，默认初始情况下，每一列的每一个数都没有出现过
        int box[9][10] = {0};// 存储每一个box的每个数是否出现过，默认初始情况下，在每个box中，每个数都没有出现过。整个board有9个box。
        for(int i=0; i<9; i++){
            for(int j = 0; j<9; j++){
                // 遍历到第i行第j列的那个数,我们要判断这个数在其所在的行有没有出现过，
                // 同时判断这个数在其所在的列有没有出现过
                // 同时判断这个数在其所在的box中有没有出现过
                if(board[i][j] == '.') continue;
                int curNumber = board[i][j]-'0';
                if(row[i][curNumber]) return false; 
                if(col[j][curNumber]) return false;
                if(box[j/3 + (i/3)*3][curNumber]) return false;

                row[i][curNumber] = 1;// 之前都没出现过，现在出现了，就给它置为1，下次再遇见就能够直接返回false了。
                col[j][curNumber] = 1;
                box[j/3 + (i/3)*3][curNumber] = 1;
            }
        }
        return true;
    }
};


