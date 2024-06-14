#include<../include/layout_v3.h>
FILE *fp;
int local[10]={0};
char picture[2][0xffff];
int main(){
	fp=fopen("./mihoyo.png","r");
	while(!feof(fp))
		picture[0][local[0]++]=fgetc(fp);
	fp=fopen("./ys.png","r");
	while(!feof(fp))
		picture[1][local[1]++]=fgetc(fp);
	picture[0][local[0]-1]=35;picture[0][local[0]-1]=35;
	window_create(600,150,35);
	new_graphics(600/2-100,150/2-20,600/2+100,150/2+20,1,35);
	new_graphics(600/2-100,150/2-30,600/2+60,150/2+50,2,35);
	window_show(0,0);
	fill_graphics_picture(1,picture[0],0xffff,0);
	sleep(3);
	fill_graphics_picture(2,picture[1],0xffff,0);
}