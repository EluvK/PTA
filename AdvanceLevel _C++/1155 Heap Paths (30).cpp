#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;

int n,in=0;
vector<int> arr,temp,res[10000];
bool flag;
void dfs(int s){
    if(2*s>n){
        temp.push_back(arr[s]);
        res[in++]=temp;
        temp.pop_back();
        return;
    }

    temp.push_back(arr[s]);

    if(2*s+1<=n) dfs(2*s+1);
    dfs(2*s);
    temp.pop_back();
}

int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    arr.resize(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    dfs(1);
    for(int i=0;i<in;i++){
        for(int j=0;j<res[i].size();j++){
            printf("%d%c",res[i][j],j==res[i].size()-1?'\n':' ');
        }
    }
    flag=true;
    if(res[0][0]>res[0][1]){
        for(int i=0;i<in;i++){
            for(int j=1;j<res[i].size();j++){
                if(res[i][j]>res[i][j-1]){
                    flag=false;
                    break;
                }
            }
        }
    }else{
       for(int i=0;i<in;i++){
            for(int j=1;j<res[i].size();j++){
                if(res[i][j]<res[i][j-1]){
                    flag=false;
                    break;
                }
            }
        }
    }
    if(res[0][0]>res[0][1]&&flag){
        printf("Max Heap");
    }else if(res[0][0]<res[0][1]&&flag){
        printf("Min Heap");
    }else printf("Not Heap");
    return 0;
}
