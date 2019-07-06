#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#define MAX 10000

using namespace std;



int main(){
//	freopen("1.txt","r",stdin);
	int ad1,ad2;
	int N;
	bool b[100005]={false};
	int next[100005]={0};

	scanf("%d%d%d",&ad1,&ad2,&N);


	for(int i=0;i<N;i++){
		char c;
		int t;
		scanf("%d",&t);
		scanf(" %c %d",&c,&next[t]);
	}
	
	while(ad1!=-1){
		b[ad1]=true;
		ad1=next[ad1];
	}
	while(ad2!=-1){
		if(b[ad2]){
			printf("%05d",ad2);
			return 0;
		}
		ad2=next[ad2];
	}
	printf("-1");
	
	return 0;
} 
