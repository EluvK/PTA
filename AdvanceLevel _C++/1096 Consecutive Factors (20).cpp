#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
	long long n;
	scanf("%lld",&n);
	long long max=0,maxi=2;
	for(long long i=2;i<sqrt(n);i++){
		long long temp=1,j=i;
		while(1){
			temp*=j;
			if(n%temp!=0) break;
			if(j-i+1>max){
				max=j-i+1;
				maxi=i; 
			}
			j++;
		}
	}
	
	if(max==0){
		printf("1\n%lld",n);
	}else{
		printf("%lld\n",max);
		for(long long i=maxi;i<maxi+max;i++){
			printf("%lld%c",i,i==maxi+max-1?'\n':'*');
		}
	}
	return 0;
	


}
