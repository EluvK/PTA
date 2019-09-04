//未能AC 仅为保存代码
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
    int data;
    node *left,*right;
};
struct form{
    int left,right,parent;
}A[1010];
int leveln[1010];
vector<int> post,in,layer;
int n,m;
node *root=new node();
node * create(int postl,int postr,int inl,int inr){
    if(postl>postr||inl>inr) return NULL;

    node *root=new node();
    root->data=post[postr];

    int k;
    for(k=inl;k<=inr;k++){
        if(in[k]==post[postr]) break;
    }
    int leftlen=k-inl,rightlen=inr-k;
    root->left=create(postl,postl+leftlen-1,inl,inl+leftlen-1);
    root->right=create(postl+leftlen,postr-1,k+1,inr);
    return root;
}

void layerorder(node *root){
    queue<node *> q;
    q.push(root);
    leveln[root->data]=1;
    while(!q.empty()){
        node *f=q.front();
        layer.push_back(f->data);
        q.pop();
        if(f->left!=NULL){
            q.push(f->left);
            leveln[f->left->data]=leveln[f->data]+1;
            A[f->data].left=f->left->data;
            A[f->left->data].parent=f->data;
        }
        if(f->right!=NULL){
            q.push(f->right);
            leveln[f->right->data]=leveln[f->data]+1;
            A[f->data].right=f->right->data;
            A[f->right->data].parent=f->data;
        }
    }
}

int tonum(string num){
    int sum=0;
    for(int i=0;i<num.size();i++){
        sum=sum*10+num[i]-'0';
    }
    return sum;
}
void deal(string s);
void d1(string str);
void d2(string str1,string str2);
void d3(string str1,string str2);
void d4(string str1,string str2);
void d5(string str1,string str2);
void d6(string str1,string str2);
void d7();
bool checksiblings(int a,int b,node *root){
    if(root->left!=NULL&&root->right!=NULL&&((root->left->data==a&&root->right->data==b)||(root->left->data==b&&root->right->data==a))){
            return true;
    }
    else if(root->left!=NULL){
        return checksiblings(a,b,root->left);
    }else if(root->right!=NULL){
        return checksiblings(a,b,root->right);
    }
    return false;
}
bool check(int num){
    if(num==0) return true;
    if((A[num].left==0&&A[num].right!=0)||(A[num].right==0&&A[num].left!=0)) return false;
    else
        return check[A[num].left]&&check[A[num].right];
}
int main(){
//    freopen("1.txt","r",stdin);

    cin>>n;
    post.resize(n+1);
    in.resize(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&post[i]);
    for(int i=1;i<=n;i++) scanf("%d",&in[i]);
    root=create(1,n,1,n);

    layerorder(root);
    cin>>m;
    string statem;
    getchar();
    for(int i=0;i<m;i++){
        getline(cin,statem);
        deal(statem);
    }
//    for(int i=0;i<layer.size();i++){
////        printf("%d ",layer[i]);
//    }
}

void deal(string str){
    vector<string> all;
    all.clear();
//    cout<<str<<endl;
    string temp;
    for(int i=0;i<str.length();i++){
        if(str[i]!=' ')
            temp=temp+str[i];
        else{
            all.push_back(temp);
            temp.clear();
        }
    }
    all.push_back(temp);
    int len=all.size();
    switch(len){
    case 4:
        d1(all[0]);break;
    case 5:
        if(all[0][0]=='I') d7();
        else d2(all[0],all[2]);
        break;
    case 6:
        d3(all[0],all[5]);
        break;
    case 7:
        if(all[3][0]=='l') d4(all[0],all[6]);
        else d5(all[0],all[6]);
        break;
    case 8:
        d6(all[0],all[2]);
        break;
    }

//15 is the root 4
//8 and 2 are siblings 5
//32 is the parent of 11 6
//23 is the left child of 16 7
//28 is the right child of 2 7
//7 and 11 are on the same level 8
//It is a full tree 5
//    for(int i=0;i<all.size();i++) cout<<all[i]<<endl;
}
void d1(string str){
    int num=tonum(str);
    if(root->data==num) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
void d2(string str1,string str2){
    int a=tonum(str1),b=tonum(str2);
    if(A[a].parent==A[b].parent) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    // if(checksiblings(a,b,root))
}
void d3(string str1,string str2){
    int a=tonum(str1),b=tonum(str2);
    if(A[b].parent==a) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
void d4(string str1,string str2){
    int a=tonum(str1),b=tonum(str2);
//    cout<<a<<b;
    if(A[b].left==a) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
void d5(string str1,string str2){
    int a=tonum(str1),b=tonum(str2);
    if(A[b].right==a) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
void d6(string str1,string str2){
    int a=tonum(str1),b=tonum(str2);
    if(leveln[a]==leveln[b]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
void d7(){
    int rt=root->data;
    if(check(rt)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
