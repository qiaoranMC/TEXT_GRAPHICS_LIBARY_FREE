#include<../include/layout_v3_mod.h>
#include<../include/layout_v3_config.h>
int init(){
	for(sys[0][0]=0;sys[0][0]<graphics_max;sys[0][0]++)
		for(sys[0][1]=0;sys[0][1]<6;sys[0][1]++)graphics[sys[0][0]][sys[0][1]]=0;
	for(sys[0][0]=0;sys[0][0]<graphics_max;sys[0][0]++)indexflag[sys[0][0]]=0;
	for(sys[0][0]=1;sys[0][0]<3;sys[0][0]++)
		for(sys[0][1]=0;sys[0][1]<10;sys[0][1]++)sys[sys[0][0]][sys[0][1]]=0;
	for(sys[0][0]=1;sys[0][0]<10;sys[0][0]++)sys[0][sys[0][0]]=0;sys[0][0]=0;
	ascii[10]=10;ascii[32]=32;sys[2][3]=0;sys[2][4]=100;}
int window_create(int width,int height,char fill){
	init();
	sys[2][0]=width;sys[2][1]=height;sys[2][2]=fill;}
int index(){
	sys[2][5]=0;
	for(sys[0][0]=sys[2][3];sys[0][0]<sys[2][4];sys[0][0]++)
		if(graphics[sys[0][0]][0]!=0||graphics[sys[0][0]][1]!=0||graphics[sys[0][0]][2]!=0||graphics[sys[0][0]][3]!=0)indexflag[sys[2][5]++]=sys[0][0];sys[0][0]=0; 
	return sys[2][5];}
int check(int id,int x,int y){
	if(graphics[id][0]==0||graphics[id][1]==0||graphics[id][2]==0||graphics[id][3]==0)return -2;
	int find=0;
	while(find<sys[2][5]) 
		if(indexflag[find]==id)break;
		else ++find;
	for(;find>=0;find--)
		if(((x>=graphics[indexflag[find]][0]&&y>=graphics[indexflag[find]][1])&&(x<=graphics[indexflag[find]][2]&&y<=graphics[indexflag[find]][3]))&&indexflag[find]!=id)
			if(graphics[indexflag[find]][4]!=0)return -1;
	return 0;}
int new_graphics(int start_x,int start_y,int end_x,int end_y,int id,int fill){
	if(start_x>sys[2][0]||start_y>sys[2][1]||end_x>sys[2][0]||end_y>sys[2][1]||start_x==0||start_y==0||end_x==0||end_y==0)return -1;
	graphics[id][0]=start_x;graphics[id][1]=start_y;graphics[id][2]=end_x;graphics[id][3]=end_y;graphics[id][4]=fill;
	index();
	return id;}
int check_id_xy(int id,int x,int y){
	if(graphics[id][0]+x-1>graphics[id][2]||graphics[id][1]+y-1>graphics[id][3]||x<=0||y<=0)return -2;
	if(check(id,graphics[id][0]+x-1,graphics[id][1]+y-1)==-1)return -1;
	return 0;}
int goto_id_xy(int id,int x,int y){
	if(graphics[id][0]+x-1>graphics[id][2]||graphics[id][1]+y-1>graphics[id][3]||x<=0||y<=0)return -2;
	if(check(id,graphics[id][0]+x-1,graphics[id][1]+y-1)!=0)return -1;
	gotoxy(graphics[id][0]+x-1,graphics[id][1]+y-1);
	return 0;}
int draw_id_dot(int id,int x,int y,int fill){
	if(graphics[id][0]+x-1>graphics[id][2]||graphics[id][1]+y-1>graphics[id][3]||x<=0||y<=0)return -2;
	if(check(id,graphics[id][0]+x-1,graphics[id][1]+y-1)!=0)return -1;
	gotoxy(graphics[id][0]+x-1,graphics[id][1]+y-1);
	printf("%c",fill);
	return 0;}
int remove_graphics(int id,char fill){
	for(sys[0][0]=graphics[id][1];sys[0][0]<=graphics[id][3];sys[0][0]++)
		for(sys[0][1]=graphics[id][0];sys[0][1]<=graphics[id][2];sys[0][1]++){
			gotoxy(sys[0][1],sys[0][0]);
			printf("%c",fill);}
	graphics[id][0]=0;graphics[id][1]=0;graphics[id][2]=0;graphics[id][3]=0;graphics[id][4]=0;
	index();}
int print_bg_only(){
	for(sys[0][0]=1;sys[0][0]<sys[2][1];sys[0][0]++)
		for(sys[0][1]=1;sys[0][1]<sys[2][0];sys[0][1]++){
			gotoxy(sys[0][1],sys[0][0]);
			printf("%c",sys[2][2]);}}
int print_graphics_only(int start,int end){
	for(sys[0][0]=start;sys[0][0]<=end;sys[0][0]++)
		for(sys[0][1]=graphics[sys[0][0]][1];sys[0][1]<graphics[sys[0][0]][3];sys[0][1]++)
			for(sys[0][2]=graphics[sys[0][0]][0];sys[0][2]<graphics[sys[0][0]][2];sys[0][2]++){
				if(check(sys[0][0],sys[0][2],sys[0][1])==-1)continue;
				gotoxy(sys[0][2],sys[0][1]);
				printf("%c",graphics[sys[0][0]][4]);}}
int window_show(){
	for(sys[0][0]=1;sys[0][0]<sys[2][1];sys[0][0]++)
		for(sys[0][1]=1;sys[0][1]<sys[2][0];sys[0][1]++){
			gotoxy(sys[0][1],sys[0][0]);
			printf("%c",sys[2][2]);}
	for(sys[0][0]=sys[2][3];sys[0][0]<=sys[2][4];sys[0][0]++)
		for(sys[0][1]=graphics[sys[0][0]][1];sys[0][1]<graphics[sys[0][0]][3];sys[0][1]++)
			for(sys[0][2]=graphics[sys[0][0]][0];sys[0][2]<graphics[sys[0][0]][2];sys[0][2]++){
				if(check(sys[0][0],sys[0][2],sys[0][1])==-1||graphics[sys[0][0]]==0)continue;
				gotoxy(sys[0][2],sys[0][1]);
				printf("%c",graphics[sys[0][0]][4]);}}
/*The end*/