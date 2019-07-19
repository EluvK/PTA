#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string change(string s){
	string res;
	char nowchar='0'-1;
	int num=0;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(nowchar!=s[i]){
			if(i) res.push_back(num+'0');
			nowchar=s[i];
			num=1;
			res.push_back(nowchar);	
		}else{
			num++;
		}
	}
	
	res.push_back(num+'0');
	return res;
}

int main(){
	string s,res;
	int n;
	cin>>s>>n;
	res=s;
	while(--n){
		res=change(s);
		s=res;
	}
	cout<<res;
} 
