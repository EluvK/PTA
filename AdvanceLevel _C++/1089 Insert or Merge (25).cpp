#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector> 
#include <math.h>
using namespace std;

void insertsort(vector<int> &a){
	int temp,i;
	for(int i=1;i<a.size();i++){
		if(a[i]<a[i-1]){
			temp=a[i];
			a.erase(a.begin()+i);
			a.insert(lower_bound(a.begin(),a.begin()+i,temp),temp);
			break;
		}
	} 
	return;
}
void mergesort(vector<int> &a,int i){
	int range=pow(2,i);
	for(int i=0;i<=a.size()/range;i++){
		sort(a.begin()+i*range,(i+1)*range>a.size()?a.end():a.begin()+(i+1)*range);
	}
} 

bool cmp(vector<int> a,vector<int> b){
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}

int main(){
//	freopen("1.txt","r",stdin);
	vector<int> a,b,res;
	int n,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		a.push_back(temp);
		b.push_back(temp);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		res.push_back(temp);
	}
	int i=1;
	while(!cmp(a,res)&&!cmp(b,res)){
		insertsort(a);
		mergesort(b,i++);
	}
	if(cmp(a,res)){
		printf("Insertion Sort\n");
		insertsort(a);
		for(int i=0;i<n;i++){
			printf("%d%c",a[i],i==n-1?'\n':' ');
		}
	}else{
		printf("Merge Sort\n");
		mergesort(b,i);
		for(int i=0;i<n;i++){
			printf("%d%c",b[i],i==n-1?'\n':' ');
		}
	}
} 
