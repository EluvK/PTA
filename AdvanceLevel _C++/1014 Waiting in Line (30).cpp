#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#define INF 0x3fffffff
using namespace std;
struct info{
    int num;
    int time;
    int out;
    info(int _n,int _t,int _o){num=_n;time=_t;out=_o;}
};
int n,m,k,qu;

queue<info> q[20];
bool Eempty(){
    for(int i=0;i<n;i++){
        if(q[i].size()<m)
            return true;
    }
    return false;
}
int getmin(){
    int mi=0;
    for(int i=1;i<n;i++){
        if(q[i].size()<q[mi].size()) mi=i;
    }
    return mi;
}
void popmin(){
    int mini,mi=999999;
    for(int i=0;i<n;i++){
        if(!q[i].empty()){
            if(q[i].front().time<mi){
                mi=q[i].front().time;
                mini=i;
            }
        }
    }
    if(mi==999999) return;
    for(int i=0;i<n;i++){
        if(!q[i].empty()){
            if(i==mini) q[i].pop();
            else q[i].front().time-=mi;
        }
    }
    return;
}
bool Allempty(){
    for(int i=0;i<n;i++){
        if(q[i].empty()==false) return false;
    }
    return true;
}
int main(){
//    freopen("1.txt","r",stdin);
    cin>>n>>m>>k>>qu;
    vector<info> c;
    int temp,in=0;
    for(int i=0;i<k;i++){
        scanf("%d",&temp);
        c.push_back(info(i,temp,0));
    }
    int window[20]={0};
    while(in<k||Eempty()){
        if(in==k&&Allempty()==true) break;
        while(in<k&&Eempty()){
            int i=getmin();
            q[i].push(c[in]);
            c[in].out=window[i]+c[in].time;
            if(c[in].out>=540) window[i]=9999;
            else window[i]+=c[in].time;
            in++;
        }
        popmin();
    }
    for(int i=0;i<qu;i++){
        scanf("%d",&temp);
        int time=c[temp-1].out;
        if(time>9999) printf("Sorry");
        else {
            int hh=time/60+8;
            int mm=time%60;
            printf("%02d:%02d",hh,mm);
        }
        if(i!=qu-1) printf("\n");
    }
    return 0;

}
