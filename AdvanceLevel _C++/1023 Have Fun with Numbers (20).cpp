#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int char2int(char c){
	return int(c)-48;
}

void sumchar(char n[],int sum[]){
	for(int i=0;i<strlen(n);i++){
		int temp=int(n[i]-48);
		sum[temp]++; 
	}
}

int main(){
	char n[50];
	char m[50]={0};
	scanf("%s",n);
	int len=strlen(n);
	int upflag=0,tempnum=0;
	for(int i=len-1;i>=0;i--){
		tempnum=2*char2int(n[i])+upflag;
		if(tempnum>9){
			upflag=1;
			tempnum-=10;
			m[i]=tempnum+'0';
		}
		else{
			upflag=0;
			m[i]=tempnum+'0';
		} 
	}
	if(upflag){
		printf("No\n1%s",m);
		return 0;
	}
	int sumn[10]={0};
	int summ[10]={0};
	sumchar(n,sumn);
	sumchar(m,summ);
	for(int i=0;i<10;i++){
		if(sumn[i]!=summ[i]){
			printf("No\n%s",m);
			return 0;
		}
	}
	printf("Yes\n%s",m);
	return 0;
} 
