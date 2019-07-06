#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#define MAX 2147483647
using namespace std;



int main(){
//	freopen("1.txt","r",stdin);
	int n,num;
	int a[50],b[50],c[50],re[50];
	int mfa,mfb,mfc;
	int lena,lenb,lenc;
	scanf("%d",&n);
	num=n;
   
	while(n--){
		mfa=0;mfb=0;mfc=0;
		for(int i=0;i<50;i++){
			a[i]=0;b[i]=0;c[i]=0;re[i]=0;
		}
		char sa[50],sb[50],sc[50];
		scanf("%s%s%s",sa,sb,sc);
		if(sa[0]=='-') mfa=1;
		if(sb[0]=='-') mfb=1;
		if(sc[0]=='-') mfc=1;
		if(mfa){
			lena=strlen(sa)-1;
			for(int i=0;i<lena;i++){
				a[i]=sa[lena-i]-'0';
			}
		}else{
			lena=strlen(sa);
			for(int i=0;i<lena;i++){
				a[i]=sa[lena-1-i]-'0';
			}
		}
		if(mfb){
			lenb=strlen(sb)-1;
			for(int i=0;i<lenb;i++){
				b[i]=sb[lenb-i]-'0';
			}
		}else{
			lenb=strlen(sb);
			for(int i=0;i<lenb;i++){
				b[i]=sb[lenb-1-i]-'0';
			}
		}
		if(mfc){
			lenc=strlen(sc)-1;
			for(int i=0;i<lenc;i++){
				c[i]=sc[lenc-i]-'0';
			}
		}else{
			lenc=strlen(sc);
			for(int i=0;i<lenc;i++){
				c[i]=sc[lenc-1-i]-'0';
			}
		}
		for(int i=0;i<50;i++){
			if(mfa) re[i]-=a[i];
			else re[i]+=a[i];
			if(mfb) re[i]-=b[i];
			else re[i]+=b[i];
			if(mfc) re[i]+=c[i];
			else re[i]-=c[i];
		}

		int pflag=0;
		for(int i=49;i>=0;i--){
			if(re[i]!=0){
				if(re[i]>0){
					printf("Case #%d: true\n",num-n);
					pflag=1;
				}
				else{
					printf("Case #%d: false\n",num-n);
					pflag=1;
				}
				break;
			}
		}
		if(!pflag) printf("Case #%d: false\n",num-n);	
	}
	return 0;
} 
