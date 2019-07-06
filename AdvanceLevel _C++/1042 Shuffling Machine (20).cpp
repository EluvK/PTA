#include<stdio.h>
#include<algorithm>

using namespace std;

struct card{
	char J;
	int jnum;
	int next;
	int index;	
}A[55];

char getchar(int i){
	switch(i){
		case 0: return 'S';
		case 1: return 'H';
		case 2: return 'C';
		case 3: return 'D';
	}
}
int main(){
	// freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<4;i++){
		for(int j=1;j<=13;j++){
			A[13*i+j].J=getchar(i);
			A[13*i+j].jnum=j;
			scanf("%d",&A[13*i+j].next);
		}
	}
	for(int i=1;i<55;i++){
		A[i].index=0;
	}
	A[53].J='J';
	A[53].jnum=1;
	A[54].J='J';
	A[54].jnum=2;
	scanf("%d%d",&A[53].next,&A[54].next);	
	
	int start=1;
	
//	for(int in=1;in<=54;in++){
//		if(A[start].index==0){
//			A[start].index=in;
//			printf("A[%d]=%d,search(%d)\n",start,in,A[start].next);
//			start=A[start].next;
//		}
//		else{
//			for(int i=1;i<55;i++){
//				if(A[i].index==0){
//					start=i;
//					printf("research to %d",i);
//					in--;
//					break;
//				}
//			}
//		}
//		
//	}
//	for(int i=1;i<=54;i++){
//		printf("%d:%c%d %d %d\n",i,A[i].J,A[i].jnum,A[i].next,A[i].index); 
//	}
	char temp[55];
	int tempnum[55];
	for(int N=0;N<n;N++){
		for(int i=1;i<55;i++){
			temp[A[i].next]=A[i].J;
			tempnum[A[i].next]=A[i].jnum;
		}
		for(int i=1;i<55;i++){
			A[i].J=temp[i];
			A[i].jnum=tempnum[i];
		}	
	}
	
	for(int i=1;i<54;i++){
		printf("%c%d ",A[i].J,A[i].jnum);
	}
	printf("%c%d",A[54].J,A[54].jnum);
	
	return 0;
	
	
}

