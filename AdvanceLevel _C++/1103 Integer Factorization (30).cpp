#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n,k,p,maxFacSum=-1;
vector<int> v,t,res;

void dfs(int i,int tempsum,int tempk,int facSum){

    if(tempk==k){
        if(tempsum==n&&facSum>maxFacSum){
            res=t;maxFacSum=facSum;
        }
        return;
    }

    while(i>=1){
        if(tempsum+v[i]<=n){
            t[tempk]=i;
            dfs(i,tempsum+v[i],tempk+1,facSum+i);
        }
        if(i==1) return;
        i--;
    }
}


int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&p);
    int temp=0,index=0;
    while(temp<=n){
        v.push_back(temp);
        index++;
        temp=pow(index,p)+0.5;//pow(),return double;
    }
    t.resize(k);
    dfs(v.size()-1,0,0,0);
    if(maxFacSum==-1){
        printf("Impossible");
        return 0;
    }
    printf("%d =",n);
    for(int i=0;i<res.size();i++){
        printf(" %d^%d",res[i],p);
        if(i!=res.size()-1) printf(" +");
    }
    return 0;
}
