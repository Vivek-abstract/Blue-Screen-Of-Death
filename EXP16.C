#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void floodFill(int x, int y, int oldc, int fillc) {
	int current = getpixel(x,y);
	if((current == oldc) && (current != fillc)) {
		putpixel(x,y,fillc);
		delay(5);
		floodFill(x+1,y,oldc,fillc);
		floodFill(x-1,y,oldc,fillc);
		floodFill(x,y+1,oldc,fillc);
		floodFill(x,y-1,oldc,fillc);
	}
}

void main() {
	int gd = DETECT, gm;
	int square[] = {200,200,250,200,250,250,200,250,200,200};
	initgraph(&gd, &gm, "C://TurboC3//BGI");

	drawpoly(5,square);
	floodFill(201, 201, BLACK, LIGHTCYAN);

	setcolor(RED);
	line(300,200,350,200);
	setcolor(LIGHTBLUE);
	line(350,200,350,250);
	setcolor(LIGHTGREEN);
	line(350,250,300,250);
	setcolor(BROWN);
	line(300,250,300,200);

	floodFill(301,201,BLACK, LIGHTCYAN);
	getch();
}