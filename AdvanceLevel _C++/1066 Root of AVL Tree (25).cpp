#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    int data;
    node *left;
    node *right;
};

int getHeight(node* root){
    if(root==NULL)
        return 0;
    else return max(getHeight(root->left),getHeight(root->right))+1;
}
node *newNode(int x){
    node *temp=new node;
    temp->data=x;
    temp->left=temp->right=NULL;
    return temp;
}

node* r_rotation(node *root);
node* l_rotation(node *root);
node* rl_rotation(node *root);
node* lr_rotation(node *root);

node* r_rotation(node *root){
    node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    return temp;
}
node* l_rotation(node *root){
    node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    return temp;
}
node* rl_rotation(node *root){
    root->right=r_rotation(root->right);
    return l_rotation(root);
}
node* lr_rotation(node *root){
    root->left=l_rotation(root->left);
    return r_rotation(root);
}
node* AVL_insert(node *&root, int x){
    if(root==NULL){
        root=newNode(x);
    }else if(root->data>x){
        root->left=AVL_insert(root->left,x);
        int l=getHeight(root->left),r=getHeight(root->right);
        if(l-r>=2){
            if(root->left->data>x) root=r_rotation(root);
            else root=lr_rotation(root);
        }
    }
    else{
        root->right=AVL_insert(root->right,x);
        int l=getHeight(root->left),r=getHeight(root->right);
        if(r-l>=2){
            if(root->right->data<x) root=l_rotation(root);
            else root=rl_rotation(root);
        }
    }
    return root;
}

int main(){
//    freopen("1.txt","r",stdin);
    int n,temp;
    node *root=NULL;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        root=AVL_insert(root,temp);
    }
    printf("%d",root->data);
}
