#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#define ROUND(a) (int)((a+0.5))
#define PI 3.14259

void Rotate(int x, int y, double angle) {
	double T[3][3] = {1,0,0,0,1,0,0,0,1};
	int a[1][3] = {0,0,1};
	double ans[1][3];
	int i, j, k;

	a[0][0] = x;
	a[0][1] = y;
	T[0][0] = cos(angle);
	T[0][1] = sin(angle);
	T[1][0] = -sin(angle);
	T[1][1] = cos(angle);
	/*
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("%lf ", T[i][j]);
		}
		printf("\n");
	}
	*/
	for(i = 0; i < 1; i++) {
		for(j = 0; j < 3; j++) {
			ans[i][j] = 0;
			for(k = 0; k < 3; k++) {
				ans[i][j] += a[i][k] * T[k][j];
			}
		}
	}
   //	printf("%lf %lf\n", ans[0][0], ans[0][1]);
	putpixel(ROUND(ans[0][0]), ROUND(ans[0][1]), LIGHTCYAN);
}

void main() {
	int i = 0, gd = DETECT, gm;
	initgraph(&gd, &gm, "C://TurboC3//BGI");

	line(200,200,300,200);
	line(300,200,300,300);
	line(300,300,200,300);
	line(200,300,200,200);

	//We apply the function to every point of the object
	for(i = 100; i <= 200; i++) {
		Rotate(i,100,PI/9);
		Rotate(200,i,PI/9);
		Rotate(i,200,PI/9);
		Rotate(100,i,PI/9);
	}

	getch();
}