#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    int n,m,a,b;
    int g[220][220];
    fill(g[0],g[0]+220*220,0);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[a][b]=g[b][a]=1;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int num;
        scanf("%d",&num);
        vector<int> arr(num);
        vector<bool> vis(n+1,false);
        bool flag=true;
        for(int j=0;j<num;j++) scanf("%d",&arr[j]);
        int s=arr[0],temps=arr[0],e;
        vis[s]=true;
        for(int j=1;j<num;j++){
            e=arr[j];
            if(g[s][e]==0){
                flag=false;break;
            }
            vis[e]=true;
            s=e;
        }
        if(s!=temps||num!=n+1) flag=false;
        if(flag){
            for(int j=1;j<=n;j++){
                if(vis[j]==false) flag=false;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}
