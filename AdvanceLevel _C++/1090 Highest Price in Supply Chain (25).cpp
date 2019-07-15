#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

struct node {
	int level;
	int num;
} A[100010];
int n;
vector<int> arr[100010];
bool cmp(node a,node b) {
	return a.level>b.level;
}

void set(int num,int level) {
	for(int i=0; i<arr[num].size(); i++) {
		A[arr[num][i]].level=level;
		set(arr[num][i],level+1);
	}
}

int main(){
//	freopen("1.txt","r",stdin);
	double p,r;
	int in;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0; i<n; i++){
		scanf("%d",&A[i].num);
		if(A[i].num==-1) in=i;
		arr[A[i].num].push_back(i);
	}
	A[in].level=0;
	set(in,1);
	
	sort(A,A+n,cmp);
	int num;
	for(num=1; num<n; num++) {
		if(A[num].level!=A[0].level) break;
	}
	printf("%.2lf %d",p*pow((1+r/100),A[0].level),num);
	return 0;
}
