#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define ROUND(a) (int)((a + 0.5))

void liangClip(int x1, int y1, int x2, int y2, int xwmin, int ywmin,
			   int xwmax, int ywmax) {
	int i, k1, k2, dx, dy;
	float u1, u2, P[4], q[4], a1[4], a2[4];
	float xc1, yc1, xc2, yc2, temp;
	int flag = 0; //to check if line is clipped

	dx = x2 - x1;
	dy = y2 - y1;

	P[0] = (-1)*dx;
	P[1] = dx;
	P[2] = (-1)*dy;
	P[3] = dy;

	q[0] = x1 - xwmin;
	q[1] = xwmax - x1;
	q[2] = y1 - ywmin;
	q[3] = ywmax - y1;

	u1 = 0;
	u2 = 1;
	for(i = 0; i < 4; i++) {
		if(flag == 0) {
			if(P[i] == 0) {
				if(q[i] >= 0) {
					//Line is parallel to window
					if(i <= 1) {
					//P1 or P2 = 0
					// i.e dx = 0 therefore line is parallel to y
						if(y1 < ywmin)
							y1 = ywmin;
						if(y2 > ywmax)
							y2 = ywmax;
						setcolor(BLUE);
						line(x1,y1,x2,y2);
						flag = 1;
					}
					if(i >= 2) {
					//P3 or P4 = 0
					//i.e. dy = 0 or line is parallel to x
						if(x1 < xwmin)
							x1 = xwmin;
						if(x2 > xwmax)
							x2 = xwmax;
						setcolor(BLUE);
						line(x1,y1,x2,y2);
						flag = 1;
					}
				}
			} else {
				temp = q[i] / P[i];
				if(P[i] < 0) {
					if(temp >= u1)
						u1 = temp;
				} else {
					if(temp < u2)
						u2 = temp;
				}
			}
		}
	}
	if(flag == 0) {
	//Line is not yet clipped i.e. its not parallel to window
		if(u1 > u2) {
			//Line is completely outside
			return;
		} else {
			xc1 = x1 + u1 * dx;
			yc1 = y1 + u1 * dy;
			xc2 = x1 + u2 * dx;
			yc2 = y1 + u2 * dy;

			setcolor(BLUE);
			line(ROUND(xc1), ROUND(yc1), ROUND(xc2), ROUND(yc2));
		}
	}
}

void main() {
	int gd = DETECT, gm, xwmin, ywmin, xwmax, ywmax;
	int x1, x2, y1, y2;
	initgraph(&gd, &gm, "C://TurboC3//BGI");

	printf("Enter (xwmin, ywmin): ");
	scanf("%d%d", &xwmin, &ywmin);
	printf("Enter (xwmax, ywmax): ");
	scanf("%d%d", &xwmax, &ywmax);

	printf("Enter line coordinates (x1,y1)\n");
	scanf("%d%d", &x1, &y1);
	printf("Enter line coordinates (x2,y2)\n");
	scanf("%d%d", &x2, &y2);

	//Initial line
	line(x1,y1,x2,y2);
	//Let's make a window
	rectangle(xwmin,ywmin, xwmax, ywmax);
	liangClip(x1,y1,x2,y2,xwmin,ywmin,xwmax,ywmax);

	getch();
}