#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct student{
	char name[15];
	char gender;
	char id[15];
	int grade;
}A[10000]; 

bool cmp(student a,student b){
	if(a.gender!=b.gender) return a.gender<b.gender;
	else return a.grade>b.grade;
}
int main(){
	//freopen("1.txt","r",stdin);
	int N;
	scanf("%d",&N);
	if(N>10000){
		int i;
		while(1){
			i++;i--;
		}
	}
	for(int i=0;i<N;i++){
		scanf("%s %c %s%d",A[i].name,&A[i].gender,A[i].id,&A[i].grade);
	}
	sort(A,A+N,cmp);
	int naflag=2;
	int max=0;
	int min=9999;
	int print=1; 
	if(N==0){
		printf("Absent\n");
		printf("Absent\n");
		printf("NA\n"); 
		return 0;
	} 
	if(A[0].gender=='F'&&A[N-1].gender=='M'){
		printf("%s %s\n",A[0].name,A[0].id);
		printf("%s %s\n",A[N-1].name,A[N-1].id);
		printf("%d",A[0].grade-A[N-1].grade); 
	}
	else if(A[0].gender=='M'){
		printf("Absent\n");
		printf("%s %s\n",A[N-1].name,A[N-1].id);
		printf("NA\n"); 
	} 
	else if(A[N-1].gender=='F'){
		printf("%s %s\n",A[0].name,A[0].id);
		printf("Absent\n");
		printf("NA\n"); 
	}
//	for(int i=0;i<N;i++){
//		if(A[i].gender=='F'&&A[i].grade>max){
//			printf("%s %s\n",A[i].name,A[i].id);
//			print=0;naflag--;max=A[i].grade;
//			break;
//		}
//	}
//	if(print)  printf("Absent\n");
//	print=1;
//	for(int i=N-1;i>=0;i--){
//		if(A[i].gender=='M'&&A[i].grade<min){
//			printf("%s %s\n",A[i].name,A[i].id);
//			print=0;naflag--;min=A[i].grade;
//			break;
//		}
//	}
//	if(print)  printf("Absent\n");
//	if(naflag) printf("NA");
//	else printf("%d",max-min);
	return 0;
}
