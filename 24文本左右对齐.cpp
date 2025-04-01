class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	int i=0;//当前已多少单词 
    	int n=0;//每行多少单词 
    	int tmp=-1;//记录每行当前多少个字符
	//	int j=0;//记录当前多少个 
		int kong=0;//记录平均多少空格 
		int kong1=0;//记录空格余数 
		int qu=0;//当前行数； 
		string opt="                                       ";//方便截取 
    	vector<string> vec(1000);
        while(i<=words.size()){
        	n=0;
		//	j=0;
			tmp=-1;
			kong=0;
			kong1=0;
			
        	while((tmp+words[i]+1)<=maxWidth){//应该是.size（） 
        		tmp+= words[i]+1;
        		i++;
        		n++; 
			}
			kong=(maxWidth-tmp)/(n-1); //没考n=1； 
			kong1=(maxWidth-tmp)%(n-1); 
			for(int q=0;q<n;q++){//拼接单词
			if(i!=words.size()){
				 vec[qu]+=words[i-n+1]+opt.substr(0,kong+kong1);
			 if(kong1>0)
			 kong1--;
			} 
			else
			{
				 vec[qu]+=words[i-n+1]+" ";
			}
			
				
			}
		}
		return vec;
    }
};
//第二版
 class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	int i=0;//当前已多少单词 
    	int n=0;//每行多少单词 
    	int tmp=-1;//记录每行当前多少个字符
	//	int j=0;//记录当前多少个 
		int kong=0;//记录平均多少空格 
		int kong1=0;//记录空格余数 
		int qu=0;//当前行数； 
		string opt="                                       ";//方便截取 
    	vector<string> vec(1000);//分配过大 不合理 ，用 push_back 代替固定大小的 vector ，方法：定义一个每一行的line，每次算完之后pushback 
        while(i<=words.size()){//问题：应该是size-1，因为下标从0开始 
        	n=0;
		//	j=0;
			tmp=-1;
			kong=0;
			kong1=0;
			
        	while((tmp+words[i].size()+1)<=maxWidth){//判断条件需要加上 i<=words.size()，不然会越界 
        		tmp+= words[i].size()+1;
        		i++;
        		n++; 
			}
			
            if(n>1){//n>1意味着有多个单词，加上 i<=words.size()，这样最后一行就不需要计算kong 
kong=(maxWidth-tmp)/(n-1); 
			kong1=(maxWidth-tmp)%(n-1); 
            }
            
			
			for(int q=0;q<n;q++){//拼接单词
			if(i!=words.size()){
				 vec[qu]+=words[i-n+1]+opt.substr(0,kong+kong1);//应该是i-n+q  kong+kong1应该再加个1 ，而且不应该是加kong1 应该每次只加1 知道kong1=0 
			 if(kong1>0)
			 kong1--;
			} 
			else
			{
				 vec[qu]+=words[i-n+1]+" ";
			}
			
				
			}//最后一行需要填充空格 
		}
		return vec;
    }
};
//最终 写成 
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0;
        int n = 0;
        int tmp = -1;
        int kong = 0;
        int kong1 = 0;
        int qu = 0;
        string opt = "                                       "; // 空格填充用
        vector<string> vec;

        while (i < words.size()) {
            n = 0;
            tmp = -1;
            kong = 0;
            kong1 = 0;
            
            // 尽可能多地放入单词
            while (i < words.size() && (tmp + words[i].size() + 1) <= maxWidth) {
                tmp += words[i].size() + 1;
                i++;
                n++;
            }

            string line;
            if (i != words.size() && n > 1) {  // 不是最后一行，且有多个单词
                kong = (maxWidth - tmp) / (n - 1);
                kong1 = (maxWidth - tmp) % (n - 1);
         cout<<kong<<"qqqqqqqqqq"<<kong1<<endl;
                for (int q = 0; q < n; q++) {
                    if(kong1>0){
line += words[i - n + q] +opt.substr(0,kong+1+1);
if (kong1 > 0) kong1--;
                    }
                    else
                    line += words[i - n + q] +opt.substr(0,kong+1);
                    
                    
                }
               line = line.substr(0, maxWidth); // 避免超出 maxWidth
            } else { // 最后一行，左对齐
                for (int q = 0; q < n; q++) {
                    line += words[i - n + q] + " ";
                }
                line = line.substr(0, maxWidth); // 最后一行补齐空格
                line += string(maxWidth - line.size(), ' ');
            }

            vec.push_back(line);
        }
        return vec;
    }
};

