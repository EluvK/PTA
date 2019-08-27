#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#define INF 0x3fffffff
using namespace std;

int cntone(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        int temp=i;
        while(temp!=0){
            if(temp%10==1) sum++;
            temp/=10;
        }
    }
    return sum;
}
int callen(int n){
    int len=0;
    do{
        len++;
        n/=10;
    }while(n!=0);
    return len;
}
int tpow(int n){
    int sum=1;
    for(int i=0;i<n-1;i++) sum*=10;
    return sum;
}

int del(int n,int len){
    int temp=tpow(len);
    return n%temp;
}
int f(int n){
    while(n>9) n/=10;
    return n;
}
int calone(int n){
    if(n<100) return cntone(n);
    int len=callen(n);
    return calone(del(n,len))+f(n)*(len-1)*tpow(len-1)+min((n-tpow(len)+1),tpow(len));
}

int main(){
    int n,sum=0;
    cin>>n;
    cout<<calone(n);
}
