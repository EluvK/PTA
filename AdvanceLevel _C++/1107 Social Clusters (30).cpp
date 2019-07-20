#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
//    freopen("1.txt","r",stdin);

    int n,num,temp;
    char c;

    scanf("%d",&n);
    map<int,int>mp;
    vector<int> q[1001];
    vector<int> qnum;

    int in=1;

    qnum.resize(n+1);
    for(int i=0;i<=n;i++){
        qnum[i]=0;
    }
    for(int i=0;i<n;i++){
        scanf("%d%c",&num,&c);
        for(int j=0;j<num;j++){
            scanf("%d",&temp);
            if(mp[temp]==0){
                mp[temp]=in;
                q[in].push_back(temp);
            }else{
                q[in].push_back(temp);
                int thatq=mp[temp];
                for(vector<int>::iterator it=q[thatq].begin();it!=q[thatq].end();it++){
                    q[in].push_back(*it);
                    mp[*it]=in;
                }
                qnum[in]+=qnum[thatq];
                q[thatq].clear();
                vector<int>().swap(q[thatq]);
                qnum[thatq]=0;
            }
        }
        qnum[in]++;
        in++;
    }
    sort(qnum.begin(),qnum.end(),cmp);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(qnum[i]!=0) cnt++;
        else break;
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%d",qnum[i]);
        if(i!=cnt-1) printf(" ");
    }

}
