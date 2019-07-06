#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#define MAX 100000
//freopen("1.txt","r",stdin);
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	
	char c[100000];
	scanf("%s",c);
	int len=strlen(c);
	
	int n1,n2,n3;
	n1=n3=(len+2)/3;
	n2=len-n1-n3+2;
	
	for(int i=0;i<n1;i++){
		printf("%c",c[i]);
		if(i!=n1-1){
			for(int j=0;j<n2-2;j++){
				printf(" ");
			}
		}
		else{
			for(int j=0;j<n2-2;j++)
			printf("%c",c[n1+j]);
		}
		printf("%c\n",c[len-i-1]);
	}
	
	return 0; 
}
