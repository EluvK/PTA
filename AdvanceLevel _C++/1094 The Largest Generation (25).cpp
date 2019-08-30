#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    vector<int> l(n+1,0),p[n+1];
    int res[101]={0};
    int a,num,b;
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&num);
        for(int j=0;j<num;j++){
            scanf("%d",&b);
            p[a].push_back(b);
        }
    }
    queue<int> q;
    q.push(1);
    l[1]=1;
    res[1]=1;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        for(int i=0;i<p[f].size();i++){
            int nxt=p[f][i];
            q.push(nxt);
            l[nxt]=l[f]+1;
            res[l[nxt]]++;
        }
    }
    int mxi=1,mx=1;
    for(int i=1;i<101;i++){
        if(res[i]>mx){
            mxi=i;
            mx=res[i];
        }
    }
    printf("%d %d",mx,mxi);
}
