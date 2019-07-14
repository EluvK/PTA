#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stack> 
#include <algorithm>
using namespace std;


int main(){
//	freopen("1.txt","r",stdin);
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	stack<int> a,ori;
	bool no;
	for(int i=0;i<k;i++){
		while(!a.empty()) a.pop();
		while(!ori.empty()) ori.pop();
		no=false;
		for(int i=n;i>0;i--){
			ori.push(i);
		}
		int temp,j;
		for(j=0;j<n;j++){
			scanf("%d",&temp);
			if(!ori.empty()){
				while(!ori.empty()&&ori.top()<=temp){
					a.push(ori.top());
					if(a.size()>m) 
						no=true;
					ori.pop();	
				}	
			}
			if(a.top()==temp){
				a.pop();
			}else{
				no=true;
			}
		}
		if(no) printf("NO\n");
		else printf("YES\n");
	}
}
