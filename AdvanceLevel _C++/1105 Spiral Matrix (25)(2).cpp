#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){

    freopen("1.txt","r",stdin);
    int cn,m,n;
    scanf("%d",&cn);
    for(n=int(sqrt(cn*1.0));n>0;n--){
        if(cn%n==0) break;
    }
    m=cn/n;
    vector<int> arr(cn);
    for(int i=0;i<cn;i++) scanf("%d",&arr[i]);
    vector<int> res[m];
    for(int i=0;i<m;i++) res[i].resize(n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            res[i][j]=0;
    }
    int flag=0;
    int si[4]={0,1,0,-1};
    int sj[4]={1,0,-1,0};
    int i=0,j=0,cnt=1;
    for(;cnt<cn;){
        int ni=i+si[flag];
        int nj=j+sj[flag];
        if(0<=ni&&ni<m&&0<=nj&&nj<n&&res[ni][nj]==0){
            res[i][j]=cnt;
//            printf("%d:%d:%d\n",i,j,cnt);
            i=ni;j=nj;cnt++;

        }else{
//            res[i][j]=cnt+1;
            flag=(flag+1)%4;

        }
//
    }
    res[i][j]=cn;
    sort(arr.rbegin(),arr.rend());
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d%c",arr[res[i][j]-1],j==n-1?'\n':' ');
        }
    }
}
