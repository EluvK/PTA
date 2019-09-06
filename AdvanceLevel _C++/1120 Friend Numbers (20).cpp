#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,temp;
    cin>>n;
    set<int> res;
    for(int i=0;i<n;i++){
        cin>>temp;
        int sum=0;
        while(temp!=0){
            sum=sum+temp%10;
            temp/=10;
        }
        res.insert(sum);
    }
    cout<<res.size()<<endl;
    for(set<int>::iterator it=res.begin();it!=res.end();it++){
        if(it!=res.begin()) printf(" ");
        printf("%d",*it);
    }
    return 0;
}
