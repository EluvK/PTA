#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

struct rat{
	long long num;
	long long den;
}A[120];

rat change(string str){
	long long num=0,den=0;
	rat sum;
	bool minus=false;
	int i;
	if(str[0]=='-') minus=true;
	for(i=0;i<str.length();i++){
		char temp=str[i];
		if(temp=='/') break;
		if(temp!='-'){
			num=num*10+temp-'0';
		}
	}
	for(;i<str.length();i++){
		char temp=str[i];
		if(temp!='/'){
			den=den*10+temp-'0';
		}
	}
	if(minus) num*=-1;
	sum.den=den;
	sum.num=num;
	return sum;
	
}

rat add(rat a,rat b){
	rat res;
	res.den=a.den*b.den;
	res.num=a.num*b.den+b.num*a.den;
	return res;
}

void output(rat a){
	if(a.num<0){
		printf("-");
		a.num*=-1;
	}
	if(a.num==0){
		printf("0");
		return;
	}
	if(a.num>a.den){
		printf("%lld",a.num/a.den);
		a.num=a.num%a.den;
		if(a.num!=0){
			printf(" ");
		} 
	}
	if(a.num!=0){
		int i=2;
		while(i<=a.num){
			if(a.num%i==0&&a.den%i==0){
				a.num/=i;
				a.den/=i;
			}else{
				i++;
			}
		}
		printf("%lld/%lld",a.num,a.den);
	}
}
void range(rat &a){
	int i=2;
	bool minus=false;
	if(a.num<0){
		 minus=true;
		 a.num*=-1;
	}
	while(i<=a.num){
		if(a.num%i==0&&a.den%i==0){
			a.num/=i;
			a.den/=i;
		}else{
			i++;
		}
	}
	if(minus){
		a.num*=-1;
	}
}

int main(){
//	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	string arr[120];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		A[i]=change(arr[i]);
	}
	for(int i=1;i<n;i++){
		A[0]=add(A[0],A[i]);
		range(A[0]);
	}
	output(A[0]);
	
}
