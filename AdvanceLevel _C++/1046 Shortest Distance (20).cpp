#include <stdio.h>
#include <string.h>

int main(){
	
	int N;
	scanf("%d",&N);
	int arr[N];
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	int sum=0;
	int dist0[N]={0};
	dist0[0]=0;
	sum=arr[0];
	for(int j=1;j<N;j++){
		sum+=arr[j];
		dist0[j]=dist0[j-1]+arr[j-1];

	}
	
	
	int num;
	int a,b;
	int dis1,dis2;
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		scanf("%d %d",&a,&b);
		dis1=0;dis2=0;
		
		if(a>b){int temp=a;a=b;b=temp;}
		dis1=dist0[b-1]-dist0[a-1];
		dis2=sum-dis1;
		if(dis2>dis1) printf("%d\n",dis1);
		else printf("%d\n",dis2);
	}
} 
// 1 2 3 4  5
// ` ` ` `  `
//5 1 2 4 14 9
