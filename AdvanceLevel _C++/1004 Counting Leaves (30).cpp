#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

struct node{
	int knum;
	int arr[100];
	int level;
}A[110];
int n,m;
bool check(){
	for(int i=1;i<=n;i++){
		if(A[i].level==0) return true;
	}
	return false;
}
int main(){
//	freopen("1.txt","r",stdin);
	int level[110]={0};
	scanf("%d",&n);
	if(n){
		scanf("%d",&m);
		for(int i=0;i<110;i++){
			A[i].level=0;
			A[i].knum=0;
		}
		for(int i=0;i<m;i++){
			int temp;
			scanf("%d",&temp);
			scanf("%d",&A[temp].knum);
			for(int j=0;j<A[temp].knum;j++){
				scanf("%d",&A[temp].arr[j]);
			}
		}
		A[1].level=1;
		while(check()){
			for(int i=1;i<=n;i++){
				if(A[i].knum&&A[i].level){
					for(int j=0;j<A[i].knum;j++){
						A[A[i].arr[j]].level=A[i].level+1;
					}
				}
			}
		}
		int max=1;
		for(int i=1;i<=n;i++){
			if(A[i].level>max) max=A[i].level;
		}
		for(int i=1;i<=n;i++){
			if(A[i].knum==0) level[A[i].level]++;
		}
		for(int i=1;i<=max;i++){
			printf("%d%c",level[i],i==max?'\n':' ');
		}		
	}	
} 
