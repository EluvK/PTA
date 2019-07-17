#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

int main(){
//	freopen("1.txt","r",stdin);
	int n,num,temp,thistree,thattree,first,newtreei=1;
	vector<int> tree[10010];
	cin>>n;
	int book[10010]={0};
	
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		if(num){
			scanf("%d",&first);
			if(book[first]==0){//不存在 
				thistree=newtreei;
				newtreei++;
				book[first]=thistree;
				tree[thistree].push_back(first);
			}else{//存在
				thistree=book[first];
			}
			for(int j=1;j<num;j++){
				scanf("%d",&temp);
				if(book[temp]==0||book[temp]==thistree){
					if(book[temp]==0){
						tree[thistree].push_back(temp);					
						book[temp]=thistree;
					}
				}else{
					//把那棵树的节点全部移过来。 
					thattree=book[temp];
					for(int i=0;i<tree[thattree].size();i++){
						tree[thistree].push_back(tree[thattree][i]);
						book[tree[thattree][i]]=thistree;
					}
					tree[thattree].clear();
//					tree[thattree].erase(tree[thattree].begin(),tree[thattree].end());
					vector<int>().swap(tree[thattree]);

				}
			}
		}
	}
	
	int sum=0,treenum=0;
	for(int i=1;i<newtreei;i++){
		if(tree[i].size()){
			treenum++;
		}
		sum+=tree[i].size();
	}
	printf("%d %d\n",treenum,sum);
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		if(book[a]==book[b]){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	
}

