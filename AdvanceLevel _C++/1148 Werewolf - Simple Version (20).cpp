#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;


int main(){
//    freopen("1.txt","r",stdin);

    int n,state[120];
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&state[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            vector<int> lie,a(n+1,1);
            a[i]=a[j]=-1;
            for(int k=1;k<=n;k++){
                if(state[k]*a[abs(state[k])]<0) lie.push_back(k);
            }
            if(lie.size()==2&&a[lie[0]]+a[lie[1]]==0){
                printf("%d %d",i,j);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}
