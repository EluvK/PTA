#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct info{
	int id;
	int rank;
	int total;
	int s[6];
	int prefectnum;
	int time;
}A[10010];

bool cmp(info a,info b){
	if(a.total!=b.total) return a.total>b.total;
	else if(a.prefectnum!=b.prefectnum) return a.prefectnum>b.prefectnum;
	else return a.id<b.id;
}
bool cmp2(info a,info b){
	if(a.time!=b.time) return a.time>b.time;
	else return a.id<b.id;
}

int main(){
//	freopen("1.txt","r",stdin);
	
	int N,M,K;
	int fulls[6];
	scanf("%d%d%d",&N,&K,&M);
	for(int i=1;i<=K;i++){
		scanf("%d",&fulls[i]);
	}
	
	for(int i=1;i<=N;i++){
		A[i].id=i;
		A[i].time=0;
		for(int j=1;j<=K;j++){
			A[i].s[j]=-1;
		} 
	}
	
	int id,pid,score;
	for(int i=0;i<M;i++){
		scanf("%d%d%d",&id,&pid,&score);
		if(score>=0){
			if(score>A[id].s[pid]) A[id].s[pid]=score;
		} 
		else if(score==-1){
			if(A[id].s[pid]==-1) A[id].s[pid]=0;
		}
		if(score!=-1) A[id].time++;
//		if(A[id].s[pid]<score){
//			A[id].s[pid]=score;
//			
//		}
	}
	
	for(int i=0;i<=N;i++){
		int sum=0;
		A[i].prefectnum=0;
		for(int j=1;j<=K;j++){
			if(A[i].s[j]==fulls[j]) A[i].prefectnum++;
			if(A[i].s[j]!=-1&&A[i].s[j]!=-2) sum+=A[i].s[j];
		}
		A[i].total=sum;
	}
	sort(A,A+N+1,cmp2);
	for(int i=0;i<N;i++){
		if(A[i].time==0){
			sort(A,A+i,cmp);
			break;
		}
	} 
//	sort(A,A+N+1,cmp);
	int ranknum=1;
	for(int i=0;i<=N;i++){
		if(A[i].time==0) break;
		if(i==0) A[i].rank=1;
		else if(A[i].total==A[i-1].total){
			A[i].rank=A[i-1].rank;
		}
		else{
			A[i].rank=ranknum;
		}
		ranknum++;
	}
	for(int i=0;i<=N;i++){
		if(A[i].rank==0) break;
		printf("%d %05d %d ",A[i].rank,A[i].id,A[i].total);
		if(A[i].s[1]==-1) printf("-");
		else printf("%d",A[i].s[1]);
		for(int j=2;j<=K;j++){
			if(A[i].s[j]==-1) printf(" -");
			else printf(" %d",A[i].s[j]);
		}
		printf("\n");
	}
	return 0;
} 
