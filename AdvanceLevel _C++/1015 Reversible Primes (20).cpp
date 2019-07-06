#include <stdio.h>
#include <string.h>
#include <math.h>

int judge(int n){
	//判断是否为质数，质数返还1
	if(n<=1) return 0;
	if(n==2) return 1;
	int max=int(sqrt(n*1.0));
	for(int i=2;i<=max+1;i++){
		if((n%i==0)) return 0;
	}
	return 1;
}
int revers(int N,int D){
	int temp[100];
	int len=0;
	do{
		temp[len++]=N%D;
		N/=D;
	}while(N!=0);
	for(int i=0;i<len;i++){
		N=N*D+temp[i];
	}
	return N;
}

int main(){
	int N,D;
	while(scanf("%d",&N)!=EOF){
//		scanf("%d",&N);
		if(N<0) break;
		scanf("%d",&D);

		printf("%s",judge(N)&&judge(revers(N,D))?"Yes\n":"No\n");
		
	}
}
