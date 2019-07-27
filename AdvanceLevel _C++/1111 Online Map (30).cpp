#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 0x3fffffff
using namespace std;

int n,m,a,b,oneway,templen,temptime;
int tm[520][520],dist[520][520];
int d[520],t[520];
bool vis[520];
vector<int> timepre[520],distpre[520];
vector<int> tempv,distres,timeres;
int mintime2dist=INF,mindist2time=INF;

void dfs1(int s,int e){
    if(s==e){
        int sum=0;
        tempv.push_back(s);
        for(int i=tempv.size()-1;i>0;i--){
            sum+=tm[tempv[i]][tempv[i-1]];
        }
        if(sum<mintime2dist){
            distres=tempv;
            mintime2dist=sum;
        }
        tempv.pop_back();
        return;
    }

    for(int i=0;i<distpre[s].size();i++){
        tempv.push_back(s);
        dfs1(distpre[s][i],e);
        tempv.pop_back();
    }
}
void dfs2(int s,int e){
    if(s==e){
        int sum=0;
        tempv.push_back(s);
        if(tempv.size()<mindist2time){
            timeres=tempv;
            mindist2time=tempv.size();
        }
        tempv.pop_back();
        return;
    }

    for(int i=0;i<timepre[s].size();i++){
        tempv.push_back(s);
        dfs2(timepre[s][i],e);
        tempv.pop_back();
    }
}
void dijkstra1(int s){//shortest
    fill(d,d+520,INF);
    fill(vis,vis+520,false);
    d[s]=0;

    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(d[j]<MIN&&vis[j]==false){
                MIN=d[j];u=j;
            }
        }
        vis[u]=true;
        if(u==-1) return;

        for(int j=0;j<n;j++){
            if(vis[j]==false&&dist[u][j]<INF){
                if(d[j]>d[u]+dist[u][j]){
                    d[j]=d[u]+dist[u][j];
                    distpre[j].clear();
                    distpre[j].push_back(u);
                }else if(d[j]==d[u]+dist[u][j]){
                    distpre[j].push_back(u);
                }
            }
        }
    }
}
void dijkstra2(int s){//fastest
    fill(t,t+520,INF);
    fill(vis,vis+520,false);
    t[s]=0;

    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(t[j]<MIN&&vis[j]==false){
                MIN=t[j];u=j;
            }
        }
        vis[u]=true;
        if(u==-1) return;

        for(int j=0;j<n;j++){
            if(vis[j]==false&&tm[u][j]<INF){
                if(t[j]>t[u]+tm[u][j]){
                    t[j]=t[u]+tm[u][j];
                    timepre[j].clear();
                    timepre[j].push_back(u);
                }else if(t[j]==t[u]+tm[u][j]){
                    timepre[j].push_back(u);
                }
            }
        }
    }
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    fill(tm[0],tm[0]+520*520,INF);
    fill(dist[0],dist[0]+520*520,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d%d%d%d",&a,&b,&oneway,&templen,&temptime);
        if(oneway==0){
            tm[b][a]=min(tm[b][a],temptime);
            dist[b][a]=min(dist[b][a],templen);
        }
        tm[a][b]=min(tm[a][b],temptime);
        dist[a][b]=min(dist[a][b],templen);
    }
    int s,e;
    scanf("%d%d",&s,&e);
    dijkstra1(s);//shortest
    dfs1(e,s);
    tempv.clear();
    dijkstra2(s);//fastest
    dfs2(e,s);
    reverse(distres.begin(),distres.end());
    reverse(timeres.begin(),timeres.end());
    int restime=0,resdist=0;
    for(int i=0;i<distres.size()-1;i++){
        resdist+=dist[distres[i]][distres[i+1]];
    }
    for(int i=0;i<timeres.size()-1;i++){
        restime+=tm[timeres[i]][timeres[i+1]];
    }
    if(timeres==distres){
        printf("Distance = %d; Time = %d:",resdist,restime);
        for(int i=0;i<distres.size();i++){
            printf(" %d",distres[i]);
            if(i!=distres.size()-1) printf(" ->");
        }
    }else{
        printf("Distance = %d:",resdist);
        for(int i=0;i<distres.size();i++){
            printf(" %d",distres[i]);
            if(i!=distres.size()-1) printf(" ->");
        }
        printf("\nTime = %d:",restime);
        for(int i=0;i<timeres.size();i++){
            printf(" %d",timeres[i]);
            if(i!=timeres.size()-1) printf(" ->");
        }
    }
}
