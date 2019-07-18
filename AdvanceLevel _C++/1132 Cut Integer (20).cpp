#include <stdio.h>
#include <iostream>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;

int callen(long long a){
	int res=0;
	while(a){
		res++;
		a/=10;
	}
	return res;
}

int main(){
//	freopen("1.txt","r",stdin);
	int n,len;
	long long num,a,b,sum;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&num);
		len=callen(num);
		
		b=num%(long long)pow(10,len/2);
		a=num/(long long)pow(10,len/2);
//		printf("%lld %lld\n",a,b);
		sum=a*b;
		if(sum!=0&&num%sum==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
	
}

