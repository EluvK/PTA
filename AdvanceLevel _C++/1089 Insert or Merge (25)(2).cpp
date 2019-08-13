#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    int n,i,j;
    int a1[110],a2[110];

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a1[i]);
    for(int i=0;i<n;i++) scanf("%d",&a2[i]);

    for(i=0;i<n-1&&a2[i+1]>=a2[i];i++);//[>=]
    for(j=i+1;j<n&&a1[j]==a2[j];j++);

    if(j==n){
        printf("Insertion Sort\n");
        sort(a1,a1+i+2);
    }else{
        printf("Merge Sort\n");
        int step=1,flag=1;
        while(flag){
            flag=0;
            for(i=0;i<n;i++){
                if(a1[i]!=a2[i]) flag=1;
            }
            step*=2;
            for(i=0;i<n/step;i++)
                sort(a1+i*step,a1+(i+1)*step);
            sort(a1+i*step,a1+n);
        }
    }
    for(i=0;i<n;i++) printf("%d%c",a1[i],i==n-1?'\n':' ');
    return 0;
}
