#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 0x3fffffff
using namespace std;

bool cmp(int a,int b){return a>b;}
int main(){
//    freopen("1.txt","r",stdin);
    int n,m;
    int w[10010],dp[10010]={0};
    bool choice[10010][110];
    fill(choice[0],choice[0]+10010*110,false);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    sort(w+1,w+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            if(dp[j]<=dp[j-w[i]]+w[i]){
                choice[i][j]=true;
                dp[j]=dp[j-w[i]]+w[i];
            }
        }
    }
    if(dp[m]!=m) printf("No Solution");
    else{
        vector<int> res;

        while(m>0){
            if(choice[n][m]==true){
                res.push_back(w[n]);
                m-=w[n];
            }
            n--;
        }

        for(int i=0;i<res.size();i++){
            printf("%d",res[i]);
            if(i!=res.size()-1) printf(" ");
        }
    }

}
