#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#define INF 0x3fffffff
using namespace std;

void downadjust(int b[],int s,int e){
    int i=1,j=i*2;
    while(j<=e){
        if(j+1<=e&&b[j]<b[j+1]) j++;
        if(b[i]>=b[j]) break;
        swap(b[i],b[j]);
        i=j;j=i*2;
    }
}

int main(){
//    freopen("1.txt","r",stdin);

    int n;scanf("%d",&n);
    int a[110],b[110];
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);

    int p;
    for(p=2;p<n;p++){
        if(b[p]<b[p-1]) break;
    }
    for(;p<=n;p++){
        if(b[p]!=a[p]){
            printf("Heap Sort\n");
            for(p=n;p>0;p--){
                if(b[p]<b[1]) break;
            }
            swap(b[1],b[p]);
            downadjust(b,1,p-1);
            for(int i=1;i<=n;i++){
                printf("%d",b[i]);
                if(i!=n) printf(" ");
            }
            return 0;
        }
    }
    printf("Insertion Sort\n");
    for(p=2;p<n;p++){
        if(b[p]<b[p-1]) break;
    }
    sort(b+1,b+p+1);
    for(int i=1;i<=n;i++){
        printf("%d",b[i]);
        if(i!=n) printf(" ");
    }
    return 0;

}
