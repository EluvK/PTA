#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int flag[100]={0};
int layer[100]={0};
int tree[100][100]={0};
int M,N;
void count(int num,int layernum){
	for(int i=0;i<M;i++){
		if(tree[i][0]==num){
			
			for(int j=0;j<tree[i][1];j++){
				if(tree[i][j+2]!=0){
//					printf("%d ",tree[i][j+2]);
					count(tree[i][j+2],layernum+1);
					layer[layernum]++;
				}
			}
			return;
		}
	}
}

int main(){
	


	scanf("%d %d",&N,&M);
	
	for(int i=0;i<M;i++){

		scanf("%d %d",&tree[i][0],&tree[i][1]);
		for(int j=0;j<tree[i][1];j++){
			scanf("%d",&tree[i][j+2]);
		}	
	}
	count(1,1);
	layer[0]++;
	int max,maxi;
	maxi=0;
	max=0;
	for(int i=0;i<100;i++){
		if(layer[i]>max){
			maxi=i;max=layer[i];
		}
	}
	printf("%d %d",max,maxi+1);
	
	return 0;
} 
