#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

/*
	printf("%d\n",'a');
	printf("%d\n",'z');
	printf("%d\n",'A');
	printf("%d\n",'Z');
	printf("%d\n",'0');
	printf("%d\n",'9');
*/
struct word{
	int num;
	char word[1000];
};
bool chardef(char c){
	int cc=int(c);
	if((cc>=97&&cc<=122)||(cc>=65&&cc<=90)||(cc>=48&&cc<=57)) return true;
	else return false;
}
char small(char c){
	int cc=int(c);
	if(cc>=65&&cc<=90) return c+32;
	else return c;
}
bool cmp(word a,word b){
	if(a.num!=b.num) return a.num>b.num;
	else return a.word[0]<b.word[0];
}
int main(){
//	freopen("1.txt","r",stdin);
	word A[1000];
	char temp[1048577];
	char c;
	char tempword[1000];
	cin.getline(temp,1048577);
	int len=strlen(temp);
	int in=0;
	int ain=0;
	int readin=1;
	for(int i=0;i<len;i++){
		c=temp[i];
		if(chardef(c)&&i!=len-1){
			tempword[in++]=small(c);
		}
		else{
			if(chardef(c)&&i==len-1) tempword[in++]=small(c);
			if(in==0) continue;
			else{
				for(int j=0;j<ain;j++){
					if(strcmp(A[j].word,tempword)==0){
						A[j].num++;
						readin=0;
						break;
					}
				}
				if(readin){
					strcpy(A[ain].word,tempword);
					A[ain].num=1;
					ain++;
					readin=1;
				}
				in=0;
				memset(tempword,0,1000);
			}
		}
	}
	int maxi=0;
	int maxnum=0;
	sort(A,A+ain,cmp);
	if(ain){
		printf("%s %d",A[0].word,A[0].num);
	}
	else printf("0");
	
	return 0;
	
//	for(int i=0;i<ain;i++){
//		if(A[i].num>maxnum){
//			maxi=i;
//			maxnum=A[i].num;
//		}
//	}	
//	printf("%s %d",A[maxi].word,maxnum);
} 
