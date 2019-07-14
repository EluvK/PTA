#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stack> 
#include <algorithm>
using namespace std;

int n;

void change(string &a,int &exp){
	int i=0;
	while(a.length()>0&&a[0]=='0'){
		a.erase(a.begin());
	}
	if(a[0]=='.'){
		a.erase(a.begin());
		while(a.length()>0&&a[0]=='0'){
			a.erase(a.begin());
			exp--;
		}
	}else{
		while(i<a.length()&&a[i]!='.'){
			i++;exp++;
		}
		if(a[i]=='.') 
			a.erase(a.begin()+i);
	}
	if(a.length()==0){
		exp=0;
	}
	i=0;
	if(a.length()>n)
		a=a.substr(0,n);
	while(i<n){
		if(i>=a.length()){
			a.push_back('0');
		}
		i++;
	}
	return;
} 

int main(){
//	freopen("1.txt","r",stdin);
	int expa=0,expb=0;
	string a,b;
	cin>>n>>a>>b;
	change(a,expa);
	change(b,expb);
	if(a==b&&expa==expb){
		cout<<"YES"<<" 0."<<a<<"*10^"<<expa;
	}else{
		cout<<"NO"<<" 0."<<a<<"*10^"<<expa<<" 0."<<b<<"*10^"<<expb;
	}
}
