#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<int> arr;
vector<int> res;
int ii=1;
struct node{
	int data;
	node* left;
	node* right; 
};

bool cmp(int a,int b){
	return a<b;
}

void inorder(int root){
	if(root>N) return;
	inorder(2*root);
	res[root]=arr[ii++];
	inorder(2*root+1);
	return;
}

int main(){	
	scanf("%d",&N);
	arr.resize(N+1);
	res.resize(N+1);
	for(int i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr.begin(),arr.end(),cmp);

	inorder(1);
	for(int i=1;i<=N;i++){
		printf("%d",res[i]);
		if(i!=N) printf(" "); 
	}
	return 0;
}
