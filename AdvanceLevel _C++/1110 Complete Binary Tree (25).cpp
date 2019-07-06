#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#define MAX 100000
//freopen("1.txt","r",stdin);
using namespace std;

struct node{
	int value;
	node* left;
	node* right;
};

int N;
int loder[30];
int in=0;
int layerorder(node *root){
	in=0; 
	queue<node*> q;
	q.push(root);
	int num=0;
	while(!q.empty()){
		node* now=q.front();
		loder[in++]=now->value;
		q.pop();
		num++;
		if(now->left!=NULL) q.push(now->left);
		if(now->right!=NULL) q.push(now->right);
	}
	return num;
}

int convert(char a[]){
	int len=strlen(a);
	int sum=0;
	sum+=a[0]-48;
	for(int i=1;i<len;i++){
		sum*=10; 
		sum+=a[i]-48;
	}
	return sum;
}
int main(){
	// freopen("1.txt","r",stdin);
	scanf("%d",&N);

	node arr[N];
	char a[5];
	char b[5];
	getchar(); 
	for(int i=0;i<N;i++){
		scanf("%s %s",a,b);
		arr[i].value=i;
		if(a[0]!='-') arr[i].left=arr+convert(a);
		else arr[i].left=NULL;
		if(b[0]!='-') arr[i].right=arr+convert(b);
		else arr[i].right=NULL;
		getchar();
	}
//		printf("%d",arr[0].left->value);
	int root=0;
	for(root=0;root<N;root++){
		if(layerorder(&arr[root])==N) break;
	}
//		printf("%d",root);
	int sca;
	for(sca=0;sca<N;sca++){
		if(arr[loder[sca]].left!=NULL){
			if(arr[loder[sca]].right!=NULL){
				continue;
			}
			else{
				break;
			}
		}
		else if(arr[loder[sca]].right!=NULL){
			sca=-33;break;
		} 
		else{
			break;
		}
		
//		if(arr[loder[sca]].left!=NULL&&arr[loder[sca]].right!=NULL){
//			continue;
//		}
//		else if(arr[loder[sca]].left!=NULL&&arr[loder[sca]].right==NULL){
//			break;
//		}
//		else if(arr[loder[sca]].left==NULL&&arr[loder[sca]].right==NULL){
//			break;
//		}
//		else{
//			sca=-1;
//			break;
//		}
	}
	if(sca<0){
		printf("NO %d",root);
		return 0;
	}
	for(sca++;sca<N;sca++){
		if(arr[loder[sca]].left!=NULL||arr[loder[sca]].right!=NULL){
			printf("NO %d",root);
			return 0;
		}
	} 
	printf("YES %d",loder[sca-1]);
	return 0;
		
		

}
