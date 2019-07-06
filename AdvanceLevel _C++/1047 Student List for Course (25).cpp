#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#define MAX 100000
//freopen("1.txt","r",stdin);
using namespace std;

//struct countn{
//	int num;
//	char value[9];
//}arr[480000]; 


struct info{
	char name[6];
	int num;
	int classs[20];
}a[40002];

int countclass[2600]={0};

struct ress{
	int in;
	int result[400];
}res[40002]; 
bool cmp(info a,info b){
	return strcmp(a.name,b.name)<0;
}
int main(){
	// freopen("1.txt","r",stdin);
	
	int M,N;
	scanf("%d%d",&M,&N);
	
	for(int i=0;i<M;i++){
		scanf("%s %d",a[i].name,&a[i].num);
		for(int j=0;j<a[i].num;j++){
			scanf("%d",&a[i].classs[j]);
			countclass[a[i].classs[j]]++;
		} 
	}
	sort(a,a+M,cmp);
	int temp=0;
	int nn=0;
	for(int i=0;i<M;i++){
		for(int j=0;j<a[i].num;j++){
//			temp=a[i].classs[j];
//			nn=res[temp].in;
			res[a[i].classs[j]].result[res[a[i].classs[j]].in++]=i;
		}
	}
	
	
	for(int i=1;i<N+1;i++){
		printf("%d %d\n",i,countclass[i]);
		for(int j=0;j<countclass[i];j++){
			printf("%s\n",a[res[i].result[j]].name);
		}
//		
//		for(int j=0;j<40000;j++){
//			for(int k=0;k<a[j].num;k++)
//			if(a[j].classs[k]==i){
//				printf("%s",a[j].name);
//				printf("\n");
//			} 
//		}
	}
}
