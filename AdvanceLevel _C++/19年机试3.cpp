#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;



int main(){
//    freopen("data.txt","r",stdin);
    int T,m,n,temp;
    scanf("%d%d%d",&T,&m,&n);
    vector<int> A(T,0);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        int loc=temp%m;
        while(A[loc%T]!=0) loc++;
        A[loc%T]=1;
    }
    int sum=0;
    for(int i=0;i<m;i++){
        int cnt=0,j=i;
        while(A[j%T]!=0){
            j++;
            if(j%T==i) break;
        }
        sum=sum+j-i+1;
    }
    double res=sum*1.0/m;
    printf("%.1f",res);
}
