#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>
#define MAX 10000

using namespace std;

struct gasstation{
	double price;
	double distance;
}; 
bool cmp(gasstation a,gasstation b){
	return a.distance<b.distance;
}

int main(){
//	freopen("1.txt","r",stdin);
	int num;
	double tankc,dis,rate;
	scanf("%lf%lf%lf%d",&tankc,&dis,&rate,&num);
	vector<gasstation> A;
	A.resize(num+1);
	for(int i=0;i<num;i++){
		scanf("%lf%lf",&A[i].price,&A[i].distance);
	}
	A[num].price=99999;
	A[num].distance=dis;
	sort(A.begin(),A.end(),cmp);
	
//	for(int i=0;i<A.size();i++){
//		
//		printf("%.0lf:%.2lf\n",A[i].distance,A[i].price);
//	}
	
	double regas=dis/rate;//��Ҫ���͵����� 
	double maxdis=tankc*rate;//�����ʻ���붨ֵ 
	double godis=0;//��ǰ��ʻ���롣 
	int gasi=0;//��ǰ����վ����� 
	int mini=-1;//���Լ�ļ���վ 
	bool fullflag;//�Ƿ����  price:mini<gasi false;
	bool nextflag=false;//�ܷ������ 
	double minp=999999;//����˼���վ�۸� 
	double sum=0;//���� 
	double tankn=0;//��ǰ���� 
	if(A[0].distance!=0){
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	while(godis!=dis){
		//��ʼ��ÿ�� 
		minp=999999;
		nextflag=false;
		fullflag=false;
		
		for(int i=gasi+1;i<A.size();i++){
			if(A[i].distance-A[gasi].distance<=maxdis){
				
				nextflag=true;
				if(A[i].price<minp){
					mini=i;
					minp=A[i].price;
					if(A[i].price<A[gasi].price){
						break;
					}
				}
			}
			else break; 
		}
		if(nextflag){
			if(A[gasi].price<A[mini].price) fullflag=true;
			else fullflag=false;
		} 
		else{//��Χ�ھ�û����վ 
			printf("The maximum travel distance = %.2f",godis+maxdis);
			return 0; 
		}
		
		//���ͣ�
		//ʣ�¾���ֱ�ӵ��� 
		if(fullflag){
			if(dis-godis<maxdis){
				sum+=((dis-godis)/rate-tankn)*A[gasi].price;
				regas-=(dis-godis)/rate-tankn;
				tankn=(dis-godis)/rate;
			}
			else{
				sum+=(tankc-tankn)*A[gasi].price;
				regas-=tankc-tankn;
				tankn=tankc;
			}
			
		}
		else{
			sum+=((A[mini].distance-A[gasi].distance)/rate-tankn)*A[gasi].price;
			regas-=(A[mini].distance-A[gasi].distance)/rate-tankn;
			tankn=(A[mini].distance-A[gasi].distance)/rate;
		}  
		//������һվ�� 
		
		tankn=tankn-((A[mini].distance-A[gasi].distance)/rate);
		gasi=mini;
		godis=A[gasi].distance;
		
	} 
	printf("%.2f",sum);
	
	
	return 0;
	
} 
