#include<../include/layout_end_renew.h>
int local[10]={0};
char public_output[0xffff]={0},a2hole_output[0xfff]={0};
int caogao(){
	while(1)
		printf("%c",getch());
}
int clear(){
	printf("\033[2Jm");
}
int initlocal(){
	//for(local[0]=0;local[0]<0xffff;local[0]++)
		//public_output[local[0]]=0;
	for(local[0]=1;local[0]<10;local[0]++)
		local[local[0]]=0;local[0]=0;
}
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
	printf("%4x ",start);
	for(a=0;a<=0xf;)
		printf("_%x_",a++);
	for(a=start;a<=end;){
		printf("\n  %2x|",b++);
		for(c=0;c<0xf;c++)
			printf("%2x ",memory[a++]);
			if(mode==1){
				a-=c;
				for(c=0;c<0xf;c++)
					printf("%2c|",memory[b++]);}}}
int a2hole(char dcl[0xffffff],int start){
	char dcl[0xfffff]={0},clh[0xfff][0xfff],db[0xffff]={0};
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
int use_print_mode(int start_x,int start_y,int mode,int lang,int len,int mph){
	initlocal();
	if(mode==1){
		if(lang==1){
			local[0]=start_x;
			local[1]=start_y;
			if(strlen(public_output)%2!=0)
				strcat(public_output," ");
			local[2]=strlen(public_output);
			gotoxy(local[0],local[1]);
			for(local[3]=0;local[3]<len;local[3]++){
				gotoxy(local[0],local[1]);
				for(local[4]=(local[2]/2)-local[3];local[4]<(local[2]/2)+local[3];local[4]++){
					if(public_output[local[4]]==10)
						continue;
					printf("%c",public_output[local[4]]);
				}
				local[0]--;
				printf("\n");
				for(local[7]=0;local[7]<mph;local[7]++);
			}
		}
		if(lang==2){
			local[0]=start_x;
			local[1]=start_y;
			if(strlen(public_output)%2!=0)
				strcat(public_output," ");
			local[2]=strlen(public_output);
			for(local[3]=0;local[3]<local[2]/2;){
				if(isascii(public_output[local[3]])==1)
					local[3]+=1;
				else
					local[3]+=3;
			}
			gotoxy(local[0],local[1]);
			for(local[4]=0;local[4]<len;local[4]++){
				gotoxy(local[0],local[1]);
				if(isascii(public_output[(local[3]-(local[6]+1))])==1)
					{local[6]+=1;local[0]-=1;}
				else
					{local[6]+=3;local[0]-=2;}
				if(isascii(public_output[(local[3]+(local[7]))])==1)
					local[7]+=1;
				else
					local[7]+=3;
				for(local[5]=local[3]-local[6];local[5]<local[3]+local[7];local[5]++){
					if(public_output[local[5]]==10)
						continue;
					if(isascii(public_output[local[5]])!=1&&isascii(public_output[local[5]+1])==1)
						printf("%c ",public_output[local[5]]);
					else if(isascii(public_output[local[5]])==1&&isascii(public_output[local[5]+1])!=1)
						printf("%c ",public_output[local[5]]);
					else
						printf("%c",public_output[local[5]]);
				}
				printf("\n");
				for(local[8]=0;local[8]<mph;local[8]++);
			}
		}
	}
	return 0;
}