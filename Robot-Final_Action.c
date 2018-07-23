#include "stdafx.h"


void robot_final_action(void){
	int i;

	#pragma omp parallel for
	for (i = 0; i < robots; i++){
		robot[i].x += robot[i].dx;
		robot[i].y += robot[i].dy;
		robot[i].ang_d = robot[i].ang_r * 180 / M_PI;
	}
}