#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> f[10000];
bool isgirl[10000];
vector<int> res;
bool ext(int d,int b){
    for(int i=0;i<f[d].size();i++){
        if(f[d][i]==b) return true;
    }
    return false;
}
int str2i(string str){
    int len=str.length();
    bool mf=(str[0]=='-')?true:false;
    int sum=0;
    for(int i=0;i<len;i++){
        if(str[i]!='-'){
            sum=sum*10+str[i]-'0';
        }
    }
    return mf?sum*-1:sum;
}
int main(){
//    freopen("1.txt","r",stdin);
    int n,m,a,b,num;
    string sa,sb;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        cin>>sa>>sb;
        if(sa[0]=='-'&&sa[1]=='0'&&sa[2]=='0'&&sa[3]=='0'&&sa[4]=='0'){
            isgirl[0]=true;
        }
        if(sb[0]=='-'&&sb[1]=='0'&&sb[2]=='0'&&sb[3]=='0'&&sb[4]=='0'){
            isgirl[0]=true;
        }
//        scanf("%d%d",&a,&b);
        a=str2i(sa);b=str2i(sb);
        if(a<0) isgirl[abs(a)]=true;
        if(b<0) isgirl[abs(b)]=true;
        f[abs(a)].push_back(abs(b));
        f[abs(b)].push_back(abs(a));
    }
    for(int i=0;i<10000;i++){
        if(!f[i].empty()){
            sort(f[i].begin(),f[i].end());
        }
    }
    bool flaga,flagb;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d%d",&a,&b);
        a=abs(a);b=abs(b);
        flaga=isgirl[a];flagb=isgirl[b];
        res.clear();
        for(int j=0;j<f[a].size();j++){
            int c=f[a][j];
            if(isgirl[c]==flaga&&c!=b){
                for(int k=0;k<f[c].size();k++){
                    int d=f[c][k];
                    if(isgirl[d]==flagb&&d!=a&&ext(d,b)){
                        res.push_back(c);
                        res.push_back(d);
                    }
                }
            }
        }
        printf("%d\n",res.size()/2);
        for(int i=0;i<res.size();i=i+2){
            printf("%04d %04d\n",res[i],res[i+1]);
        }
    }


    return 0;
}
