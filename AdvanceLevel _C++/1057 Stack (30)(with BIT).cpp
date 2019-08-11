#include <stdio.h>
#include <iostream>
#include <stack>
#define lowbit(i) ((i)&(-i))
using namespace std;
const int maxn=100010;
int c[maxn];
stack<int> s;
void update(int x,int v){
    for(int i=x;i<maxn;i+=lowbit(i))
        c[i]+=v;
}
int getsum(int x){
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i))
        sum+=c[i];
    return sum;
}
void peekmedian(){
    int left=1,right=maxn,mid,k=(s.size()+1)/2;
    while(left<right){
        mid=(left+right)/2;
        if(getsum(mid)>=k)
            right=mid;
        else left=mid+1;
    }
    printf("%d\n",left);
}
int main(){
//    freopen("1.txt","r",stdin);
    int n,temp;
    scanf("%d",&n);
    char cmd[15];
    for(int i=0;i<n;i++){
        scanf("%s",cmd);
        if(cmd[1]=='u'){
            scanf("%d",&temp);
            s.push(temp);
            update(temp,1);
        }else if(cmd[1]=='o'){
            if(!s.empty()){
                update(s.top(),-1);
                printf("%d\n",s.top());
                s.pop();
            }else printf("Invalid\n");
        }else{
            if(!s.empty()) peekmedian();
            else printf("Invalid\n");
        }
    }
}
