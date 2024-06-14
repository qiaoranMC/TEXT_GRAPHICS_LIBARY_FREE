#include<../include/layout_v3.h>
#include<../include/tools.h>
char buffer[0xffff]={0};
int main(){
	window_create(88,26,35);
	new_graphics(88/2-20,26/2-2,88/2+20,26/2+1,1,35);
	new_graphics(88/2-19,26/2-1,88/2+19,26/2+0,2,32);
	sleep(1);
	print_graphics_only(0,2);
	strcpy(public_output,"Hello world!");
	use_print_mode(0,0,88,24,1,1,7,11451419);
	sleep(1);
	strcpy(public_output,"I`m Green Dam!");
	use_print_mode(0,0,88,24,1,1,8,19198100);
	sleep(1);
	print_graphics_only(0,2);
	strcpy(public_output,"你好世界！");
	use_print_mode(0,0,88,24,1,1,10,11451419);
	sleep(1);
	print_graphics_only(0,2);
	strcpy(public_output,"我是Green Dam！");
	use_print_mode(0,0,88,24,1,1,10,19198100);
	gotoxy(114514,1919810);
}