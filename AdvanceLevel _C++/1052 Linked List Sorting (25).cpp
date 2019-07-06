#include<stdio.h>
#include<algorithm>

using namespace std;
struct info{
	int adress;
	int key;
	int next;
	bool in;	
}A[100000];
bool cmp(info a,info b){
	if(!a.in||!b.in) return a.in>b.in;
	else return a.key<b.key;
}
int main(){
//	freopen("1.txt","r",stdin);
	int N,count=0,start;
	scanf("%d%d",&N,&start);
	int a,b,c;
	for(int i=0;i<N;i++){
		scanf("%d",&a);
		A[a].adress=a;
		scanf("%d%d",&A[a].key,&A[a].next);
		A[a].in=false;
	}
	
	for(int i=start;i!=-1;i=A[i].next){
		A[i].in=true;
		count++;
	}
	
	sort(A,A+100000,cmp);
	if(count==0){
		printf("0 -1");return 0;
	}
	printf("%d %05d\n",count,A[0].adress);
	
	for(int i=0;i<count;i++){
		printf("%05d %d ",A[i].adress,A[i].key);
		if(i!=count-1){
			printf("%05d\n",A[i+1].adress);
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}
