#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
struct AVLTree{
	int key;
	struct AVLTree *left;
	struct AVLTree *right;
};

int avltree_height(AVLTree *tree);
AVLTree* avltree_search(AVLTree *x,int key);
AVLTree* avltree_insert(AVLTree *tree,int key);
AVLTree* leftrotation(AVLTree *k2);
AVLTree* rightrotation(AVLTree *k1);
AVLTree* lrrotation(AVLTree *k3);
AVLTree* rlrotation(AVLTree *k1);

int avltree_height(AVLTree *tree){
	if(tree==NULL){
		return 0;
	}
	int l=avltree_height(tree->left);
	int r=avltree_height(tree->right);
	return max(l,r)+1;
}

AVLTree * avltree_search(AVLTree *x,int key){
	if(x==NULL||x->key==key) return x;
	if(key<x->key) return avltree_search(x->left,key);
	else return avltree_search(x->right,key);
}

AVLTree* avltree_insert(AVLTree *tree,int key){
	if(tree==NULL){
		tree=new AVLTree();
		tree->key=key;
	}else if(tree->key>key){
		tree->left=avltree_insert(tree->left,key);
		int l=avltree_height(tree->left),r=avltree_height(tree->right);
		if(l-r>=2){
			if(key<tree->left->key)
				tree=rightrotation(tree);
			else
				tree=lrrotation(tree);
		}
	}else{
		tree->right=avltree_insert(tree->right,key);
		int l=avltree_height(tree->left),r=avltree_height(tree->right);
		if(r-l>=2){
			if(key>tree->right->key)
				tree=leftrotation(tree);
			else
				tree=rlrotation(tree);
		}
	}
	return tree;
}

AVLTree* rightrotation(AVLTree *tree){
	AVLTree *temp=tree->left;
	tree->left=temp->right;
	temp->right=tree;
	return temp;
}
AVLTree* leftrotation(AVLTree *tree){
	AVLTree *temp=tree->right;
	tree->right=temp->left;
	temp->left=tree;
	return temp;
}
AVLTree* rlrotation(AVLTree *tree){
	tree->right=rightrotation(tree->right);
	return leftrotation(tree);
}
AVLTree* lrrotation(AVLTree *tree){
	tree->left=leftrotation(tree->left);
	return rightrotation(tree);
}

int after=0,comp=1;
vector<int> layerorder(AVLTree *tree){
	vector<int> res;
	queue<AVLTree*> q;
	q.push(tree);
	while(!q.empty()){
		AVLTree* now=q.front();
		q.pop();
		res.push_back(now->key);
		if(now->left!=NULL){
			q.push(now->left);
			if(after) comp=0;
		}else{
			after=1;
		}
		if(now->right!=NULL){
			q.push(now->right);
			if(after) comp=0;
		}else{
			after=1;
		}
	}
	return res;
}

int main(){
//	freopen("1.txt","r",stdin);
	int n,temp;
	scanf("%d",&n);
	AVLTree *tree=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		tree=avltree_insert(tree,temp);
	}
	vector<int> q=layerorder(tree);
	for(int i=0;i<q.size();i++){
		printf("%d%c",q[i],i==q.size()-1?'\n':' ');
	}
	if(comp) printf("YES");
	else printf("NO");
}
