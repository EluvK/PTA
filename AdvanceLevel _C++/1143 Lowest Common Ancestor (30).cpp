#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    int m,n,temp,a,b;
    scanf("%d%d",&m,&n);
    map<int,int> mp;
    vector<int> pre;
    pre.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&pre[i]);
        mp[pre[i]]=1;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        if(mp[a]==0&&mp[b]==0)
            printf("ERROR: %d and %d are not found.\n",a,b);
        else if(mp[a]==0||mp[b]==0)
            printf("ERROR: %d is not found.\n",mp[a]==0?a:b);
        else{
            for(int j=0;j<n;j++){
                if((pre[j]>=a&&pre[j]<=b)||(pre[j]<=a&&pre[j]>=b)){
                    temp=pre[j];break;
                }
            }
            if(a==temp||b==temp){
                printf("%d is an ancestor of %d.\n",temp,a==temp?b:a);
            }else{
                printf("LCA of %d and %d is %d.\n",a,b,temp);
            }
        }
    }
}
