#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#define MAX 2147483647
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	int c,p;
	int arrc[100010]={0};
	int arrp[100010]={0};
	int sum=0;
	scanf("%d",&c);
	for(int i=0;i<c;i++){
		scanf("%d",&arrc[i]);
	}
	scanf("%d",&p);
	for(int i=0;i<p;i++){
		scanf("%d",&arrp[i]);
	}
	sort(arrc,arrc+c);
	sort(arrp,arrp+p);
	
	int i=0,j=0;
	while(i<c&&j<p&&arrc[i]<0&&arrp[j]<0){
		sum+=arrc[i]*arrp[j];
		i++;j++;
	} 
	i=c-1;j=p-1;
	while(i>=0&&j>=0&&arrc[i]>0&&arrp[j]>0){
		sum+=arrc[i]*arrp[j];
		i--;j--;
	}
	
	printf("%d",sum);
	return 0;
} 
