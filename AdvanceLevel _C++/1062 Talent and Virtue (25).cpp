#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <math.h>
#define MAX 2147483647
using namespace std;

struct info{
	int id,vg,tg,all,kind;//0-sages 1-noblemen
};

bool cmp(info a,info b){
	if(a.kind!=b.kind) return a.kind<b.kind;
	else if(a.all!=b.all) return a.all>b.all;
	else if(a.vg!=b.vg) return a.vg>b.vg;
	else return a.id<b.id;
}

int main(){
//	freopen("1.txt","r",stdin);
	int N,L,H,a,b,c,i=0; 
	info A[100010];
	scanf("%d%d%d",&N,&L,&H);
	
	for(int j=0;j<N;j++){
		scanf("%d%d%d",&a,&b,&c);
		if(b>=L&&c>=L){
			A[i].id=a;A[i].vg=b;A[i].tg=c;A[i].all=b+c;
			if(b>=H&&c>=H) A[i].kind=0;
			else if(b>=H&&c<H) A[i].kind=1;
			else if(b<H&&c<H&&b>=c) A[i].kind=2;
			else A[i].kind=3;
			i++;
		}	
	}
	sort(A,A+i,cmp);
	printf("%d\n",i);
	for(int j=0;j<i;j++){
		printf("%08d %d %d\n",A[j].id,A[j].vg,A[j].tg);
	}
	return 0;
 } 
