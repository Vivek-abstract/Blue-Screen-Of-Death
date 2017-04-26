#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void TranslateX_ScaleX(int x, int y, int tx, int sx) {
	int T[3][3] = {1,0,0,0,1,0,0,0,1};
	int S[3][3] = {1,0,0,0,1,0,0,0,1};
	int a[1][3] = {0,0,1};
	int b[1][3], ans[1][3];
	int i, j, k;

	a[0][0] = x;
	a[0][1] = y;
	T[2][0] = tx;
	S[0][0] = sx;


	//Multiply [x y 1]*T[3x3]
	for(i = 0; i < 1; i++) {
		for(j = 0; j < 3; j++) {
			b[i][j] = 0;
			for(k = 0; k < 3; k++) {
				b[i][j] += a[i][k] * T[k][j];
			}
		}
	}
	/*for(i = 0; i < 1;i++) {
		for(j = 0; j < 3; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	*/
	//Multiply b[1x3]*S[3x3]
	for(i = 0; i < 1; i++) {
		for(j = 0; j < 3; j++) {
			ans[i][j] = 0;
			for(k = 0; k < 3; k++) {
				ans[i][j] += b[i][k] * S[k][j];
			}
		}
	}
	putpixel(ans[0][0], ans[0][1], LIGHTCYAN);
}

void main() {
	int i = 0, gd = DETECT, gm;
	initgraph(&gd, &gm, "C://TurboC3//BGI");

	line(200,200,300,200);
	line(300,200,300,300);
	line(300,300,200,300);
	line(200,300,200,200);

	//We apply the function to every point of the object
	for(i = 200; i <= 300; i++) {
		TranslateX_ScaleX(i,200,5,2);
		TranslateX_ScaleX(300,i,5,2);
		TranslateX_ScaleX(i,300,5,2);
		TranslateX_ScaleX(200,i,5,2);
	}

	getch();
}