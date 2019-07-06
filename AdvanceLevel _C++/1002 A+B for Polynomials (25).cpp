#include <stdio.h>
#include <math.h>
int main(){
	double coeff[1001]={0};
	int num;
	int exp;
	double coe;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d %lf",&exp,&coe);
		coeff[exp]+=coe;
	}
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d %lf",&exp,&coe);
		coeff[exp]+=coe;
	}
	int shownum=0;
	for(int i=0;i<1001;i++){
		if(fabs(coeff[i]-0.0)>10e-5){
			shownum++;
		}
	}
	printf("%d",shownum);
	if(shownum){
		for(int i=1000;i>=0;i--){
			if(fabs(coeff[i]-0.0)>10e-5){
				printf(" %d %.1f",i,coeff[i]);
			}
		}
	}
	
	return 0;
	
} 

