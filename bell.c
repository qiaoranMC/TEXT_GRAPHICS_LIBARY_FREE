#include</sdcard/pfh/include/layout_v3.h>
int i=1,x[10]={0},y[10]={0},x1[10]={0},y1[10]={0},opx[10]={0},opy[10]={0},ch[10]={0};
int task0(){
	new_graphics(x[i],y[i],x1[i],y1[i],i,ch[i]);
	print_graphics_only(0,10);
	if(opy[i]==0)
		if(y[i]==50)
			{opy[i]=1;y[i]-=10;y1[i]-=10;}
		else{y[i]+=10;y1[i]+=10;}
	else if(opy[i]==1)
		if(y[i]==0)
			{opy[i]=0;y[i]+=10;y1[i]+=10;}
		else{y[i]-=10;y1[i]-=10;}
	if(opx[i]==0)
		if(x[i]==500)
			{opx[i]=1;x[i]-=10;x1[i]-=10;}
		else{x[i]+=10;x1[i]+=10;}
	else if(opx[i]==1)
		if(x[i]==0)
			{opx[i]=0;x[i]+=10;x1[i]+=10;}
		else{x[i]-=10;x1[i]-=10;}
}
int main(){
	init();
	window_create(200,700,32);
	x[1]=0;y[1]=0;x1[1]=10;y1[1]=10;ch[1]=97;
	x[2]=0;y[2]=10;x1[2]=10;y1[2]=20;ch[2]=98;
	x[3]=0;y[3]=50;x1[3]=10;y1[3]=60;ch[3]=99;
	x[4]=0;y[4]=40;x1[4]=10;y1[4]=50;ch[4]=100;opy[4]=1;
	for(;;){
		//getch();
		task0();
		i++;
		if(i>4)
			i=1;
	}
}