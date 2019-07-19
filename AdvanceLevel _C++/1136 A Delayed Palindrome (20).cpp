#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool ispal(string s){
	int len=s.length();
	for(int i=0;i<len/2+1;i++){
		if(s[i]!=s[len-1-i]) return false;
	}
	return true;
}

string add(string a,string b){
	string res,res2;
	char temp;
	int flag=0;
	for(int i=0;i<a.length();i++){
		temp=a[i]-'0'+b[i]+flag;
		flag=0;
		if(temp-'0'>9){
			flag=1;
			temp-=10;
		}
		res.push_back(temp); 
	}
	if(flag){
		res.push_back('1');
	}
	reverse(res.begin(),res.end());
	return res;
}

int main(){
//	freopen("1.txt","r",stdin);
	string n,temp,res;
	cin>>n;
	int cnt=10;
	while(cnt--){
		if(ispal(n)){
			cout<<n<<" is a palindromic number.";
			break;
		}
		temp=n;
		reverse(temp.begin(),temp.end());
		res=add(n,temp);
		cout<<n<<" + "<<temp<<" = "<<res<<endl;
		n=res;
	}
	if(cnt==-1) printf("Not found in 10 iterations.");
	return 0;
	temp=n;
	reverse(temp.begin(),temp.end());
	res=add(n,temp);
	cout<<n<<" + "<<temp<<" = "<<res; 
}
