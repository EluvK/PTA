#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
int in[40],post[40];
struct node{
    int data,level;
    node *left;
    node *right;
};
struct resnode{
    int data,level;
    resnode(int d,int l){data=d;level=l;}
};
vector<resnode> res;

node * create(int inL,int inR,int postL,int postR){

    if(postL>postR) return NULL;

    node *root =new node;
    root->data=post[postR];
    int i;
    for(i=inL;i<=inR;i++){
        if(in[i]==post[postR]) break;
    }
//    int leftnum=i-inL,rightnum=inR-i;
    root->left=create(inL,i-1,postL,postL+i-inL-1);
    root->right=create(i+1,inR,postL+i-inL,postR-1);
    return root;

}

void levelorder(node *root){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node * now=q.front();
        q.pop();
        res.push_back(resnode(now->data,now->level));
        if(now->left!=NULL) q.push(now->left);
        if(now->right!=NULL) q.push(now->right);
    }
}

void taglevel(node *root,int l){
    if(root==NULL) return;
    root->level=l;
    if(root->left!=NULL) taglevel(root->left,l+1);
    if(root->right!=NULL) taglevel(root->right,l+1);
    return;
}
int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    for(int i=0;i<n;i++) scanf("%d",&post[i]);
    node *root=new node;
    root=create(0,n-1,0,n-1);
    taglevel(root,1);
    levelorder(root);
    vector<int> levels;
    levels.push_back(0);
    for(int i=1;i<res.size();i++){
        if(res[i].level!=res[i-1].level) levels.push_back(i);
    }
    levels.push_back(res.size());
    for(int i=0;i<levels.size()-1;i=i+2){
        reverse(res.begin()+levels[i],res.begin()+levels[i+1]);
    }
    for(int i=0;i<res.size();i++){
        printf("%d",res[i].data);
        if(i!=res.size()-1) printf(" ");
    }
    return 0;
}
