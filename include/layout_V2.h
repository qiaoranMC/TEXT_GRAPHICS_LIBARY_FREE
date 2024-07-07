#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<../include/layout_v2_config.h>
#include<../include/layout_v2_mod.h>
int init(){
	for(sys[0][0]=1;sys[0][0]<=2;sys[0][0]++)
		for(sys[0][1]=0;sys[0][1]<=10;sys[0][1]++)
			sys[sys[0][0]][sys[0][1]]=0;
	ascii[0]=10;ascii[1]=32;
	return 0;
}
int window_create(int width,int heiglt,int fill){
	sys[2][0]=width;sys[2][1]=heiglt;sys[1][0]=0;
	for(sys[0][0]=0;sys[0][0]<heiglt;sys[0][0]++){
		for(sys[0][1]=0;sys[0][1]<width;sys[0][1]++){
			window[sys[1][0]]=fill;sys[1][0]++;
		}
		window[sys[1][0]]=ascii[0];sys[1][0]++;
	}
	for(sys[1][0]=0xffffff;sys[1][0]>=0;sys[1][0]--){
		if(window[sys[1][0]]==ascii[0])
			break;
		else
			window[sys[1][0]]=0;
	}
	sys[2][2]=sys[1][0];
	return -1;
}
int new_graphics(int start_x,int start_y,int end_x,int end_y,int id,int fill){
	sys[1][0]=0;
	for(sys[0][0]=0;sys[0][0]<start_x;sys[0][0]++)
		sys[1][0]++;
	for(sys[0][0]=0;sys[0][0]<start_y;sys[0][0]++)
		sys[1][0]=sys[1][0]+sys[2][2]+1;sys[1][1]=sys[1][0];
	for(sys[0][0]=0;sys[0][0]<end_y;sys[0][0]++){
		for(sys[0][1]=0;sys[0][1]<end_x;sys[0][1]++)
			{window[sys[1][0]]=fill;graphics[sys[1][0]]=id;sys[1][0]++;}
		sys[1][0]=sys[1][0]+sys[2][0]+1-end_x;
	}
	sys[1][2]=sys[1][0];
	return 0;
}
int fill_graphics_picture(int start,int end,int id,char picture[0xffffff],int len,int op){
	sys[1][0]=0;
	for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++){
		if(graphics[sys[0][0]]==id)
			break;
		if(sys[0][0]==sys[2][2])
			return -1;
	}
	sys[1][0]=sys[0][0];sys[1][1]=sys[0][0];
	for(sys[0][0]=0;sys[0][0]<len;sys[0][0]++){
		if(graphics[sys[1][0]]==id){
			if(picture[sys[0][0]]==10){
				for(;graphics[sys[1][0]]!=id;sys[1][0]++);
				for(;graphics[sys[1][0]]==id;sys[1][0]++);
				continue;
			}
			if(op==1){
				if(picture[sys[0][0]]>=32&&picture[sys[0][0]]<=126)
					window[sys[1][0]]=picture[sys[0][0]];
				else
					window[sys[1][0]]=ascii[1];
			}else
				window[sys[1][0]]=picture[sys[0][0]];
		}else
			sys[0][0]--;
		sys[1][0]++;
		if(sys[1][0]>=sys[2][2]||sys[0][0]>=0xffffff)
			return -2;
	}
	sys[1][2]=sys[1][0];
	return 0;
}
int remove_graphics(int start,int end,int id,int fill){
	for(sys[0][0]=start;sys[0][0]<=end||sys[0][0]<=sys[2][2];sys[0][0]++)
		if(graphics[sys[0][0]]==id)
			{graphics[sys[0][0]]=0;window[sys[0][0]]=fill;}
}
int window_show(){
	for(sys[0][0]=0;sys[0][0]<sys[2][2];sys[0][0]++)
		printf("%c",window[sys[0][0]]);
}
//The my c lang work
//use tcc compile