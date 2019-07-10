#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string> 
#include<vector>
using namespace std;

vector<int> a;
vector<int> res;
int re[300];
int in=0;
int outflag=0;

bool ispal(string s){
	int len=s.length();
	for(int i=0;i<len/2+1;i++){
		if(s[i]!=s[len-1-i]) return false;
	}
	return true;
}

string addstr(string a,string b){
	int len=a.length();
	int flag=0;
	int temp;
	string res;
//	char res[100];
	for(int i=0;i<len;i++){
		temp=a[i]-'0'+b[i]-'0'+flag;
		flag=0;
		if(temp>9){
			flag=1;
			res.push_back(temp-10+'0'); 

		}
		else{

			res.push_back(temp+'0');
		}
	}
	if(flag) res.push_back('1');
	reverse(res.begin(),res.end());
	return res;
}

int main(){
//	freopen("1.txt","r",stdin);

	string s;

	int n;
	cin>>s; 
	scanf("%d",&n);
	int num=0;
	while(n--){
		if(ispal(s)){
			cout<<s<<endl;
			printf("%d",num);
			return 0;
		}
		else{
			string s2=s;
			reverse(s2.begin(),s2.end());
			s=addstr(s,s2);
			num++;		
		}
	}
	cout<<s<<endl;
	printf("%d",num);
			
	return 0;
}
