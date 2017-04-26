#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void bezier(int x[], int y[]) {
	float px, py, u;

	for(u = 0; u < 1; u += 0.01) {

		px = (1-u)*(1-u)*(1-u)*x[0]
		   + 3*u*(1-u)*(1-u)*x[1]
		   + 3*u*u*(1-u)*x[2]
		   + u*u*u*x[3];

		py = (1-u)*(1-u)*(1-u)*y[0]
		   + 3*u*(1-u)*(1-u)*y[1]
		   + 3*u*u*(1-u)*y[2]
		   + u*u*u*y[3];

		putpixel(px,py,LIGHTMAGENTA);
	}
}

void main() {
	int gd = DETECT, gm;
	int x[] = {350, 250, 250, 350};
	int y[] = {100, 150, 200, 250};
	initgraph(&gd, &gm, "C://TurboC3//BGI");

	bezier(x,y);
	setcolor(LIGHTMAGENTA);
	line(350,100,350,350);

	getch();
}