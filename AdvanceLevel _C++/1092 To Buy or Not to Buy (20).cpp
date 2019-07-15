#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
 	int num[200]={0};
 	string a,b;
 	cin>>a>>b;
 	for(int i=0;i<a.length();i++){
 		num[int(a[i])]++;	
	}
	int mis=0; 
	for(int i=0;i<b.length();i++){
		if(num[int(b[i])]>0){
			num[int(b[i])]--; 
		}else{
			mis++;
		}
	} 
	if(mis){
		printf("No %d",mis);
	}else{
		printf("Yes %d",a.length()-b.length());
	}
}
