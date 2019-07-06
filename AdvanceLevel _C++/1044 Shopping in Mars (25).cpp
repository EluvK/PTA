#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#define MAX 10000

using namespace std;



int main(){
	// freopen("1.txt","r",stdin);
	int N,M;
	int start=1;
	int end=0;
	int minout=-9999999;
	int equalflag=0;
	vector<int> num;

	scanf("%d%d",&N,&M);
	int storeM=M;
	num.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
		end++;
		M-=num[i];
		
		while(M<=0){
			if(M==0){
				printf("%d-%d\n",start,end);
				M+=num[start-1];
				start++;
				equalflag=1;
			}
			else{//M<0
				while(M<0){
					if(M>minout) minout=M;
					M+=num[start-1];
					start++;
				}
			}
		}
	}
	if(equalflag){
		return 0;
	} 
	else{
		start=1;
		end=0;
		M=storeM;
		for(int i=0;i<N;i++){
			end++;
			M-=num[i];
			
			while(M<=minout){
				if(M==minout){
					printf("%d-%d\n",start,end);
					M+=num[start-1];
					start++;
					equalflag=1;
				}
				else{//M<0
					while(M<minout){
						
						M+=num[start-1];
						start++;
					}
				}
			}
		}
	}
	
	
} 
