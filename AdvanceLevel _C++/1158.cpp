//未能AC 仅为保存代码
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct info{
    int a,b,d;
    info(int _a,int _b,int _d){a=_a;b=_b;d=_d;}
};

int d[1010][1010];
int num[1010];

int main(){
//    freopen("1.txt","r",stdin);
    int k,n,m;
    int a,b,dur;
    scanf("%d%d%d",&k,&n,&m);
//    vector<info> recd(m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&a,&b,&dur);
//        recd.push_back(info(a,b,dur));

        if(d[a][b]==0) num[a]++;
        d[a][b]+=dur;
    }
    vector<int> sus;
    for(int i=1;i<=n;i++){
        if(num[i]>k){
            int tempn=0,temprep=0;
            for(int j=1;j<=n;j++){
                if(d[i][j]!=0&&d[i][j]<=5){
                    tempn++;
                    if(d[j][i]!=0) temprep++;
                }
            }
            if(tempn>k&&5*temprep<=tempn) sus.push_back(i);
        }
    }
    int mxsize=sus.size();
    if(mxsize==0){
        printf("None");
        return 0;
    }
    vector<int> susgang[mxsize];
    int id=1;
    susgang[0].push_back(sus[0]);
    for(int i=1;i<sus.size();i++){
        bool bf=false;
        for(int j=0;j<id;j++){
            for(int k=0;k<susgang[j].size();k++){
                if(d[sus[i]][susgang[j][k]]!=0&&d[susgang[j][k]][sus[i]]!=0){
                    susgang[j].push_back(sus[i]);
                    bf=true;
                    break;
                }

            }
            if(bf) break;
        }
        if(!bf) susgang[id++].push_back(sus[i]);
    }

    for(int i=0;i<id;i++){
        for(int j=0;j<susgang[i].size();j++){
            printf("%d%c",susgang[i][j],j==susgang[i].size()-1?'\n':' ');
        }
    }
//    for(int i=0;i<sus.size();i++){
//        printf("%d ",sus[i]);
//    }
}
