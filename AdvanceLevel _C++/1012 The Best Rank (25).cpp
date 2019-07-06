#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define MAX 3000

struct studentinfo{
	char num[6];
	int C;
	int M;
	int E;
	double A;
	int rank[4];
}arr[MAX];

bool cmpC(studentinfo a,studentinfo b){
	return a.C>b.C;
}
bool cmpM(studentinfo a,studentinfo b){
	return a.M>b.M;
}
bool cmpE(studentinfo a,studentinfo b){
	return a.E>b.E;
}
bool cmpA(studentinfo a,studentinfo b){
	return a.A>b.A;
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%s %d %d %d",arr[i].num,&arr[i].C,&arr[i].M,&arr[i].E);
		arr[i].A=(arr[i].C+arr[i].M+arr[i].E)/3;
	}
	
	sort(arr,arr+N,cmpA);
	for(int i=0;i<N;i++){
		if(i==0) arr[i].rank[0]=1;
		else if(arr[i].A==arr[i-1].A){
			arr[i].rank[0]=arr[i-1].rank[0];
		}
		else arr[i].rank[0]=i+1;
	}
	sort(arr,arr+N,cmpC);
	for(int i=0;i<N;i++){
		if(i==0) arr[i].rank[1]=1;
		else if(arr[i].C==arr[i-1].C){
			arr[i].rank[1]=arr[i-1].rank[1];
		}
		else arr[i].rank[1]=i+1;
	}
	sort(arr,arr+N,cmpM);
	for(int i=0;i<N;i++){
		if(i==0) arr[i].rank[2]=1;
		else if(arr[i].M==arr[i-1].M){
			arr[i].rank[2]=arr[i-1].rank[2];
		}
		else arr[i].rank[2]=i+1;
	}
	sort(arr,arr+N,cmpE);
	for(int i=0;i<N;i++){
		if(i==0) arr[i].rank[3]=1;
		else if(arr[i].E==arr[i-1].E){
			arr[i].rank[3]=arr[i-1].rank[3];
		}
		else arr[i].rank[3]=i+1;
	}
	char findx[6];
	for(int i=0;i<M;i++){
		scanf("%s",findx);
		int flag=0;
		for(int j=0;j<N;j++){
			if(strcmp(arr[j].num,findx)==0){
				flag=1;
				int min=99999;
				int index=0;
				for(int k=0;k<4;k++){
					if(arr[j].rank[k]<min){
						min=arr[j].rank[k];
						index=k;
					}
				}
				printf("%d ",min);
				switch(index){
					case 0: printf("A\n");break;
					case 1: printf("C\n");break;
					case 2: printf("M\n");break;
					case 3: printf("E\n");break;
				}
				break;
			}	
		}	
		if(!flag) printf("N/A\n");
	} 
	
	
	return 0;
}

/*
2 1 
100001 90 90 90 
100002 90 90 90
100001


*/ 
