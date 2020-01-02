#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

struct node{
    int adr,data,next;
    node(int a,int d,int n){adr=a;data=d;next=n;}
};

int main()
{
//    freopen("1.txt","r",stdin);
    int f,num,k;
    cin>>f>>num>>k;
    int ta,tb,tc;
    int book[100001]={0};
    vector<node> all;
    for(int i=0;i<num;i++){
        scanf("%d%d%d",&ta,&tb,&tc);
        all.push_back(node(ta,tb,tc));
        book[ta]=i;
    }
    vector<node> l,res;
    while(f!=-1){
        l.push_back(all[book[f]]);
        f=all[book[f]].next;
    }
    int len=l.size();
    int gnum=(len+k-1)/k;
    for(int i=gnum-1;i>=0;i--){
        int mx=(i+1)*k>len?len:(i+1)*k;
        for(int j=i*k;j<mx;j++){
            res.push_back(l[j]);
        }
    }
    for(int i=0;i<res.size()-1;i++){
        printf("%05d %d %05d\n",res[i].adr,res[i].data,res[i+1].adr);
    }
    printf("%05d %d -1",res[res.size()-1].adr,res[res.size()-1].data);
    return 0;
}
