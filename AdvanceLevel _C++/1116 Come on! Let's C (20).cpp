#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

bool isprime(int n){
	if(n==2) return true;
	for(int i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}

int main(){
//	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	int arr[n];
	int book[10000]={0};
	int check[10000]={0};
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		book[arr[i]]=i;
	}
	
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int temp;
		scanf("%d",&temp);
		printf("%04d: ",temp);
		if(book[temp]==0){
			printf("Are you kidding?\n");
		}else if(check[temp]==1){
			printf("Checked\n");
		}else if(book[temp]==1){
			printf("Mystery Award\n");
			check[temp]=1;
		}else if(isprime(book[temp])){
			printf("Minion\n");
			check[temp]=1;
		}else{
			 printf("Chocolate\n");
			 check[temp]=1; 
		}
	}
}
