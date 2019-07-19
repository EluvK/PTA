#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct info{
	int adress;
	int data;
	int next;
}A[100010];

int main(){
//	freopen("1.txt","r",stdin);
	int n,first,k;
	scanf("%d%d%d",&first,&n,&k);
	int book[100010]={0};
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&A[i].adress,&A[i].data,&A[i].next);
		book[A[i].adress]=i;
	}
	vector<info> res1;
	vector<info> res2;
	vector<info> res3;
	info temp;
	while(first!=-1){
		temp.adress=first;
		temp.data=A[book[first]].data;
		if(temp.data<0){
			res1.push_back(temp);
		}else if(temp.data<=k){
			res2.push_back(temp);
		}else{
			res3.push_back(temp);
		}
		first=A[book[first]].next;
	}
	
	
	for(int i=0;i<res2.size();i++){
		temp.adress=res2[i].adress;
		temp.data=res2[i].data;
		res1.push_back(temp);
	}
	for(int i=0;i<res3.size();i++){
		temp.adress=res3[i].adress;
		temp.data=res3[i].data;
		res1.push_back(temp);
	}

	printf("%05d %d ",res1[0].adress,res1[0].data);
	for(int i=1;i<res1.size();i++){
		printf("%05d\n%05d %d ",res1[i].adress,res1[i].adress,res1[i].data);
	}
	printf("-1"); 
	return 0;
}
