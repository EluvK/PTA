#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define INF 0x3fffffff
using namespace std;

int san[110];
int n,m,k;
vector<int> res[110];
struct info{
    int num;
    int r;
    int ge,gi;
    vector<int> ap;
}s[40010];

bool cmp(info a,info b){
    if(a.gi+a.ge!=b.ge+b.gi) return a.gi+a.ge>b.ge+b.gi;
    else return a.ge>b.ge;
}
void getrank(int n){
    for(int i=0;i<n;i++){
        if(i==0) s[i].r=1;
        else if(s[i].ge==s[i-1].ge&&s[i].gi==s[i-1].gi) s[i].r=s[i-1].r;
        else s[i].r=i+1;
    }
}
int getlast(int ranknum){
    int i=ranknum;
    for(;i<n;i++){
        if(s[i].r!=s[ranknum].r) break;
    }
    return i-1;
}
void range(int n){
//    printf("%d\n",n);
    int i;
    for(i=0;i<k;i++){
        int app=s[n].ap[i];
        if(res[app].size()<san[app]){
            res[app].push_back(s[n].num);
            break;
        }
    }
}
void mutlirange(int start,int end){
//    printf("%d-%d\n",start,end);
    int f=-1;
    int j;
    vector<int> toarrange;
    for(int i=start;i<=end;i++){
        for(j=0;j<k;j++){
            int app=s[i].ap[j];
            if(res[app].size()<san[app]){
                toarrange.push_back(app);
                break;
            }
        }
        if(j==k) toarrange.push_back(f);
    }

    for(int i=start;i<=end;i++){
        if(toarrange[i-start]!=-1);
        res[toarrange[i-start]].push_back(s[i].num);
    }
}
int main(){
//    freopen("1.txt","r",stdin);

    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        scanf("%d",&san[i]);
    }
    for(int i=0;i<n;i++){
        s[i].num=i;
        s[i].ap.resize(k);
        scanf("%d%d",&s[i].ge,&s[i].gi);
        for(int j=0;j<k;j++){
            scanf("%d",&s[i].ap[j]);
        }
    }
    sort(s,s+n,cmp);
    getrank(n);

    for(int i=0;i<n;i++){
        if(s[i].r!=s[i+1].r) range(i);
        else{
            int j=getlast(i);
            mutlirange(i,j);
            i=j;
        }
    }
    for(int i=0;i<m;i++){
        sort(res[i].begin(),res[i].end());
        for(int j=0;j<res[i].size();j++){
            printf("%d%c",res[i][j],j==res[i].size()-1?'\n':' ');
        }
        if(res[i].size()==0) printf("\n");
    }
}


