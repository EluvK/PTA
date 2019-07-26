#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

int n,k;
struct info{
    string car;
    int time;
    int flag;
}A[10010];

vector<int> res[5050];
map<string,int> mp;
map<int,string> mp2;


bool cmp(info a,info b){
    if(a.car!=b.car) return a.car<b.car;
    else if(a.time!=b.time) return a.time<b.time;
    else return a.flag<b.flag;
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&k);
    string temp;
    int hh,mm,ss,in=1,tempi;
    for(int i=0;i<n;i++){
        cin>>temp;
        scanf("%d:%d:%d",&hh,&mm,&ss);
        A[i].car=temp;
        cin>>temp;
        if(temp[0]=='i') A[i].flag=0;
        else A[i].flag=1;
        A[i].time=3600*hh+60*mm+ss;
    }
    sort(A,A+n,cmp);
    for(int i=0;i<n-1;i++){
        if(A[i].car==A[i+1].car&&A[i].flag==0&&A[i+1].flag==1){
            if(mp[A[i].car]==0){
                mp[A[i].car]=in;
                mp2[in]=A[i].car;
                in++;
            }
            tempi=mp[A[i].car];
            res[tempi].push_back(A[i].time);
            res[tempi].push_back(A[i+1].time);
            i++;
        }
    }
    int t[86405]={0};
    vector<int> maxc;
    maxc.resize(in);
    for(int i=1;i<in;i++){
        for(int j=0;j<res[i].size();j=j+2){
            t[res[i][j]]++;t[res[i][j+1]]--;
            maxc[i]=maxc[i]+res[i][j+1]-res[i][j];
        }
    }
    for(int i=1;i<86405;i++){
        t[i]+=t[i-1];
    }
    vector<int> maxi;
    maxi.push_back(0);
    for(int i=0;i<in;i++){
        if(maxc[i]>maxc[maxi[0]]){
            maxi.clear();
            maxi.push_back(i);
        }else if(maxc[i]==maxc[maxi[0]]){
            maxi.push_back(i);
        }
    }

    for(int i=0;i<k;i++){
        scanf("%d:%d:%d",&hh,&mm,&ss);
        printf("%d\n",t[3600*hh+60*mm+ss]);
    }
    for(int i=0;i<maxi.size();i++){
        cout<<mp2[maxi[i]]<<" ";
    }
    hh=maxc[maxi[0]]/3600;
    mm=maxc[maxi[0]]/60%60;
    ss=maxc[maxi[0]]%60;
    printf("%02d:%02d:%02d",hh,mm,ss);

}
