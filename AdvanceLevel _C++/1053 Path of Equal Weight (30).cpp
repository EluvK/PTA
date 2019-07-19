#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
	vector<int> childnum;
}tree[100];

vector<int> arr;
vector<int> res[100];
vector<int> temp;
int n,m,s;
int in=0;

void DFS(int num,int sum){
	
	sum+=arr[num];
	temp.push_back(arr[num]);
	if(sum==s&&tree[num].childnum.size()==0){
		res[in++]=temp;
	}
	
	for(int i=0;i<tree[num].childnum.size();i++){
		if(sum+arr[tree[num].childnum[i]]<=s){
			DFS(tree[num].childnum[i],sum);
		}
	}
	temp.pop_back();
}

bool cmp(int a,int b){
	return arr[a]>arr[b];
}

int main(){
//	freopen("1.txt","r",stdin);
	
	scanf("%d%d%d",&n,&m,&s);
	arr.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int temp,num,temp2;
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		tree[temp].childnum.clear();
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&temp2);
			tree[temp].childnum.push_back(temp2);
		}
		sort(tree[temp].childnum.begin(),tree[temp].childnum.end(),cmp);
	}
	
	DFS(0,0);
	
	for(int i=0;i<in;i++){
		for(int j=0;j<res[i].size();j++){
			printf("%d%c",res[i][j],j==res[i].size()-1?'\n':' ');
		}
	}	
	
} 
