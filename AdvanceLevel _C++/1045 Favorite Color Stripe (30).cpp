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

int main(){
//    freopen("1.txt","r",stdin);

    int n,num,temp;
    vector<int> wtd,given;
    scanf("%d",&n);
    scanf("%d",&num);
    int flag[200];
    int book[200];
    fill(flag,flag+200,-1);
    for(int i=1;i<=num;i++){
        scanf("%d",&temp);
        wtd.push_back(temp);
        book[temp]=i;
        flag[temp]=0;
    }
    int cnt=0;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&temp);
        if(flag[temp]==0){
            given.push_back(temp);
            cnt++;
        }
    }

    int maxnum[20000]={0};
    for(int i=0;i<cnt;i++){
        num=given[i];
        int bound=book[num];
        for(int j=0;j<bound;j++){
            maxnum[num]=max(maxnum[num],maxnum[wtd[j]]);
        }

        maxnum[num]++;
    }
    int res=0;
    for(int i=0;i<wtd.size();i++){
        if(maxnum[wtd[i]]>res) res=maxnum[wtd[i]];
    }
    printf("%d",res);

}
