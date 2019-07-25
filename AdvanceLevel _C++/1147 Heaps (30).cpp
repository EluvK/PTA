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

int tree[1010];
void postorder(int start,int mx){
    if(start>mx) return;
    postorder(2*start,mx);
    postorder(2*start+1,mx);
    printf("%d%c",tree[start],start==1?'\n':' ');
}
int main(){
    freopen("1.txt","r",stdin);

    int m,n;scanf("%d%d",&m,&n);
    bool notheapflag;
    for(int i=0;i<m;i++){
        notheapflag=false;
        for(int j=1;j<=n;j++){
            scanf("%d",&tree[j]);
        }
        if(tree[1]>tree[2]){
            //possible max heap;
            for(int k=1;k<=(n+1)/2;k++){
                if((2*k<=n&&tree[k]<tree[2*k])||(2*k+1<=n&&tree[k]<tree[2*k+1])) notheapflag=true;
                if(notheapflag) break;
            }
            if(!notheapflag) printf("Max Heap\n");
        }else{
            //possible min heap;
             for(int k=1;k<=(n+1)/2;k++){
                if((2*k<=n&&tree[k]>tree[2*k])||(2*k+1<=n&&tree[k]>tree[2*k+1])) notheapflag=true;
                if(notheapflag) break;
            }
            if(!notheapflag) printf("Min Heap\n");
        }
        if(notheapflag) printf("Not Heap\n");
        postorder(1,n);
    }
}
