#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct mooncake{
	double amount;
	double sell;
	double price;
}A[1010]; 

bool cmp(mooncake a,mooncake b){
	return a.price>b.price;
}
int main(){
//	freopen("1.txt","r",stdin);
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%lf",&A[i].amount);	
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&A[i].sell);
		A[i].price=A[i].sell/A[i].amount;
	}
	sort(A,A+n,cmp);
	double sum=0;
	int i=0;
	while(d){
		if(A[i].amount>=d){
			sum+=A[i].price*d;
			d=0;
		}
		else{
			sum+=A[i].sell;
			d-=A[i].amount;
		}
		if(i<n) i++;
		else break;
	}
	printf("%.2f",sum);
	return 0;
}
