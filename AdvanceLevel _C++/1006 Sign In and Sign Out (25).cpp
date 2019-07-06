#include <stdio.h>
#include <string.h> 

int main(){
	
	int inputnum;
	scanf("%d",&inputnum);
	
	char input[inputnum][3][20];
	for(int i=0;i<inputnum;i++){
		scanf("%s %s %s",&input[i][0][0],&input[i][1][0],&input[i][2][0]);
	}
//	printf("%s",input[1][2]);
//	printf("%c",input[1][2][3]);
	

	int in=0;
	int out=0;
	for(int i=0;i<inputnum;i++){
		if(strcmp(input[i][1],input[in][1])<0){
			in=i;
		}
		if(strcmp(input[i][2],input[out][2])>0){
			out=i;
		}
	}
	printf("%s %s",input[in][0],input[out][0]);

	return 0;
	
}

