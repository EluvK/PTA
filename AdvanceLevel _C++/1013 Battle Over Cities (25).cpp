#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define INF 0x3fffffff
using namespace std;

int N,M,K;
vector<int> r[1001];
bool vis[1001];

void dfs(int start,int avoid){
    vis[start]=true;
    for(int i=0;i<r[start].size();i++){
        int next=r[start][i];
        if(next!=avoid&&vis[next]==false) dfs(next,avoid);
    }
}
void dfsT(int avoid){
    int num=0;
    for(int i=1;i<=N;i++){
        if(i!=avoid&&vis[i]==false){
            dfs(i,avoid);
            num++;
        }
    }
    if(num) printf("%d\n",num-1);
    else printf("0\n");
}
int main(){
//    freopen("1.txt","r",stdin);

    int a,b,q,num;
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<M;i++){
        scanf("%d%d",&a,&b);
        r[a].push_back(b);
        r[b].push_back(a);
    }
    for(int i=0;i<K;i++){
        scanf("%d",&q);
        fill(vis,vis+1001,false);
        dfsT(q);
    }
}
