#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    int n1,n2,e,mx=0;
    double p[2500]={0},res[2500]={0},t;
    cin>>n1;
    for(int i=0;i<n1;i++){
        cin>>e;
        mx=max(mx,e);
        cin>>p[e];
    }
    cin>>n2;
    for(int i=0;i<n2;i++){
        cin>>e>>t;
        for(int j=0;j<=mx;j++){
            if(p[j]!=0) res[e+j]+=(t*p[j]);
        }
    }
    mx=0;
    int cnt=0;
    for(int i=0;i<2500;i++){
        if(res[i]!=0){
             mx=i;cnt++;
        }
    }
    cout<<cnt;
    for(int i=mx;i>=0;i--){
        if(res[i]!=0) printf(" %d %.1f",i,res[i]);
    }
}
