#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,a,b;
    cin>>n>>m;
    int gmap[210][210];
    fill(gmap[0],gmap[0]+210*210,0);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        gmap[a][b]=gmap[b][a]=1;
    }

    int k,num;
    cin>>k;
    for(int cnt=1;cnt<=k;cnt++){
        scanf("%d",&num);
        vector<int> arr(num+1);
        for(int i=0;i<num;i++) scanf("%d",&arr[i]);
        arr[num]=0;
        bool flag=true;
        for(int i=0;i<num;i++){
            for(int j=i+1;j<num;j++){
                if(gmap[arr[i]][arr[j]]==0){
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag){
            bool missflag=false;
            int res=-1;
            map<int,int> mp;
            for(int i=0;i<num;i++) mp[arr[i]]=1;
            for(int i=1;i<=n;i++){
                if(mp[i]==0){
                    bool thisflag=true;
                    for(int j=0;j<num;j++){
//                        cout<<arr[j]<<" "<<arr[i]<<endl;
                        if(gmap[arr[j]][i]==0){
                            thisflag=false;
                            break;
                        }
                    }
                    if(thisflag){
                        missflag=true;
                        res=i;
                        break;
                    }
                }
            }
            if(missflag) printf("Area %d may invite more people, such as %d.\n",cnt,res);
            else printf("Area %d is OK.\n",cnt);
        }else printf("Area %d needs help.\n",cnt);
    }

    return 0;
}
