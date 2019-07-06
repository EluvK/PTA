#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
	int N,b;
	int arr[100];
	
	scanf("%d %d",&N,&b);
	int len=0;
	int num;
	num=N;
	while(N){
			
		arr[len++]=N%b;
		N=N/b;
	}
	int flag=0;
	if(len==1||num==0){
		printf("Yes\n");
	}
	else{
		for(int i=0;i<len/2+1;i++){
			if(arr[i]!=arr[len-i-1]){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("No\n");
		}
		else printf("Yes\n");
	}
	
	
	printf("%d",arr[len-1]);
	for(int i=len-2;i>=0;i--){	
		printf(" %d",arr[i]);
	}
	
	// 26 2
	//arr N len
	//0 13 1
	//1 6 2
	//0 3 3
	//1 1 4
	//1 0
	
} 
