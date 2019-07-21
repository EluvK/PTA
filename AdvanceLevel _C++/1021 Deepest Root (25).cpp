#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define INF 0x3fffffff
using namespace std;

vector<int> node[10010];
vector<int> l;
vector<int> lm;
vector<bool> vis;
int lmax;
void bfs(int n,int level){
    queue<int> q;
    q.push(n);
    vis[n]=true;
    l[n]=1;
    lmax=1;
    while(!q.empty()){
        int head=q.front();
        q.pop();
        for(int i=0;i<node[head].size();i++){
            if(vis[node[head][i]]==false){
                vis[node[head][i]]=true;
                q.push(node[head][i]);
                l[node[head][i]]=l[head]+1;
                lmax=max(lmax,l[node[head][i]]);
            }
        }
    }
}

int main(){
//    freopen("1.txt","r",stdin);
    int n,a,b,num=0;
    scanf("%d",&n);
    l.resize(n+1);
    vis.resize(n+1);
    lm.resize(n+1);
    fill(vis.begin(),vis.end(),false);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&a,&b);
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            bfs(i,1);
            num++;
        }
    }
    if(num!=1){
        printf("Error: %d components",num);
    }else{
        for(int i=1;i<=n;i++){
            fill(vis.begin(),vis.end(),false);
            bfs(i,1);
            lm[i]=lmax;
        }
        int m=0;
        for(int i=1;i<=n;i++){
            if(lm[i]>m) m=lm[i];
        }
        for(int i=1;i<=n;i++){
            if(lm[i]==m) printf("%d\n",i);
        }
    }
    return 0;
}


