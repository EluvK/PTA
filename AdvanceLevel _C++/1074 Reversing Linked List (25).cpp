#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
struct node{
    int index;
    int adress;
    int data;
    int next;
}A[100010];

bool cmp(node a,node b){
    return a.index<b.index;
}

int main(){
//    freopen("1.txt","r",stdin);
    int start,n,k;
    scanf("%d%d%d",&start,&n,&k);
    int book[100010]={0};
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&A[i].adress,&A[i].data,&A[i].next);
        book[A[i].adress]=i;
        A[i].index=100001;
    }
    int in=1;
    while(start!=-1){
        A[book[start]].index=in++;
        start=A[book[start]].next;
    }
    sort(A,A+n,cmp);
    n=in-1;
    int rt=n/k;
    for(int i=0;i<rt;i++){
        for(int j=0;j<k/2;j++){
            swap(A[i*k+j].index,A[i*k+k-j-1].index);
        }
    }

    sort(A,A+n,cmp);
    for(int i=0;i<n-1;i++){
        printf("%05d %d %05d\n",A[i].adress,A[i].data,A[i+1].adress);
    }
    printf("%05d %d -1",A[n-1].adress,A[n-1].data);

}
