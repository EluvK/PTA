#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#define MAX 100000

using namespace std;
struct mice{
		int oriid;
		int rank;
		int weight;
		int index;	
};

bool cmp(mice a,mice b){
	return a.index<b.index;
}

int min(int a,int b){
	return a>b?b:a;
}

int main(){
	// freopen("1.txt","r",stdin);
	int N,g,num;
	scanf("%d%d",&N,&g);
	mice M[N];
	int v[N];
	for(int i=0;i<N;i++){
		scanf("%d",&v[i]);
		
	}
	for(int i=0;i<N;i++){
		scanf("%d",&num);
		M[i].oriid=i;
		M[i].rank=0;
		M[i].weight=v[num];
		M[i].index=num;
	}
//	sort(M,M+N,cmp);
	
	queue<mice> q;
	for(int i=0;i<N;i++){
		q.push(M[i]);
	}
	while(!q.empty()){
		int groupnum=(q.size()+g-1)/g;
		int size=q.size();
		if(size==1){
			mice temp=q.front();
			M[temp.oriid].rank=1;
			break; 
		}
		mice maxnode;
		int maxw=-1;
		int count=0;
		for(int i=0;i<size;i++){
			mice temp=q.front();
			M[temp.oriid].rank=groupnum+1;
			count++;
			q.pop();
			if(temp.weight>maxw){
				maxw=temp.weight;
				maxnode=temp;
			}
			if(count==g||i==size-1){
				maxw=-1;count=0;
				q.push(maxnode);
			}
		}
		
		
	}
	
	
	
	

	
	sort(M,M+N,cmp);
	printf("%d",M[0].rank);
	for(int i=1;i<N;i++){
		printf(" %d",M[i].rank);
	}
} 
