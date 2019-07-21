#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define INF 0x3fffffff
using namespace std;

struct node{
    int v;
    int dis;
    int cost;
    node(int _v,int _dis,int _cost){v=_v;dis=_dis;cost=_cost;}
};
vector<int> d;
vector<int> cst;
vector<node> p[500];
vector<bool> vis;
vector<int> pre;

int N,M,S,D;

void dijkstra(int start){
    fill(d.begin(),d.end(),INF);
    fill(cst.begin(),cst.end(),INF);
    fill(vis.begin(),vis.end(),false);
    for(int i=0;i<N;i++){
        pre[i]=i;
    }
    d[start]=0;
    cst[start]=0;
    for(int i=0;i<N;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<N;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;

        for(int j=0;j<p[u].size();j++){
            int v=p[u][j].v;
            if(vis[v]==false){
               if(d[u]+p[u][j].dis<d[v]){
                    d[v]=d[u]+p[u][j].dis;
                    cst[v]=cst[u]+p[u][j].cost;
                    pre[v]=u;
                }else if(d[u]+p[u][j].dis==d[v]){
                    if(cst[v]>cst[u]+p[u][j].cost){
                        cst[v]=cst[u]+p[u][j].cost;
                        pre[v]=u;
                    }
                }
            }
        }
    }
}


int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d%d%d",&N,&M,&S,&D);
    d.resize(N);
    cst.resize(N);
    vis.resize(N);
    pre.resize(N);
    int a,b,dist,c;
    for(int i=0;i<M;i++){
        scanf("%d%d%d%d",&a,&b,&dist,&c);
        p[a].push_back(node(b,dist,c));
        p[b].push_back(node(a,dist,c));
    }
    dijkstra(S);

    vector<int> res;
    int temp=D;
    while(temp!=S){
        res.push_back(temp);
        temp=pre[temp];
    }
    printf("%d",S);
    for(int i=res.size()-1;i>=0;i--){
        printf(" %d",res[i]);
    }
    printf(" %d %d",d[D],cst[D]);

    return 0;
}


