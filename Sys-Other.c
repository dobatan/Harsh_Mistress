#include "stdafx.h"


void sys_log_save(void){
	int i;
	int j;

	#pragma omp parallel for
	for (i = 0; i < robots; i++){
		//Robot_Log
		//robot_log[i][step].step		= step;
		//robot_log[i][step].x		= robot[i].x;
		//robot_log[i][step].y		= robot[i].y;
		//robot_log[i][step].ang_r	= robot[i].ang_r;
		//robot_log[i][step].state	= robot[i].state;

		//State_Log
		state_log[i][step]			= robot[i].state;
	}

	//Food_Log
	#pragma omp parallel for
	for (j = 0; j < foods; j++){
		food_log[j][step].step		= step;
		food_log[j][step].x			= food[j].x;
		food_log[j][step].y			= food[j].y;
		food_log[j][step].dis		= food[j].dis;
		food_log[j][step].state		= food[j].state;
	}
}


void sys_step_memo(void){//Step‚XXX
	int step_EO;

	step_EO = step % 2;
	if(step_EO == 0){
		t = 0;
		t_1 = 1;
	}
	else{
		t = 1;
		t_1 = 0;
	}
}
