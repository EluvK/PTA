#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,cnt=1;
vector<int> arr,res;

void inorder(int num){
    if(num>n) return;
    inorder(2*num);
    res[num]=arr[cnt++];
    inorder(2*num+1);
    return;
}

int main(){
//    freopen("1.txt","r",stdin);
    cin>>n;
    arr.resize(n+1);
    res.resize(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    sort(arr.begin(),arr.end());
    inorder(1);
    for(int i=1;i<=n;i++) printf("%d%c",res[i],i==n?'\n':' ');
    return 0;
}
