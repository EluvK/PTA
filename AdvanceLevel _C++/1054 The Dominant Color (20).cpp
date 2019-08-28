#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    int n,m,num=0;
    long long temp,a;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&temp);
            if(num==0) a=temp;
            else if(a!=temp)
                num--;
            else num++;
        }
    }
    cout<<a;
    return 0;
}
