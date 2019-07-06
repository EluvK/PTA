#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct book{
	int num;//Êä³ö%07d
	char title[100];
	char author[100];
	char keyword[5][15];
	char publisher[100];
	char pubyear[5];
	 
}A[10000];
int N;

void se1(char c[]){
//	printf("1: %s\n",c);
	bool findflag=false;
	for(int i=0;i<N;i++){
		if(strcmp(A[i].title,c)==0){
			printf("%07d\n",A[i].num);
			findflag=true;
		}
	}
	if(!findflag) printf("Not Found\n"); 
}
void se2(char c[]){
//	printf("2: %s\n",c);
	bool findflag=false;
	for(int i=0;i<N;i++){
		if(strcmp(A[i].author,c)==0){
			printf("%07d\n",A[i].num);
			findflag=true;
		}
	}
	if(!findflag) printf("Not Found\n"); 
}
void se3(char c[]){
//	printf("3: %s\n",c);
	bool findflag=false;
	for(int i=0;i<N;i++){
		for(int j=0;j<5;j++){
			if(strcmp(A[i].keyword[j],c)==0){
				printf("%07d\n",A[i].num);
				findflag=true;
			}
		}
	}
	if(!findflag) printf("Not Found\n"); 
}
void se4(char c[]){
//	printf("4: %s\n",c);
	bool findflag=false;
	for(int i=0;i<N;i++){
		if(strcmp(A[i].publisher,c)==0){
			printf("%07d\n",A[i].num);
			findflag=true;
		}
	}
	if(!findflag) printf("Not Found\n"); 
}
void se5(char c[]){
//	printf("5: %s\n",c);
	bool findflag=false;
	for(int i=0;i<N;i++){
		if(strcmp(A[i].pubyear,c)==0){
			printf("%07d\n",A[i].num);
			findflag=true; 
		}
	}
	if(!findflag) printf("Not Found\n"); 
}
bool cmp(book a,book b){
	return a.num<b.num;
}




int main(){
//	freopen("1.txt","r",stdin);
	
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i].num);
		getchar();scanf("%[^\n]",A[i].title);
		getchar();scanf("%[^\n]",A[i].author);
		char keywordtemp[100];
		getchar();scanf("%[^\n]",keywordtemp);
		int number=0;
		int k=0;
		for(int j=0;j<strlen(keywordtemp);j++){
			char c;
			c=keywordtemp[j];
			if(c!=' '){
				A[i].keyword[number][k++]=c;
			}
			else{
				number++;k=0; 
			}
		}
		getchar();scanf("%[^\n]",A[i].publisher);
		getchar();scanf("%[^\n]",A[i].pubyear);
	}
	sort(A,A+N,cmp); 
	int M;
	scanf("%d",&M);
	int in;
	char search[100];
	for(int i=0;i<M;i++){
		
		scanf("%d: %[^\n]",&in,search);
		
		printf("%d: %s\n",in,search);
		
		switch(in){
			case 1: se1(search);break;
			case 2: se2(search);break;
			case 3: se3(search);break;
			case 4: se4(search);break;
			case 5: se5(search);break;
		}
	}
	return 0;
}
