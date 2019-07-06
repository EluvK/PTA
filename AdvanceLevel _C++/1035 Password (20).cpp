#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

struct pswd{
	char name[20];
	char wd[20];
	bool pfg;
}; 

bool check(char c){
	if((c=='1')||(c=='0')||(c=='l')||(c=='O'))
		return false;
	return true;
}

char change(char c){
	if(c=='1') return '@';
	if(c=='0') return '%';
	if(c=='l') return 'L';
	if(c=='O') return 'o'; 
}

int main(){
//	freopen("1.txt","r",stdin);
	
	int n,count=0,len,num=0;
	scanf("%d",&n);
	vector<pswd> p;
	p.resize(n);
	char temp[20];
	for(int i=0;i<n;i++){
		scanf("%s%s",p[i].name,temp);
		len=strlen(temp);
		p[i].pfg=false;
		for(int j=0;j<len;j++){
			if(check(temp[j])){
				p[i].wd[j]=temp[j];
			}else{
				p[i].wd[j]=change(temp[j]);
				count++;
				p[i].pfg=true;
			}
		} 
		if(count){
			num++;
			count=0;
		}
	}
	
	if(num){
		printf("%d\n",num);
		for(int i=0;i<p.size();i++){
			if(p[i].pfg){
				printf("%s %s\n",p[i].name,p[i].wd);
			}
		}
	}
	else if(n==1){
		printf("There is 1 account and no account is modified",n);
	}
	else{
		printf("There are %d accounts and no account is modified",n);
	}
	
	
}
