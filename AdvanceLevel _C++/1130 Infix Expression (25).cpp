#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

struct node{
    string str;
    int left,right;
}A[40];

int n;

string dfs(int root){
    if(A[root].left==-1&&A[root].right==-1) return A[root].str;
    if(A[root].left==-1&&A[root].right!=-1) return "("+A[root].str+dfs(A[root].right)+")";
    if(A[root].left!=-1&&A[root].right!=-1) return "("+dfs(A[root].left)+A[root].str+dfs(A[root].right)+")";
}
int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    vector<bool> vis;
    vis.resize(n+1);
    fill(vis.begin(),vis.end(),false);
    for(int i=1;i<=n;i++){
        cin>>A[i].str;
        scanf("%d%d",&A[i].left,&A[i].right);
        if(A[i].left!=-1) vis[A[i].left]=true;
        if(A[i].right!=-1) vis[A[i].right]=true;
    }
    int rootnum;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            rootnum=i;break;
        }
    }
    string res=dfs(rootnum);
    if(res[0]=='(') res=res.substr(1,res.size()-2);
    cout<<res;
    return 0;
}
