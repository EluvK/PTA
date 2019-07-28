#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n,m,k;

bool vis[210];
int path[210][210];

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int a,b,num;
    fill(path[0],path[0]+210*210,0);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        path[a][b]=path[b][a]=1;
    }
    scanf("%d",&k);
    bool res;
    for(int i=0;i<k;i++){
        scanf("%d",&num);
        fill(vis,vis+n+1,false);
        res=true;
        scanf("%d",&a);
        int s=a;
        for(int i=0;i<num-1;i++){
            scanf("%d",&b);
            if(path[a][b]==0||vis[a]){
                res=false;
            }else{
                vis[a]=true;
            }
            a=b;
        }
        if(a!=s) res=false;

        for(int i=1;i<=n;i++){
            if(vis[i]==false){
                 res=false;break;
            }
        }
        if(res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
