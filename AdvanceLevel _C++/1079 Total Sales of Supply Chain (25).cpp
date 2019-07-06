#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#define MAX 100000
using namespace std;

struct node{
	double price,num;
	vector<int>child;
	int visited;
}info[MAX];
int N;
double price;
double rate;

void DFS(int root,int layer){
		if(info[root].visited) return;
		info[root].price=price*pow((100+rate)/100,layer);
		info[root].visited=1;
		for(int j=0;j<info[root].child.size();j++){
			DFS(info[root].child[j],layer+1);
		}
		return; 
}

int main(){
	
	
	scanf("%d %lf %lf",&N,&price,&rate);
	
	for(int i=0;i<N;i++){
		int tempnum;
		int tempchild;
		int tempamount;
		scanf("%d",&tempnum);
		if(tempnum){
			info[i].num=0;
			for(int j=0;j<tempnum;j++){
				scanf("%d",&tempchild);
				info[i].child.push_back(tempchild);
			}
		}
		else{
			scanf("%d",&tempamount);
			info[i].num=tempamount;
		}
		info[i].visited=0;
	}
	DFS(0,0);
	double sum=0;
	for(int i=0;i<N;i++){
		if(info[i].num){
			sum+=info[i].num*info[i].price;
		}
	}
	printf("%.1f",sum);
}
