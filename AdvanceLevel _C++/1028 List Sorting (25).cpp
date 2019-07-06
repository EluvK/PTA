#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

struct info{
	int id;
	char name[15];
	int grade;
};

bool cmp1(info a,info b){
	return a.id<b.id;
}

bool cmp2(info a,info b){
	
	return strcmp(a.name,b.name)!=0?strcmp(a.name,b.name)<0:a.id<b.id; 
}

bool cmp3(info a,info b){
	return a.grade!=b.grade?a.grade<b.grade:a.id<b.id;
}

int main(){
	// freopen("1.txt","r",stdin);
	int N,s;
	scanf("%d%d",&N,&s);
	vector<info> A;
	A.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d%s%d",&A[i].id,A[i].name,&A[i].grade);
	}
	switch(s){
		case 1:
			sort(A.begin(),A.end(),cmp1);
			break;
		case 2:
			sort(A.begin(),A.end(),cmp2);
			break;
		case 3:
			sort(A.begin(),A.end(),cmp3);
			break;
	}
	for(int i=0;i<N;i++){
		printf("%06d %s %d\n",A[i].id,A[i].name,A[i].grade);
	}
	
	return 0;
}
