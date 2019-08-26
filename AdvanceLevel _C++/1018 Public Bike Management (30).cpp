#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;

int c,m,n,sp;
vector<int> amt,pre[520];
int g[520][520];
int d[520];
bool vis[520];
void dijkstra(){
    d[0]=0;
    for(int i=0;i<n+1;i++){
        int u=-1,dis=INF;
        for(int j=0;j<n+1;j++){
            if(vis[j]==false&&d[j]<dis){
                u=j;dis=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<520;j++){
            if(g[u][j]<INF&&vis[j]==false){
                if(g[u][j]+d[u]<d[j]){
                    d[j]=g[u][j]+d[u];
                    pre[j].clear();
                    pre[j].push_back(u);
                }else if(d[j]==g[u][j]+d[u]){
                    pre[j].push_back(u);
                }
            }
        }
    }
}

vector<int> psb[1000];
vector<int> temp;
int ind=0;
void dfs(int s,int e){
    if(s==e){
        psb[ind++]=temp;
        return;
    }
    for(int i=0;i<pre[e].size();i++){
        temp.push_back(pre[e][i]);
        dfs(s,pre[e][i]);
        temp.pop_back();
    }
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d%d%d",&c,&n,&sp,&m);
    amt.resize(n+1);
    fill(g[0],g[0]+520*520,INF);
    fill(d,d+520,INF);
    fill(vis,vis+520,false);
    int s,e,dis;
    for(int i=1;i<=n;i++) scanf("%d",&amt[i]);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&s,&e,&dis);
        g[s][e]=min(g[s][e],dis);
        g[e][s]=g[s][e];
    }
    dijkstra();
    temp.push_back(sp);
    dfs(0,sp);
    int resn=INF,resi=0,resb;
    for(int i=0;i<ind;i++){
        reverse(psb[i].begin(),psb[i].end());
        int x=0,to=0;
        for(int j=1;j<psb[i].size();j++){
            int nxt=psb[i][j];
            x=x+amt[nxt]-c/2;
            if(x<0){
                to=to-x;
                x=0;
            }
        }
        if(to<resn||(to==resn&&x<resb)){
            resi=i;
            resn=to;
            resb=x;
        }
    }
    printf("%d 0",resn);
    for(int i=1;i<psb[resi].size();i++) printf("->%d",psb[resi][i]);
    printf(" %d",resb);
    return 0;
}
