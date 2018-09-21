#include "stdafx.h"

void p_food(int i){
	int p;

	//Robot perceptual cues　
	robot[i].p_touch_food		=	0;		//Determining touch to Food
//	robot[i].p_phero		=	0;		//Determining touch to pheromone
	robot[i].p_arrival_nest		=	0;		//Determining touch to nest

	//Perceptual cues: touch food
	if(robot[i].state == 1 || robot[i].state == 3){
		for(p = 0; p < foods; p++){
			double dis_ac = sqrt(pow(robot[i].x - food[p].x, 2) + pow(robot[i].y - food[p].y, 2));
			double dis_r = Food_scale + scale_argos;

			if(dis_ac <= dis_r){
				robot[i].p_touch_food = TRUE;//ON
				//robot[i].ang_OA = atan2((robot[i].y - food[p].y), (robot[i].x - food[p].x));

				//Flagging of each food item
				robot_parallelism_check(i, p);
			}
		}
	}
	else
		robot[i].p_touch_food = FALSE;
}


void p_pheromone(int i){
	//Perceptual cues: touch pheromone
	if(robot[i].state == 1 || robot[i].state == 3){
		//Left sensor
		if(robot[i].L_sensor > P_Det){
			robot[i].p_phero_L = TRUE;
			robot[i].p_sc_timer = 0;
		}
		else
			robot[i].p_phero_L = FALSE;

		//Right sensor
		if(robot[i].R_sensor > P_Det){
			robot[i].p_phero_R = TRUE;
			robot[i].p_sc_timer = 0;
		}
		else
			robot[i].p_phero_R = FALSE;
	}
	else{
		robot[i].p_phero_L = FALSE;
		robot[i].p_phero_R = FALSE;
	}

	if(robot[i].p_phero_L == TRUE && robot[i].p_phero_R == TRUE){
		robot_mem[i].ang_r_mem1 = atan2(robot[i].dy, robot[i].dx);
	}
}


void p_nest(int i){
	//Perceptual cues: touch nest
	if(robot[i].state == 2){
		if(pow(robot[i].x - nest_x, 2) + pow(robot[i].y - nest_y, 2) <= pow(G1_scale, 2))
			robot[i].p_arrival_nest = TRUE;	
	}
	else
		robot[i].p_arrival_nest = FALSE;//OFF
}


void p_lay_failure(int i){
	if(robot[i].state == 2 && robot[i].count_lay_failure >= 5)
		robot[i].p_lay_miss = TRUE;
	else
		robot[i].p_lay_miss = FALSE;
}


void robot_perceptual_cues(void){
	int i;

	#pragma omp parallel for
	for (i = 0; i < robots; i++){
		p_food(i);
		p_pheromone(i);
		p_nest(i);
		p_lay_failure(i);
	}
}
