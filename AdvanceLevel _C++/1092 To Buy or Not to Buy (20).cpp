#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    string s1,s2;
    int cnt=0,cnt2=0;
    cin>>s1>>s2;
    int num[200]={0};
    for(int i=0;i<s2.length();i++)
        num[s2[i]]++;
    for(int i=0;i<s1.length();i++){
        if(num[s1[i]]){
            num[s1[i]]--;
        }
        else cnt++;
    }
    for(int i=0;i<200;i++){
        if(num[i]) cnt2+=num[i];
    }
    if(cnt2) printf("No %d",cnt2);
    else printf("Yes %d",cnt);

    return 0;
}
