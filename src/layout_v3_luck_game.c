#include</sdcard/pfh/include/layout_v3.h>
FILE *fp;
char picture[0xffff]={0};
int local[10]={0};
int main(){
	srand(time(0));
	window_create(600,500,32);
	while(1){
		sleep(1);
		for(local[1]=0;local[1]<1145;local[1]++){
			new_graphics(local[2]=rand()%100,local[3]=rand()%30,local[2]+10,local[3]+10,1,35);
			print_graphics_only(0,1);
		}
		sleep(1);
		clrscr();
	}
}