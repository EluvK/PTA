#include<stdio.h>
#include<iostream>
#include<cctype>
#include<algorithm>
#include<string.h>
#include<string> 
#include<math.h>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;

bool isprime(long long num){
	if(num==2) return true;
	if(num==1||num==0) return false;
	long long max=(long long)sqrt(num*1.0)+1;
	for(int i=2;i<max;i++){
		if(num%i==0) return false;
	}
	return true;
	
}

long long str2int(string s){
	long long sum=0;
	for(int i=0;i<s.length();i++){
		sum=sum*10+s[i]-'0';
	}
	return sum;
}

int main(){
//	freopen("1.txt","r",stdin);
	int L,K;
	string str,temp;
	long long num;
	cin>>L>>K>>str;	
	for(int i=0;i<=L-K;i++){
		temp=str.substr(i,K);
		num=str2int(temp);
//		printf("%05lld\n",num);
		if(isprime(num)){
//			printf("%lld",num);
			cout<<temp;
			return 0;
		}
	}
	printf("404");
	return 0;
} 
