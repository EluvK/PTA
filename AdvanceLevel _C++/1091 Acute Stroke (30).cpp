#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 0x3fffffff
using namespace std;

int m,n,l,t;
int arr[1300][130][80];
bool vis[1300][130][80];
int X[6]={0,0,0,0,1,-1};
int Y[6]={1,-1,0,0,0,0};
int Z[6]={0,0,1,-1,0,0};
struct node{
    int x,y,z;
};

bool judge(int x,int y,int z){
    if(arr[x][y][z]==0||vis[x][y][z]==true) return false;
    if(x>=m||x<0||y<0||z<0||y>=n||z>=l) return false;
    return true;
}

int bfs(int j,int k,int i){
    int res=0;
    node temp;
    temp.x=j;temp.y=k;temp.z=i;

    queue<node> q;
    q.push(temp);
    vis[j][k][i]=true;
    while(!q.empty()){
        node now=q.front();
        q.pop();
        res++;
        for(int i=0;i<6;i++){
            int nx=now.x+X[i];
            int ny=now.y+Y[i];
            int nz=now.z+Z[i];
            if(judge(nx,ny,nz)){
                vis[nx][ny][nz]=true;
                temp.x=nx;temp.y=ny;temp.z=nz;
                q.push(temp);
            }
        }

    }
    if(res<t) return 0;
    else return res;
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d%d%d",&m,&n,&l,&t);

    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                scanf("%d",&arr[j][k][i]);
            }
        }
    }
    int res=0;
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(arr[j][k][i]==1&&vis[j][k][i]==false)
                    res+=bfs(j,k,i);
            }
        }
    }
    printf("%d",res);
    return 0;
}
