#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct info{
    string num;
    int time;
    bool flag;
    info(string n,int t,bool f){num=n;time=t;flag=f;}
};
bool cmp1(info a,info b){
    if(a.num!=b.num) return a.num<b.num;
    else return a.time<b.time;
}

int main(){
//    freopen("1.txt","r",stdin);
    int n,m,hh,mm,ss,tm;
    string carnum,cinflag;
    bool fg;
    cin>>n>>m;
    vector<info> v;
    for(int i=0;i<n;i++){
        cin>>carnum;
        scanf("%d:%d:%d",&hh,&mm,&ss);
        tm=3600*hh+60*mm+ss;
        cin>>cinflag;
        if(cinflag[0]=='i') fg=true;
        else fg=false;
        v.push_back(info(carnum,tm,fg));
    }
    sort(v.begin(),v.end(),cmp1);
    for(int i=0;i<v.size();i++){
        if(i+1==v.size()) v.pop_back();
        else{
            if(v[i].num==v[i+1].num&&v[i].flag&&v[i+1].flag==false){
                i++;continue;
            }else{
                v.erase(v.begin()+i);
                i--;
            }
        }
    }
    int num[86420]={0};
    map<string,int> mp;
    for(int i=0;i<v.size();i=i+2){
        num[v[i].time]++;
        num[v[i+1].time]--;
        mp[v[i].num]+=v[i+1].time-v[i].time;
    }
    for(int i=1;i<86410;i++) num[i]+=num[i-1];
    for(int i=0;i<m;i++){
        scanf("%d:%d:%d",&hh,&mm,&ss);
        tm=3600*hh+60*mm+ss;
        printf("%d\n",num[tm]);
    }
    vector<string> res;
    int maxtime=0;
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
        if(it->second>maxtime){
            res.clear();
            res.push_back(it->first);
            maxtime=it->second;
        }else if(it->second==maxtime){
            res.push_back(it->first);
        }
    }
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    printf("%02d:%02d:%02d",maxtime/3600,maxtime/60%60,maxtime%60);
}
