#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
vector<int> f[1001]; //f[i] means i follower list.
vector<int> v;//visited
vector<int> l;//level
void bfs(int start,int maxlevel){
    queue<int> q;
    int num=0;
    l[start]=0;
    q.push(start);
    v[start]=1;
    while(!q.empty()){
        int temp=q.front();
        q.pop();num++;
        for(int i=0;i<f[temp].size();i++){
            if(l[temp]<maxlevel&&v[f[temp][i]]==0){
                v[f[temp][i]]=1;
                l[f[temp][i]]=l[temp]+1;
                q.push(f[temp][i]);
            }
        }
    }
    printf("%d\n",num-1);
}

int main(){
//    freopen("1.txt","r",stdin);
    int N,L,num,temp;
    scanf("%d%d",&N,&L);

    v.resize(N);
    l.resize(N);
    for(int i=1;i<=N;i++){
        scanf("%d",&num);
        for(int j=0;j<num;j++){
            scanf("%d",&temp);
            f[temp].push_back(i);
        }
    }

    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d",&temp);
        for(int j=1;j<=N;j++){
            v[j]=0;l[j]=0;
        }
        bfs(temp,L);
    }
}
