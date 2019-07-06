#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct number{
	char num[10];
	int len;
	int index;
}a[10010]; 

bool cmp(number a,number b){
	if(a.num[0]!=b.num[0]) return a.num[0]<b.num[0];
	else{
		for(int i=0;i<min(a.len,b.len);i++){
			if(a.num[i]!=b.num[i]){
				return a.num[i]<b.num[i];
			}
		}
		if(a.len<b.len){
			if(b.num[a.len]!=a.num[0]) return a.num[0]<b.num[a.len];
			else{
				
				for(int i=0;i<min(a.len,b.len-a.len);i++){
					if(a.num[i]!=b.num[a.len+i]) return a.num[i]<b.num[a.len+i];
				}
				
				if(a.len<b.len-a.len){
					return a.num[0]<b.num[2*a.len];
				}
				else return a.num[b.len-a.len]<b.num[0];
			} 
		}
		else{
			if(a.num[b.len]!=b.num[0]) return a.num[b.len]<b.num[0];
			else{
				for(int i=0;i<min(b.len,a.len-b.len);i++){
					if(a.num[b.len+i]!=b.num[i]) return a.num[b.len+i]<b.num[i];
				}
				if(b.len<a.len-b.len){
					return a.num[2*b.len]<b.num[0];
				}
				else return a.num[0]<b.num[a.len-b.len];
			} 
		}
	}
}
int main(){
//	freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",a[i].num);
		a[i].len=strlen(a[i].num);
		a[i].index=0;
	}
	sort(a,a+n,cmp);
	int zeroflag=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].len;j++){
				if(a[i].num[j]=='0'){
					if(zeroflag==1) printf("%c",a[i].num[j]);
					else continue;
				}
				else{
					zeroflag=1;
					printf("%c",a[i].num[j]);
				}
		}
	}
    if(zeroflag==0) printf("0");	
} 
