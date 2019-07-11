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

using namespace std;

long long any2dec(string c,long long radix){
	long long sum=0;
	int index=0,temp=0;
	for(int i=c.length()-1;i>=0;i--){
		temp=isdigit(c[i])?c[i]-'0':c[i]-'a'+10;
		sum+=temp*pow(radix,index++); 
	}
	return sum;
}
long long findradix(string c,long long n){
	char it=*max_element(c.begin(),c.end());//最大元素max_element返回的是迭代器。
	long long low=(isdigit(it)?it-'0':it-'a'+10)+1;//最小进制要比最大元素大1；
	long long high=max(n,low);
	while(low<=high){
		long long mid=(low+high)/2;
		long long t=any2dec(c,mid);
		if(t<0||t>n) high=mid-1;//t<0;转换的进制溢出，也是大于n 
		else if(t==n) return mid;
		else low=mid+1;
	} 
	return -1;
}

int main(){
	long long tag,radix,result;
	string n1,n2,temp;
	cin>>n1>>n2>>tag>>radix;
	if(tag==2){
		temp=n1;
		n1=n2;
		n2=temp;
	}
	result=findradix(n2,any2dec(n1,radix));
	if(result==-1){
		printf("Impossible");
	}
	else printf("%lld",result);
	
	return 0;	
} 
