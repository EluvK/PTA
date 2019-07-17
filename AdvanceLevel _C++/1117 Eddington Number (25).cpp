#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	
	int n,temp;
	vector<int> a;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		a.push_back(temp);
	}
	sort(a.begin(),a.end(),cmp);
	for(int i=0;i<a.size();i++){
//		printf("%d ",a[i]);
	}
	for(int i=0;i<=n;i++){
		if(a[i]<=i+1){
			printf("%d",i);
			return 0;
		}
	}
}

