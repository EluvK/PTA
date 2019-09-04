#include <stdio.h>
#include <iostream>
using namespace std;
int isprime(int n){
    if(n<=1) return false;
    if(n==2||n==3) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int check(int n){
    if(isprime(n)&&(isprime(n+6)||isprime(n-6))) return false;
    return true;
}

int main(){
//    freopen("1.txt","r",stdin);
    int n;
    cin>>n;
    if(isprime(n)&&(isprime(n+6)||isprime(n-6))){
        printf("Yes\n");
        if(isprime(n-6))
            printf("%d",n-6);
        else printf("%d",n+6);
    }
    else{
        while(check(n)){
            n++;
        }
        printf("No\n%d",n);
    }
    return 0;
}
