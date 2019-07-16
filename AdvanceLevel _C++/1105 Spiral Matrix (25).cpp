#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int num,m,n;

void cal(int num){
	int i=sqrt(num);
	for(;i>0;i--){
		if(num%i==0) break;
	}
	n=i;m=num/n;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
//	freopen("1.txt","r",stdin);
	cin>>num;
	cal(num);
//	printf("%d %d",m,n);
	while(m!=0&&n!=0){	
		int arr[m][n],temp,x=0,y=0,dir=0;//0-right,1-down,2-left,3-up
		vector<int> a;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				arr[i][j]=0;
			}
		}
		for(int i=0;i<num;i++){
			scanf("%d",&temp);
			a.push_back(temp);
		}
		
		sort(a.begin(),a.end(),cmp);
		for(int i=0;i<num;i++){
			arr[x][y]=a[i];
			switch(dir){
				case 0:
					if(y==n-1||arr[x][y+1]!=0){
						dir++;
						x++;
					}else{
						y++;
					}
					break;
				case 1:
					if(x==m-1||arr[x+1][y]!=0){
						dir++;
						y--;
					}else{
						x++;
					}
					break;
				case 2:
					if(y==0||arr[x][y-1]!=0){
						dir++;
						x--;
					}
					else{
						y--;
					}
					break;
				case 3:
					if(x==0||arr[x-1][y]!=0){
						dir=0;
						y++;
					}else{
						x--;
					}
					break;
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				printf("%d%c",arr[i][j],j==n-1?'\n':' ');
			}
		}
		return 0;
	}
}
