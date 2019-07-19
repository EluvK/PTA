#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
int father[10010];

int findF(int a){
    if(father[a]==a) return a;
    else{
        int F=findF(father[a]);
        father[a]=F;
        return F;
    }
}

int main(){
//	freopen("1.txt","r",stdin);
	int n,temp,a,b,num,first;
    set<int> all;
    set<int> fa;
	for(int i=0;i<10010;i++){
        father[i]=i;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
        scanf("%d",&num);
        if(num){
            scanf("%d",&first);
            all.insert(first);
            first=father[first];
            for(int j=1;j<num;j++){
                scanf("%d",&temp);
                all.insert(temp);
                if(father[temp]!=temp){
                    father[findF(temp)]=first;
                }
                father[temp]=first;
            }
        }
	}

	for(set<int>::iterator it=all.begin();it!=all.end();it++){
//        printf("%d:%d\n",*it,findF(*it));
        fa.insert(findF(*it));
	}
	printf("%d %d\n",fa.size(),all.size());
	scanf("%d",&num);
	for(int i=0;i<num;i++){
        scanf("%d%d",&a,&b);
        if(findF(a)==findF(b)) printf("Yes\n");
        else printf("No\n");
	}
}
