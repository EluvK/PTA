#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;
int sz,n,m,temp;
vector<int> hashtable;

int searchhash(int n){
    int i=0,cnt=0;
    while(i<=sz){
        int mod=(n+i*i)%sz;
        cnt++;
        if(hashtable[mod]==n||hashtable[mod]==0) break;
        i++;
    }
    return cnt;
}

void hashrange(int n){
    bool flag=false;
    for(int i=0;i<=sz;i++){
        int mod=(n+i*i)%sz;
        if(hashtable[mod]==0){
            hashtable[mod]=n;
            flag=true;
            break;
        }
    }
    if(!flag) printf("%d cannot be inserted.\n",n);
    return;
}

bool isprime(int n){
    if(n==2||n==3) return true;
    if(n==1) return false;
    for(int i=2;i<=(int)sqrt(n*1.0)+1;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
//    freopen("1.txt","r",stdin);
    int sum=0;
    scanf("%d%d%d",&sz,&n,&m);
    while(!isprime(sz)) sz++;
    hashtable.resize(sz);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        hashrange(temp);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&temp);
        sum+=searchhash(temp);
    }
    printf("%.1f",sum*1.0/m);
    return 0;
}
