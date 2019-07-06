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
	int N;
	int bet[100010]={0};//Ñ¹µÄÈËÊı
	vector<int> in; 
	queue<int> q;

	scanf("%d",&N);
	in.resize(N);
	for(int i=0;i<N;i++){
		int temp;
		scanf("%d",&temp);
		bet[temp]++;
		in[i]=temp;
	}
	
	for(int i=0;i<N;i++){
		if(bet[in[i]]<=1){
			if(!q.empty()&&q.front()==in[i]){
				q.pop();
			}
			else{
				q.push(in[i]);
			}
		}
	}
	if(!q.empty()){
		printf("%d",q.front());
	}
	else{
		printf("None");
	}
	
	
	
	
	
} 
