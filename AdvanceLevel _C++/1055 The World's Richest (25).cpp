#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct info{
    string name;
    int age,w;
};
bool cmp(info a,info b){
    if(a.w!=b.w) return a.w>b.w;
    else return a.age==b.age?a.name<b.name:a.age<b.age;
}
int main(){
//    freopen("1.txt","r",stdin);
    int N,K,num,low,high;
    cin>>N>>K;
    vector<info> v(N);
    for(int i=0;i<N;i++) cin>>v[i].name>>v[i].age>>v[i].w;
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<K;i++){
        scanf("%d%d%d",&num,&low,&high);
        printf("Case #%d:\n",i+1);
        int temp=num,j=0;
        for(j=0;j<v.size();j++){
            if(low<=v[j].age&&v[j].age<=high){
                cout<<v[j].name;
                printf(" %d %d\n",v[j].age,v[j].w);
                if(--temp==0) break;
            }
        }
        if(temp==num) printf("None\n");
    }
}
