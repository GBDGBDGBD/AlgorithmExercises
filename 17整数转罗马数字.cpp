class Solution {
	public:
		string intToRoman(int num) {
			int tmp=0;
			int n=0;
			int m=1;//位数当前
			int tmp1==0;//实际数字
			int tmp2=0;
			int tmp3=0;
			char arr[30];
			i=0;
			while(num>0) {
				tmp=num%10;
				num=num/10;
				tmp1=tmp*m;
				if(tmp==4) {
					if(m==1) {
						arr[i]='V';
						arr[i+1]='I';
						i+=2;
					} else if(m==2) {
						arr[i]='L';
						arr[i+1]='X';
						i+=2;
					} else if(m==3) {
						arr[i]='D';
						arr[i+1]='C';
					}
				} else if(tmp==9) {
					if(m==1) {
						arr[i]='X';
						arr[i+1]='I';
						i+=2;
					} else if(m==2) {
						arr[i]='C';
						arr[i+1]='X';
						i+=2;
					} else if(m==3) {
						arr[i]='M';
						arr[i+1]='C';
						i+=2;
					}
				} else {
					if(m==1) {
						if(tmp>=5) {
							for(int i=0; i<tmp-5; i++) {
								arr[i]='I';
								i++;
							}
							arr[i]='V';
							i++;
						} else {
							for(int i=0; i<tmp; i++) {
								arr[i]='I';
								i++;
							}
						}
					}
					else if(m==2){
						if(tmp>=5) {
							for(int i=0; i<tmp-5; i++) {
								arr[i]='X';
								i++;
							}
							arr[i]='L';
							i++;
						} else {
							for(int i=0; i<tmp; i++) {
								arr[i]='X';
								i++;
							}
						}
					}
					else if(m==3){
						if(tmp>=5) {
							for(int i=0; i<tmp-5; i++) {
								arr[i]='C';
								i++;
							}
							arr[i]='D';
							i++;
						} else {
							for(int i=0; i<tmp; i++) {
								arr[i]='C';
								i++;
							}
						}
					}
					else if(m==4){
							for(int i=0; i<tmp; i++) {
								arr[i]='M';
								i++;
							}
					}
				}


				m++;
			}
			int q=sizeof(arr)/sizeof(arr[0]);
			reverse(arr,arr+n); 
			return arr;
		}
};
//太复杂 错误
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result = "";
        for (auto &[value, symbol] : romanMap) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }
};

