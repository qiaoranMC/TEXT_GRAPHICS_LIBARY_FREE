#include<../include/layout_v3.h>
int local[10]={0};
char dcl[0xfffff]={0},clh[0xfff][0xfff],db[0xffff]={0},public_output[0xffff]={0},a2hole_output[0xfff]={0};
int putstr(char *str,int len){
	int i=0;
	for(i=0;i<len;i++){
		if(isascii(str[i])==0){
			break;
		}
		printf("%c",str[i]);
	}
}
int hexdump(int memory[0xffffff],int mode,int start,int end){
	int a=0,b=0,c=0,d=0,e=0;
	printf("%4x ",local[0]);
	local[4]=0;
	for(a=0;a<=0xf;)
		printf("_%x_",a++);
	for(a=start;a<=end;){
		printf("\n  %2x|",local[4]++);
		for(b=0;b<=0xf;b++)
			printf("%2x ",memory[a++]);
			if(mode==1){
				a-=b;
				for(b=0;b<=0xf;b++)
					printf("%2c|",memory[b++]);}}}
int a2hole(char dcl[0xffffff],int start){
	int local[10];
	clh[0][0]=10;local[0]=0;local[1]=1;
	for(local[0]=0;local[0]<0xffff;){
		if(dcl[local[0]]==10){
			db[local[1]]=local[2];local[1]++;local[2]=0;
		}else if(dcl[local[0]]==-1){
			clh[local[1]][local[2]]=0;
			break;
		}
		clh[local[1]][local[2]++]=dcl[local[0]];local[0]++;
	}
	local[2]=0;
	for(local[0]=start;db[local[0]]!=0;local[0]++){
		for(local[1]=db[local[0]];local[1]>0;local[1]--)
			{a2hole_output[local[2]++]=clh[local[0]][local[1]];}
			a2hole_output[local[2]++]=10;
	}
	return local[2];
}
int use_print_mode(int start_x,int start_y,int end_x,int end_y,int mode,int lang,int len,int mph){
	if(mode==1){
		if(lang==1){
			if(abs(start_x-end_x)%2!=0||abs(start_y-end_y)%2!=0)
				return -1;
			local[0]=abs(start_x-end_x)/2;
			local[1]=abs(start_y-end_y)/2;
			if(strlen(public_output)%2!=0)
				strcat(public_output," ");
			local[2]=strlen(public_output);
			gotoxy(local[0],local[1]);
			for(local[3]=0;local[3]<len;local[3]++){
				gotoxy(local[0],local[1]);
				for(local[4]=(local[2]/2)-local[3];local[4]<(local[2]/2)+local[3];local[4]++){
					printf("%c",public_output[local[4]]);
				}
				local[0]--;
				printf("\n");
				for(local[7]=0;local[7]<mph;local[7]++);
			}
		}
	}
	return 0;
}