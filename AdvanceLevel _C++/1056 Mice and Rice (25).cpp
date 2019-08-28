#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct info{
    int id,num,w,rk;
};
bool cmp1(info a,info b){
    if(a.rk!=b.rk) return a.rk<b.rk;
    else return a.id<b.id;
}
bool cmp2(info a,info b){
    return a.num<b.num;
}
int main(){
//    freopen("1.txt","r",stdin);
    int np,nk,temp;
    cin>>np>>nk;
    vector<int> w(np);
    vector<info> p(np);
    for(int i=0;i<np;i++) scanf("%d",&w[i]);
    for(int i=0;i<np;i++){
        p[i].id=i;
        scanf("%d",&p[i].num);
        p[i].w=w[p[i].num];
        p[i].rk=0;
    }
    int n=np,rknum,tnum;
    do{
        rknum=(n+nk-1)/nk+1;
        tnum=(n+nk-1)/nk;
        for(int i=0;i<tnum;i++){
            int mxi=0,mx=-1;
            for(int j=0;j<nk;j++){
                int ts=i*nk+j;
                if(ts>=n) break;
                if(p[ts].w>mx){
                    mx=p[ts].w;mxi=j;
                }
                p[ts].rk=rknum;
            }
            p[i*nk+mxi].rk=0;
        }
        sort(p.begin(),p.begin()+n,cmp1);
        n=rknum-1;
    }while(n!=1);
    sort(p.begin(),p.end(),cmp2);
    for(int i=0;i<np;i++) printf("%d%c",p[i].rk==0?1:p[i].rk,i==np-1?'\n':' ');
}
