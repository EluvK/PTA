#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int visited[20000]={0};
int weight[20000]={0};

vector<int> res[20000];
vector<int> ressum;
struct node{
    int v;
    int w;
    node(int _v,int _w){v=_v;w=_w;}
};

struct resnode{
    int i;
    int num;
    resnode(int _i,int _num){i=_i;num=_num;}
};

vector<node> adj[20000];

int cg(string a){
    int sum=0;
    sum=a[0]-'A';
    sum=sum*26+a[1]-'A';
    sum=sum*26+a[2]-'A';
    return sum;
}
void print(int i){
    char res[6];
    res[0]=i/26/26+'A';
    res[2]=i%26+'A';
    res[1]=i/26%26+'A';
    res[3]='\0';
    printf("%s",res);
}
int dfs(int i,int resnum){
    int sum=0;
    visited[i]=1;
    res[resnum].push_back(i);
    for(int j=0;j<adj[i].size();j++){
        node next=adj[i][j];
        weight[i]+=next.w;
        sum+=next.w;
        if(visited[next.v]==0){
            sum+=dfs(next.v,resnum);
        }
    }
    return sum;
}
bool cmp(resnode a,resnode b){
    return a.i<b.i;
}
int main(){
//    freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);

    string a,b;
    int temp;
    for(int i=0;i<n;i++){
        cin>>a>>b>>temp;
        adj[cg(a)].push_back(node(cg(b),temp));
        adj[cg(b)].push_back(node(cg(a),temp));
    }
    int resnum=0;
    for(int i=0;i<20000;i++){
        if(adj[i].size()!=0&&visited[i]==0){
            ressum.push_back(dfs(i,resnum));
            resnum++;
        }
    }

    int cnt=0;
    vector<resnode> r;
    int max,maxi;

    for(int i=0;i<resnum;i++){
        max=-1;
        for(int j=0;j<res[i].size();j++){
            if(weight[res[i][j]]>max){
                max=weight[res[i][j]];
                maxi=res[i][j];
            }
        }
        if(ressum[i]/2>k&&res[i].size()>2){
            r.push_back(resnode(maxi,res[i].size()));
//            r.push_back(maxi);
//            r2.push_back(res[i].size());
            cnt++;
        }
    }
    sort(r.begin(),r.end(),cmp);

    printf("%d\n",cnt);
    for(int i=0;i<r.size();i++){
        print(r[i].i);
        printf(" %d\n",r[i].num);
    }
    return 0;

}
