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

void preorder(node* root){//ǰ����� 
	if(root==NULL){
		return;//���� 
	}
	printf("%d ",root->data);//��ǰ�ڵ㣻
	preorder(root->left);
	preorder(root->right); 
}

void inorder(node* root){//�������
	if(root==NULL){
		return;
	} 
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void postorder(node *root){//������� 
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

void layerorder(node *root){//��α��� 
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

//��������򹹽�������
//��������[preL,preR],��������[inL,inR],�𲽷��ظ��ڵ��ַ
node* create(int preL,int preR,int inL,int inR,int pre[],int in[]){
	
	if(preL>preR) return NULL;
	
	node* root =new node;//�½ڵ�ŵ�ǰ��ַ
	root->data=pre[preL];//ǰ��ĵ�һ��Ϊ���ڵ�
	
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL]){
			break;//���������ҵ�in[k]==pre[L] 
		}
	} 
	int numLeft=k-inL;//�����Ϊ�����������������ĸ��� 
	//��������������[preL+1,preL+numLeft] �����У�[inL,k-1] 
	//��������������[preL+numLeft+1,preR] �����У�[k+1,inR] 
	
	root->left=create(preL+1,preL+numLeft,inL,k-1,pre,in);
	root->right=create(preL+numLeft+1,preR,k+1,inR,pre,in);
	
	return root; 
} 

//����ͺ�����������
//��������[inL,inR],��������[postL,postR],�𲽷��ظ��ڵ��ַ
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
	
	//��������[postL,postL+numLeft-1] [inL,k-1] 
	//��������[postL+numLeft,postR-1] [k+1,inR]
	
	root->left=create2(inL,k-1,postL,postL+numLeft-1,in,post);
	root->right=create2(k+1,inR,postL+numLeft,postR-1,in,post);
	
	return root;
} 


//void BinaryTreeFromOrderings(int *inorder,int *lastorder,int length)//�������У��������У���������ҪѰ�ҵ��ֶγ���
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
