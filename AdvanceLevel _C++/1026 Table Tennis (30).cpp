#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 0x3fffffff
using namespace std;

struct person{
    int arrive,start,time;
    bool vip;
}tempperson;
struct tablenode{
    int end=8*3600,num;
    bool vip;
};

vector<person> player;
vector<tablenode> table;

void alloctable(int personid,int tableid){
    if(player[personid].arrive<=table[tableid].end)
        player[personid].start=table[tableid].end;
    else
        player[personid].start=player[personid].arrive;

    table[tableid].end=player[personid].start+player[personid].time;
    table[tableid].num++;
}

bool cmp1(person a,person b){
    return a.arrive<b.arrive;
}
bool cmp2(person a,person b){
    return a.start<b.start;
}

int findnextvip(int vipid){
    vipid++;
    while(vipid<player.size()&&player[vipid].vip==false) vipid++;
    return vipid;
}

int main(){
    int n,k,m,viptable;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int hh,mm,ss,temptime,flag;
        scanf("%d:%d:%d%d%d",&hh,&mm,&ss,&temptime,&flag);
        tempperson.arrive=hh*3600+mm*60+ss;
        tempperson.start=21*3600;
        if(tempperson.arrive>=21*3600) continue;
        tempperson.time=temptime<=120?temptime*60:7200;
        tempperson.vip=flag==1?true:false;
        player.push_back(tempperson);
    }
    scanf("%d%d",&k,&m);
    table.resize(k+1);
    for(int i=0;i<m;i++){
        scanf("%d",&viptable);
        table[viptable].vip=true;
    }
    sort(player.begin(),player.end(),cmp1);
    int i=0,vipid=-1;
    vipid=findnextvip(vipid);
    while(i<player.size()){
        int index=-1,minendtime=INF;
        for(int j=1;j<=k;j++){
            if(table[j].end<minendtime){
                minendtime=table[j].end;
                index=j;
            }
        }
        if(table[index].end>=21*3600) break;
        if(player[i].vip==true&&i<vipid){
            i++;continue;
        }
        if(table[index].vip==true){
            if(player[i].vip==true){
                alloctable(i,index);
                if(vipid==i) vipid=findnextvip(vipid);
                i++;
            }else{
                if(vipid<player.size()&&player[vipid].arrive<=table[index].end){
                    alloctable(vipid,index);
                    vipid=findnextvip(vipid);
                }else{
                    alloctable(i,index);;
                    i++;
                }
            }
        }else{
            if(player[i].vip==false){
                alloctable(i,index);
                i++;
            }else{
                int vipindex=-1,minvipendtime=INF;
                for(int j=1;j<=k;j++){
                    if(table[j].vip==true&&table[j].end<minvipendtime){
                        minvipendtime=table[j].end;
                        vipindex=j;
                    }
                }
                if(vipindex!=-1&&player[i].arrive>=table[vipindex].end){
                    alloctable(i,vipindex);
                    if(vipid==i) vipid=findnextvip(vipid);
                    i++;
                }else{
                    alloctable(i,index);
                    if(vipid==i) vipid=findnextvip(vipid);
                    i++;
                }
            }
        }
    }
    sort(player.begin(),player.end(),cmp2);
    for(i=0;i<player.size()&&player[i].start<21*3600;i++){
        printf("%02d:%02d:%02d ",player[i].arrive/3600,player[i].arrive%3600/60,player[i].arrive%60);
        printf("%02d:%02d:%02d ",player[i].start/3600,player[i].start%3600/60,player[i].start%60);
        printf("%.0f\n",round((player[i].start-player[i].arrive)/60.0));
    }
    for(int i=1;i<=k;i++){
        printf("%d",table[i].num);
        if(i!=k) printf(" ");
    }

}
