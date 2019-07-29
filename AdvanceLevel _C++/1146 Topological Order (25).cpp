#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> g[1010];
int n,m,a,b;
bool vis[1010];
int arr[1010];
bool first=true;
bool check(int n){
    for(int i=0;i<g[n].size();i++){
        if(vis[g[n][i]]==false) return false;
    }
    vis[n]=true;
    return true;
}
int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[b].push_back(a);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        fill(vis,vis+n+1,false);
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
        }
        for(int j=0;j<n;j++){
            if(check(arr[j])==false){
                if(!first) printf(" ");
                printf("%d",i);
                first=false;
                break;
            }
        }
    }
    return 0;
}
