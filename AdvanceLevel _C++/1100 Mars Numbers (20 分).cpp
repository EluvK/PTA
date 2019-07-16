#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
string low[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string high[13]={"cccc","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
void c2mars(int num){
	if(num/13) cout<<high[num/13];
	if(num/13&&num%13) cout<<" ";
	if(num%13 || num==0) cout<<low[num%13];
	cout<<endl;
	return;
//	int b=num%13,a=num/13;
//	if(a==0){
//		cout<<low[b]<<endl;
//	}
//	else{
//		if(b==0){
//			cout<<high[a]<<endl;
//		}else{	
//			cout<<high[a]<<" "<<low[b]<<endl;
//		}	
//	}
}

void c2earth(string str){
	int a=0,b=0;
	string s1=str.substr(0,3),s2;
	if(str.length()>4) s2=str.substr(4,3);
	for(int i=0;i<13;i++){
		if(s1==low[i]||s2==low[i]) b=i;
		if(s1==high[i]) a=i;
	}
	cout<<a*13+b<<endl;
	return;
}

void judge(string str){
	if(str[0]>='0'&&str[0]<='9'){
		int num=0;
		for(int i=0;i<str.length();i++){
			num=num*10+str[i]-'0';	
		}
		c2mars(num);
	}else{
		c2earth(str); 
	}
}

int main(){
//	freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	string temp;
	getchar();
	for(int i=0;i<n;i++){
		getline(cin,temp);
		 judge(temp);
	}

}
