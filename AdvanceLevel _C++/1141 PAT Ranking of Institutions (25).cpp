#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

struct info{
	string school;
	double sum;
	int ranksum;
	int num; 
}a[100010];
bool cmp(info a,info b){
	if(a.ranksum!=b.ranksum) return a.ranksum>b.ranksum;
	else if(a.num!=b.num) return a.num<b.num;
	else return a.school<b.school;
}

int main(){
//	freopen("1.txt","r",stdin);
	string id,temp;
	int n,s,in=1,flag=0;
	cin>>n;
	map<string,int> mp;
	for(int i=0;i<n;i++){
		cin>>id>>s>>temp;
		if(id[0]=='B') flag=-1;
		else if(id[0]=='A') flag=0;
		else if(id[0]=='T') flag=1;
		transform(temp.begin(),temp.end(),temp.begin(),::tolower);
		if(mp[temp]==0){
			mp[temp]=in;
			a[in].school=temp;
			a[in].sum=s*pow(1.5,flag);
			a[in].num=1;
			in++;
		}
		else{
			a[mp[temp]].sum+=s*pow(1.5,flag);
			a[mp[temp]].num++;
		}
	}
	for(int i=1;i<in;i++){
		a[i].ranksum=(int)a[i].sum;
	}
	sort(a+1,a+in,cmp);
	int rank=1;
	printf("%d\n",in-1);
	for(int i=1;i<in;i++){
		if(i!=1&&a[i].ranksum==a[i-1].ranksum){
			
		}
		else rank=i;
		cout<<rank<<" "<<a[i].school<<" "<<a[i].ranksum<<" "<<a[i].num<<endl;
	}
} 
