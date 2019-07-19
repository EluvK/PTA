#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> inpt;
vector<int> pre;
vector<int> post;
struct node{
	int data;
	node* left;
	node* right;
};

void mirror(node *root){
    if(root==NULL) return;
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}

void preorder(node *root){
	if(root==NULL) return;
	pre.push_back(root->data);
	preorder(root->left);
	preorder(root->right);
}
bool judge(node *root){
    int i=0;
    bool flag=true;
    preorder(root);
    for(;i<inpt.size();i++){
        if(pre[i]!=inpt[i]){
            flag=false;
        }
    }
    if(flag) return true;
    mirror(root);
    pre.clear();
    preorder(root);
    flag=true;
    for(i=0;i<inpt.size();i++){
        if(pre[i]!=inpt[i]){
            flag=false;
        }
    }
    if(flag){
        return true;
    }
    return false;
}
node *newNode(int x){
	node* temp=new node;
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}
void insert(node *&root,int x){
	if(root==NULL){
		root=newNode(x);
		return;
	}
	else if(x<root->data){
		insert(root->left,x);
	}else{
		insert(root->right,x);
	}
}
void postorder(node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    post.push_back(root->data);
}
int main(){
//	freopen("1.txt","r",stdin);
	int n,temp,i;
	cin>>n;
	node *root=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		inpt.push_back(temp);
		insert(root,temp);
	}
	if(judge(root)){
		printf("YES\n");
		postorder(root);
		for(int i=0;i<n;i++){
            printf("%d%c",post[i],i==n-1?'\n':' ');
		}
	}
	else{
		printf("NO");
	}
}
