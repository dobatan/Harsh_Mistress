#include "stdafx.h"


void state1_behavior(int i){	//Initial condition
	//robot[0].dx = -1;
	//robot[0].dy = 0;
	//robot[0].ang_r = atan2(robot[0].dy, robot[0].dx);

	//robot[1].dx = 1;
	//robot[1].dy = 0;
	//robot[1].ang_r = atan2(robot[1].dy, robot[1].dx);

	random_walk(i);
}


void state2_behavior(int i){	//Carrying single item
	//robot[0].dx = 0.1;
	//robot[0].dy = -1;
	//robot[0].ang_r = atan2(robot[0].dy, robot[0].dx);

	//robot[1].dx = 0.1;
	//robot[1].dy = 0;
	//robot[1].ang_r = atan2(robot[1].dy, robot[1].dx);

	go2nest(i);			//Move to nest

	//if (robot[i].count_move < 200){
	//	robot[i].dx = 0;
	//	robot[i].dy = 0;
	//	robot[i].count_move++;
	//}

	if(p_density != 0)
		add_pheromone(i);	//Adding pheromone
}


void state3_behavior(int i){	//Attraction: outbound
	//robot[0].dx = -1;
	//robot[0].dy = 0;
	//robot[0].ang_r = atan2(robot[0].dy, robot[0].dx);

	//robot[1].dx = -0.1;
	//robot[1].dy = 0;
	//robot[1].ang_r = atan2(robot[1].dy, robot[1].dx);

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
