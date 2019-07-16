#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<int> arr[100010];

int mind=9999999,minn=1; 
void set(int n,int level){
	if(mind<level) return;
	if(arr[n].size()==0){
		if(mind==level)
			minn++;
		else if(mind>level){
			mind=level;
			minn=1;
		}
	}	
	for(int i=0;i<arr[n].size();i++){
		set(arr[n][i],level+1);
	}
}

int main(){
//	freopen("1.txt","r",stdin);
	int n;
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i=0;i<n;i++){
		int temp,next;
		scanf("%d",&temp);
		if(temp){
			for(int j=0;j<temp;j++){
				scanf("%d",&next);
				arr[i].push_back(next);
			}
		}
	}
	set(0,0);

	printf("%.4f %d",p*pow(1+r/100,mind),minn);
	return 0;
}
