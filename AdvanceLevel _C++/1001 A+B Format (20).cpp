#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

void opt(int n){
    string str;
    int cnt=0;
    bool flag=n<0?true:false;
    n=abs(n);
    while(n!=0){
        char c=n%10+'0';
        str=c+str;
        if(++cnt==3&&n>=10){
            str=","+str;cnt=0;
        }
        n/=10;
    }
    if(flag) printf("-");
    cout<<str;
}

int main(){
//    freopen("1.txt","r",stdin);
    int a,b;
    scanf("%d%d",&a,&b);
    if(a+b) opt(a+b);
    else printf("0");
    return 0;
}
