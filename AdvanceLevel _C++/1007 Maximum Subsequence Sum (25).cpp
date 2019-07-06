#include <stdio.h>

int main(){
	
	int K;
	scanf("%d",&K);

	int N[K]={0};
	int flag=0;//all nagetive tag
	int max=0;
	int temp=0;
	int ii,jj;
	ii=0;jj=K-1;
	int sum[K]={0};//0-iµÄºÍ 
	scanf("%d",&N[0]);
	
	if(N[0]>0) flag=1;
	sum[0]=N[0];
	for(int i=1;i<K;i++){
		scanf("%d",&N[i]);
		if(N[i]>0) flag=1;
		sum[i]=N[i]+sum[i-1];
	} 
	int noprintf=0;
	if(!flag){
		for(int i=0;i<K;i++){
			if(N[i]==0){
				printf("0 %d %d",N[i],N[i]);
				noprintf=1;
				break;
			} 
		}
		if(!noprintf){
			printf("0 %d %d",N[0],N[K-1]);
		}
	}
	else{
		for(int len=1;len<=K;len++){
			for(int begini=0;begini<=K-len;begini++){
				if(begini){
					temp=temp-N[begini-1]+N[begini-1+len];
					if(temp>=max){
						if(temp==max){if(begini<ii){ii=begini;jj=begini+len-1;}}
						else{max=temp;ii=begini;jj=begini+len-1;}
					}
				}
				else{//begini=0
					temp=sum[len-1];
					if(temp>=max){
						if(temp==max){if(begini<ii){ii=begini;jj=begini+len-1;}}
						else{max=temp;ii=begini;jj=begini+len-1;}
					}
				}
			}
		}
		printf("%d %d %d",max,N[ii],N[jj]); 
	}
	
	
	
	
	
	return 0;
	
}

