 #include <stdio.h>
 #include <conio.h>
 #include <graphics.h>

 void midpointCircle(int xc, int yc, int r) {
	int Po, Pk, k, x, y;
	putpixel(0+xc, r+yc, LIGHTCYAN);

	Po = 1-r;
	Pk = Po;
	x = 0;
	y = r;

	while(x <= y) {
		if(Pk < 0) {
			x++;
			Pk += 2*x + 1;
		} else {
			x++;
			y--;
			Pk += 2*x - 2*y + 1;
		}
		//Upper right 1/4th circle
		putpixel(y + xc, -x + yc, LIGHTCYAN);
		putpixel(x + xc, -y + yc, LIGHTCYAN);
		delay(5);
	}

 }

 void main() {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C://Turboc3//BGI");
	midpointCircle(250,250,100);
	getch();
 }