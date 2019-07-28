#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
int pre[50];
int post[50];
vector<int> ans;

bool check(int preL,int preR,int postL,int postR){

    if(preL>preR) return false;
    if(preL==preR){
//        printf("%d ",pre[preL]);//left right
        ans.push_back(pre[preL]);
        return true;
    }
    int i;
    for(i=preL+1;i<preR;i++){
        if(pre[i]==post[postR-1]) break;
    }
    //×ó×ÓÊ÷preL+1,i-1,postL,postL+i-1-preL-1
    //ÓÒ×ÓÊ÷i,preR,postR-1-preR+i,postR-1
    bool res=true;
    res=res&check(preL+1,i-1,postL,postL+i-1-preL-1);
//    printf("%d ",pre[preL]);//root
    ans.push_back(pre[preL]);
    res=res&check(i,preR,postR-1-preR+i,postR-1);

    return res;
}


int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&pre[i]);
    for(int i=1;i<=n;i++) scanf("%d",&post[i]);
    if(check(1,n,1,n)) printf("Yes\n");
    else printf("No\n");
    for(int i=0;i<ans.size();i++){
        printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    return 0;
}
