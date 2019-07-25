#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#define INF 0x3fffffff
using namespace std;

struct node{
    int ind,left,right;
}tree[200];

int ino[200];
int in=0;
void inorder(int root){
    if(root==-1) return;
    inorder(tree[root].left);
    ino[in++]=tree[root].ind;
    inorder(tree[root].right);
}
int levelo[200];
int le=0;
void levelorder(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        levelo[le++]=tree[now].ind;
        if(tree[now].left!=-1) q.push(tree[now].left);
        if(tree[now].right!=-1) q.push(tree[now].right);
    }
}
int main(){
//    freopen("1.txt","r",stdin);

    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        tree[i].ind=i;
        scanf("%d%d",&tree[i].left,&tree[i].right);
    }
    inorder(0);
    int data[200];
    for(int i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    sort(data,data+n);
    int book[200];
    for(int i=0;i<n;i++){
        book[ino[i]]=data[i];
    }
    levelorder(0);
    for(int i=0;i<n;i++){
        printf("%d",book[levelo[i]]);
        if(i!=n-1) printf(" ");
    }
}
