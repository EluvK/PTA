#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int> mp;
bool combig(string a,string b){
    string ta=a.substr(6,8);
    string tb=b.substr(6,8);
//    cout<<ta<<tb<<endl;
    if(ta>tb) return false;
    else return true;
}
int main(){
//    freopen("1.txt","r",stdin);
    int n,m,cnt=0;
    cin>>n;
    vector<string> clist(n);
    for(int i=0;i<n;i++){
        cin>>clist[i];
        mp[clist[i]]=1;
    }
    cin>>m;
    string temp,mx1="372928999999998710",mx2="372928999999998710";
    for(int i=0;i<m;i++){
        cin>>temp;
        if(combig(temp,mx2)){
            mx2=temp;
        }
        if(mp[temp]==1){
            cnt++;
            if(combig(temp,mx1)) mx1=temp;
        }
    }
    printf("%d\n",cnt);
    if(cnt) cout<<mx1;
    else cout<<mx2;
}
