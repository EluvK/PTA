#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

int r[210][210],dis[210],n,m,in=0;
bool vis[210];

map<string,int> mp;
map<int,string> mp2;
vector<int> h,tempv,res[1000],pre[210];

void dfs(int s,int e){
    if(s==e){
        tempv.push_back(e);
        res[in++]=tempv;
        tempv.pop_back();
        return;
    }

    for(int i=0;i<pre[s].size();i++){
        tempv.push_back(s);
        dfs(pre[s][i],e);
        tempv.pop_back();
    }
    return;
}
void dijkstra(int s){
    fill(dis,dis+210,INF);
    dis[s]=0;
    for(int i=1;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n;j++){
            if(vis[j]==false&&dis[j]<MIN){
                u=j;MIN=dis[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;

        for(int j=1;j<=n;j++){
            if(vis[j]==false&&r[j][u]<INF){
                if(dis[u]+r[j][u]<dis[j]){
                    dis[j]=dis[u]+r[j][u];
                    pre[j].clear();
                    pre[j].push_back(u);
                }else if(dis[u]+r[j][u]==dis[j]){
                    pre[j].push_back(u);
                }
            }
        }
    }
}

int calcst(int n){
    int len=res[n].size();
    int sum=0;
    for(int i=0;i<len-1;i++){
        sum+=r[res[n][i]][res[n][i+1]];
    }
    return sum;
}

void pri(int n){
    int len=res[n].size();
    for(int i=0;i<len;i++){
        cout<<mp2[res[n][i]];
        if(i!=len-1) cout<<"->";
    }
    return;
}

int calhap(int n){
    int sum=0;
    for(int j=1;j<res[n].size();j++){
        sum+=h[res[n][j]];
    }
    return sum;
}
int main(){
//    freopen("1.txt","r",stdin);

    scanf("%d%d",&n,&m);
    h.resize(n+1);
    string first,temp1,temp2;
    int tempdis;
    cin>>first;
    mp[first]=1;mp2[1]=first;
    for(int i=2;i<=n;i++){
        cin>>temp1>>h[i];
        mp[temp1]=i;
        mp2[i]=temp1;
    }
    fill(r[0],r[0]+210*210,INF);

    for(int i=0;i<m;i++){
        cin>>temp1>>temp2>>tempdis;
        r[mp[temp1]][mp[temp2]]=r[mp[temp2]][mp[temp1]]=min(tempdis,r[mp[temp2]][mp[temp1]]);
    }
    dijkstra(1);
    dfs(mp["ROM"],1);

    for(int i=0;i<in;i++){
        reverse(res[i].begin(),res[i].end());
    }

    int maxhap=0,avghap=0,ansi;
    int tempmax,tempavg;
    for(int i=0;i<in;i++){
        tempmax=calhap(i);
        if(tempmax>maxhap){
            ansi=i;
            maxhap=tempmax;
            avghap=maxhap/(res[i].size()-1);
        }else if(tempmax==maxhap&&((tempmax/(res[i].size()-1))>avghap)){
            ansi=i;
            maxhap=tempmax;
            avghap=tempmax/(res[i].size()-1);
        }
    }

    int cst=calcst(ansi);
    printf("%d %d %d %d\n",in,cst,maxhap,avghap);
    pri(ansi);
}

