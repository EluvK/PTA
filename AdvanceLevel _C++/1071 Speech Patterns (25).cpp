#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
//	freopen("1.txt", "r", stdin);
	string s;
	getline(cin,s);
	map<string, int> mmp;
	string a = "";
	int m = 0;int i=0;
	while(s.length()!=i){
		string r="";
        while(i<s.size()){
            if(isdigit(s[i])==false&&isalpha(s[i])==false){
                i++;break;
            }
            else r+=isdigit(s[i])?s[i]:tolower(s[i]);
            i++;
        }
		if(r!=""){
			mmp[r]+=1;
			if(mmp[r]>m){
				a = r;
				m = mmp[r];
			}else if(mmp[r]==m and r<a){
				a = r;
			}
		}
	}
	cout<<a<<" "<<m<<endl;
	return 0;
}
