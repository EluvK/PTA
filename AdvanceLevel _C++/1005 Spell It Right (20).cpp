#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main(){
	char arr[102];
	cin.getline(arr,102);
	int len=strlen(arr);
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=int(arr[i])-48;
	}
	if(!sum){ printf("zero");
	} 
	char narr[5];
	int nlen=0;
	while(sum){
		narr[nlen++]=sum%10+48;
		sum/=10;
	}
//	puts(narr); 
	for(int i=nlen-1;i>=0;i--){
		switch(narr[i]){
			case '1': printf("one");break;
			case '2': printf("two");break;
			case '3': printf("three");break;
			case '4': printf("four");break;
			case '5': printf("five");break;
			case '6': printf("six");break;
			case '7': printf("seven");break;
			case '8': printf("eight");break;
			case '9': printf("nine");break;
			case '0': printf("zero");break;
		}
		if(i) printf(" ");
		
	}
	
}
