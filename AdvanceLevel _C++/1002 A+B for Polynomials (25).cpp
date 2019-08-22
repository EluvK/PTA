#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    int n,temp,cnt=0,mx=0,tt=2;
    double e[1010]={0.0},ipt;
    while(tt--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %lf",&temp,&ipt);
            e[temp]+=ipt;
            mx=max(temp,mx);
        }
    }
    for(int i=0;i<=mx;i++) if(e[i]!=0) cnt++;
    printf("%d",cnt);
    for(int i=mx;i>=0;i--){
        if(e[i]!=0){
            printf(" %d %.1lf",i,e[i]);
        }
    }
    return 0;
}
