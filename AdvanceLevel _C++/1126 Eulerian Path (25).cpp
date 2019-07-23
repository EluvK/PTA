#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#define INF 0x3fffffff
using namespace std;
int g[600][600];
int gnum=0;
bool vis[600]={false};

void dfs(int start){
    vis[start]=true;
    gnum++;
    for(int i=0;i<600;i++){
        if(g[start][i]==1&&vis[i]==false){
            dfs(i);
        }
    }
}

int main(){
//    freopen("1.txt","r",stdin);

    int n,m,a,b;
    scanf("%d%d",&n,&m);
    fill(g[0],g[0]+600*600,0);
    int num[600]={0};
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        g[a][b]=g[b][a]=1;
        num[a]++;num[b]++;
    }

    dfs(1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(num[i]%2) cnt++;
        printf("%d%c",num[i],i==n?'\n':' ');
    }
    if(gnum!=n) printf("Non-Eulerian");
    else if(cnt==0) printf("Eulerian");
    else if(cnt==2) printf("Semi-Eulerian");
    else printf("Non-Eulerian");

}
