#include <bits/stdc++.h> 
using namespace std;
int sa=0,sb=0;
void play(int a,int b){
	if(a==0){
	if(b==0)
	;
	else if(b==1||b==4)
	sa++;
	else
	sb++;
		
	}
	else if(a==1){
		if(b==0||b==3)
		sa++;
		else if(b==1)
		;
		else
		sb++;
	}
	else if(a==2){
		if(b==2)
		;
		else if(b==0||b==3)
		sb++;
		else
		sa++;
		
	}
	else if(a==3){
		if(b==0||b==1)
		sb++;
		else if(b==3)
		;
		else
		sa++;	
	}
	else{
		if(b==0||b==1)
		sa++;
		else if(b==4)
		;
		else
		sb++; 
		}
	}
	
int main(){
	int n,na,nb;
	cin>>n>>na>>nb;
	int a[na],b[nb];
	for(int i=0;i<na;i++){
		cin>>a[i];
	}
	for(int i=0;i<nb;i++){
		cin>>b[i];
	}
	int ta=0,tb=0;
	for(int i=0;i<n;i++){
		if(ta>=na)
		ta-=na;
		if(tb>=nb)
		tb-=nb;
		play(a[ta],b[tb]);
		ta++;tb++;
		
	}
	cout<<sa<<" "<<sb;
	return 0;
	
}
