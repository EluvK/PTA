#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

bool isprime(int n){
	if(n==1||n==2) return true;
	else{
		int temp=int(sqrt(n*1.0));
		for(int i=2;i<=temp;i++){
			if(n%i!=0) continue;
			else return false;
		}
	}
	return true;
}

int main(){
//	freopen("1.txt","r",stdin);
	
	int N;
	scanf("%d",&N);
	
	printf("%d=",N);
	if(N==1){
		printf("1");
	}
	while(!isprime(N)){
		int max=int(sqrt(N*1.0));
		for(int i=2;i<=max;i++){
			if(N%i==0){
				int num=0;
				while(N%i==0){
					num++;
					N=N/i; 
				}
				if(num>1){
					if(N==1){
						printf("%d^%d",i,num);
						return 0;
					}else{
						printf("%d^%d*",i,num);
					}
				}
				else{
						if(N==1){
						printf("%d",i,num);
						return 0;
					}else{
						printf("%d*",i,num);
					}
				}
			}
			max=int(sqrt(N*1.0));
		}
	}
	if(N!=1){
		printf("%d",N);	
	}
//	printf("%d",N);
	
} 
