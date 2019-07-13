#include <stdio.h>
#include <iostream>

using namespace std;

bool isprime(int n){
	if(n==1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
//	freopen("1.txt","r",stdin);
	int n,m,temp,mod,trytime;
	scanf("%d%d",&n,&m);
	if(!isprime(n)){
		while(!isprime(++n)){
		}
	}
	int hash[20000];
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		for(trytime=0;trytime<=n;trytime++){
			mod=(temp+trytime*trytime)%n;
			if(hash[mod]==0){
				hash[mod]=1;
				printf("%d%c",mod,i==m-1?'\n':' ');
				break;
			}
		}
		if(trytime>n){
			printf("-%c",i==m-1?'\n':' ');
		}
	}	
}
