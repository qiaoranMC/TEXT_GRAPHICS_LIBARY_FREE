#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
int sys[3][10],graphics[0xffffff][6];
int init(){
	for(sys[0][0]=0;sys[0][0]<0xfff;sys[0][0]++){
		for(sys[0][1]=0;sys[0][1]<6;sys[0][1]++){
			graphics[sys[0][0]][sys[0][1]]=0;
		}
	}
	for(sys[0][0]=1;sys[0][0]<3;sys[0][0]++)
		for(sys[0][1]=0;sys[0][1]<10;sys[0][1]++)
			sys[sys[0][0]][sys[0][1]]=0;
	sys[2][0]=10;sys[2][1]=32;
	return 0;
}
int window_create(int width,int heiglt,int fill){
	sys[2][2]=width;sys[2][3]=heiglt;sys[2][4]=fill;
	return -1;
}
int new_graphics(int start_x,int start_y,int end_x,int end_y,int id,int fill){
	if(start_x>sys[2][2]||start_y>sys[2][3]||end_x>sys[2][2]||end_y>sys[2][3])
		return -1;
	graphics[id][0]=start_x;graphics[id][1]=start_y;graphics[id][2]=end_x;graphics[id][3]=end_y;graphics[id][4]=fill;
	return 0;
}
int fill_graphics_picture(int id,char picture[0xffffff],int len,int op){
	sys[0][3]=0;
	for(sys[0][1]=graphics[id][1];sys[0][1]<graphics[id][3];sys[0][1]++){
		for(sys[0][2]=graphics[id][0];sys[0][2]<graphics[id][2];sys[0][2]++){
			if(picture[sys[0][3]]==10){
				sys[0][1]++;sys[0][2]=graphics[id][0];sys[0][3]++;
			}
			gotoxy(sys[0][2],sys[0][1]);
			printf("%c",picture[sys[0][3]++]);
			if(sys[0][3]>len)
				break;
		}
	}
	return 0;
}
int fill_graphics_text(int id,char text[0xffffff],int len,int op){
	sys[0][3]=0;
	gotoxy(graphics[id][0],graphics[id][1]);
	for(sys[0][1]=graphics[id][1];sys[0][1]<graphics[id][3];sys[0][1]++){
		for(sys[0][2]=graphics[id][0];sys[0][2]<graphics[id][2];sys[0][2]++){
			if(text[sys[0][3]]==10){
				sys[0][1]++;sys[0][2]=graphics[id][0];sys[0][3]++;
				gotoxy(sys[0][2],sys[0][1]);
			}
			printf("%c",text[sys[0][3]++]);
			if(sys[0][3]>len)
				break;
		}
		gotoxy(sys[0][2],sys[0][1]);
	}
	return 0;
}
int remove_graphics(int id,int fill){
	for(sys[0][1]=graphics[id][1];sys[0][1]<graphics[id][3];sys[0][1]++){
		for(sys[0][2]=graphics[id][0];sys[0][2]<graphics[id][2];sys[0][2]++){
			gotoxy(sys[0][2],sys[0][1]);
			printf("%c",fill);
		}
	}
	graphics[id][0]=0;graphics[id][1]=0;graphics[id][2]=0;graphics[id][3]=0;graphics[id][4]=0;
	return 0;
}
int print_bg_only(){
	for(sys[0][0]=0;sys[0][0]<sys[2][3];sys[0][0]++)
		for(sys[0][1]=0;sys[0][1]<sys[2][2];sys[0][1]++){ 	
			gotoxy(sys[0][1],sys[0][0]);
			printf("%c",sys[2][4]);
		}
}
int print_graphics_only(int start,int end){
	for(sys[0][0]=start;sys[0][0]<=end;sys[0][0]++)
		for(sys[0][1]=graphics[sys[0][0]][1];sys[0][1]<graphics[sys[0][0]][3];sys[0][1]++)
			for(sys[0][2]=graphics[sys[0][0]][0];sys[0][2]<graphics[sys[0][0]][2];sys[0][2]++){
				gotoxy(sys[0][2],sys[0][1]);
				printf("%c",graphics[sys[0][0]][4]);
			}
}
int window_show(int start,int end){
	for(sys[0][0]=0;sys[0][0]<sys[2][3];sys[0][0]++)
		for(sys[0][1]=0;sys[0][1]<sys[2][2];sys[0][1]++){ 	
			gotoxy(sys[0][1],sys[0][0]);
			printf("%c",sys[2][4]);
		}
	for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++)
		for(sys[0][1]=graphics[sys[0][0]][1];sys[0][1]<graphics[sys[0][0]][3];sys[0][1]++)
			for(sys[0][2]=graphics[sys[0][0]][0];sys[0][2]<graphics[sys[0][0]][2];sys[0][2]++){
				if(sys[0][2]>sys[2][2]||sys[0][1]>sys[2][3])
					return -1;
				gotoxy(sys[0][2],sys[0][1]);
				printf("%c",graphics[sys[0][0]][4]);
			}
	return 0;
}