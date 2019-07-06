#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#define MAX 0x7fffffff
using namespace std;


int main(){
	int n,m,mid,in=0;
	scanf("%d",&n);
    int a[200010];
    
	for(int i=1;i<n+1;i++){
		scanf("%d",&a[i]);  	
	}
	a[n+1]=MAX;
	scanf("%d",&m);
	mid=(n+m+1)/2;
	//n=in+size
	int i=1,j,count=0,temp;
	for(j=1;j<m+1;j++){
		scanf("%d",&temp);
		while(a[i]<temp){
			count++;
			if(count==mid) printf("%d",a[i]);
			i++;//ÏÂÒ»¸ö 
		}
		count++;
		if(count==mid) printf("%d",temp);
	}
	while(i<=n){
		count++;
		if(count==mid) printf("%d",a[i]);
		i++;
	}

	return 0;
} 


