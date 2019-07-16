#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	printf("%d",n%2);
	vector<long long> a;
	for(int i=0;i<n;i++){
		long long temp;
		scanf("%lld",&temp);
		a.push_back(temp);
	} 
	sort(a.begin(),a.end());
	long long sum1=0,sum2=0;
	for(int i=0;i<n/2;i++){
		sum1+=a[i];
	}
	for(int i=n/2;i<n;i++){
		sum2+=a[i];
	}
	printf(" %lld",sum2-sum1);
	return 0;
}
