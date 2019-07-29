#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> arr[100010];
int k[1010];

bool check(int j,int l){
    if(arr[l].size()<arr[j].size()){
        for(int i=0;i<arr[l].size();i++){
            if(arr[l][i]==j) return true;
        }
    }else{
       for(int i=0;i<arr[j].size();i++){
            if(arr[j][i]==l) return true;
        }
    }
    return false;
}

int main(){
//    freopen("1.txt","r",stdin);
    int n,m,num,cnt,a,b;
    bool flag;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&num);
        flag=true;
        for(int j=0;j<num;j++){
            scanf("%d",&k[j]);
        }
        for(int j=0;j<num;j++){
            for(int l=j+1;l<num;l++){
                if(check(k[j],k[l])){
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
}
