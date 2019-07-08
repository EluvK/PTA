#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <math.h>
#define MAX 2147483647
using namespace std;

int Big(int n){
	int a[4]={0};
	for(int i=0;i<4;i++){
		a[i]=n%10;
		n/=10;
	}
	sort(a,a+4);
	int res=0;
	for(int i=3;i>=0;i--){
		res*=10;
		res+=a[i];
	}
	return res;
}
int Small(int n){
	int a[4]={0};
	for(int i=0;i<4;i++){
		a[i]=n%10;
		n/=10;
	}
	sort(a,a+4);
	int res=0;
	for(int i=0;i<4;i++){
		res*=10;
		res+=a[i];
	}
	return res;
}

int main() {
//	freopen("1.txt","r",stdin);
	int n,big,small,res;
	
	scanf("%d",&n);
	big=Big(n);
	small=Small(n); 
	res=big-small;
	if(res==0){
		printf("%04d - %04d = 0000",n,n);
		return 0;
	}
	while(res!=6174){
		printf("%04d - %04d = %04d\n",big,small,res);
		small=Small(res);
		big=Big(res);
		res=big-small;
	}
	printf("%04d - %04d = %04d\n",big,small,res);	
}
