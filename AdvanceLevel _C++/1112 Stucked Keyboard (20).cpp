#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
bool find(vector<char> res,char c){
	for(int i=0;i<res.size();i++){
		if(res[i]==c) return false;
	} 
	return true;
}

int main(){
//	freopen("1.txt","r",stdin);
	string str;
	int n,len;
	map<char,int> mp;
	map<char,int> res;
	vector<char> re; 
	cin>>n>>str;
	len=str.length();
	
	for(int i=0;i<len-1;i++){
		if(str[i]!=str[i+1]){
			mp[str[i]]=1;
		}
		else if(mp[str[i]]==1){
			continue;
		}else{
			int j;
			for(j=0;j<n;j++){
				if(i+j>=len) break;
				if(str[i+j]!=str[i]) break;
			}
			if(j==n){
				 mp[str[i]]=-1;
				 i=i+n-1;
			}
		}
	}
	
	for(int i=0;i<len;i++){
		if(mp[str[i]]==-1){
			if(res[str[i]]!=1){
				res[str[i]]=1;
			}
			if(find(re,str[i])){
				re.push_back(str[i]);
			}
			i=i+n-1;
		}
	}
//	for(map<char,int>::iterator it=res.begin();it!=res.end();it++){
//		printf("%c",it->first);
//	}
	for(int i=0;i<re.size();i++){
		printf("%c",re[i]);
	}
	cout<<endl;
	for(int i=0;i<len;i++){
		printf("%c",str[i]);
		if(res[str[i]]==1){
			i=i+n-1;
		}
		else{
		}
	}
}
