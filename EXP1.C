#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

void lineBres(int x1, int y1, int x2, int y2) {
	int k, temp, xk, yk, dx, dy, Po, Pk;
	float m;
	if(x1 > x2) {
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	dx = x2 - x1;
	dy = y2 - y1;
	xk = x1;
	yk = y1;
	putpixel(xk,yk, LIGHTCYAN);

	if(dx != 0) {
		m =  (float)dy / dx;
		if(m <= 1) {
			Po = 2*dy - dx;
			Pk = Po;
			for(k = 0; k < dx; k++) {
				if(Pk <= 0) {
					xk++;
					putpixel(xk,yk, LIGHTCYAN);
					Pk += 2*dy;
				} else {
					xk++;
					yk++;
					putpixel(xk, yk, LIGHTCYAN);
					Pk += 2*dy - 2*dx;
				}
			}
		} else {
			// m > 1
			Po = 2*dx - dy;
			Pk = Po;
			for(k = 0; k < dy; k++) {
				if(Pk <= 0) {
					yk++;
					putpixel(xk, yk, LIGHTCYAN);
					Pk += 2*dx;
				} else {
					xk++;
					yk++;
					putpixel(xk, yk, LIGHTCYAN);
					Pk += 2*dx - 2*dy;
				}
			}
		}
	} else {
		//x coordinate is same i.e. line is vertical
		if(y1 > y2) {
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		while(y1 <= y2) {
			putpixel(x1,y1, LIGHTCYAN);
			y1++;
		}
	}
}

void main() {
	int gd= DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	lineBres(100, 100, 300, 100);
	lineBres(300, 100, 300, 300);
	lineBres(300, 300, 100, 300);
	lineBres(100, 300, 100, 100);

	//I can't seem to figure out how to make this work for negative slope
	//so don't use an example of negative slope
	getch();
}