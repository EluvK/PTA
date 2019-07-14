#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

string res;
void read(char c){
	string s[10]={"ling ","yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu "};
	res+=s[c-'0'];
}


int main(){
//	freopen("1.txt","r",stdin);
	string a;
	cin>>a;
	if(a[0]=='-'){
		res+="Fu ";
		a.erase(a.begin());
	}
	if(a[0]=='0'){
		cout<<"ling";
		return 0;
	}
	while(a.length()>0){
		if(a.length()==9){
			read(a[0]);
			res+="Yi ";
			a.erase(a.begin());
		}
		if(a.length()==8){
			if(a[0]=='0'){
				while(a[0]=='0') a.erase(a.begin()); 
				if(a.length()!=0){
					read('0');
				}
			}
			else{
				read(a[0]);
				res+="Qian ";
				a.erase(a.begin());
			}
		}
		
		if(a.length()==7){
			if(a[0]=='0'){
				while(a[0]=='0'&&a.length()>5) a.erase(a.begin());
				if(a.length()!=0&&a.length()!=5){
					read('0');
				}
			}
			else{
				read(a[0]);
				res+="Bai ";
				a.erase(a.begin());
			}
		}
			
		if(a.length()==6){
			if(a[0]=='0'){
				while(a[0]=='0'&&a.length()>5) a.erase(a.begin());
				if(a.length()!=0&&a.length()!=5){
					read('0');
				}
			}
			else{
				read(a[0]);
				res+="Shi ";
				a.erase(a.begin());
			}
		}
		
		if(a.length()==5){
			
			if(a[0]=='0'){
				if(a.length()==5) res+="Wan ";
				while(a[0]=='0') a.erase(a.begin());
				if(a.length()!=0){
					read('0');
				}
			}
			else{
				read(a[0]);
				if(a.length()==5) res+="Wan ";
				a.erase(a.begin());
			}
		}	
		
		if(a.length()==4){
			if(a[0]=='0'){
				while(a[0]=='0') a.erase(a.begin()); 
				if(a.length()!=0){
					read('0');
				}
			}
			else{
				read(a[0]);
				res+="Qian ";
				a.erase(a.begin());
			}
		}
		
		if(a.length()==3){
			if(a[0]=='0'){
				while(a[0]=='0') a.erase(a.begin());
				if(a.length()!=0){
					read('0');
				}
			}
			else{
				read(a[0]);
				res+="Bai ";
				a.erase(a.begin());
			}
		}
			
		if(a.length()==2){
			if(a[0]=='0'){
				while(a[0]=='0') a.erase(a.begin());
				if(a.length()!=0){
					read('0');
				}
			}
			else{
				read(a[0]);
				res+="Shi ";
				a.erase(a.begin());
			}
		}
		
		if(a.length()==1){
			
			if(a[0]=='0'){
				while(a[0]=='0') a.erase(a.begin());
				if(a.length()!=0){
					read('0');
				}
			}
			else{
				read(a[0]);
				a.erase(a.begin());
			}
		}	
	}
//	cout<<"11"<<*res.end()<<"11"<<endl;
	if(res[res.length()-1]==' ') 
		res=res.substr(0,res.length()-1);
//	cout<<"11"<<*res.end()<<"11"<<endl;
	cout<<res;
	
} 
