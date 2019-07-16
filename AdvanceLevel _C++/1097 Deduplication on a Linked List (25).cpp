#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

struct node{
	int key;
	int next;	
}a[100010];

int main(){
//	freopen("1.txt","r",stdin);
	int s,n,adress;
	vector<int> r,w;
	scanf("%d%d",&s,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&adress);
		scanf("%d%d",&a[adress].key,&a[adress].next);
	}
	int s1=s;
	int map[20010];
	for(int i=0;i<20010;i++){
		map[i]=-1;
	}
	do{
		int temp=a[s1].key;
		if(temp<0) temp*=-1;
		if(map[temp]==-1){
			map[temp]=s1;
			r.push_back(s1);
		}else{//已经存在的数字
			w.push_back(s1);
		}
		s1=a[s1].next;
	}while(s1!=-1);
	
	for(int i=0;i<r.size();i++){
		printf("%05d %d ",r[i],a[r[i]].key);
		if(i==r.size()-1) printf("-1\n");
		else printf("%05d\n",r[i+1]);
	}
//	printf("\n");
	for(int i=0;i<w.size();i++){
		printf("%05d %d ",w[i],a[w[i]].key);
		if(i==w.size()-1) printf("-1\n");
		else printf("%05d\n",w[i+1]);
	}
}
