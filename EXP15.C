#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void boundaryFill(int x, int y, int fillc, int boundaryc) {
	int current = getpixel(x,y);
	if((current != boundaryc) && (current != fillc)) {
		putpixel(x,y,fillc);
		delay(5);
		boundaryFill(x+1,y,fillc,boundaryc);
		boundaryFill(x-1,y,fillc,boundaryc);
		boundaryFill(x,y+1,fillc, boundaryc);
		boundaryFill(x,y-1,fillc, boundaryc);
	}
}

void main() {
	int gd = DETECT, gm;
	int square[] = {200,200,250,200,250,250,200,250,200,200};
	initgraph(&gd, &gm, "C://TurboC3//BGI");

	drawpoly(5,square);
	boundaryFill(201, 201, RED, WHITE);

	getch();
}