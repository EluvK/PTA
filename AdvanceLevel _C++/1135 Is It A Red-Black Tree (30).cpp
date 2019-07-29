#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

int cse,num;
int arr[40];

node * create(node *root ,int n){
    if(root==NULL){
        root=new node();
        root->data=n;
        root->left=root->right=NULL;
    }else if(abs(n)<abs(root->data)) root->left=create(root->left,n);
    else root->right=create(root->right,n);

    return root;
}

bool check2(node *root){
    if(root->data<0) return false;
    else return true;
}

bool check4(node *root){
    if(root==NULL) return true;
    if(root->data<0){
        if(root->left!=NULL&&root->left->data<0) return false;
        if(root->right!=NULL&&root->right->data<0) return false;
    }
    return check4(root->left)&&check4(root->right);
}

int getblacknum(node *root){
    if(root==NULL) return 0;
    int l=getblacknum(root->left);
    int r=getblacknum(root->right);
    return root->data>0?max(l,r)+1:max(l,r);
}

bool check5(node *root){
    if(root==NULL) return true;
    int l=getblacknum(root->left);
    int r=getblacknum(root->right);
    if(l!=r) return false;
    return check5(root->left)&&check5(root->right);
}

bool checkall(node *root){
    if(check2(root)&&check4(root)&&check5(root))
        return true;
    else return false;
}

int main(){
//    freopen("1.txt","r",stdin);

    scanf("%d",&cse);
    for(int q=0;q<cse;q++){
        scanf("%d",&num);
        node *root=NULL;
        for(int i=0;i<num;i++){
            scanf("%d",&arr[i]);
            root=create(root,arr[i]);
        }
        if(checkall(root)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
