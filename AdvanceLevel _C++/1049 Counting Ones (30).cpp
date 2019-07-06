#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;
int getones(int n);
int range(int len,int n); 
int callen(int n){//计算n的位数
	int count=0;
	while(n){
		count++;
		n/=10;
	}
	return count;
}

int getonesbylen(int len){
    //计算n位数内（1-9999）中1出现的个数
    //规律：
	return len*pow(10,len-1);
}

int numof(int i){
    //暴力迭代
	int len=callen(i);
	int sum=0;
	while(len--){
		if(i%10==1) sum++;
		i/=10;
	}
	return sum;
}

int getones(int n){
    //计算n以内1出现的个数；
	if(n>100){//暴力迭代的范围控制
		int len=callen(n);
		return getonesbylen(len-1)+range(len,n); 
	}
	else{
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=numof(i);
		}
		return sum;
	}
}
int range(int len,int n){
	//计算len位数字到n这个范围内1出现的个数
    //10000-23405 len=5
	int num=pow(10,len-1);//10000
	int firstnum=n/num;//2
	int leftnum=n-num*firstnum;//3495
	if(firstnum==1){
		return (leftnum)+getones(leftnum)+1;
	}
	else return num+(firstnum-1)*getonesbylen(len-1)+getones(leftnum);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",getones(n));
    return 0;
} 
