#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

struct info{
	char name[10];
	int h;
	int r;
	int rank;
}a[20000];

bool cmp(info a,info b){
	if(a.h!=b.h) return a.h>b.h;
	else return strcmp(a.name,b.name)<0;
}
bool cmp2(info a,info b){
	if(a.r!=b.r) return a.r<b.r;
	else return a.rank<b.rank; 
}
int cal(int mid,int i){
	if(i==0) return mid;
	else return (i+1)/2*pow(-1,i)+mid;
}
int main(){
//	freopen("1.txt","r",stdin);
	int n,r,rnum,first,mid;
	scanf("%d%d",&n,&r);
	for(int i=0;i<n;i++){
		scanf("%s%d",a[i].name,&a[i].h);
	}
	sort(a,a+n,cmp);
	first=n-(n/r)*(r-1);
	rnum=n/r;
	mid=first/2+1;
	for(int i=0;i<first;i++){
		a[i].r=1;
		a[i].rank=cal(mid,i);
	}	
	

	mid=rnum/2+1;
	for(int i=0;i<rnum;i++){
		a[first+i].rank=cal(mid,i);
		a[first+i].r=2;
	}
	for(int j=3;j<=r;j++){
		for(int i=0;i<rnum;i++){
			a[first+(j-2)*rnum+i].rank=a[first+i].rank;
			a[first+(j-2)*rnum+i].r=j;
		}
	}

	sort(a,a+n,cmp2);
	
	for(int i=0;i<n-1;i++){
		printf("%s%c",a[i].name,a[i].r==a[i+1].r?' ':'\n');
	}
	printf("%s",a[n-1].name);
	return 0;

}
