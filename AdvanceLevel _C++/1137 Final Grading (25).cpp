#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct info{
	string name;
	int gp,gm,gf,g;
}A[40000];

bool cmp(info a,info b){
	if(a.g!=b.g) return a.g>b.g;
	else return a.name<b.name; 
}
int main(){
//	freopen("1.txt","r",stdin);
	int p,m,n;
	scanf("%d%d%d",&p,&m,&n);
	map<string,int> mp;
	string temp;
	int tempg;
	int in=1;
	for(int i=0;i<40000;i++){
		A[i].gp=A[i].gm=A[i].gf=-1;
	}
	for(int i=0;i<p;i++){
		cin>>temp;
		scanf("%d",&tempg);
		if(mp[temp]==0){
			mp[temp]=in;
			A[in].name=temp;
			A[in].gp=tempg;
		}else{
			A[mp[temp]].name=temp;
			A[mp[temp]].gp=tempg;
		}
		in++;
	}
	for(int i=0;i<m;i++){
		cin>>temp;
		scanf("%d",&tempg);
		if(mp[temp]==0){
			mp[temp]=in;
			A[in].name=temp;
			A[in].gm=tempg;
		}else{
			A[mp[temp]].name=temp;
			A[mp[temp]].gm=tempg;
		}
		in++;
	}
	for(int i=0;i<n;i++){
		cin>>temp;
		scanf("%d",&tempg);
		if(mp[temp]==0){
			mp[temp]=in;
			A[in].name=temp;
			A[in].gf=tempg;
		}else{
			A[mp[temp]].name=temp;
			A[mp[temp]].gf=tempg;
		}
		in++;
	}
	
	for(int i=1;i<in;i++){
		if(A[i].gm!=-1&&A[i].gf!=-1){
			A[i].g=A[i].gm>A[i].gf?(0.4*A[i].gm+0.6*A[i].gf+0.5):A[i].gf;
		}
		if(A[i].gm==-1){
			A[i].g=A[i].gf*1.0;
		}
	}
	sort(A+1,A+in,cmp);
	for(int i=1;i<in;i++){
		if(A[i].gp>=200&&A[i].g>=60){
			cout<<A[i].name;
			printf(" %d %d %d %d\n",A[i].gp,A[i].gm,A[i].gf,A[i].g);
		}
	}
}
