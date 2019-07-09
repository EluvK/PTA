#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct info{
	char name[40];
	int age;
	int worth;
}A[100010];
 
 
bool cmp(info a,info b){
	if(a.worth!=b.worth) return a.worth>b.worth;
	else if(a.age!=b.age) return a.age<b.age;
	else return strcmp(a.name,b.name)<0;
}
 
int main(){
//	freopen("1.txt","r",stdin);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s%d%d",A[i].name,&A[i].age,&A[i].worth);
	}
	
	sort(A,A+n,cmp);
	int num,min,max,nn;
	for(int i=1;i<=k;i++){
		
		scanf("%d%d%d",&num,&min,&max);
		nn=num;
		printf("Case #%d:\n",i);
		for(int j=0;j<n;j++){
			if(A[j].age>=min&&A[j].age<=max){
				printf("%s %d %d\n",A[j].name,A[j].age,A[j].worth);
				num--;
			}
			if(num==0) break;
		}
		if(num==nn) printf("None\n");
		
	}
	return 0;
 }
