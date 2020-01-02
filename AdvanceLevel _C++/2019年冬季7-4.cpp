#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;
int in[40];

struct node{
    int data;
    node *left,*right;
};

node * create(int lnum,int rnum){
    if(lnum>rnum) return NULL;

    int k=lnum,MIN=INF;
    for(int i=lnum;i<=rnum;i++){
        if(in[i]<MIN){
            k=i;MIN=in[i];
        }
    }
    node *root=new node();
    root->data=in[k];
    root->left=create(lnum,k-1);
    root->right=create(k+1,rnum);
    return root;
}

int main()
{
//    freopen("1.txt","r",stdin);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>in[i];
    }
    node * root=create(1,n);

    vector<int> res;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *f=q.front();
        q.pop();
        res.push_back(f->data);
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i!=res.size()-1) cout<<" ";
    }

    return 0;
}
