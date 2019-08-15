#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    string str;
    int n,i,j,len;
    map<char,int> tag,in;
    cin>>n>>str;
    len=str.length();
    vector<char> res;
    for(i=0;i<len;i=j){
        j=i;
        while(j<len&&str[j]==str[i]) j++;
        if((j-i)%n!=0) tag[str[i]]=1;
    }
    for(i=0;i<len;i++){
        if(tag[str[i]]==0&&in[str[i]]==0){
           res.push_back(str[i]);
           in[str[i]]=1;
        }
    }
    for(i=0;i<res.size();i++) printf("%c",res[i]);
    printf("\n");
    for(i=0;i<len;i++){
        if(tag[str[i]]==0) i=i+n-1;
        printf("%c",str[i]);
    }
}
