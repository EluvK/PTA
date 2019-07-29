#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3fffffff
using namespace std;

struct info{
    char level;
    int site;
    int date;
    int num;
    int grade;
    info(char c,int s,int d,int n,int g){level=c;site=s;date=d;num=n;grade=g;}
};
struct node{
    int site;
    int num;
    node(int s,int n){site=s;num=n;}
};
int n3[1010];
int N,M;

int cb(char a,char b,char c){
    return (a-'0')*100+(b-'0')*10+(c-'0');
}
bool cmp1(info a,info b){
    if(a.level!=b.level) return a.level>b.level;
    else if(a.grade!=b.grade) return a.grade>b.grade;
    else if(a.site!=b.site) return a.site<b.site;
    else if(a.date!=b.date) return a.date<b.date;
    else return a.num<b.num;
}
bool cmp2(node a,node b){
    if(a.num!=b.num) return a.num>b.num;
    else return a.site<b.site;
}
int main(){
//    freopen("1.txt","r",stdin);
    scanf("%d%d",&N,&M);
    string str;
    char c;
    int s,d,n,g,temp,type;
    vector<info> A;
    for(int i=0;i<N;i++){
        cin>>str>>g;
        c=str[0];
        s=cb(str[1],str[2],str[3]);
        d=cb(str[4],str[5],str[6])*1000+cb(str[7],str[8],str[9]);
        n=cb(str[10],str[11],str[12]);
        A.push_back(info(c,s,d,n,g));
    }
    for(int i=1;i<=M;i++){
        scanf("%d",&temp);
        if(temp==1){
            getchar();
            scanf("%c",&c);
            printf("Case %d: %d %c\n",i,temp,c);
            int st,cnt=0;
            st=A.size();
            sort(A.begin(),A.end(),cmp1);
            for(int j=0;j<A.size();j++){
                if(A[j].level==c){
                    st=min(st,j);cnt++;
                }
            }
            if(cnt==0) printf("NA\n");
            else{
                for(int j=st;j<st+cnt;j++){
                    printf("%c%03d%06d%03d %d\n",A[j].level,A[j].site,A[j].date,A[j].num,A[j].grade);
                }
            }
        }else if(temp==2){
            scanf("%d",&type);
            printf("Case %d: %d %03d\n",i,temp,type);
            int cnt=0,sum=0;
            for(int j=0;j<A.size();j++){
                if(A[j].site==type){
                    cnt++;sum+=A[j].grade;
                }
            }
            if(cnt==0) printf("NA\n");
            else printf("%d %d\n",cnt,sum);

        }else{
            scanf("%d",&type);
            printf("Case %d: %d %06d\n",i,temp,type);
            fill(n3,n3+1010,0);
            for(int j=0;j<A.size();j++){
                if(A[j].date==type){
                    n3[A[j].site]++;
                }
            }
            vector<node> res;
            for(int j=0;j<1000;j++){
                if(n3[j]) res.push_back(node(j,n3[j]));
            }
            if(res.size()==0) printf("NA\n");
            else {
               sort(res.begin(),res.end(),cmp2);
                for(int j=0;j<res.size();j++){
                    printf("%03d %d\n",res[j].site,res[j].num);
                }
            }
        }
    }
    return 0;
}
