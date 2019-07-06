#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#define MAX 10000

using namespace std;

char i2c(int n){
	if(n<10) return n+48;
	else if(n==10) return 'A';
	else if(n==11) return 'B';
	else if(n==12) return 'C';
}
void pri13(int n){
	char res;
	int temp;
	temp=n%13;
	res=i2c(temp);
	if(n/13) printf("%c",i2c(n/13));
	else printf("0");
	printf("%c",res);
	return;
}


int main(){
//	freopen("1.txt","r",stdin);
	
	int num;
	printf("#");
	while(scanf("%d",&num)!=EOF){
		pri13(num);
	}
	
	
	
	
} 
