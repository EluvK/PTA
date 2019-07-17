#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;

struct node{
	int a;int b;
}A[60000];

int main(){
//	freopen("1.txt","r",stdin);
	int n,m,temp,sum;
	int book[100000]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%d",&A[i].a,&A[i].b);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		book[temp]=1;
	}
	for(int i=0;i<n;i++){
		if(book[A[i].a]&&book[A[i].b]){
			book[A[i].a]=book[A[i].b]=0;
			m-=2;
		}
	}
	printf("%d\n",m);
	for(int i=0;i<100000;i++){
		if(!m) break;
		if(book[i]){
			printf("%05d",i);
			m--;
			if(m) printf(" ");
		}
	}
	
	
}
