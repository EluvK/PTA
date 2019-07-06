#include <stdio.h>
#include <math.h>

int main(){
	double A[1100]={0};
	double B[1100]={0};
	double R[3000]={0};
	int scannum;
	int scanexp;
	scanf("%d",&scannum);
	for(int i=0;i<scannum;i++){
		
		scanf("%d",&scanexp);
		scanf("%lf",&A[scanexp]);
	}
	scanf("%d",&scannum);
	for(int i=0;i<scannum;i++){
		
		scanf("%d",&scanexp);
		scanf("%lf",&B[scanexp]);
	}
	
//	int maxexpA=0,maxexpB=0;
//	for(int i=0;i<1050;i++){
//		if(A[i]>maxexpA) maxexpA=i;
//		if(B[i]>maxexpB) maxexpB=i;
//	}
//	//乘积最大系数；
//	
//	int maxexpR=maxexpA+maxexpB;
//	int expa,expb;
//	
//	R[maxexpR]=A[maxexpA]*B[maxexpB];
	for(int i=0;i<1002;i++){
		for(int j=0;j<1002;j++){
			if(A[i]&&B[j]){
				R[i+j]+=A[i]*B[j];
			}
		}
	}
//	for(int i=2002;i>=0;i--){
//		for(expa=0;expa<2002;expa++){
//			expb=i-expa;
//			if(A[expa]&&B[expb]){
//				R[i]+=A[expa]*B[expb];
//			}
//		}
//	} 
	
	//输出
	int numR=0;
	for(int i=2000;i>=0;i--){
		if(R[i]!=0.0) numR++; 
	}
	
	printf("%d",numR);
	for(int i=2000;i>=0;i--){
		if(fabs(R[i])>10e-2){
			printf(" %d %.1f",i,R[i]);
		}
	} 
	
	
	return 0;
	
}

