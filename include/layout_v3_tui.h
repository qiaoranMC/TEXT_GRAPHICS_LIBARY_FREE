#include<../include/layout_v3_config.h>
int uprint(char str[0xffffff],int delay){
	setbuf(stdout,0);
	for(int i=0;i<strlen(str);i++){
		printf("%c",str[i]);
		usleep(delay);
	}
}
int gotoxy_print(char str[0xffffff],int x,int y){
	gotoxy(x,y);
	printf(str);
}
int draw_pic(int id,char pic[0xffffff]){
	int x=1,y=1,i=0,n=0;
	for(n=0;n<strlen(pic);n++)
		if(pic[i]==ascii[10]){x=1;y++;i++;}
		else draw_id_dot(id,x++,y,pic[i++]);
}