#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    int n,a,b;
    scanf("%d",&n);
    map<int,int> mp;
    set<int> res,temp;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        mp[a]=b;mp[b]=a;
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(mp[mp[a]]==a){
            if(temp.find(mp[a])==temp.end()){
                temp.insert(a);
            }else{
                temp.erase(temp.find(mp[a]));
            }
            continue;
        }
        res.insert(a);
    }
    for(set<int>::iterator it=temp.begin();it!=temp.end();it++)
        res.insert(*it);
    printf("%d\n",res.size());
    for(set<int>::iterator it=res.begin();it!=res.end();it++){
        if(it!=res.begin()) printf(" ");
        printf("%05d",*it);
    }
}
