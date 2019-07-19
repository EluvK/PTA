#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> pre;
vector<int> in; 


//ori todo
struct node{
	int data;
	node *left;
	node *right;
};

node * create(int preL,int preR,int inL,int inR){	
	if(inL>inR) return NULL;
	
	node *root =new node;
	root->data=pre[preL];
	int k=inL;
	while(in[k]!=pre[preL]) k++;
	int num=k-inL;
	root->left=create(preL+1,preL+num,inL,k-1);
	root->right=create(preL+num+1,preR,k+1,inR); 
	
}


//act todo
bool flag=false;
void postorder(int preL,int preR,int inL,int inR){
	if(inL>inR||flag) return;
	
	int k=inL;
	while(in[k]!=pre[preL]) k++;
	postorder(preL+1,preL+k-inL,inL,k-1);
	postorder(preL+k-inL+1,preR,k+1,inR);
	
	if(!flag){
		printf("%d",in[k]);
		flag=true;
	}
}

int main(){
//	freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	in.resize(n);
	pre.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	postorder(0,n-1,0,n-1);
	return 0;
}
