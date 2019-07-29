#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct edge{
    int x,y;
}E[10010];
vector<int> num[10010];
int n,m,k,cnt,temp;
bool vis[10010];
int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&E[i].x,&E[i].y);
        num[E[i].x].push_back(i);
        num[E[i].y].push_back(i);
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int j;
        fill(vis,vis+m+1,false);
        scanf("%d",&cnt);
        for(j=0;j<cnt;j++){
            scanf("%d",&temp);
            for(int l=0;l<num[temp].size();l++){
                vis[num[temp][l]]=true;
            }
        }
        for(j=1;j<=m;j++){
            if(vis[j]==false) break;
        }
        if(j==m+1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
