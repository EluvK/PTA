#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    int l=0,r=n-1,sum=-1,temp=0,tempi=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        temp+=arr[i];
        if(temp<0){
            temp=0;
            tempi=i+1;
        }else if(temp>sum){
            sum=temp;
            l=tempi;
            r=i;
        }
    }
    if(sum<0) sum=0;
    printf("%d %d %d",sum,arr[l],arr[r]);
    return 0;
}
