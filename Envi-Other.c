#include "stdafx.h"

void position(void)
{
	//
	int i;

	#pragma omp parallel for
	for (i = 0; i < robots; ++i){
		robot[i].grid_x = (int)(robot[i].x);
		robot[i].grid_y = (int)(robot[i].y);

		if(robot[i].grid_x == WIDTH)
			robot[i].grid_x = WIDTH - 1;
		if(robot[i].grid_y == HEIGHT)
			robot[i].grid_y = HEIGHT - 1;
	}
}


void envi_other(void){
	position();
}
