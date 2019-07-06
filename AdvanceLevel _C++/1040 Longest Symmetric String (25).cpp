#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#define MAX 10000

using namespace std;

//坑1：至少有一个，maxnum初始为1
 
int main(){
	//freopen("1.txt","r",stdin);
	char in[1005];
	cin.getline(in,1005);
	int len=strlen(in);

	vector<int> arr;
	for(int i=0;i<len;i++){
		arr.push_back(-1);
		arr.push_back(in[i]);
	}
	arr.push_back(-1);
	len=arr.size(); 

	int i;
	int maxnum=3;
	bool returnflag=false;
	
	for(i=1;i<len;i++){
		int l,r;
		int step=1;
		for(l=i-1,r=i+1;l>=0&&r<len;l--,r++){
			if(arr[l]!=arr[r]){
				break;
			}
			step+=2;
		} 
		maxnum=max(maxnum,step);
	}
	
	printf("%d",maxnum/2);
	
	return 0;
	
} 
