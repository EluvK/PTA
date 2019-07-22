#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <stack>
#define INF 0x3fffffff
using namespace std;

int pre[40];
int in[40];
int post[40];

struct node{
    int data;
    node* left;
    node* right;
};
int ppo=0;
void postorder(node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    post[ppo++]=root->data;
}
node *create(int preL,int preR,int inL,int inR){
    if(inL>inR) return NULL;

    node *root=new node;
    root->data=pre[preL];
    int i;
    for(i=inL;i<inR;i++){
        if(in[i]==pre[preL]) break;
    }
    root->left=create(preL+1,preL+i-inL,inL,i-1);
    root->right=create(preL+i-inL+1,preR,i+1,inR);
    return root;

}

int main(){
//    freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    getchar();
    string str;
    stack<int> st;
    int cnt=0,num,ppre=0,iin=0;
    while(cnt<n){
        getline(cin,str);
        if(str[1]=='u'){
            if(str.length()==6){
                num=str[5]-'0';
            }else{
                num=str[5]-'0';
                num=num*10+str[6]-'0';
            }
            st.push(num);
            pre[ppre++]=num;
        }else{
            num=st.top();
            st.pop();
            in[iin++]=num;
            cnt++;
        }
    }
    node *root=create(0,n-1,0,n-1);
    postorder(root);
    for(int i=0;i<n;i++){
        printf("%d",post[i]);
        if(i!=n-1) printf(" ");
    }
}
