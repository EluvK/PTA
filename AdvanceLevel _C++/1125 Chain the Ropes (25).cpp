#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	int n,temp;
	multiset<double> a;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		a.insert(1.0*temp);
	} 
	double i,j;
	while(a.size()!=1){

		i=*a.begin();
		a.erase(a.begin());
		j=*a.begin();
		a.erase(a.begin());
		a.insert((i+j)/2);
	}
	printf("%d",(int) *a.begin());
	
	
} 

