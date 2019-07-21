#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define INF 0x3fffffff
using namespace std;
struct node{
    int u;
    int w;
    node(int _u,int _w){u=_u;w=_w;}
};

vector<int> peo;
vector<node> road[520];
int rroad[520][520];
vector<int> d;//min distance;
vector<int> num;
vector<bool> visited;
vector<int> w;
int n,m,c1,c2;

void dijkstra2(int start){
    for(int i=0;i<n;i++){
        d[i]=INF;
        visited[i]=false;
        num[i]=0;
        w[i]=0;
    }
    d[start]=0;
    w[start]=peo[start];
    num[start]=1;
    for(int i=0;i<n;i++){
        int v=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(visited[j]==false&&d[j]<MIN){
                v=j;MIN=d[j];
            }
        }
        if(v==-1) return;
        visited[v]=true;
        for(int u=0;u<n;u++){
            //v-u
            if(rroad[v][u]!=INF&&visited[u]==false){
                if(d[u]>d[v]+rroad[v][u]){
                    d[u]=d[v]+rroad[v][u];
                    num[u]=num[v];
                    w[u]=w[v]+peo[u];
                }else if(d[u]==d[v]+rroad[v][u]){
                    num[u]+=num[v];
                    if(w[v]+peo[u]>w[u]){
                        w[u]=w[v]+peo[u];
                    }
                }
            }
        }
    }


}
void dijkstra(int start){
    for(int i=0;i<n;i++){
        d[i]=INF;
//        pre[i]=i;
        visited[i]=false;
        num[i]=0;
        w[i]=0;
    }
    d[start]=0;
    w[start]=peo[start];
    num[start]=1;
    for(int i=0;i<n;i++){
        int v=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(visited[j]==false&&d[j]<MIN){
                v=j;
                MIN=d[j];
            }
        }// find min v;
        if(v==-1) return;//没有最小的了。
        visited[v]=true;
        // s-v-u  s-u
        for(int j=0;j<road[v].size();j++){
            int u=road[v][j].u;
            if(visited[u]==false){
                if(d[v]+road[v][j].w<d[u]){
                    d[u]=d[v]+road[v][j].w;
                    num[u]=num[v];
                    w[u]=w[v]+peo[u];
                }else if(d[v]+road[v][j].w==d[u]){
                    if(w[v]+peo[u]>w[u]){
                        w[u]=w[v]+peo[u];
                    }
                    num[u]+=num[v];
                }
            }
        }

    }

}

int main(){
//    freopen("1.txt","r",stdin);

    scanf("%d%d%d%d",&n,&m,&c1,&c2);

    peo.resize(n);
    d.resize(n);
    visited.resize(n);
    num.resize(n);
    w.resize(n);
    fill(rroad[0],rroad[0]+520*520,INF);

    for(int i=0;i<n;i++){
        scanf("%d",&peo[i]);
    }

    int v,u,wei;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&v,&u,&wei);
        rroad[v][u]=rroad[u][v]=wei;
        road[v].push_back(node(u,wei));
        road[u].push_back(node(v,wei));
    }
    dijkstra2(c1);

    printf("%d %d",num[c2],w[c2]);


}
