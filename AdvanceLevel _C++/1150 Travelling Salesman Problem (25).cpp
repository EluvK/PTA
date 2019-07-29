#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;


int g[220][220];
int vis[220];
int flag;
vector<int> arr;

int main(){
//    freopen("1.txt","r",stdin);
    int n,m,num,cnt,a,b,s,dis,res=INF,resi=1;
    scanf("%d%d",&n,&m);
    fill(g[0],g[0]+220*220,INF);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&dis);
        g[a][b]=g[b][a]=min(g[a][b],dis);
    }
    scanf("%d",&m);

    for(int i=1;i<=m;i++){
        scanf("%d",&num);
        arr.resize(num);
        for(int j=0;j<num;j++) scanf("%d",&arr[j]);

        fill(vis,vis+220,0);
        a=arr[0];
        s=a;
        cnt=0;flag=0;
        for(int j=1;j<num;j++){
            b=arr[j];
            cnt+=g[a][b];
            vis[b]++;
            if(cnt>INF) break;
            a=b;
        }
        printf("Path %d: ",i);
        if(cnt>INF) printf("NA ");
        else printf("%d ",cnt);
        if(a!=s||cnt>INF) printf("(Not a TS cycle)\n");
        else{
            for(int j=1;j<=n;j++){
                if(vis[j]==0){
                    flag=2;
                    break;
                }
                if(vis[j]>1){
                    flag=1;
                }
            }
            if(flag==1) printf("(TS cycle)\n");
            if(flag==0) printf("(TS simple cycle)\n");
            if(flag==2) printf("(Not a TS cycle)\n");
            if(flag!=2){
                if(cnt<res){
                    res=cnt;resi=i;
                }
            }
        }
    }
    printf("Shortest Dist(%d) = %d",resi,res);
}
