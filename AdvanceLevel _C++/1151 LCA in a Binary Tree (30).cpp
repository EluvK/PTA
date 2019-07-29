#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;

int in[10010],pre[10010];
map<int,int> mp1,mp2;
int main(){
//    freopen("1.txt","r",stdin);
    int m,n,a,b,res;
    int inL,inR,preL,preR;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&in[i]);
        mp1[in[i]]=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&pre[i]);
        mp2[pre[i]]=i;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        if(mp1[a]==0||mp1[b]==0){
            if(mp1[a]==0&&mp1[b]==0){
                printf("ERROR: %d and %d are not found.\n",a,b);
            }else if(mp1[a]==0){
                printf("ERROR: %d is not found.\n",a);
            }else{
                printf("ERROR: %d is not found.\n",b);
            }
        }else{
            inL=mp1[a];inR=mp1[b];
            preL=min(mp2[a],mp2[b]);
            if(inL>inR) swap(inL,inR);
            res=in[inL];
            for(int j=inR;j>=inL;j--){
                if(mp2[in[j]]<=preL){
                    res=in[j];break;
                }
            }
            if(res==a){
                printf("%d is an ancestor of %d.\n",a,b);
            }else if(res==b){
                printf("%d is an ancestor of %d.\n",b,a);
            }else{
                printf("LCA of %d and %d is %d.\n",a,b,res);
            }
        }
    }

}
