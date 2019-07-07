#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <set>
#include <math.h>
#define MAX 2147483647
using namespace std;



int main(){
//	freopen("1.txt","r",stdin);
	int n,m,temp;
	int c[1001]={0};
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		c[temp]++;
	} 
//	sort(c,c+n);
	for(int i=0;i<1001;i++){
		if(c[i]){
			c[i]--;
			if(m>i&&c[m-i]){
				printf("%d %d",i,m-i);
				return 0;
			}
			c[i]++;
		}
	}
	printf("No Solution");
	return 0;
//
//	int i=0,j=1,sum;
//	if(n>10000){
//		j=n-1;
//		for(j=n-1;c[j]>m/2-1;j--){
//			for(i=0;i<n;i++){
//				if(c[i]+c[j]==m){
//					printf("%d %d",c[i],c[j]);
//					return 0;
//				}else if(c[i]+c[j]>m){
//					break;
//				}
//			}
//		}
//		printf("No Solution");
//		return 0;
//		
////		while(i<n&&j>0&&c[i]<c[j]){
////			sum=c[i]+c[j];
////			if(sum>m){
////				j--;
////			}else if(sum<m){
////				i++;
////			}else{
////				printf("%d %d",c[i],c[j]);
////				return 0;
////			}
////		}
////		printf("No Solution");
////		return 0;
//	}
//	int rea=9999,reb=9999;
//	while(i<n&&j<n&&c[i]<=m&&c[j]<=m){
//		sum=c[i]+c[j];
//		if(sum==m){
//			if(rea>c[i]){
//				rea=c[i];reb=c[j];
//			}
//			j++;i=j-1;
//		}else if(sum<m){
//			j++;
//			i=j-1;
//		}else if(i){
//				i--;
//		}else{
//			break;
//		}
//	}
//	if(rea!=9999){
//		printf("%d %d",rea,reb); 
//	}else{
//		printf("No Solution");
//	}
 } 
