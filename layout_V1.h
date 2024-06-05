#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include<time.h>










char window[100000000],sub_window[100000000],button_icon[100000000],bk=0,mouse_icon=0;
int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,m,x=0,y=0,address=0,heiglt=0,width=0,fill=0,show=0,static_x=0,static_y=0,mouse=0,mouse_x=0,mouse_y=0,notes=0,flag=0,os=0,button[100000000],text_box[100000000],level[100000000],cache[100000000],sys[10],ascii[10];
void init(){
    for(sys[0]=0;sys[0]<100000000;sys[0]++){
        window[sys[0]]=0;sub_window[sys[0]]=0;text_box[sys[0]]=0;button[sys[0]]=0;button_icon[sys[0]]=0;level[sys[0]]=0;cache[sys[0]]=0;
    }
}
void window_create(int width,int heiglt,int fill){
	static_x=width;static_y=heiglt;address=0;
	for(sys[0]=0;sys[0]<heiglt;sys[0]++){
		for(sys[1]=0;sys[1]<width;sys[1]++){
			window[address]=fill;address++;
		}
		window[address]=ascii[0];address++;
	}
	for(address=100000000;address>0;address--){
	    if(window[address]==ascii[0]){
			break;
		}
		window[address]=0;
	}
	show=address;
}
void add_sub_window(int start_x,int start_y,int end_x,int end_y,int id,int fill){
    address=0;
    for(sys[0]=0;sys[0]<start_x;sys[0]++){
        address++; 
    }
    for(sys[0]=0;sys[0]<start_y;sys[0]++){
        address=address+static_x+1;
    }
    cache[0]=address;
    for(sys[0]=0;sys[0]<end_y;sys[0]++){
        for(sys[1]=0;sys[1]<end_x;sys[1]++){
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
    for(sys[0]=0;sys[0]<start_x;sys[0]++){
        address++;
    }
    for(sys[0]=0;sys[0]<start_y;sys[0]++){
        address=address+static_x+1;
    }
    cache[0]=address;
    for(sys[0]=0;sys[0]<end_y;sys[0]++){
        for(sys[1]=0;sys[1]<end_x;sys[1]++){
            text_box[address]=id;window[address]=ascii[1];address++;
        }
        address=address+static_x+1-end_x;
    }
    cache[1]=address;
}
void add_button(int start_x,int start_y,int end_x,int end_y,int id,char button_icon[100000000]){
	address=0;sys[0]=0;sys[1]=0;sys[2]=0;sys[0]=strlen(button_icon);
	for(sys[3]=0;sys[3]<start_x;sys[3]++){
		address++;
	}
	for(sys[3]=0;sys[3]<start_y;sys[3]++){
		address=address+static_x+1;
	}
	cache[0]=address;
	for(sys[3]=0;sys[3]<end_y;sys[3]++){
		for(sys[4]=0;sys[4]<end_x;sys[4]++){
			button[address]=id;
			if(sys[1]>=sys[0]){
				window[address]=ascii[1];sys[1]++;
			}else if(button_icon[sys[1]]==ascii[0]){
                cache[1]=address;
                for(;button[address]!=id;address++){}
                cache[2]=address;
                for(;button[address]==id;address++){}
                cache[3]=address;sys[1]++;
			}else{
				window[address]=button_icon[sys[1]];sys[1]++;
			}
			address++;
		}
		address=address+static_x+1-end_x;
	}
	cache[4]=address;
}
void add_level(int end_x,int end_y,int id){
    address=0;
    for(sys[0]=0;sys[0]<end_x;sys[0]++){
        address++;
    }
    for(sys[0]=0;sys[0]<end_y;sys[0]++){
        address=address+static_x+1;
    }
    cache[0]=address;level[address]=id;window[address]=ascii[1];
}
void edit_text(int start,int end,char text[100000000],int size,int id,int locate,int op){
    sys[0]=0;sys[1]=0;sys[2]=0;address=0;
    for(sys[3]=start;sys[3]<end;sys[3]++){
        if(text_box[sys[3]]==id){
            break;
        }
        address++;
        if(address==show){
            return;
        }
    }
    cache[0]=address;
    for(sys[3]=0;sys[3]<locate;sys[3]++){
        address++;
        if(text_box[address]!=id){
            address=address+static_x+1;
        }
    }
    cache[1]=address;
    for(sys[3]=0;sys[3]<size;sys[3]++){
        if(text_box[address]==id){
            if(window[address]==mouse_icon){
                continue;
            }
            if(text[sys[3]]==ascii[0]){
                cache[2]=address;
                for(;text_box[address]!=id;address++){}
                cache[3]=address;
                for(;text_box[address]==id;address++){}
                cache[4]=address;
                continue;
            }
            if(op==1){
                if(text[sys[3]]>=32&&text[sys[3]]<=126){
                    window[address]=text[sys[3]];
                }else{
                    window[address]=ascii[1];
                }
            }else{
                window[address]=text[sys[3]];
            }
            address++;
        }else{
            sys[3]--;address++;
            if(address==show){
                return;
            }
        }
    }
    cache[5]=address;
}
void scanner(int scanmode,int op,int input,int input1){
    sys[0]=0;
    if(scanmode==0){
        if(op==0){
            for(sys[1]=0;sys[1]<show;sys[1]++){
                if(window[sys[1]]==input){
                    cache[sys[0]]=sys[1];sys[0]++;
                }
            }
        }
        if(op==1){
            for(sys[1]=0;sys[1]<show;sys[1]++){
                if(window[sys[1]]==input){
                    window[sys[1]]=input1;
                }
            }
        }
    }
    if(scanmode==1){
        if(op==0){
            for(sys[1]=0;sys[1]<show;sys[1]++){
                if(sub_window[sys[1]]==input){
                    cache[sys[0]]=sys[1];sys[0]++;
                }
            }
        }
        if(op==1){
            for(sys[1]=0;sys[1]<show;sys[1]++){
                if(sub_window[sys[1]]==input){
                    sub_window[sys[1]]=input1;
                }
            }
        }
    }
    if(scanmode==2){
        if(op==0){
            for(sys[1]=0;sys[1]<show;sys[1]++){
                if(button[sys[1]]==input){
                    cache[sys[0]]=sys[1];sys[0]++;
                }
            }
        }
        if(op==1){
            for(sys[1]=0;sys[1]<show;sys[1]++){
                if(button[sys[1]]==input){
                    button[sys[1]]=input1;
                }
            }
        }
    }
    if(scanmode==3){
        if(op==0){
            for(sys[1]=0;sys[1]<show;sys[1]++){
                if(text_box[sys[1]]==input){
                    cache[sys[0]]=sys[1];sys[0]++;
                }
            }
        }
        if(op==1){
            for(sys[1]=0;sys[1]<show;sys[1]++){
                if(text_box[sys[1]]==input){
                    text_box[sys[1]]=input1;
                }
            }
        }
    }
    if(scanmode==4){
        if(op==0){
            for(sys[1]=0;sys[1]<show;sys[1]++){
                if(level[sys[1]]==input){
                    cache[sys[0]]=sys[1];sys[0]++;
                }
            }
        }
        if(op==1){
            for(sys[1]=0;sys[1]<show;sys[1]++){
                if(level[sys[1]]==input){
                    level[sys[1]]=input1;
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
int remove_sub_window(int start,int end,int id,int fill,int fail,int op){
    sys[0]=0;sys[1]=0;address=0;
    if(sub_window[mouse]==id&&op==1||op==3){
        sys[1]=1;
    }
    for(sys[2]=start;sys[2]<end;sys[2]++){
        if(sub_window[sys[2]]==id){
            if(sys[0]==0){
                cache[0]=sys[2];sys[0]=1;
            }
            sub_window[sys[2]]=0;
            if(window[sys[2]]==mouse_icon){
                continue;
            }
            window[sys[2]]=fill;
        }
    }
    cache[1]=sys[2];
    if(sys[1]==1){
        sys[1]=0;
        if(sys[0]==1){
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
int remove_text_box(int start,int end,int id,int fill,int fail,int op){
    sys[0]=0;sys[1]=0;address=0;
    if(text_box[mouse]==id&&op==1||op==3){
        sys[1]=1;
    }
    for(sys[2]=start;sys[2]<end;sys[2]++){
        if(text_box[sys[2]]==id){
            if(sys[0]==0){
                cache[0]=sys[2];sys[0]=1;
            }
            text_box[sys[2]]=0;
            if(window[sys[2]]==mouse_icon){
                continue;
            }
            window[sys[2]]=fill;
        }
    }
    cache[1]=sys[2];
    if(sys[1]==1){
        sys[1]=0;
        if(sys[0]==1){
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
    sys[0]=0;sys[1]=0;address=0;
    if(button[mouse]==id&&op==1||op==3){
        sys[1]=1;
    }
    for(sys[2]=start;sys[2]<end;sys[2]++){
        if(button[sys[2]]==id){
            if(sys[0]==0){
                cache[0]=sys[2];sys[0]=1;
            }
            button[sys[2]]=0;
            if(window[sys[2]]==mouse_icon){
                continue;
            }
            window[sys[2]]=fill;
        }
    }
    cache[1]=sys[2];
    if(sys[1]==1){
        sys[1]=0;
        if(sys[0]==1){
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
int remove_level(int start,int end,int id,int fill,int fail,int op){
    sys[0]=0;sys[1]=0;address=0;
    if(level[mouse]==id&&op==1||op==3){
        sys[1]=1;
    }
    for(sys[2]=start;sys[2]<end;sys[2]++){
        if(level[sys[2]]==id){
            if(sys[0]==0){
                cache[0]=sys[2];sys[0]=1;
            }
            level[sys[2]]=0;
            if(window[sys[2]]==mouse_icon){
                continue;
            }
            window[sys[2]]=fill;
        }
    }
    cache[1]=sys[2];
    if(sys[1]==1){
        sys[1]=0;
        if(sys[0]==1){
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
    sys[0]=getch();
	if(sys[0]==ascii[2]){
		mouse=mouse-static_x-1;
	}
	if(sys[0]==ascii[3]){
		mouse=mouse+static_x+1;
	}
	if(sys[0]==ascii[4]){
		mouse=mouse-1;
	}
	if(sys[0]==ascii[5]){
		mouse=mouse+1;
	}
	if(sys[0]==ascii[0]){
   		return 1;
	}
	//printf("%d\n",mouse);
}
void window_show(){
	for(sys[0]=0;sys[0]<show;sys[0]++){
		printf("%c",window[sys[0]]);
		//printf("%d",window[sys[0]]);
	}
}
