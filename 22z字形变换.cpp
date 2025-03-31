#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
    	//一行的没考虑 
        int rows=numRows,cols=200; //cols直接s.size() 
        int n=0;int m=0;
        int tag=0;
        string s1; 
        vector<vector<char>> vec(rows,vector<char>(cols,' '));//固定cols导致边界错误 
        for(int i=0;i<s.size();i++){
        	vec[n][m]=s[i];
        	if(n==rows-1)
        	tag=1;
        	else if(n==0)
        	tag==0;//问题1 应该是= 
            if(tag==0){
            	n++;
			}
			else if(tag==1){
				n--;m++;
			}
		}
		for(int i=0;i<rows-1;i++){
			for(int j=0;j<m-1;j++){//s.size() 
				if(vec[i][j]!=' ')
				s1+=vec[i][j];
			}
		}
		return s1;
    }
};
int main(){
	string s;
	int n;
	cin>>s>>n;
	Solution sol;
	cout<<sol.convert(s,n)<<endl;
	return 0;
	
}

//第一版
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)  return s;
        int rows=numRows,cols=s.size(); 
        int n=0;int m=0;
        int tag=0;
        string s1; 
        vector<vector<char>> vec(rows,vector<char>(cols,' '));
         for(int i=0;i<s.size();i++){
        	vec[n][m]=s[i];
        	if(n==rows-1)
        	tag=1;
        	else if(n==0)
        	tag=0;
            if(tag==0){
            	n++;
			}
			else if(tag==1){
				n--;m++;
			}
		}
		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				if(vec[i][j]!=' ')
				s1+=vec[i][j];
			}
		}
		return s1;
    }
}; 
//改后 这样操作可以不用管纵坐标 
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;  // 如果只有 1 行，直接返回

        vector<string> vec(numRows); // 用字符串数组存储每行字符
        int n = 0, dir = 1; // 方向：1 表示向下，-1 表示向上

        for (char c : s) {
            vec[n] += c; // 直接追加字符
            if (n == 0) dir = 1;        // 到达第一行，向下移动
            if (n == numRows - 1) dir = -1;  // 到达最后一行，向上移动
            n += dir;
        }

        // 组合所有行
        string s1;
        for (string &row : vec) {
            s1 += row;
        }
        return s1;
    }
};
 
