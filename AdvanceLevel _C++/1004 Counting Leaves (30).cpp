#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> kid[110];
int res[110],mx=0;
void dfs(int s,int lv){
    if(kid[s].empty()){
        res[lv]++;
        mx=max(mx,lv);
    }else{
        for(int i=0;i<kid[s].size();i++)
            dfs(kid[s][i],lv+1);
    }
}
int main(){
//    freopen("1.txt","r",stdin);
    int n,m,rt,num,cnt;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&rt,&num);
        kid[rt].resize(num);
        for(int j=0;j<num;j++) scanf("%d",&kid[rt][j]);
    }
    dfs(1,1);
    for(int i=1;i<=mx;i++)
        printf("%d%c",res[i],i==mx?'\n':' ');
}
