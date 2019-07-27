#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 0x3fffffff
using namespace std;
bool vis[10010];
struct info{
    int num,fa,mo,kidnum;
    vector<int> kid;
    int stnum;
    int area;
}A[10010];
vector<int> st;

struct node{
    int id,num;
    double st,ar;
    node(int i,int n,double s,double a){id=i;num=n;st=s;ar=a;}
};
vector<node> res;

void bfs(int start){
    info temp;
    queue<int> q;
    int cntnum=0,cntset=0,cntarea=0,id=10000;
    q.push(start);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        id=min(id,now);
        cntnum++;
        cntset+=A[now].stnum;
        cntarea+=A[now].area;
        vis[now]=true;

        if(vis[A[now].fa]==false&&A[now].fa!=-1){
            q.push(A[now].fa);
            vis[A[now].fa]=true;
        }

        if(vis[A[now].mo]==false&&A[now].mo!=-1){
            q.push(A[now].mo);
            vis[A[now].mo]=true;
        }
        for(int i=0;i<A[now].kid.size();i++){
            if(vis[A[now].kid[i]]==false){
                q.push(A[now].kid[i]);
                vis[A[now].kid[i]]=true;
            }
        }
    }
    double st=cntset*1.0/cntnum,area=cntarea*1.0/cntnum;
    res.push_back(node(id,cntnum,st,area));
}
bool cmp(node a,node b){
    if(a.ar!=b.ar) return a.ar>b.ar;
    else return a.id<b.id;
}

int main(){
//    freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    int temp,kidtemp,fat,mot;
    fill(vis,vis+10010,true);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        A[temp].num=temp;
        st.push_back(temp);
        vis[temp]=false;
        scanf("%d%d%d",&fat,&mot,&A[temp].kidnum);
        A[temp].fa=fat;
        A[temp].mo=mot;
        A[fat].kid.push_back(temp);
        A[mot].kid.push_back(temp);
        vis[fat]=false;vis[mot]=false;
        for(int j=0;j<A[temp].kidnum;j++){
            scanf("%d",&kidtemp);
            A[temp].kid.push_back(kidtemp);
            if(A[kidtemp].fa) A[kidtemp].mo=temp;
            else A[kidtemp].fa=temp;
            vis[kidtemp]=false;
        }
        scanf("%d%d",&A[temp].stnum,&A[temp].area);
    }
    int cnt=0;
    for(int i=0;i<st.size();i++){
        if(vis[st[i]]==false)
            bfs(st[i]);
    }
    sort(res.begin(),res.end(),cmp);
    printf("%d",res.size());
    for(int i=0;i<res.size();i++){
        printf("\n%04d %d %.3f %.3f",res[i].id,res[i].num,res[i].st,res[i].ar);
    }
}
