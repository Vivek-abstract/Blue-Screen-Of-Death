#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void ScaleXY(int x, int y, int sx, int sy) {
	int T[3][3] = {1,0,0,0,1,0,0,0,1};
	int S[3][3] = {1,0,0,0,1,0,0,0,1};
	int a[1][3] = {0,0,1};
	int ans[1][3];
	int i, j, k;

	a[0][0] = x;
	a[0][1] = y;
	S[0][0] = sx;
	S[1][1] = sy;

	for(i = 0; i < 1; i++) {
		for(j = 0; j < 3; j++) {
			ans[i][j] = 0;
			for(k = 0; k < 3; k++) {
				ans[i][j] += a[i][k] * S[k][j];
			}
		}
	}
	putpixel(ans[0][0], ans[0][1], LIGHTCYAN);
}

void main() {
	int i = 0, gd = DETECT, gm;
	initgraph(&gd, &gm, "C://TurboC3//BGI");

	line(100,100,200,100);
	line(200,100,200,200);
	line(200,200,100,200);
	line(100,200,100,100);

	//We apply the function to every point of the object
	for(i = 100; i <= 200; i++) {
		ScaleXY(i,100,2,2);
		ScaleXY(200,i,2,2);
		ScaleXY(i,200,2,2);
		ScaleXY(100,i,2,2);
	}

	getch();
}