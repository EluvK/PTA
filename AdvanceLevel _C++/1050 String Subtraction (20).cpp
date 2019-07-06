#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#define MAX 10011

using namespace std;


int main(){
	// freopen("1.txt","r",stdin);
	char s1[MAX];
	char s2[MAX];
	scanf("%[^\n]",s1);
	getchar();//读取缓冲区的换行符 
	scanf("%[^\n]",s2);
	
	int len1=strlen(s1);
	int len2=strlen(s2);
	
	int count=0;
	int a[MAX]={0}; 
	for(int i=0;i<len2;i++){
		for(int j=0;j<len1;j++){
			if(s1[j]==s2[i]){
				a[j]=1;
			}
		}
	} 
	for(int i=0;i<len1;i++){
		if(a[i]) continue;
		printf("%c",s1[i]);
	}
	
//	
//	
//	
//	int a[len1]={0};
//	int index=0;
//	for(int i=0;i<len1;i++){
//		if(s1[i]=='0'){
//			index++;
//		}
//		else a[i]=index;
//	}
//	char str[len1];
//	for(int i=0;i<len1;i++){
//		str[i-a[i]]=s1[i];
//	}
//	str[len1-count]='\0';
//	printf("%s",str);
} 
