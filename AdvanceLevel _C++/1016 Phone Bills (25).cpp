#include <stdio.h>
#include <iostream>
#include <set>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

#define aday ((a[3]-'0')*10+a[4]-'0')
#define bday ((b[3]-'0')*10+b[4]-'0')
#define ahour ((a[6]-'0')*10+a[7]-'0')
#define bhour ((b[6]-'0')*10+b[7]-'0')
#define amin ((a[9]-'0')*10+a[10]-'0')
#define bmin ((b[9]-'0')*10+b[10]-'0')

struct info{
	char name[30];
	char time[30];
	int flag;
	int eff;
}A[2000];

int rate[24];
double alldaycost;
bool cmp(info a,info b){
	if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	else if(strcmp(a.time,b.time)!=0) return strcmp(a.time,b.time)<0;
	else return a.flag<b.flag;
}
bool cmp2(info a,info b){
	if(a.eff!=b.eff) return a.eff>b.eff;
	else if(strcmp(a.name,b.name)!=0) return strcmp(a.name,b.name)<0;
	else if(strcmp(a.time,b.time)!=0) return strcmp(a.time,b.time)<0;
	else return a.flag<b.flag;
}
			
int calmin(char a[],char b[]){
	int sum=0;
	sum+=bmin-amin;
	sum+=60*(bhour-ahour);
	sum+=24*60*(bday-aday);
	return sum;
}
double calcost(char a[],char b[]){
	double cost=0;
	cost-=amin*rate[ahour];
	cost+=bmin*rate[bhour];
	for(int i=ahour;i<bhour;i++){
		cost+=60*rate[i];
	}
	for(int i=bhour;i<ahour;i++){
		cost-=60*rate[i];
	}
	for(int i=aday;i<bday;i++){
		cost+=alldaycost;
	}
	return cost/100;
}


int main(){
//	freopen("1.txt","r",stdin);
	alldaycost=0;
	for(int i=0;i<24;i++){
		scanf("%d",&rate[i]);
		alldaycost+=rate[i]*60;
	}
	
	int n;
	char temp[20];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%s%s",A[i].name,A[i].time,temp);
		if(temp[1]=='n') A[i].flag=0;
		else A[i].flag=1;
		A[i].eff=0;
	}
	sort(A,A+n,cmp);
	for(int i=0;i<n-1;i++){
		if(strcmp(A[i].name,A[i+1].name)==0&&A[i].flag==0&&A[i+1].flag==1){
			A[i].eff=A[i+1].eff=1;
		}
	}
	sort(A,A+n,cmp2);
	int cnt=0;
	for(int i=0;i<n;i++){
		if(A[i].eff==0) cnt++;
	}
	n-=cnt;
	double sum=0;
	int min;
	double cost=0;
	char namenow[30];
	char timea[30],timeb[30];
	for(int i=0;i<n;i++){
		if(strcmp(A[i].name,namenow)!=0){
			if(i!=0){
				printf("Total amount: $%.2lf\n",sum);
				sum=0;
			}
			printf("%s %c%c\n",A[i].name,A[i].time[0],A[i].time[1]);
		}
		strcpy(namenow,A[i].name);
		if(A[i].flag==0&&A[i].eff) strcpy(timea,A[i].time);
		if(A[i].flag==1&&A[i].eff){
			strcpy(timeb,A[i].time);
			min=calmin(timea,timeb);
			cost=calcost(timea,timeb);
			printf("%s %s %d $%.2lf\n",timea+3,timeb+3,min,cost);
			sum+=cost;
		}
		if(i==n-1){
			printf("Total amount: $%.2lf",sum);
		}	
	}
	return 0;
}
