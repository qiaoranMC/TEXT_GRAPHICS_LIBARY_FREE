#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>
char window[10000000]={0},sub_window[10000000]={0},button_icon[10000000]={0},bk=0,mouse_icon=0;
int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,m,x=0,y=0,address=0,heiglt=0,width=0,fill=0,show=0,static_x=0,static_y=0,mouse=0,mouse_x=0,mouse_y=0,notes=0,ret=0,dvc=0,sys[3][10],sys_new[3][10],button[10000000]={0},text_box[10000000]={0},level[10000000]={0},cache[10000000]={0},graphics[0xffffff]={0},graphics_new[0xffffff][6];
void init(){
	/*for(i=0;i<100000000;i++){
        window[i]=0;sub_window[i]=0;text_box[i]=0;button[i]=0;button_icon[i]=0;level[i]=0;cache[i]=0;
    }*/
	for(sys[0][0]=1;sys[0][0]<3;sys[0][0]++)
		for(sys[0][1]=0;sys[0][1]<10;sys[0][1]++)
			sys[sys[0][0]][sys[0][1]]=0;
	sys[2][0]=10;sys[2][1]=32;
	for(sys_new[0][0]=0;sys_new[0][0]<0xfffff;sys_new[0][0]++){
		for(sys_new[0][1]=0;sys_new[0][1]<6;sys_new[0][1]++){
			graphics_new[sys_new[0][0]][sys_new[0][1]]=0;
		}
	}
	for(sys_new[0][0]=1;sys_new[0][0]<3;sys_new[0][0]++)
		for(sys_new[0][1]=0;sys_new[0][1]<10;sys_new[0][1]++)
			sys_new[sys_new[0][0]][sys_new[0][1]]=0;
	sys_new[2][0]=10;sys_new[2][1]=32;
	return 0;
}
//CREATE
void window_create(int width,int heiglt,int fill){
	if(dvc==1||dvc==0){
		static_x=width;static_y=heiglt;address=0;
		for(y=0;y<heiglt;y++){
			for(x=0;x<width;x++){
				window[address]=fill;address++;
			}
			window[address]=10;address++;
		}
		for(i=10000000;i>0;i--){
		    if(window[i]==10){
				break;
			}
			window[i]=0;
		}
		show=i;
		sys[2][2]=width;sys[2][3]=heiglt;sys[1][0]=0;
		for(sys[0][0]=0;sys[0][0]<heiglt;sys[0][0]++){
			for(sys[0][1]=0;sys[0][1]<width;sys[0][1]++){
				window[sys[1][0]]=fill;sys[1][0]++;
			}
			window[sys[1][0]]=sys[2][0];sys[1][0]++;
		}
		for(sys[1][0]=0xffffff;sys[1][0]>=0;sys[1][0]--){
			if(window[sys[1][0]]==sys[2][0])
				break;
			else
				window[sys[1][0]]=0;
		}
		sys[2][4]=sys[1][0];
	}
	if(dvc==2||dvc==0){
		sys_new[2][2]=width;sys_new[2][3]=heiglt;sys_new[2][4]=fill;
	}
	return 0;
}
void add_sub_window(int start_x,int start_y,int end_x,int end_y,int id,int fill){
    address=0;a=0;b=0;c=0;
    for(x=0;x<start_x;x++){
        address++; 
    }
    for(y=0;y<start_y;y++){
        address=address+static_x+1;
    }
    cache[0]=address;
    for(y=0;y<end_y;y++){
        for(x=0;x<end_x;x++){
            sub_window[address]=id;
            window[address]=fill;
            address++;
        }
        address=address+static_x+1-end_x;
    }
    cache[1]=address;
}
void add_text_box(int start_x,int start_y,int end_x,int end_y,int id){
    address=0;
    for(x=0;x<start_x;x++){
        address++;
    }
    for(y=0;y<start_y;y++){
        address=address+static_x+1;
    }
    cache[0]=address;
    for(y=0;y<end_y;y++){
        for(x=0;x<end_x;x++){
            text_box[address]=id;window[address]=32;address++;
        }
        address=address+static_x+1-end_x;
    }
    cache[1]=address;
}
void add_button(int start_x,int start_y,int end_x,int end_y,int id,char button_icon[100000000]){
	address=0;a=0;b=0;c=0;b=strlen(button_icon);
	for(x=0;x<start_x;x++){
		address++;
	}
	for(y=0;y<start_y;y++){
		address=address+static_x+1;
	}
	cache[0]=address;
	for(y=0;y<end_y;y++){
		for(x=0;x<end_x;x++){
			button[address]=id;
			if(c>=b){
				window[address]=32;c++;
			}else if(button_icon[c]==10){
                cache[1]=address;
                for(;button[address]!=id;address++){}
                cache[2]=address;
                for(;button[address]==id;address++){}
                cache[3]=address;c++;
			}else{
				window[address]=button_icon[c];c++;
			}
			address++;
		}
		address=address+static_x+1-end_x;
	}
	cache[4]=address;
}
void add_level(int end_x,int end_y,int id){
    address=0;
    for(x=0;x<end_x;x++){
        address++;
    }
    for(y=0;y<end_y;y++){
        address=address+static_x+1;
    }
    cache[0]=address;level[address]=id;window[address]=32;
}
//OPERATION
void edit_text(int start,int end,char text[100000000],int size,int id,int locate,int op){
    a=0;b=0;c=0;address=0;
    for(i=start;i<end;i++){
        if(text_box[i]==id){
            break;
        }
        address++;
        if(address==show){
            return;
        }
    }
    cache[0]=address;
    for(i=0;i<locate;i++){
        address++;
        if(text_box[address]!=id){
            address=address+static_x+1;
        }
    }
    cache[1]=address;
    for(i=0;i<size;i++){
        if(text_box[address]==id){
            if(window[address]==mouse_icon){
                continue;
            }
            if(text[i]==10){
                cache[2]=address;
                for(;text_box[address]!=id;address++){}
                cache[3]=address;
                for(;text_box[address]==id;address++){}
                cache[4]=address;
                continue;
            }
            if(op==1){
                if(text[i]>=32&&text[i]<=126){
                    window[address]=text[i];
                }else{
                    window[address]=32;
                }
            }else{
                window[address]=text[i];
            }
            address++;
        }else{
            i--;address++;
            if(address==show){
                return;
            }
        }
    }
    cache[5]=address;
}
int scanner(int scanmode,int op,int input,int input1){
    int s=0;
    if(scanmode==0){
        if(op==0){
            for(i=0;i<show;i++){
                if(window[i]==input){
                    cache[s]=i;s++;
                }
            }
        }
        if(op==1){
            for(i=0;i<show;i++){
                if(window[i]==input){
                    window[i]=input1;
                }
            }
        }
    }
    if(scanmode==1){
        if(op==0){
            for(i=0;i<show;i++){
                if(sub_window[i]==input){
                    cache[s]=i;s++;
                }
            }
        }
        if(op==1){
            for(i=0;i<show;i++){
                if(sub_window[i]==input){
                    sub_window[i]=input1;
                }
            }
        }
    }
    if(scanmode==2){
        if(op==0){
            for(i=0;i<show;i++){
                if(button[i]==input){
                    cache[s]=i;s++;
                }
            }
        }
        if(op==1){
            for(i=0;i<show;i++){
                if(button[i]==input){
                    button[i]=input1;
                }
            }
        }
    }
    if(scanmode==3){
        if(op==0){
            for(i=0;i<show;i++){
                if(text_box[i]==input){
                    cache[s]=i;s++;
                }
            }
        }
        if(op==1){
            for(i=0;i<show;i++){
                if(text_box[i]==input){
                    text_box[i]=input1;
                }
            }
        }
    }
    if(scanmode==4){
        if(op==0){
            for(i=0;i<show;i++){
                if(level[i]==input){
                    cache[s]=i;s++;
                }
            }
        }
        if(op==1){
            for(i=0;i<show;i++){
                if(level[i]==input){
                    level[i]=input1;
                }
            }
        }
    }
}
int level_click_cmp(int id){
    if(level[mouse]==id){
        return 1;
    }else{
        return 0;
    }
}
//DELETE
int remove_sub_window(int start,int end,int id,int fill,int fail,int op){
    a=0;address=0;
    if(sub_window[mouse]==id&&op==1||op==3){
        ret=1;
    }
    for(i=start;i<end;i++){
        if(sub_window[i]==id){
            if(a==0){
                cache[0]=i;a=1;
            }
            sub_window[i]=0;
            if(window[i]==mouse_icon){
                continue;
            }
            window[i]=fill;
        }
    }
    cache[1]=i;
    if(ret==1){
        ret=0;
        if(a==1){
            if(op==2||op==3){
                window[mouse]=mouse_icon;
                return fail;
            }
            window[mouse]=mouse_icon;
            return fill;
        }else{
            if(op==2||op==3){
                window[mouse]=mouse_icon;
                return fill;
            }
            window[mouse]=mouse_icon;
            return fail;
        }
    }
}
int remove_text_box(int start,int end,int id,int fill,int fail,int set,int op){
    a=0;
    if(text_box[mouse]==id&&op==1||op==3){
        ret=1;
    }
    for(i=start;i<end;i++){
        if(text_box[i]==id){
            if(a==0){
                cache[0]=i;a=1;
            }
            text_box[i]=0;
            if(window[i]==mouse_icon){
                continue;
            }
            window[i]=fill;
        }
    }
    cache[1]=i;
    if(ret==1){
        ret=0;
        if(a==1){
            if(op==2||op==3){
                window[mouse]=mouse_icon;
                return fail;
            }
            window[mouse]=mouse_icon;
            return fill;
        }else{
            if(op==2||op==3){
                window[mouse]=mouse_icon;
                return fill;
            }
            window[mouse]=mouse_icon;
            return fail;
        }
    }
}
int remove_button(int start,int end,int id,int fill,int fail,int op){
    a=0;
    if(button[mouse]==id&&op==1||op==3){
        ret=1;
    }
    for(i=start;i<end;i++){
        if(button[i]==id){
            if(a==0){
                cache[0]=i;a=1;
            }
            button[i]=0;
            if(window[i]==mouse_icon){
                continue;
            }
            window[i]=fill;
        }
    }
    cache[1]=i;
    if(ret==1){
        ret=0;
        if(a==1){
            if(op==2||op==3){
                window[mouse]=mouse_icon;
                return fail;
            }
            window[mouse]=mouse_icon;
            return fill;
        }else{
            if(op==2||op==3){
                window[mouse]=mouse_icon;
                return fill;
            }
            window[mouse]=mouse_icon;
            return fail;
        }
    }
}
int mouse_move(){
    i=getch();
	if(i==65){
		mouse=mouse-static_x-1;
	}
	if(i==66){
		mouse=mouse+static_x+1;
	}
	if(i==68){
		mouse=mouse-1;
	}
	if(i==67){
		mouse=mouse+1;
	}
	if(i==10){
    	return 1;
	}
	//printf("%d\n",mouse);
}
void window_show(){
	if(dvc==1||dvc==0){
		for(i=0;i<show;i++){
			printf("%c",window[i]);
		}
		printf("\n");
		for(sys[0][0]=0;sys[0][0]<sys[2][4];sys[0][0]++)
			printf("%c",window[sys[0][0]]);
	}
	if(dvc==2||dvc==0){
		for(sys_new[0][0]=0;sys_new[0][0]<sys_new[2][3];sys_new[0][0]++)
			for(sys_new[0][1]=0;sys_new[0][1]<=sys_new[2][2];sys_new[0][1]++){ 	
				gotoxy(sys_new[0][1],sys_new[0][0]);
				printf("%c",sys_new[2][4]);
			}
		for(sys_new[0][0]=0;sys_new[0][0]<0x0;sys_new[0][0]++)
			for(sys_new[0][1]=graphics_new[sys_new[0][0]][1];sys_new[0][1]<graphics_new[sys_new[0][0]][3];sys_new[0][1]++)
				for(sys_new[0][2]=graphics_new[sys_new[0][0]][0];sys_new[0][2]<graphics_new[sys_new[0][0]][2];sys_new[0][2]++){
					if(sys_new[0][2]>sys_new[2][2]||sys_new[0][1]>sys_new[2][3])
						return -1;
					gotoxy(sys_new[0][2],sys_new[0][1]);
					printf("%c",graphics_new[sys_new[0][0]][4]);
				}
	}
	return 0;
}
void dbg(){
    h++;
    printf("%d\n",h);
    getch();
}
int new_graphics(int start_x,int start_y,int end_x,int end_y,int id,int fill){
	if(dvc==1||dvc==0){
		sys[1][0]=0;
		for(sys[0][0]=0;sys[0][0]<start_x;sys[0][0]++)
			sys[1][0]++;
		for(sys[0][0]=0;sys[0][0]<start_y;sys[0][0]++)
			sys[1][0]=sys[1][0]+sys[2][2]+1;sys[1][1]=sys[1][0];
		for(sys[0][0]=0;sys[0][0]<end_y;sys[0][0]++){
			for(sys[0][1]=0;sys[0][1]<end_x;sys[0][1]++)
				{window[sys[1][0]]=fill;graphics[sys[1][0]]=id;sys[1][0]++;}
			sys[1][0]=sys[1][0]+sys[2][2]+1-end_x;
		}
		sys[1][2]=sys[1][0];
	}
	if(dvc==2||dvc==0){
		if(start_x>sys[2][2]||start_y>sys[2][3]||end_x>sys[2][2]||end_y>sys[2][3])
			return -1;
		graphics_new[id][0]=start_x;graphics_new[id][1]=start_y;graphics_new[id][2]=end_x;graphics_new[id][3]=end_y;graphics_new[id][4]=fill;
	}
	return 0;
}
int fill_graphics_picture(int start,int end,int id,char picture[0xffffff],int len,int op){
	if(dvc==1||dvc==0){
		sys[1][0]=0;
		for(sys[0][0]=start;sys[0][0]<end;sys[0][0]++){
			if(graphics[sys[0][0]]==id)
				break;
			if(sys[0][0]==sys[2][4])
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
						window[sys[1][0]]=sys[2][1];
				}else
					window[sys[1][0]]=picture[sys[0][0]];
			}else
				sys[0][0]--;
			sys[1][0]++;
			if(sys[1][0]>=sys[2][4]||sys[0][0]>=0xffffff)
				return -2;
		}
		sys[1][2]=sys[1][0];
		sys[0][3]=0;
	}
	if(dvc==2||dvc==0){
		for(sys[0][1]=graphics_new[id][1];sys[0][1]<graphics_new[id][3];sys[0][1]++){
			for(sys[0][2]=graphics_new[id][0];sys[0][2]<graphics_new[id][2];sys[0][2]++){
				if(picture[sys[0][3]]==10){
					sys[0][1]++;sys[0][2]=graphics_new[id][0];sys[0][3]++;
				}
				gotoxy(sys[0][2],sys[0][1]);
				printf("%c",picture[sys[0][3]++]);
				if(sys[0][3]>len)
					break;
			}
		}
	}
	return 0;
}
int remove_graphics(int start,int end,int id,int fill){
	if(dvc==1||dvc==0){
		for(sys[0][0]=start;sys[0][0]<=end||sys[0][0]<=sys[2][4];sys[0][0]++)
			if(graphics[sys[0][0]]==id)
				{graphics[sys[0][0]]=0;window[sys[0][0]]=fill;}
	}
	if(dvc==2||dvc==0){
		for(sys[0][1]=graphics_new[id][1];sys[0][1]<graphics_new[id][3];sys[0][1]++){
			for(sys[0][2]=graphics_new[id][0];sys[0][2]<graphics_new[id][2];sys[0][2]++){
				gotoxy(sys[0][2],sys[0][1]);
				printf("%c",fill);
			}
		}
		graphics_new[id][0]=0;graphics_new[id][1]=0;graphics_new[id][2]=0;graphics_new[id][3]=0;graphics_new[id][4]=0;
	}
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
		for(sys[0][1]=graphics_new[sys[0][0]][1];sys[0][1]<graphics_new[sys[0][0]][3];sys[0][1]++)
			for(sys[0][2]=graphics_new[sys[0][0]][0];sys[0][2]<graphics_new[sys[0][0]][2];sys[0][2]++){
				gotoxy(sys[0][2],sys[0][1]);
				printf("%c",graphics_new[sys[0][0]][4]);
			}
}
int main(){
	dvc=2;
	init();
	window_create(40,10,35);
	window_show();
}