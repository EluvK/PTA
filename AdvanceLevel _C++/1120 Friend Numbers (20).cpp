#include <stdio.h>
#include <iostream>
#include <set>
 
using namespace std;

int change(int n){
	int sum=0;
	while(n){
		sum+=n%10;
		n/=10;
	}
	return sum;
}

int main(){
//	freopen("1.txt","r",stdin);
	int n,temp;
	cin>>n;
	set<int> st;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		st.insert(change(temp));
	}
	printf("%d\n",st.size());
	for(set<int>::iterator it=st.begin();it!=st.end();it++){
		if(it!=st.begin()) printf(" ");
		printf("%d",*it);
	}
}

