#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<string> 
#include<algorithm>

#define MAX 26*26*26*10
using namespace std;

struct student{
	char name[5];
	vector<int> course;
}A[40010];

int char2num(char c[]){
	int sum=0;
	for(int i=0;i<3;i++){
		sum=sum*26+c[i]-'A';
	}
	sum=sum*10+c[3]-'0';
	return sum;
} 

vector<int> student[MAX];

int main(){
	
//	freopen("1.txt","r",stdin);
	int N,K;
	scanf("%d%d",&N,&K);
	char name[5];
	int id;
	for(int i=0;i<K;i++){
		int cnum,n;
		scanf("%d%d",&cnum,&n);
		for(int j=0;j<n;j++){
			scanf("%s",name);
			id=char2num(name);
			student[id].push_back(cnum);
		}
	}

	for(int i=0;i<N;i++){
		scanf("%s",name);
		id=char2num(name);
		sort(student[id].begin(),student[id].end());
		printf("%s %d",name,student[id].size());
		if(student[id].size()!=0){
			for(int j=0;j<student[id].size();j++){
				printf(" %d",student[id][j]);
			}
		} 
		printf("\n");
	}
	return 0; 
} 
