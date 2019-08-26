#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct student{
    char name[15];
    char gender;
    char id[15];
    int grade;
}s,MAX,MIN;
int main(){
//    freopen("1.txt","r",stdin);
    int n;
    MAX.grade=-1;
    MIN.grade=101;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s.name>>s.gender>>s.id>>s.grade;
        if(s.gender=='M'&&s.grade<MIN.grade)
                MIN=s;
        else if(s.gender=='F'&&s.grade>MAX.grade)
                MAX=s;
    }
    if(MAX.grade==-1) cout<<"Absent"<<endl;
    else cout<<MAX.name<<" "<<MAX.id<<endl;
    if(MIN.grade==101) cout<<"Absent"<<endl;
    else cout<<MIN.name<<" "<<MIN.id<<endl;
    if(MAX.grade==-1||MIN.grade==101) cout<<"NA"<<endl;
    else cout<<MAX.grade-MIN.grade<<endl;
    return 0;
}
