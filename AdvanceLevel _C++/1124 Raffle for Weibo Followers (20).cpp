#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	
	int m,n,s;
	scanf("%d%d%d",&m,&n,&s);
	if(s>m){
		printf("Keep going...");
		return 0;
	}
	string temp;
	map<string,int> mp;
	for(int i=1;i<s;i++){
		cin>>temp;
	}
	int step=0;
	for(int i=s;i+step<=m;i++){
		cin>>temp;
		if((i-s)%n==0){
			if(mp[temp]==0){
				mp[temp]=1;
				flag=1;
				cout<<temp<<endl;
			}else{
				step++;
				i--;
			}
			
		}
	}
	return 0;
} 

