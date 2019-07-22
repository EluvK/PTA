#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define INF 0x3fffffff
using namespace std;

struct info{
    int arrt;
    int lasttime;
}A[10010];

bool cmp(info a,info b){
    return a.arrt<b.arrt;
}

int change(string str){
    int sum=0;
    sum+=10*(str[6]-'0')+str[7]-'0';
    sum+=60*(10*(str[3]-'0')+str[4]-'0');
    sum+=3600*(10*(str[0]-'0')+str[1]-'0');
    return sum;
}

int main(){
//    freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    string time;
    int m;
    int waittime=0;
    for(int i=0;i<n;i++){
        cin>>time>>m;
        A[i].arrt=change(time);
        A[i].lasttime=m*60;
    }
    sort(A,A+n,cmp);
    vector<int> window;
    window.resize(k);
    for(int i=0;i<k;i++){
        window[i]=28800;
    }
    int i;
    for(i=0;i<n;i++){
        if(A[i].arrt>=61201) break;
        int tempi=0,minf=window[0];
        for(int j=1;j<k;j++){
            if(minf>window[j]){
                minf=window[j];
                tempi=j;
            }
        }
        if(window[tempi]<=A[i].arrt){
            window[tempi]=A[i].arrt+A[i].lasttime;
        }else{
            waittime+=(window[tempi]-A[i].arrt);
            window[tempi]+=A[i].lasttime;
        }
    }

    double res=waittime*1.0/(i*60);
    printf("%.1f",res);
}
