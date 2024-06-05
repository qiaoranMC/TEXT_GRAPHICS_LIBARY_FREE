#include</sdcard/pfh/include/layout_v3.h>
FILE *fp;
char picture[0xffff]={0};
int local[10]={};
int main(){
	fp=fopen("./se.txt","r");
	while(!feof(fp))
		picture[local[0]++]=fgetc(fp);
	local[2]=0;local[3]=0;local[4]=200;local[5]=50;
	window_create(600,500,32);
	for(local[1]=0;local[1]<100;local[1]++){
		new_graphics(local[2]=rand()%500,local[3]=rand()%100,local[2]+200,local[3]+50,1,35);
		fill_graphics_picture(1,picture,0xffff,0);
	}
}