#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;

int n,m,a,b;
vector<int> g[10010],arr;
set<int> c;
bool flag;
int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    scanf("%d",&m);
    arr.resize(n+1);

    for(int i=0;i<m;i++){
        c.clear();flag=true;
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
            c.insert(arr[j]);
        }
        for(int j=0;j<n;j++){
            a=j;
            for(int k=0;k<g[a].size();k++){
                b=g[a][k];
                if(arr[a]==arr[b]){
                    flag=false;
                    break;
                }
            }
            if(flag==false) break;
        }
        if(flag) printf("%d-coloring\n",c.size());
        else printf("No\n");
    }
    return 0;
}
