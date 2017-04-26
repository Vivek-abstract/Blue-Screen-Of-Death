#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void midpointEllipse(long xc, long yc, long rx, long ry) {
	long x = 0, y = ry;
	double P10, P1k, P20, P2k;

	putpixel(x + xc, y + yc, LIGHTCYAN);

	P10 = pow(ry,2) - pow(rx,2)*ry + pow(rx,2)/4.0;
	P1k = P10;
	while(2*ry*ry*x <= 2*rx*rx*y) {
		if(P1k < 0) {
			x++;
			P1k += 2*ry*ry*x + ry*ry;
		} else {
			x++;
			y--;
			P1k += 2*ry*ry*x - 2*rx*rx*y + ry*ry;
		}
		putpixel(x + xc, y + yc, LIGHTCYAN);
		putpixel(-x + xc, y + yc, LIGHTCYAN);
		putpixel(x + xc, -y + yc, LIGHTCYAN);
		putpixel(-x + xc, -y + yc, LIGHTCYAN);
		delay(5);
	}

	P20 = pow(ry,2)*pow((x+0.5),2) +
		  pow(rx,2)*pow((y-1),2) -
		  pow(rx,2)*pow(ry,2);
	P2k = P20;

	//Note this condition
	while(2*ry*ry*x >= 2*rx*rx*y && y != 0) {
		if(P2k > 0) {
			y--;
			P2k = P2k - 2*rx*rx*y + rx*rx;
		} else {
			y--;
			x++;
			P2k = P2k + 2*ry*ry*x - 2*rx*rx*y + rx*rx;
		}
		putpixel(x + xc, y + yc, LIGHTCYAN);
		putpixel(-x + xc, y + yc, LIGHTCYAN);
		putpixel(x + xc, -y + yc, LIGHTCYAN);
		putpixel(-x + xc, -y + yc, LIGHTCYAN);
		delay(5);
	}
}

void main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C://TurboC3//BGI");

	midpointEllipse(250, 250, 50, 100);

	getch();
}