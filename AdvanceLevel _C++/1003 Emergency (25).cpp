#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#define INF 0x3fffffff
using namespace std;

int n,m,c1,c2;
vector<int> tm;
int g[520][520];
bool vis[520];
int d[520];
vector<int> pre[520];

void dijkstra(int s,int e){
    fill(d,d+520,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,dist=INF;
        for(int j=0;j<n;j++){
            if(d[j]<dist&&vis[j]==false){
                dist=d[j];
                u=j;
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<n;j++){
            if(g[u][j]<INF&&vis[j]==false){
                if(g[u][j]+d[u]<d[j]){
                    d[j]=g[u][j]+d[u];
                    pre[j].clear();
                    pre[j].push_back(u);
                }else if(g[u][j]+d[u]==d[j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
}

int mxw=0,cnt=0;
void dfs(int s,int e,int w){
    if(s==e){
        if(w+tm[s]>mxw) mxw=w+tm[s];
        cnt++;
        return;
    }
    for(int i=0;i<pre[e].size();i++)
        dfs(s,pre[e][i],w+tm[e]);
}
int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    tm.resize(n);
    for(int i=0;i<n;i++) scanf("%d",&tm[i]);
    int a,b,dis;
    fill(g[0],g[0]+520*520,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&dis);
        g[a][b]=min(g[a][b],dis);
        g[b][a]=g[a][b];
    }
    dijkstra(c1,c2);
    dfs(c1,c2,0);
    printf("%d %d",cnt,mxw);
    return 0;
}
