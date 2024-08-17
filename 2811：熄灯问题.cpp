#include<bits/stdc++.h>
using namespace std;
int main(){
	int puzzle[6][8]={0},press[6][8]={0};
	for(int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			int tmp=5;
			cin>>tmp;
			puzzle[i+1][j+1]=tmp;
		}
	}
	for(int a0=0;a0<2;a0++)
	for(int a1=0;a1<2;a1++)
	for(int a2=0;a2<2;a2++)
	for(int a3=0;a3<2;a3++)
	for(int a4=0;a4<2;a4++)
	for(int a5=0;a5<2;a5++){
		press[1][1]=a0;
		press[1][2]=a1;
		press[1][3]=a2;
		press[1][4]=a3;
		press[1][5]=a4;
		press[1][6]=a5;
		
		for(int i=2;i<=5;i++){
			for(int j=1;j<=6;j++){
				press[i][j]=(puzzle[i-1][j]+press[i-1][j]+press[i-1][j-1]
				+press[i-1][j+1]+press[i-2][j])%2;
			}
			
		}
		for(int k=1;k<=6;k++){
			if((press[5][k]+puzzle[5][k]+press[4][k]+press[5][k-1]+press[5][k+1])%2){
				goto tap;
		}}
	   for(int q=1;q<=5;q++){
	   	for(int w=1;w<=6;w++){
	   		cout<<press[q][w]<<" ";
		   }
		   std::cout << std::endl;

	   }
	   return 0;
	   tap:;
	}
	

}
