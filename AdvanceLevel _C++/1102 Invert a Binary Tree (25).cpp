#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#define MAX 0x7fffffff
using namespace std;

struct info{
	int num;
	int left;
	int right;
}N[15];

struct node{
	int data;
	node* left;
	node* right;
}no[15];


int loder[30];
int ioder[30];
int io=0;
int levelorder(node *root){
	int in=0;
	queue<node*> q;
	q.push(root);
	int num=0;
	while(!q.empty()){
		node *now=q.front();
		loder[in++]=now->data;
		q.pop();
		num++;
		if(now->left!=NULL) q.push(now->left);
		if(now->right!=NULL) q.push(now->right);
	}
	return num;
}
void inorder(node *root){
	if(root==NULL) return;
	inorder(root->left);
	ioder[io++]=root->data;
	inorder(root->right);
}

int main(){
//	freopen("1.txt", "r", stdin);
	int n;
	char a,b;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		getchar();
		scanf("%c %c",&a,&b);
		N[i].num=i;
		if(a!='-') N[i].right=a-'0';
		else N[i].right=-1;
		if(b!='-') N[i].left=b-'0';
		else N[i].left=-1;
	}
	for(int i=0;i<n;i++){
		no[i].data=N[i].num;
		if(N[i].left!=-1) no[i].left=&(no[N[i].left]);
		else no[i].left=NULL;
		if(N[i].right!=-1) no[i].right=&(no[N[i].right]); 
		else no[i].right=NULL;
	}
	
	int root;
	for(root=0;root<n;root++){
		if(levelorder(&(no[root]))==n) break;
	}
//	printf("%d",root);

	inorder(&no[root]);
	for(int i=0;i<n;i++){
		printf("%d%c",loder[i],i==n-1?'\n':' ');
	}
	for(int i=0;i<n;i++){
		printf("%d%c",ioder[i],i==n-1?'\n':' ');
	}
	return 0;
}

