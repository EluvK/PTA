#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

struct rat{
	long long num;
	long long den;
};
rat multi(rat a,rat b);
rat multin(rat a);
rat add(rat a,rat b);
rat minu(rat a,rat b);
rat divi(rat a,rat b);

long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}

rat range(rat a){
	rat res;
	bool m=false;
	if(a.num<0){
		m=true;
		a.num*=-1;
	}
	if(a.num==0){
		res.num=0;res.den=1;

	}else{
		long long i=gcd(a.num,a.den);
		res.num=a.num/i;
		res.den=a.den/i;
	}
	if(m) res.num*=-1; 
	return res;	
}

void print(rat a){
	if(a.num==a.den&&a.num!=0){
		printf("1");
		return;
	}
	if(a.num!=0&&a.den==0){
		printf("Inf");
		return;
	}
	if(a.num==0){
		if(a.den==0){
			printf("Inf");
			return; 
		}
		else{
			printf("0");
			return;	
		}
	}
	else if(a.num<0){
		printf("(-");
		print(multin(a));
		printf(")");
	}else if(a.num>a.den){
		printf("%d",a.num/a.den);
		if(a.num%a.den!=0){
			printf(" %d/%d",a.num%a.den,a.den);	
		}
	
	}else{
		printf("%d/%d",a.num,a.den);
	}
	return;
}

rat add(rat a,rat b){
	rat res;
	res.num=a.num*b.den+b.num*a.den;
	res.den=a.den*b.den;
	return range(res);
}
rat minu(rat a,rat b){
	rat res;
	res.num=a.num*b.den-b.num*a.den;
	res.den=a.den*b.den;
	return range(res);
}
rat multi(rat a,rat b){
	rat res;
	res.num=a.num*b.num;
	res.den=a.den*b.den;
	return range(res);
}
rat divi(rat a,rat b){
	rat res;
	if(b.num==0){
		res.num=0;
		res.den=0;
		return res;
	}
	else{
		res.num=a.num*b.den;
		res.den=a.den*b.num;
		if(res.den<0){
			res.num*=-1;
			res.den*=-1;
		}
		return range(res);
	}
}

rat multin(rat a){
	rat res;
	res.num=a.num*-1;
	res.den=a.den;
	return res;
}
int main(){
	freopen("1.txt","r",stdin);
	rat a,b;
	scanf("%lld/%lld%lld/%lld",&a.num,&a.den,&b.num,&b.den);
	a=range(a);
	b=range(b);
	print(a);printf(" + ");print(b);printf(" = ");print(add(a,b));printf("\n");
	print(a);printf(" - ");print(b);printf(" = ");print(minu(a,b));printf("\n");
	print(a);printf(" * ");print(b);printf(" = ");print(multi(a,b));printf("\n");
	print(a);printf(" / ");print(b);printf(" = ");print(divi(a,b));printf("\n");
	return 0;
}
