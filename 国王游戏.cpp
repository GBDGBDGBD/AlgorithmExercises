#include<bits/stdc++.h> 
using namespace std;
int N;
int a[1005],b[1005];//,ka,kb;
int ans[20000],t[20000],lena,lent,tt[20000],t2[20000],len;
void _init(){
	scanf("%d%d%d",&N,&a[0],&b[0]);
	for(int i=1;i<=N;i++)
	    scanf("%d%d",&a[i],&b[i]);
}
void _qst_ab(int l,int r){
	int i=l,j=r,ma=a[(i+j)>>1],mb=b[(i+j)>>1];
	while(i<=j){
		while(a[i]*b[i]<ma*mb) i++;
		while(a[j]*b[j]>ma*mb) j--;
		if(i<=j){
			swap(a[i],a[j]);
			swap(b[i],b[j]);
			i++;
			j--;
		}
		
	}
	if(l<j) _qst_ab(l,j);
	if(i<r) _qst_ab(i,r);
}
void _get_t(int Left,int Right){
	for(int i=1;i<=lent;i++){
		tt[i]+=t[i]*Left;
		tt[i+1]+=tt[i]/10;
		tt[i]%=10;
	}
	lent++;
	while(tt[lent]>=10){
		tt[lent+1]=tt[lent]/10;
		tt[lent]%=10;
		lent++;
		
	}
	while(lent>1&&tt[lent]==0)lent--;
	len=lent;
	memcpy(t,tt,sizeof(tt));
	memset(tt,0,sizeof(tt));
	for(int i=1,j=len;i<=len;i++,j--){
		t2[i]=t[j];
	}
	int x=0,y=0;
	for(int i=1;i<=len;i++){
		y=x*10+t2[i];
		tt[i]=y/Right;
		x=y%Right;
	}
	x=1;
	while(x<len&&tt[x]==0)x++;
	memset(t2,0,sizeof(t2));
	for(int i=1,j=x;j<=len;i++,j++)
		t2[i]=tt[j];
		memcpy(tt,t2,sizeof(t2));
		len=len+1-x;
	
}
bool _cmp(){
	if(len>lena) return true;
	if(len<lena) return false;
	for(int i=1;i<=len;i++){
		if(ans[i]<tt[i]) return true;
		else if(ans[i]>tt[i]) return false;
	} return false; 
}
void _solve(){
	_qst_ab(1,N);
	t[1]=1;lent=1;
	for(int i=1;i<=N;i++){
		memset(tt,0,sizeof(tt));
		len=0;
		_get_t(a[i-1],b[i]);
		if(_cmp()){
			memcpy(ans,tt,sizeof(tt));
			lena=len;
			
		}
	}
	for(int i=1;i<=lena;i++)
	cout<<ans[i];
	cout<<endl;
}
int main(){
	_init();
	_solve();
	return 0;
}
