#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 0x3fffffff
using namespace std;
int n,m,k,r;
struct node{
    int v;
    int w;
    node(int _v,int _w){v=_v;w=_w;}
};
vector<int> d;
vector<node> s[1100];
vector<bool> vis;

void dijkstra(int start){
    fill(d.begin(),d.end(),INF);
    fill(vis.begin(),vis.end(),false);

    d[start]=0;

    for(int i=1;i<=n+m;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n+m;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;

        for(int j=0;j<s[u].size();j++){
            int v=s[u][j].v;
            if(vis[v]==false){
                if(d[u]+s[u][j].w<d[v]){
                    d[v]=d[u]+s[u][j].w;
                }
            }
        }
    }
}

int conv(string s){
    if(s[0]=='G'){
        int sum=0;
        for(int i=1;i<s.length();i++){
            sum=10*sum+s[i]-'0';
        }
        return sum+n;
    }
    else {
        int sum=0;
        for(int i=0;i<s.length();i++){
            sum=10*sum+s[i]-'0';
        }
        return sum;
    }
}
int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d%d%d",&n,&m,&k,&r);
    d.resize(n+m+1);
    vis.resize(n+m+1);
    string a,b;
    int aa,bb,dis;
    for(int i=0;i<k;i++){
        cin>>a>>b>>dis;
        aa=conv(a);bb=conv(b);
        s[aa].push_back(node(bb,dis));
        s[bb].push_back(node(aa,dis));
    }
    int resi=-1;
    double thisavg,thismin,resavg=0,resmin=0;
    int j;
    for(int i=n+1;i<=m+n;i++){
        dijkstra(i);
        thisavg=0;thismin=r;
        for(j=1;j<=n;j++){
            if(d[j]>r) break;
            else {
                thisavg+=d[j];
                thismin=thismin>d[j]?d[j]:thismin;
            }
        }
        if(j==n+1){
            thisavg/=n;
            if(thismin>resmin){
                resi=i;resmin=thismin;resavg=thisavg;
            }else if(thismin==resmin&&thisavg<resavg){
                resavg=thisavg;resi=i;
            }
        }
    }
    if(resi==-1) printf("No Solution");
    else printf("G%d\n%.1f %.1f",resi-n,resmin,resavg);

}
