#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define MAX 1000000007
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    string str;
    cin>>str;
    int len=str.length();
    vector<int> p(len+2,0),t(len+2,0);
    for(int i=1;i<=len;i++){
        if(str[i-1]=='P') p[i]=p[i-1]+1;
        else p[i]=p[i-1];
    }
    for(int i=len;i>=1;i--){
        if(str[i-1]=='T') t[i]=t[i+1]+1;
        else t[i]=t[i+1];
    }
    long long sum=0;
    for(int i=1;i<len;i++){
        if(str[i-1]=='A') sum=sum+p[i]*t[i];
        sum%=MAX;
    }
    printf("%lld",sum);
}
