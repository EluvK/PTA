#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
//    freopen("1.txt","r",stdin);
    string name,in,out,rin="23:59:59",rout="00:00:00",iname,outname;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name>>in>>out;
        if(in<rin){
            rin=in;
            iname=name;
        }
        if(out>rout){
            rout=out;
            outname=name;
        }
    }
    cout<<iname<<" "<<outname;
    return 0;
}
