#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        int tmp;
        int n=0;
        int tag=0;
        string s1;
        for(int i=0;i<s.size();i++){
        	if(s[i]!=' '){
        		v[n]+=s[i];//这里会访问空元素 然后报错 
        	
        		tag=1;
			}
			else if(tag==1&&s[i]==' '){
					n++;
					tag=0;
				
			}
        	
		}
		for(int i=v.size()-1;i>=0;i--){
			s1.append(v[i]);
			s1.append(" ");
		}
		return s1;
    }
};
int main(){
	string s;
	cin>>s;
Solution sol;
cout << sol.reverseWords(s);

}

//更正后
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;  // 存储单词
        string word, result;

        for (char c : s) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                v.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) v.push_back(word);

        for (int i = v.size() - 1; i >= 0; i--) {
            result += v[i];
            if (i > 0) result += ' ';
        }

        return result;
    }
};

int main() {
    string s;
    getline(cin, s);  

    Solution sol;
    cout << sol.reverseWords(s) << endl;

    return 0;
}
 
