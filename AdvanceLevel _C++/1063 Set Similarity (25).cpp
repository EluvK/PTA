#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <math.h>
#define MAX 2147483647
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	set<int> book[55];
	int n,num,temp; 
	scanf("%d",&n);
	for(int i=1;i<n+1;i++){
		scanf("%d",&num);
		for(int j=0;j<num;j++){
			scanf("%d",&temp);
			book[i].insert(temp);
		}
	}
	int a,b,all,same;
	scanf("%d",&n);
	for(int ii=0;ii<n;ii++){
		scanf("%d%d",&a,&b);
		all=0;same=0;
 		set<int>::iterator i=book[a].begin();
 		set<int>::iterator j=book[b].begin();
 		while(i!=book[a].end()&&j!=book[b].end()){
			if(*i<*j){
				i++;all++;
			}else if(*i>*j){
				j++;all++;
			}else if(*i==*j){
				i++;j++;all++;same++;
			}
		}
		if(i!=book[a].end()){
			while(i!=book[a].end()){
				i++;all++;
			}
		}
		if(j!=book[b].end()){
			while(j!=book[b].end()){
				j++;all++;
			}
		}
		printf("%.1f%%\n",100*double(same)/double(all));
	}
	return 0;
 } 
