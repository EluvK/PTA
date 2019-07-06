#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;
int getones(int n);
int range(int len,int n); 
int callen(int n){//����n��λ��
	int count=0;
	while(n){
		count++;
		n/=10;
	}
	return count;
}

int getonesbylen(int len){
    //����nλ���ڣ�1-9999����1���ֵĸ���
    //���ɣ�
	return len*pow(10,len-1);
}

int numof(int i){
    //��������
	int len=callen(i);
	int sum=0;
	while(len--){
		if(i%10==1) sum++;
		i/=10;
	}
	return sum;
}

int getones(int n){
    //����n����1���ֵĸ�����
	if(n>100){//���������ķ�Χ����
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
	//����lenλ���ֵ�n�����Χ��1���ֵĸ���
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
