#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


int main(){
//	freopen("1.txt","r",stdin);
	
	int a1,b1,c1;
	int a2,b2,c2;
	scanf("%d.%d.%d",&a1,&b1,&c1);
	scanf("%d.%d.%d",&a2,&b2,&c2);
	c1+=c2;
	b1+=b2+(c1/29);
	c1=c1%29;
	a1+=a2+(b1/17);
	b1=b1%17;
	printf("%d.%d.%d",a1,b1,c1); 
	
} 
