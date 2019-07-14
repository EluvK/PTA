#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct info{
	char name[20];
	char id[20];
	int grade;
}A[1010]; 

bool cmp(info a,info b){
	return a.grade>b.grade;
}

int main(){
//	freopen("1.txt","r",stdin);
	int n,min,max,cnt=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%s%d",A[i].name,A[i].id,&A[i].grade);
	}
	scanf("%d%d",&min,&max);
	sort(A,A+n,cmp);
	for(int i=0;i<n;i++){
		if(A[i].grade<=max&&A[i].grade>=min){
			printf("%s %s\n",A[i].name,A[i].id);
			cnt++;
		}
	}
	if(!cnt) printf("NONE");
	return 0;
	
} 
