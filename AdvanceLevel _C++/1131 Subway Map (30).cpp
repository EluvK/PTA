#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;

struct node{
    int line,s,e;
    node(){}
    node(int a,int b,int c){line=a;s=b;e=c;}
};
int minstation,vis[10000];
vector<node> ans;
vector<int> v[10000];
map<int,int> mp;

void setline(int x,int y,int i){
    if(x>y) swap(x,y);
    mp[x*10000+y]=i;
}
int searchline(int x,int y){
    if(x>y) swap(x,y);
    return mp[x*10000+y];
}
void dfs(int lhd,int pre,int u,int e,vector<node> &rp,int station){
    if(u==e){
        rp.push_back(node(searchline(pre,u),lhd,u));
        if(station<minstation||(station==minstation&&rp.size()<ans.size())){
            minstation=station;
            ans=rp;
        }
        rp.pop_back();
        return;
    }
    vis[u]=1;
    for(int i=0;i<v[u].size();i++){
        int w=v[u][i];
        if(vis[w]) continue;
        if(pre!=u&&searchline(pre,u)!=searchline(u,w)){
            rp.push_back(node(searchline(pre,u),lhd,u));
            dfs(u,u,w,e,rp,station+1);
            rp.pop_back();
        }else dfs(lhd,u,w,e,rp,station+1);
    }
    vis[u]=0;
}
int main(){
    int n,k;
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int m,x,y;
        scanf("%d%d",&m,&x);
        for(int j=1;j<m;j++){
            scanf("%d",&y);
            setline(x,y,i);
            v[x].push_back(y);
            v[y].push_back(x);
            x=y;
        }
    }
    scanf("%d",&k);
    while(k--){
        int s,e;
        scanf("%d%d",&s,&e);
        minstation=INF;
        ans.resize(200);
        vector<node> rp;
        dfs(s,s,s,e,rp,0);
        printf("%d\n",minstation);
        for(int i=0;i<ans.size();i++){
            printf("Take Line#%d from %04d to %04d.\n",ans[i].line,ans[i].s,ans[i].e);
        }
    }
}
