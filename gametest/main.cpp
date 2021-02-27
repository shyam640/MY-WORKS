#include<windows.h>
#include<graphics.h>
#include <winbgim.h> 

main(int argc, char *argv[])
{
	initwindow(300, 300);					// init window graphics
	setbkcolor(1);							// set background
   	cleardevice();
	setcolor(14);							// set text color
	circle(100,100,20);// print text in window graphics
	while(!kbhit()) delay(1);				// pause screen	
}