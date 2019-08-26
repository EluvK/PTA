#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    string str;
    cin>>str;
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    vector<string> res;
    int sum=0;
    for(int i=0;i<str.length();i++) sum+=str[i]-'0';
    do{

        int temp=sum%10;;
        res.push_back(arr[temp]);
        sum/=10;
    }while(sum);
    for(int i=res.size()-1;i>=0;i--){
        if(i!=res.size()-1) cout<<" ";
        cout<<res[i];
    }
    return 0;
}
