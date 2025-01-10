#include<../include/layout_v3_config.h>
int debug(int s,int a,int b){
	if(s==0)
		printf("%d,",sys[a][b]);
	else if(s==1)
		printf("%d,",local[a]);
	else if(s==2)
		printf("%d,",graphics[a][b]);
	else if(s==3)
		printf("%d,%d,",a,b);
	//for(int i=0;i<20000000;i++);gotoxy(100,1);printf("%d,%d",sys[0][1],sys[0][2]);
}
int fill_graphics_picture(int id,char picture[0xffffff],int len,int op){
	sys[0][3]=0;
	for(sys[0][1]=graphics[id][1];sys[0][1]<graphics[id][3];sys[0][1]++)
		for(sys[0][2]=graphics[id][0];sys[0][2]<graphics[id][2];sys[0][2]++){
			if(sys[0][3]>len)return 0;
			gotoxy(sys[0][2],sys[0][1]);
			if(check(id,sys[0][2],sys[0][1])==-1||(picture[sys[0][3]]==0&&op==2)||(picture[sys[0][3]]==0&&op==3)){
				if(picture[sys[0][3]]==ascii[10])sys[0][5]=1;
				if(sys[0][5]==0)sys[0][3]++;sys[0][5]=0;
				continue;}
			if(picture[sys[0][3]]==ascii[10]||sys[0][5]==1){
				while(sys[0][2]++<graphics[id][2])
					if(check(id,sys[0][2],sys[0][1])==0)printf("%c",ascii[32]);
				sys[0][3]++;
				continue;}
			if(op==0||op==2)
				if(picture[sys[0][3]]==9)printf(" ",sys[0][3]++);
				else printf("%c",picture[sys[0][3]++]);
			else if(op==1||op==3)
				if(picture[sys[0][3]]>=32&&picture[sys[0][3]]<=126)printf("%c",picture[sys[0][3]++]);
				else if(picture[sys[0][3]]==9)printf(" ",sys[0][3]++);
				else printf("%c",ascii[32]);}}
int use_print_mode(int id,int start_x,int start_y,int mode,int lang,int len,int mph){
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
					//if(check(id,local[2]/2-local[3],local[2]/2+local[3])==0)
						printf("%c",public_output[local[4]]);
				}
				local[0]--;
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
int locate_xy(int id,int x,int y){
	gotoxy(graphics[id][0]+x,graphics[id][1]+y);}
int draw_pixel(int id,int x,int y){
	if(check(id,graphics[id][0]+x,graphics[id][1]+y)==0)gotoxy(graphics[id][0]+x,graphics[id][1]+y);
	else return 1;
	return 0;}
int clear_array(int select,int start,int end){
	if(select==1){
		for(sys[0][0]=1;sys[0][0]<3;sys[0][0]++)
			for(sys[0][1]=0;sys[0][1]<10;sys[0][1]++){sys[local[0]][local[1]]=0;}
		for(sys[0][0]=1;sys[0][0]<10;sys[0][0]++)sys[0][sys[0][0]]=0;sys[0][0]=0;}
	if(select==2)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)
			for(sys[0][1]=0;sys[0][1]<6;sys[0][1]++)graphics[sys[0][0]][sys[0][1]]=0;
	if(select==3)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)indexflag[sys[0][0]]=0;
	if(select==4)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)ret[sys[0][0]]=0;
	if(select==5)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)ascii[sys[0][0]]=0;
	if(select==11)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)local[sys[0][0]]=0;
	if(select==12)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)data[sys[0][0]]=0;
	if(select==13)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)public_input[sys[0][0]]=0;
	if(select==14)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)public_output[sys[0][0]]=0;
	if(select==21)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)text_address[sys[0][0]]=0;
	if(select==22)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)
			for(sys[0][1]=0;sys[0][1]<0xff;sys[0][1]++)gifaddress[sys[0][0]][sys[0][1]]=0;
	if(select==23)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)bind[sys[0][0]]=0;
	if(select==24)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)program[sys[0][0]]=0;
	if(select==25)
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)
			for(sys[0][1]=0;sys[0][1]<0xf;sys[0][1]++)step[sys[0][0]][sys[0][1]]=0;
	sys[0][0]=0;sys[0][1]=0;
}

/*The end*/