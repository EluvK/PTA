#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#define INF 0x3fffffff
#define MAX 502
using namespace std;

int n,m;
vector<int> edge[MAX];
int distmap[MAX][MAX];
int timemap[MAX][MAX];

//res:
int mindist,mintime;
vector<int> resDistRoute,resTimeRoute;

struct Vertex{
    int x,dist;
    bool operator <(const Vertex &v) const{
        return dist>v.dist;
    }
};
void buildEdge(int st,int ed,int length,int time){
    edge[st].push_back(ed);
    distmap[st][ed]=length;
    timemap[st][ed]=time;
}

void dijkstra1(int st,int ed){
    vector<bool> vis(n,false);
    vector<int> dist(n,INF),time(n,INF);
    vector<vector<int> > route(n);
    priority_queue<Vertex> pq;
    dist[st]=time[st]=0;
    pq.push(Vertex{st,0});
    while(!pq.empty()){
        int f=pq.top().x;
        pq.pop();

        if(vis[f]) continue;
        vis[f]=true;
        route[f].push_back(f);
        if(f==ed) break;
        for(int i=0;i<edge[f].size();i++){
            int to=edge[f][i];
            if(vis[to]) continue;
            if(dist[to]>dist[f]+distmap[f][to]||
            (dist[to]==dist[f]+distmap[f][to]&&time[to]>time[f]+timemap[f][to])){
                dist[to]=dist[f]+distmap[f][to];
                time[to]=time[f]+timemap[f][to];
                route[to]=route[f];
                pq.push(Vertex{to,dist[to]});
            }
        }
    }
    resDistRoute=route[ed];
    mindist=dist[ed];
}

void dijkstra2(int st,int ed){
    vector<bool> vis(n,false);
    vector<int> time(n,INF);
    vector<vector<int> > route(n);
    priority_queue<Vertex> pq;
    time[st]=0;
    pq.push(Vertex{st,0});
    while(!pq.empty()){
        int f=pq.top().x;
        pq.pop();
        if(vis[f]) continue;
        vis[f]=true;
        route[f].push_back(f);
        if(f==ed) break;
        for(int i=0;i<edge[f].size();i++){
            int to=edge[f][i];
            if(vis[to]) continue;
            if(time[to]>time[f]+timemap[f][to]||
               (time[to]==time[f]+timemap[f][to]&&route[to].size()>route[f].size())
               ){
                time[to]=time[f]+timemap[f][to];
                route[to]=route[f];
                pq.push(Vertex{to,time[to]});
               }
        }
    }
    mintime=time[ed];
    resTimeRoute=route[ed];
}
void ppath(vector<int> path){
    for(int i=0;i<path.size();i++)
        printf(" %d%s",path[i],i==path.size()-1?"\n":" ->");
}
int main(){
//    freopen("1.txt","r",stdin);

    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int v1,v2,o,l,t;
        scanf("%d%d%d%d%d",&v1,&v2,&o,&l,&t);
        buildEdge(v1,v2,l,t);
        if(o==0) buildEdge(v2,v1,l,t);
    }
    int s,e;
    scanf("%d%d",&s,&e);
    dijkstra1(s,e);
    dijkstra2(s,e);
    if(resDistRoute==resTimeRoute){
        printf("Distance = %d; Time = %d:",mindist,mintime);
        ppath(resDistRoute);
    }else{
        printf("Distance = %d:",mindist);
        ppath(resDistRoute);
        printf("Time = %d:",mintime);
        ppath(resTimeRoute);
    }
    return 0;
}
