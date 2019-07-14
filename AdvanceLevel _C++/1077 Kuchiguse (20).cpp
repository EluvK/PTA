#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	int n;
	cin>>n;
	getchar();
	string arr[120];
	string result;
	for(int i=0;i<n;i++){
		getline(cin,arr[i]);
	}
	for(int i=0;i<n;i++){
		reverse(arr[i].begin(),arr[i].end());
	}
	for(int i=0;i<arr[0].length();i++){
		char temp=arr[0][i];
		int j;
		for(j=1;j<n;j++){
			if(arr[j].length()<i) break;
			if(arr[j][i]!=temp) break;
		}
		if(j==n) result.push_back(temp);
        else break;
	}
	
	if(result.length()!=0){
		reverse(result.begin(),result.end());
		// while(*result.begin()==' '){
		// 	result.erase(result.begin());
		// } 
		cout<<result;	
	}
	else{
		cout<<"nai";
	}
}
