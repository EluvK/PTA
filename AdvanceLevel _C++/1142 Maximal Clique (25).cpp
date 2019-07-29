#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int g[300][300];
bool in[300];
vector<int> arr;
bool suit(int num){
    for(int i=0;i<arr.size();i++){
        int j=arr[i];
        if(g[j][num]==0) return false;
    }
    return true;
}

bool isClique(){
    int a,b;
    for(int i=0;i<arr.size();i++){
        a=arr[i];
        for(int j=i+1;j<arr.size();j++){
            b=arr[j];
            if(g[a][b]==0) return false;
        }
    }
    return true;
}
bool isMaxC(){
    fill(in,in+300,false);
    for(int i=0;i<arr.size();i++){
        in[arr[i]]=true;
    }
    for(int i=0;i<300;i++){
        if(in[300]==false){
            if(suit(i)) return false;
        }
    }
    return true;
}
int main(){
//    freopen("1.txt","r",stdin);
    int n,m,a,b,num;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        g[a][b]=g[b][a]=1;
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&num);
        arr.clear();
        arr.resize(num);
        for(int j=0;j<num;j++){
            scanf("%d",&arr[j]);
        }
        if(isClique()){
            if(isMaxC()){
                printf("Yes\n");
            }else{
                printf("Not Maximal\n");
            }
        }else{
            printf("Not a Clique\n");
        }
    }

    return 0;
}
