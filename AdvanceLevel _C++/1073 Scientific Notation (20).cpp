#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#define MAX 2147483647
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	char in[10010];
	cin.getline(in,10010);
	if(in[0]=='-') printf("%c",in[0]);
	int len,expi=0,num;
	for(expi=0;expi<strlen(in);expi++){
		if(in[expi]=='E') break;
	}
	int exp=0;
	for(int i=expi+2;i<strlen(in);i++){
		exp*=10;exp+=in[i]-'0';
	}
	if(in[expi+1]=='-'){
		int i;
		for(i=0;i<exp;i++){
			printf("0");
			if(i==0) printf(".");
		}
		printf("%c",in[1]);
		if(i==0) printf(".");
		for(int i=3;i<expi;i++){
			printf("%c",in[i]);
		}
		
	}else{
		printf("%c",in[1]);
		num=exp;
		int i=3;
		while(num--){
			if(in[i]!='E'){
				printf("%c",in[i]);i++;
			}
			else printf("0");
		}
		if(i!=expi) printf(".");
		for(i;i<expi;i++){
				printf("%c",in[i]);
		}
	}
	
	return 0;
 } 
