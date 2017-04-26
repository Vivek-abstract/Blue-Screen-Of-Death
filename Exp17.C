#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define ROUND(a) ((int) (a+0.5))

//We use a structure to store the two points
struct region {
	int t,b,r,l,x,y;
};

//A function for debugging
void display(struct region P) {
	printf("(%d,%d,%d,%d,%d,%d)",P.t,P.b,P.r,P.l,P.x,P.y);
}

//A function that calculates the region codes of point P
struct region *calculate(struct region P,
								int xwmin,int ywmin,int xwmax,int ywmax){
	struct region *temp;
	temp = (struct region *)malloc(sizeof(struct region));
	if(P.y > ywmax)
		temp->t=1;
	else
		temp->t=0;
	if(P.y < ywmin)
		temp->b=1;
	else
		temp->b=0;
	if(P.x < xwmin)
		temp->l=1;
	else
		temp->l=0;
	if(P.x > xwmax)
		temp->r=1;
	else
		temp->r=0;
	temp->x = P.x;
	temp->y = P.y;
	return temp;
}

//The main logic behind midpoint subdivision!
//if RC of both points = 0000 then line is completely visible
//else:
//  if logical ANDing of RC of both points = 0000 then
//    line may be visible, calculate midpoint(P1,P2 and
//    repeat for P1,M and M,P2
//  else:
//    line is invisible
void midpointsubdivision(struct region P1, struct region P2,
								 int xwmin,int ywmin,int xwmax,int ywmax) {
	struct region M,*P1n,*P2n;
	P1n = calculate(P1,xwmin,ywmin,xwmax,ywmax);
	P2n = calculate(P2,xwmin,ywmin,xwmax,ywmax);

	//Checks if everything is 0000 i.e. line is visible
	if(P1n->t==0 && P1n->b==0 && P1n->r==0 && P1n->l==0 && P2n->t==0
					&& P2n->b==0 && P2n->r==0 && P2n->l==0) {
		line(P1n->x,P1n->y,P2n->x,P2n->y);
	} else {
		//Checks logical ANDing of RC of P1 and P2
		if(((P1n->t & P2n->t)==0) && ((P1n->b & P2n->b)==0) &&
		((P1n->r & P2n->r)==0) && ((P1n->l & P2n->l)==0)) {
			//Line is partially visible calculate midpoint
			M.x = (P1n->x+P2n->x)/2;
			M.x = ROUND(M.x);
			M.y = (P1n->y+P2n->y)/2;
			M.y = ROUND(M.y);
			midpointsubdivision(P1,M,xwmin,ywmin,xwmax,ywmax);
			midpointsubdivision(M,P2,xwmin,ywmin,xwmax,ywmax);
		} else {
			//Line is invisible
			return;
		}

	}
}

void main() {
	int x1 = 50,y1 =50, x2= 400,y2 = 400, gm, gd = DETECT;
	int xwmin = 100,ywmin = 100,xwmax = 200, ywmax = 200;
	struct region *P1,*P2;
	initgraph(&gd,&gm,"..\\BGI");

	//Take two points and assign them to structure
	P1 = (struct region *)malloc(sizeof(struct region));
	P2 = (struct region *)malloc(sizeof(struct region));
	P1->x = x1;
	P1->y = y1;
	P2->x = x2;
	P2->y = y2;

	//Initially
	rectangle(xwmin,ywmin,xwmax,ywmax);
	line(x1,y1,x2,y2);
	getch();
	cleardevice();

	//Finally
	rectangle(xwmin,ywmin,xwmax,ywmax);
	setcolor(BLUE);
	midpointsubdivision(*P1,*P2,xwmin,ywmin,xwmax,ywmax);
	getch();
}