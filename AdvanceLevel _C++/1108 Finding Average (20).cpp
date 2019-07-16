#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	int n,num=0;
	double sum=0,temp;
	char a[50],b[50];
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%s",a);
		sscanf(a,"%lf",&temp);
		sprintf(b,"%.2f",temp);
		int flag=0;
		for(int j=0;j<strlen(a);j++){
			if(a[j]!=b[j]){
				flag=1;break;
			}
		}
		if(flag||temp<-1000||temp>1000){
			printf("ERROR: %s is not a legal number\n",a);
		}else{
			sum+=temp;
			num++; 
		}
		
	}
	if(num==1){
		printf("The average of 1 number is %.2f",sum);
	}else if(num>1){
		printf("The average of %d numbers is %.2f",num,sum/num);
	}else{
		printf("The average of 0 numbers is Undefined");
	}
	return 0;
	
	
}
