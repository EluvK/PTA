#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <math.h>
#define MAX 2147483647
using namespace std;



int main() {
//	freopen("1.txt","r",stdin);

	char a[80],b[80],c[80],d[80];
	scanf("%s%s%s%s",a,b,c,d);
	char res[2];
	int i=0;
	while(i<strlen(a)&&i<strlen(b)){
		if(a[i]==b[i]&&a[i]>='A'&&a[i]<='G'){
			res[0]=a[i];
			break;
		}
		i++;
	}
	i++;
	while(i<strlen(a)&&i<strlen(b)){
		if(a[i]==b[i]&&((a[i]>='A'&&a[i]<='N')||(a[i]>='0'&&a[i]<='9'))){
			res[1]=a[i];
			break;
		}
		i++;
	}
	int j=0;
	int min;
	while(j<strlen(c)&&j<strlen(d)){
		if(c[j]==d[j]&&((c[j]>='A'&&c[j]<='Z')||(c[j]>='a'&&c[j]<='z'))){
			min=j;
			break;	
		}
		j++;
	}
	string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int hour=(res[1]<='9'&&res[1]>='0')?res[1]-'0':res[1]-'A'+10;
	cout<<week[res[0]-'A'];
	printf(" %02d:%02d",hour,min);
	return 0;
}
