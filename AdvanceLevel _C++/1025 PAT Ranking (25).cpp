#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#define MAX 10000

using namespace std;

struct info{
	char num[15];
	int grade;
	int localnum;
	int localrank;
	int rank;
};

bool cmp(info a,info b){
	if(a.localnum!=b.localnum) return a.localnum<b.localnum;
	else if(a.grade!=b.grade) return a.grade>b.grade;
	else return strcmp(a.num,b.num)<0;
}
bool cmp2(info a,info b){
	if(a.grade!=b.grade) return a.grade>b.grade;
	// else if(a.localnum!=b.localnum) return a.localnum<b.localnum;
	else return strcmp(a.num,b.num)<0;
}

int main(){
	//freopen("1.txt","r",stdin);
	
	int llnum;
	int size=0;
	int scanfindex=0;
	vector<info> sinfo;
	scanf("%d",&llnum);
	for(int i=1;i<llnum+1;i++){
		int snum;
		scanf("%d",&snum);
		size+=snum; 
		sinfo.resize(size);
		for(int j=1;j<=snum;j++){
			scanf("%s%d",sinfo[scanfindex].num,&sinfo[scanfindex].grade);
			sinfo[scanfindex].localnum=i;
			scanfindex++;
		}
	}
	sort(sinfo.begin(),sinfo.end(),cmp);
	
	int ranknum=2;
	sinfo[0].localrank=1;
	for(int i=1;i<size;i++){
		if(sinfo[i].localnum==sinfo[i-1].localnum){
			if(sinfo[i].grade==sinfo[i-1].grade){
				sinfo[i].localrank=sinfo[i-1].localrank;
				ranknum++;
			}
			else sinfo[i].localrank=ranknum++;	
		}
		else{
			sinfo[i].localrank=1;
			ranknum=2;
		}
		
	}
	
	sort(sinfo.begin(),sinfo.end(),cmp2);
	
	sinfo[0].rank=1;
	ranknum=2;
	for(int i=1;i<size;i++){
		if(sinfo[i].grade==sinfo[i-1].grade){
				sinfo[i].rank=sinfo[i-1].rank;
				ranknum++;
			}
			else sinfo[i].rank=ranknum++;	
	}
	
	printf("%d\n",size);
	for(int i=0;i<size;i++){
		printf("%5s %d %d %d\n",sinfo[i].num,sinfo[i].rank,sinfo[i].localnum,sinfo[i].localrank);
	}
	
	return 0;
	
} 
