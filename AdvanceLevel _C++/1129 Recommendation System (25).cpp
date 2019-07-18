#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct info{
	int qnum;
	int time;
	
	bool operator <(const info &a) const{
		return (time!=a.time)?time>a.time:qnum<a.qnum;
	}
};

int main(){
//	freopen("1.txt","r",stdin);
	int n,k,temp;
	set<info> st;
	int book[50010]={0};
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(i){
			printf("%d:",temp);
			int cnt=0;
			for(set<info>::iterator it=st.begin();cnt<k&&it!=st.end();it++){
				printf(" %d",it->qnum);
				cnt++;
			}
			printf("\n");
		}
//		info node;
//		node.qnum=temp;
//		node.time=book[temp];
		set<info>::iterator it =st.find(info{temp,book[temp]});
		if(it!=st.end()) st.erase(it);
		book[temp]++;
		st.insert(info{temp,book[temp]});
		
	}
	return 0;
}

