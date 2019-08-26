#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    int n,temp,fre=0,res=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        if(temp>fre) res=res+6*(temp-fre);
        else res=res+4*(fre-temp);
        fre=temp;
    }
    res=res+5*n;
    cout<<res;
    return 0;
}
