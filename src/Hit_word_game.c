#include<stdio.h>
#include<time.h>
#include<conio.h>
int main(){
	int ch=0,cmp=0;
	srand(time(0));
	while(1){
		cmp=rand()%256;
		if(cmp>33&&cmp<126){
			printf("%c\n",cmp);
			ch=getch();
			if(ch==cmp)
				printf("Very good!\n");
		}
	}
	return 0;
}