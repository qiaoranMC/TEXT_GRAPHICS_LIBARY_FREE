#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<stdarg.h>
#define graphics_max 0xffff
/*global*/
int local[0xf],data[0xffffff];
char public_input[0xffffff],public_output[0xffffff];
/*system*/
int sys[3][10],graphics[0xffff][6],indexflag[0xffff],ret[0xffff];
char ascii[256];
/*fui_system*/
int text_address[0xffffff],gifaddress[0xffff][0xff],bind[0xffff],program[0xffffff],step[0xffff][0xf];
/*The end*/