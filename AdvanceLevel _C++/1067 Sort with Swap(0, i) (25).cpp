#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <math.h>
#define MAX 2147483647
using namespace std;

int a[100010];
int cnt,n;
int flag[100010]={0};

int main() {
//	freopen("1.txt","r",stdin);

	scanf("%d",&n);
	vector<int> na;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i) na.push_back(i);
	}
	int cnt=0,loop=0,loopn=0;
	int num=0,i=0,j=0;
	while(cnt!=n&&j!=na.size()){
		
		if(loop){
			//i=第一个没flag的
			loop=0;
			while(j!=na.size()){
				i=na[j++];
				if(a[i]!=i&&flag[i]==0){
						loopn++;
						break;	
				}
			}
		}
		
		if(a[i]==i){
			if(flag[i]==0){
				flag[i]=1;
				cnt++;
				loop=1;
			}
		}else{
			if(flag[i]==0){
				cnt++;num++;flag[i]=1;
				i=a[i];
			}
			else{
				loop=1;
			}
		}
	}
	int res=0;
	if(a[0]==0) res++;
	res=res+num-1+loopn;
	printf("%d",res);
	return 0;

}
