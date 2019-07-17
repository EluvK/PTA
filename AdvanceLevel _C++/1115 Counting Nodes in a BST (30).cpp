#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

struct node{
	int num;
	node *left;
	node *right;
};

node * create(node *root,int n){
	if(root==NULL){
		root=new node;
		root->num=n;
		root->right=NULL;
		root->left=NULL;
	}
	else if(root->num<n){
		root->right=create(root->right,n);
	}else{
		root->left=create(root->left,n);
	}
	return root;
}
int depth[1000]={0};
int maxd=-1;
void dfs(node *root,int dep){
	if(root==NULL){
		maxd=(maxd>dep)?maxd:dep;
		return;
	}
	depth[dep]++;
	dfs(root->left,dep+1);
	dfs(root->right,dep+1);
}

int main(){
//	freopen("1.txt","r",stdin);
	int n,temp;
	cin>>n;
	node *root=NULL; 
	for(int i=1;i<=n;i++){
		scanf("%d",&temp);
		root=create(root,temp);
	}
	dfs(root,0);
	printf("%d + %d = %d",depth[maxd-1],depth[maxd-2],depth[maxd-1]+depth[maxd-2]);
	
	
}

