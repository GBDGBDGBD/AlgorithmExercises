class Solution {
public:
    bool isPalindrome(string s) {
    		if(s.size()<=1)
		return true;
    	int i=0;
        for(char &c:s){
        	if(c>='A'&&c<='Z'){
        		c+=32;
			}
			else if(!(c>='a'&&c<='z')){//数字忘了 
				s.erase(0,i);//边界没考虑 
				i--;
			}
			i++;
		} 
	int i=0;
	int j=s.size();
	while(i<=j){//空格没删 
		if(s[i]!=s[j])
		return false;
	}
	return true;
		
    }
};
 //第二版  

class Solution {
public:
    bool isPalindrome(string s) {
    		if(s.size()<=1)
		return true;
    	int i=0;
        for(char &c:s){//操作i之后 c已经变了 
          //  cout<<s<<endl;
          cout<<(int)c<<endl;
        	if(c>='A'&&c<='Z'){
        		c+=32;
			}
			else if(!((c>='a'&&c<='z')||(c>='0'&&c<='9'))){
                if(i<s.size())
				s.erase(s.begin()+i);
				//i--;
                
			}
			i++;
		} 
        cout<<s<<endl;
	int i1=0;
	int j=s.size()-1;
	while(i1<=j){
       if(s[i1]==' ')
        i1++;
        if(s[j]==' ')
        j--;
        cout<<"i1:"<<s[i1]<<endl;
         cout<<"j:"<<s[j]<<endl;
		if(s[i1]!=s[j])
		return false;
        i1++;j--;
        
	}
	return true;
		
    }
};



class Solution {
public:
    bool isPalindrome(string s) {
    		if(s.size()<=1)
		return true;
    	int i=0;
       for (int i = 0; i < s.size(); ) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
        s[i] += 32; // 转小写
        i++;
    } 
    else if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
        s.erase(s.begin() + i); // 删除非字母数字字符
        // i 不增加，因为当前索引的新字符还未检查
    } 
    else {
        i++; // 继续遍历
    }
}

        cout<<s<<endl;
	int i1=0;
	int j=s.size()-1;
	while(i1<=j){
       if(s[i1]==' ')
        i1++;
        if(s[j]==' ')
        j--;
        cout<<"i1:"<<s[i1]<<endl;
         cout<<"j:"<<s[j]<<endl;
		if(s[i1]!=s[j])
		return false;
        i1++;j--;
        
	}
	return true;
		
    }
};
