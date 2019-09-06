#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int v;
    node *left,*right;
};
int getHeight(node *root){
    if(root==NULL) return 0;
    int l=getHeight(root->left);
    int r=getHeight(root->right);
    return max(l,r)+1;
}
node * r_rotation(node *root){
    node *temp=root->left;
    root->left=temp->right;
    temp->right=root;
    return temp;
}
node * l_rotation(node *root){
    node *temp=root->right;
    root->right=temp->left;
    temp->left=root;
    return temp;
}
node * lr_rotation(node *root){
    root->left=l_rotation(root->left);
    return r_rotation(root);
}
node * rl_rotation(node *root){
    root->right=r_rotation(root->right);
    return l_rotation(root);
}
void AVL_insert(node *&root,int temp){
    if(root==NULL){
        root=new node();
        root->v=temp;
    }else if(root->v>temp){
        AVL_insert(root->left,temp);
        int l=getHeight(root->left),r=getHeight(root->right);
        if(l-r>=2){
            if(root->left->v>temp)
                root=r_rotation(root);
            else
                root=lr_rotation(root);
        }
    }else{
        AVL_insert(root->right,temp);
        int l=getHeight(root->left),r=getHeight(root->right);
        if(r-l>=2){
            if(root->right->v<temp)
                root=l_rotation(root);
            else
                root=rl_rotation(root);
        }
    }
}

int main(){
//    freopen("1.txt","r",stdin);
    int n,temp;
    scanf("%d",&n);
    node *root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        AVL_insert(root,temp);
    }
    vector<int> res;
    queue<node *> q;
    q.push(root);
    bool after=0,flag=1;
    while(!q.empty()){
        node * f=q.front();
        q.pop();
        res.push_back(f->v);
        if(f->left!=NULL){
            q.push(f->left);
            if(after) flag=false;
        }else after=true;
        if(f->right!=NULL){
            q.push(f->right);
            if(after) flag=false;
        }else after=true;
    }
    for(int i=0;i<res.size();i++){
        printf("%d%c",res[i],i==res.size()-1?'\n':' ');
    }
    printf("%s",flag?"YES":"NO");
}
