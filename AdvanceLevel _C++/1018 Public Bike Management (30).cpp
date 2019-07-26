#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

int c,n,sp,m;
int d[520],g[520][520],in=0,ansi,ansout=INF,ansback=INF,tout,tback;
vector<int> oribike,pre[520],temp,res[100000];
bool vis[520];

void dijkstra(int start){
    d[start]=0;
    for(int i=0;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<=n;j++){
            if(d[j]<MIN&&vis[j]==false){
                u=j;MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int j=0;j<=n;j++){
            if(vis[j]==false&&g[u][j]<INF){
                if(d[u]+g[u][j]<d[j]){
                    d[j]=d[u]+g[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }else if(d[u]+g[u][j]==d[j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
}

void dfs(int s,int e){
    if(s==e){
        temp.push_back(s);
        res[in]=temp;
        reverse(res[in].begin(),res[in].end());
        in++;
        temp.pop_back();
        return;
    }
    for(int i=0;i<pre[s].size();i++){
        temp.push_back(s);
        dfs(pre[s][i],e);
        temp.pop_back();
    }
    return;
}

void calbike(int n){
    int num;
    int x=0,y=0;
    for(int i=1;i<res[n].size();i++){
        num=res[n][i];
        x=x+oribike[num]-c/2;
        if(x<0){
            y=y-x;
            x=0;
        }
    }
    tout=y;tback=x;
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d%d%d",&c,&n,&sp,&m);
    oribike.resize(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&oribike[i]);
    fill(d,d+520,INF);
    fill(g[0],g[0]+520*520,INF);
    int a,b,dis;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&dis);
        g[a][b]=g[b][a]=min(g[a][b],dis);
    }
    dijkstra(0);
    dfs(sp,0);

    for(int i=0;i<in;i++){
        calbike(i);
        if(tout<ansout){
            ansi=i;ansout=tout;ansback=tback;
        }else if(tout==ansout&&tback<ansback){
            ansi=i;ansback=tback;
        }
    }
    printf("%d ",ansout);
    for(int i=0;i<res[ansi].size();i++){
        printf("%d",res[ansi][i]);
        if(i!=res[ansi].size()-1) printf("->");
    }
    printf(" %d",ansback);
}
