#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	double temp,sum=0;
	for(int i=1;i<=n;i++){
		scanf("%lf",&temp);
		sum+=temp*i*(n+1-i);//temp����i��n+1-i�����п������. 
	}
	printf("%.2f",sum);
}
