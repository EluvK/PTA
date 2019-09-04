//wa*1
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

struct node{
    int data;
    int adr;
    int next;
    int ind;
}A[100010];
struct node2{
    int adr,data;
    node2(int a,int d){adr=a;data=d;}
};
bool cmp(node &a,node &b){
    return a.ind<b.ind;
}

int main(){
//    freopen("data.txt","r",stdin);
    int s,n,k;
    scanf("%d%d%d",&s,&n,&k);
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&A[i].adr,&A[i].data,&A[i].next);
        mp[A[i].adr]=i;
    }
    int temp=s,i=1,j;
    while(temp!=-1){
        temp=mp[temp];
        A[temp].ind=i++;
        temp=A[temp].next;
    }
    sort(A+1,A+n+1,cmp);
    vector<node2> res;
    i=k;j=n;
    while(i!=0||j!=k){
        if(i!=0){
            res.push_back(node2(A[i].adr,A[i].data));
            i--;
        }
        if(j!=k){
            res.push_back(node2(A[j].adr,A[j].data));
            j--;
        }
    }
    for(i=0;i<res.size()-1;i++){
        printf("%05d %d %05d\n",res[i].adr,res[i].data,res[i+1].adr);
    }
    printf("%05d %d -1\n",res[res.size()-1].adr,res[res.size()-1].data);
}
