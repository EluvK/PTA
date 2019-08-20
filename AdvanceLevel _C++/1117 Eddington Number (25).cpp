#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());
    for(int i=0;i<n;i++){
        if(a[i]<=i+1){
            cout<<i;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
