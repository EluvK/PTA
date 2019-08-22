#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

long long fac[20];
void init(){
    fac[1]=fac[0]=1;
    for(int i=2;i<17;i++){
        fac[i]=fac[i-1]*i;
    }
    return;
}

int main(){
//    freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    init();
    int mx=1;
    for(int i=16;i>=1;i--){
        if(n%fac[i]==0){
            mx=i;break;
        }
    }
    if(mx==1){
        bool flag=false;
        for(int temp=2;temp<=sqrt(n);temp++){
            if(n%temp==0){
                printf("1\n%d",temp);
                flag=true;
            }
        }
        if(!flag) printf("1\n%d",n);
    }else{
        for(int temp=16-mx;temp>=1;temp--){
            int cal=fac[temp+mx-1]/fac[temp-1];
            if(n%cal==0){
                if(cal==fac[mx]){
                    //start from 1
                    temp++;mx--;
                }
                printf("%d\n",mx);
                for(int j=temp;j<temp+mx;j++){
                    printf("%d%c",j,j==temp+mx-1?'\n':'*');
                }
                return 0;
            }
        }
    }
    return 0;
}
