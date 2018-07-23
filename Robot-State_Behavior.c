#include "stdafx.h"


void state1_behavior(int i){
	random_walk(i);
}


void state2_behavior(int i){
	go2nest(i);
	if(p_density != 0)
		add_pheromone(i);
}


void state3_behavior(int i){
	follow_pheromone(i);
	robot[i].p_sc_timer++;
}


void robot_state_behavior(void){
	int i;

	#pragma omp parallel for
	for (i = 0; i < robots; ++i){
		switch(robot[i].state){
			case 1:
				state1_behavior(i);
				break;
			case 2:
				state2_behavior(i);
				break;
			case 3:
				state3_behavior(i);
				break;
			default:
				break;
		}
	}
}
