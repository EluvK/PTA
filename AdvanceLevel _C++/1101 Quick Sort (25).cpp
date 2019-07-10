#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	int ori[100010];
	int leftmax[100010];
	int rightmin[100010];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&ori[i]);
		if(i==0) leftmax[0]=ori[0];
		else leftmax[i]=ori[i]>leftmax[i-1]?ori[i]:leftmax[i-1];
	}
	for(int i=n-1;i>=0;i--){
		if(i==n-1){
			rightmin[i]=ori[i];
		}
		else rightmin[i]=ori[i]<rightmin[i+1]?ori[i]:rightmin[i+1];
	}
	int sum=0,firstflag=1,firsti;
	for(int i=0;i<n;i++){
		if(ori[i]>=leftmax[i]&&ori[i]<=rightmin[i]){
			sum++;
			if(firstflag){
				firsti=i;firstflag=0;
			}
		}
	}	
	printf("%d\n",sum);
	if(sum){
		printf("%d",ori[firsti]);
	}
	if(sum>1){
		for(int i=firsti+1;i<n;i++){
			if(ori[i]>=leftmax[i]&&ori[i]<=rightmin[i]){
				printf(" %d",ori[i]);	
			}	
		}	
	}
	if(sum==0) printf("\n");
	
	return 0;
}
