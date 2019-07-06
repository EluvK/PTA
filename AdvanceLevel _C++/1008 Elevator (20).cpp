#include <stdio.h>

int cal(int a,int b){
	if(a<b){
		return (b-a)*6;
	}
	else return 4*(a-b);
}

int main(){
	int sum=0;
	int a=0;
	int b=0;
	char c;
	int num=0;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d",&b);
		sum+=cal(a,b)+5;
		a=b;
	} 
	printf("%d",sum);
	
}

