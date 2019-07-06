#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	
	int M,N;
	scanf("%d%d",&M,&N);
	
	int anum;
	
	char a[9],b[9];
	scanf("%s",a);
	anum=1;
	for(int i=0;i<N*M-1;i++){
		scanf("%s",b);
		if(strcmp(a,b)==0){
			anum++;
		}
		else{
			anum--;
			if(anum==0){
				scanf("%s",a);
				i++;
                anum=1;
			}
		}
	}
	printf("%s",a); 
	
}
