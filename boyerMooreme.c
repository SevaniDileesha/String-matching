#include<stdio.h>
#include<string.h>

#define alpha 256
int max (int a, int b) { return (a > b)? a: b; }


void preprocessing(char pattern[],int m,int prepro[alpha]){
	int i;
	for(i=0;i<alpha;i++){
		prepro[i]=-1;
		//printf("i=%d\n",i);
	}
	for(i=0;i<m;i++){
		prepro[(int)pattern[i]]=i;
		//printf("i=%d\n",i);
	}
}

void main(){
	char text[50];
	char pattern[50];
	printf("enter the text \n");
	scanf("%s",text);
	printf("enter the pattern \n");
	scanf("%s",pattern);
	search(text,pattern);
}

void search(char text[],char pattern[]){
	int n=strlen(text);
	int m=strlen(pattern);
	
	int prepro[alpha];
	preprocessing(pattern,m,prepro);
	
	int s=0;
	while(s<=(n-m)){
		int j=m-1;
		//printf("j = %d\n",j);
	    while(j >= 0 && pattern[j] == text[s+j]){
            j--;
        }
        if (j < 0){
            printf("\n pattern occurs at shift = %d", s);
            s += (s+m < n)? m-prepro[text[s+m]] : 1;
        }else{
            s += max(1, j - prepro[text[s+j]]);
        }
		 
    }

}




