#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>

#include <iostream>
using namespace std;



struct node{
    int data;
//    int level;
    node* left;
    node* right;
};

void preorder(node* root){//前序遍历 
	if(root==NULL){
		return;//空树 
	}
	printf("%d ",root->data);//当前节点；
	preorder(root->left);
	preorder(root->right); 
}

void inorder(node* root){//中序遍历
	if(root==NULL){
		return;
	} 
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void postorder(node *root){//后序遍历 
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

void layerorder(node *root){//层次遍历 
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		printf("%d ",now->data); 
		if(now->left!=NULL) q.push(now->left);
		if(now->right!=NULL) q.push(now->right);
	}
}

//先序和中序构建二叉树
//先序区间[preL,preR],中序区间[inL,inR],逐步返回根节点地址
node* create(int preL,int preR,int inL,int inR,int pre[],int in[]){
	
	if(preL>preR) return NULL;
	
	node* root =new node;//新节点放当前地址
	root->data=pre[preL];//前序的第一个为根节点
	
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL]){
			break;//在中序中找到in[k]==pre[L] 
		}
	} 
	int numLeft=k-inL;//中序分为左右子树，左子树的个数 
	//左子树在先序中[preL+1,preL+numLeft] 中序中，[inL,k-1] 
	//右子树在先序中[preL+numLeft+1,preR] 中序中，[k+1,inR] 
	
	root->left=create(preL+1,preL+numLeft,inL,k-1,pre,in);
	root->right=create(preL+numLeft+1,preR,k+1,inR,pre,in);
	
	return root; 
} 

//中序和后序建立二叉树
//中序区间[inL,inR],后序区间[postL,postR],逐步返回根节点地址
node* create2(int inL,int inR,int postL,int postR,int in[],int post[]){
	if(postL>postR) return NULL;
	
	node* root=new node;
	root->data=post[postR];
	
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==post[postR]){
			break;
		}
	}
	
	int numLeft=k-inL;
	
	//左子树：[postL,postL+numLeft-1] [inL,k-1] 
	//右子树：[postL+numLeft,postR-1] [k+1,inR]
	
	root->left=create2(inL,k-1,postL,postL+numLeft-1,in,post);
	root->right=create2(k+1,inR,postL+numLeft,postR-1,in,post);
	
	return root;
} 


//void BinaryTreeFromOrderings(int *inorder,int *lastorder,int length)//中序序列，先序序列，中序中需要寻找的字段长度
//{
//    if(length==0) return;
//    node* node=new node;
//    node->data=lastorder+length-1;
//    int rootindex;
//    for(rootindex=0;rootindex<length;rootindex++)
//        if(inorder[rootindex]==node->data)
//            break;
//    cout<<node->data<<" ";
//    BinaryTreeFromOrderings(inorder,lastorder,rootindex);
//    BinaryTreeFromOrderings(inorder+rootindex+1,lastorder+rootindex,length-(rootindex+1));
//}


int main(){
	
//	int in[7]={1,2,3,4,5,6,7};
//	int post[7]={2,3,1,5,7,6,4};
//	node* root=new node;
//	root=create2(0,6,0,6,in,post);
//	preorder(root);
//	printf("\n");
//	inorder(root);
//	printf("\n");
//	postorder(root);
//	printf("\n");
//	layerorder(root); 
//
	int N;
	int in[50];
	int post[50];
	scanf("%d",&N);
	for(int i=0;i<N;i++){scanf("%d",&post[i]);} 
	for(int i=0;i<N;i++){scanf("%d",&in[i]);} 
	node* root=new node;
	root=create2(0,N-1,0,N-1,in,post);
//	layerorder(root);
	
	queue<node*> q;
	q.push(root);
	node* now=q.front();
	q.pop();
	printf("%d",now->data); 
	if(now->left!=NULL) q.push(now->left);
	if(now->right!=NULL) q.push(now->right);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		printf(" %d",now->data); 
		if(now->left!=NULL) q.push(now->left);
		if(now->right!=NULL) q.push(now->right);
	}
	return 0;
} 
