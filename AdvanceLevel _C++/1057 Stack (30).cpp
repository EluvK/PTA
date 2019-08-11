#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int main(){
	// freopen("1.txt","r",stdin);
	int n;
	scanf("%d",&n);
	char cmd[15];
	int num;
	int size;
	int last;
	vector<int> s;
	vector<int> temp;
	for(int i=0;i<n;i++){
		scanf("%s",cmd);
		if(strcmp(cmd,"Pop")==0){
			if(s.size()==0){
				printf("Invalid\n");
			}
			else{
				last=*(s.end()-1);
				printf("%d\n",last);
				temp.erase(lower_bound(temp.begin(),temp.end(),last));
				s.pop_back();
			}
		}else if(strcmp(cmd,"Push")==0){
			scanf("%d",&num);
			s.push_back(num);
			temp.insert(lower_bound(temp.begin(),temp.end(),num),num);
		}else if(strcmp(cmd,"PeekMedian")==0){
			size=s.size();
			if(size==0){
				printf("Invalid\n");
			}else{

				printf("%d\n",*(temp.begin()+(size+1)/2-1));
			}
		}
	}
}
