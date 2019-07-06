#include <stdio.h>

int main(){
	int maxnum[3];
	double a[3][3];
	scanf("%lf %lf %lf",&a[0][0],&a[0][1],&a[0][2]);
	scanf("%lf %lf %lf",&a[1][0],&a[1][1],&a[1][2]);
	scanf("%lf %lf %lf",&a[2][0],&a[2][1],&a[2][2]);
	double num[3]={0};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(a[i][j]>num[i]){
				maxnum[i]=j;
				num[i]=a[i][j];
			}
		}
		switch(maxnum[i]){
			case 0:printf("W ");break;
			case 1:printf("T ");break;
			case 2:printf("L ");break;
		}
	}
	double sum=1;
	for(int i=0;i<3;i++){
		sum*=num[i];
	}
	printf("%.2lf",2*(sum*0.65-1));
	return 0;
}
