#include <stdio.h>
#include <string.h>

void process(int num){
	int len=0;//Êý×Ö¸öÊý 
	int f=0;//0->+ 1->-
	if(num<0) f=1;
	if(f) num*=-1;
	int temp=num;
	while(temp){
		len++;
		temp/=10;
	}
	if(f) printf("-");
	char arr[12]={'\0'};
	int count=0;
	int flag=0;
	while(num){
		if(flag!=3){	
			arr[count]=char(num%10+48);
			num/=10;
			flag++;
			count++;
		}
		else{
			flag=0;
			arr[count]=',';
			count++;
			len++;
		} 
	}
	for(int i=len-1;i>=0;i--){
		printf("%c",arr[i]);
	}
}

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int sum=a+b;
	if(!sum){
		printf("0");
	}else	
		process(sum); 
	return 0;
} 

