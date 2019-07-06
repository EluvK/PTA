#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#define MAX 2147483647
using namespace std;

int book[MAX]={0};

int main(){
//	freopen("1.txt","r",stdin);

	int n,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(temp>0){
			book[temp]=1;
		}
	}	
	for(int i=1;i<MAX;i++){
		if(book[i]==0){
			printf("%d",i);
			break;
		}
	}	
	return 0;
	
} 
