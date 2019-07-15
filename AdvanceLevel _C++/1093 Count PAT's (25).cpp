#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	int p[100010]={0};
	int t[100010]={0};
	char temp;
	string str;
	cin>>str;
	if(str[0]=='P'){
		p[0]=1;
	}else if(str[0]=='T'){
		t[0]=1;
	}
	
	for(int i=1;i<str.length();i++){
		if(str[i]=='P'){
			p[i]=p[i-1]+1;
			t[i]=t[i-1];
		}else if(str[i]=='T'){
			p[i]=p[i-1];
			t[i]=t[i-1]+1;
		}else{
			p[i]=p[i-1];
			t[i]=t[i-1];
		}
	}
	long long sum=0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='A'){
			sum+=p[i]*(t[str.length()-1]-t[i]);
		}
	}
	sum%=1000000007;
	printf("%lld",sum);
}
