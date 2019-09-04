#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool isprime(long long n){
    if(n==1) return false;
    if(n==2||n==3) return true;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
int len(int n){
    int sum=0;
    while(n!=0){
        n/=10;
        sum++;
    }
    return sum;
}
int main(){
    int n,num,i=2;
    cin>>n;
    vector<int> res;
    if(n==1){
        printf("1\nNo");
        return 0;
    }
    while(!isprime(n)&&n!=1){
        num=0;
        while(n%i==0){
            n/=i;
            num++;
        }
        if(num>0) res.push_back(i);
        if(num>1) res.push_back(num);
        i++;
    }
    if(n!=1) res.push_back(n);
    long long sum=0;
    for(int i=0;i<res.size();i++){
        sum=sum*pow(10,len(res[i]))+res[i];
    }
    cout<<sum<<endl;
    if(isprime(sum)) cout<<"Yes";
    else cout<<"No";
    return 0;
}
