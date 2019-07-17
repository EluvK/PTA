#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
int a[1001][1001];

bool check(int i,int j,int M){
	for(int k=1;k<=M;k++){
		if(a[i][k]||a[k][j]) 
		return false;
	}
	int ii=i-1,jj=j-1;
	while(ii>0&&jj>0){
		if(a[ii--][jj--]) 
		return false;
	}
	ii=i+1;jj=j+1;
	while(ii<=M&&jj<=M){
		if(a[ii++][jj++]) 
		return false;
	}
	ii=i+1;jj=j-1;
	while(ii<=M&&jj>0){
		if(a[ii++][jj--]) 
		return false;
	}
	ii=i-1;jj=j+1;
	while(ii>0&&jj<=M){
		if(a[ii--][jj++]) 
		return false;
	}
	return true;
}

int main(){
//	freopen("1.txt","r",stdin);
	int n,m,temp;
	scanf("%d",&n);
	while(n--&&scanf("%d",&m)!=EOF){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				a[i][j]=0;
			}
		}
		int i=1;
		for(;i<=m;i++){
			scanf("%d",&temp);
			if(!check(i,temp,m)){
				printf("NO\n");
				for(int k=0;k<m-i;k++){
					scanf("%d",&temp);
				}
				break;
			}
			else{
				a[i][temp]=1;
			}
		}
		if(i==m+1) printf("YES\n");
	}
} 

