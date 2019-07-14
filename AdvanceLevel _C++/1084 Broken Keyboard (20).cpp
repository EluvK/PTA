#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
	
	string a,b,ans;
	cin>>a>>b;	
	for(int i=0;i<a.length();i++){
		if(b.find(a[i])==string::npos && ans.find(toupper(a[i]))==string::npos)
			ans+=toupper(a[i]);
	}
	cout<<ans;
	return 0;
}
