#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main () {
	int i, gd = DETECT, gm;
	initgraph(&gd, &gm, "C://TurboC3//BGI");

	for(i = 0; i < 100; i++) {
		delay(20);
		cleardevice();
		line(i+150,150,i+300,150);
		line(i+300,150,i+300,300);
		line(i+300,300,i+150,300);
		line(i+150,300,i+150,150);
		setcolor(LIGHTCYAN);
		line(i+170,170,i+225,280);
		line(i+225,280,i+280,170);
	}
	getch();
}