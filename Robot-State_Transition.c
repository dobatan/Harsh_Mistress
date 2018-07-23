#include "stdafx.h"


void state1_change(int i){
	if (robot[i].p_touch_food == 1){
		robot[i].state = 2;
		robot[i].count_move = 0;
	}
	if (robot[i].p_phero_L == TRUE || robot[i].p_phero_R == TRUE){
		P_p_rand = (double)rand() / ((double)RAND_MAX + 1);
		if (P_p_rand < P_p[swarm]) {
			robot[i].state = 3;
			robot[i].p_sc_timer = 0;
		}
	}
}


void state2_change(int i){
	if (robot[i].p_arrival_nest == TRUE){
		robot[i].state = 1;
		robot[i].p_sc_timer = 0;
		robot_parallelism_flagdown(i);
		foodcount += 1;
	}
	if(robot[i].p_lay_miss == TRUE){
		robot[i].state = 1;
		robot[i].count_lay_failure = 0;
	}
}


void state3_change(int i){
	if (robot[i].p_touch_food == TRUE){
		robot[i].state = 2;
		robot[i].count_move = 0;
	}
	if(robot[i].p_sc_timer > 60)
		robot[i].state = 1;
}


void robot_state_transition_rules(void){
	int i;

	#pragma omp parallel for
	for (i = 0; i < robots; ++i){
		switch(robot[i].state){		
			case 1:
				state1_change(i);
				break;
			case 2:
				state2_change(i);
				break;
			case 3:
				state3_change(i);
				break;
			default:
				break;
		}
	}
}
