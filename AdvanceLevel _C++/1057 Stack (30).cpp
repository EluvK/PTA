#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
vector<int> a,b;

int main(){
//    freopen("1.txt","r",stdin);
    int n,num;
    char inst[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",inst);
        if(inst[1]=='o'){
            if(a.empty())
                printf("Invalid\n");
            else{
                int temp=a[a.size()-1];
                a.pop_back();
                b.erase(lower_bound(b.begin(),b.end(),temp));
                printf("%d\n",temp);
            }
        }else if(inst[1]=='u'){
            int temp;
            scanf("%d",&temp);
            a.push_back(temp);
            b.insert(lower_bound(b.begin(),b.end(),temp),temp);
        }else{
            if(a.empty())
                printf("Invalid\n");
            else{
                int temp=(b.size()+1)/2-1;
                printf("%d\n",b[temp]);
            }
        }
    }
}
