#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	int n;
	long long p;
	long long arr[100010];
	scanf("%d%lld",&n,&p);
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	sort(arr,arr+n);
	int max=0,temp=0;
	for(int i=0;i<n;i++){
		for(int j=i+max;j<n;j++){
			if(arr[j]<=arr[i]*p){
				temp=j-i+1;
				if(temp>max){
					max=temp;
				}
			}else{
				break;
			}
		}
	}
	
	printf("%lld",max);
	return 0;
}
