#include<stdio.h>
#include<stdlib.h>
FILE *fp;
int local[0xf],memory[0xffff];
int initall(){
	for(local[0]=0;local[0]<=0xffff;)
		memory[local[0]++]=0;
	for(local[0]=1;local[0]<=0xf;)
		local[local[0]++]=0;
	local[0]=0;
}
int readfile(){
	fp=fopen("./data.bin","r");
	for(local[0]=0;local[0]<0xffff;)
		memory[local[0]++]=fgetc(fp);
	local[0]=0;
}
int saveall(){
	fclose(fp);
	fp=fopen("./data.bin","w");
	for(local[0]=0;local[0]<0xffff;){
		fseek(fp,local[0],0);
		fputc(memory[local[0]++],fp);
	}
}
int editmode(){
	while(1){
		system("clear");
		printf("%4x ",local[0]);
		for(local[3]=0;local[3]<=0xf;)
			printf("_%x_",local[3]++);
		for(local[3]=0;local[3]<local[2];){
			printf("\n  %2x|",local[5]++);
			for(local[4]=0;local[4]<=0xf;local[4]++){
				printf("%2x ",memory[local[3]++]);
			}
		}
		local[5]=0;
		printf("%4x>>>",local[0]);
		scanf("%x",&local[1]);
		if(local[1]==-1)
			scanf("%x",&local[2]);
		else if(local[1]==-2)
			scanf("%x",&local[0]);
		else if(local[1]==-3)
			saveall();
		else
			memory[local[0]++]=local[1];
	}
}
int main(){
	initall();
	readfile();
	editmode();
}