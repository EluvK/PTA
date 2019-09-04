//TEL*1
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define INF 0x3fffffff
using namespace std;

int g[1020][1020];
//点1-ns 救护站 ns+1-ns+na
int ns,na;
vector<int> cinnum;
vector<int> pre[1020];
int m,k;
int resnum,resi,resd,resanum;
vector<int> tempres,res;

void dfs(int st,int ed,int num,int d,int anum,int ri){
    if(st==ed){
        if((d<resd)||(d==resd&&anum>resanum)||(d==resd&&anum==resanum&&num<resnum)){
            resnum=num;
            resd=d;
            resanum=anum;
            res=tempres;
            resi=ri;
        }
        return;
    }

    for(int i=0;i<pre[st].size();i++){
        tempres.push_back(st);
        dfs(pre[st][i],ed,num+1,d+g[st][pre[st][i]],anum,ri);
        tempres.pop_back();
    }
}
void prt(int n){
    if(n<=ns) printf("%d",n);
    else printf("A-%d",n-ns);
}
void dijkstra(int e){
    int d[1020];
    fill(d,d+1020,INF);
    bool vis[1020]={false};
    d[e]=0;
    bool flag=false;
    for(int i=1;i<=ns+na;i++){
        int u=-1,dis=INF;
        for(int j=1;j<=ns+na;j++){
            if(vis[j]==false&&d[j]<dis){
                u=j;dis=d[j];
            }
        }
        if(u==-1) break;
        for(int j=ns+1;j<=ns+na;j++){
            if(vis[j]&&cinnum[j-ns]>0) flag=true;
        }
        if(flag) break;

        vis[u]=true;
        for(int j=1;j<=ns+na;j++){
            if(g[u][j]<INF&vis[j]==false){
                if(g[u][j]+d[u]<d[j]){
                    d[j]=g[u][j]+d[u];
                    pre[j].clear();
                    pre[j].push_back(u);
                }else if(g[u][j]+d[u]==d[j]){
                    pre[j].push_back(u);
                }
            }
        }
    }


    resnum=INF,resi=-1,resd=INF,resanum=1;
    for(int i=ns+1;i<=ns+na;i++){
        if(cinnum[i-ns]<1||d[i]==INF) continue;
        tempres.clear();
        dfs(i,e,0,0,cinnum[i-ns],i);
    }
    if(resd==INF){
        printf("All Busy\n");
    }else{
        res.push_back(e);
        cinnum[resi-ns]--;
        for(int i=0;i<res.size();i++){
//        for(int i=res.size()-1;i>=0;i--){
            if(i!=0) printf(" ");
            prt(res[i]);
        }
        printf("\n");
        printf("%d\n",resd);
    }
}




int tonum(string str){
    int sum=0;
    for(int i=0;i<str.length();i++){
        sum=sum*10+str[i]-'0';
    }
    return sum;
}
int cvt(string str){
    if(str[0]=='A'){
        return tonum(str.substr(2,str.length()-2))+ns;
    }else return tonum(str);
}
int main(){
//    freopen("data.txt","r",stdin);
    scanf("%d%d",&ns,&na);
    cinnum.resize(na+1);
    for(int i=1;i<=na;i++) scanf("%d",&cinnum[i]);

    fill(g[0],g[0]+1020*1020,INF);
    scanf("%d",&m);
    string str1,str2;
    int tm;

    for(int i=0;i<m;i++){
        cin>>str1>>str2>>tm;
        int a=cvt(str1);
        int b=cvt(str2);
        g[a][b]=g[b][a]=tm;
    }

    int temp;
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&temp);
        dijkstra(temp);
    }
    return 0;
}
