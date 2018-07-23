#include "stdafx.h"


void collision_robot(int i, int j){
	if(i != j){
		robot[i].dis_pot = sqrt(pow(robot[j].x - robot[i].x, 2) + pow(robot[j].y - robot[i].y, 2));

		if(robot[i].dis_pot <= scale_argos * 2){
			Collision_total += 1;
			robot_mem2_in(i);

			robot[i].ang_ij = atan2((robot[j].y - robot[i].y), (robot[j].x - robot[i].x));
			robot[i].ang_OS = fabs(robot[i].ang_ij - robot[i].ang_r);

			robot[i].count_collision = 0;
			if(robot[i].state == 2){
				if(robot[i].ang_OS <= M_PI/2 && robot[i].ang_OS >= -M_PI/2)
					robot[i].colli_robot = TRUE;
				else
					robot[i].colli_robot = FALSE;
			}
			else
				robot[i].colli_robot = TRUE;
		}
	}
}

void collision_wall(int i){
	if(robot[i].x < scale_argos){
		robot_mem2_in(i);

		robot[i].x = scale_argos;
		robot[i].ang_OS = fabs(M_PI - fabs(robot[i].ang_r));

		robot[i].colli_wall = TRUE;
		robot[i].count_collision = 0;
	}

	else if(robot[i].x > WIDTH - scale_argos){
		robot_mem2_in(i);

		robot[i].x = WIDTH - scale_argos;
		robot[i].ang_OS = fabs(robot[i].ang_r);

		robot[i].colli_wall = TRUE;
		robot[i].count_collision = 0;
	}

	else if(robot[i].y < scale_argos){
		robot_mem2_in(i);

		robot[i].y = scale_argos;
		
		if(robot[i].ang_r >= 0)
			robot[i].ang_OS = fabs(M_PI/2 + robot[i].ang_r);
		else if(robot[i].ang_r < -M_PI/2)
			robot[i].ang_OS = -M_PI/2 + fabs(robot[i].ang_r);
		else if(robot[i].ang_r < 0 && robot[i].ang_r >= -M_PI/2)
			robot[i].ang_OS = M_PI/2 - fabs(robot[i].ang_r);
		
		robot[i].colli_wall = TRUE;
		robot[i].count_collision = 0;
	}

	else if(robot[i].y > HEIGHT - scale_argos){
		robot_mem2_in(i);

		robot[i].y = HEIGHT - scale_argos;
		
		if(robot[i].ang_r >= 0)
			robot[i].ang_OS = fabs(M_PI/2 - robot[i].ang_r);
		else if(robot[i].ang_r < -M_PI/2)
			robot[i].ang_OS = M_PI*1.5 - fabs(robot[i].ang_r);
		else if(robot[i].ang_r < 0 && robot[i].ang_r >= -M_PI/2)
			robot[i].ang_OS = M_PI/2 + fabs(robot[i].ang_r);

		robot[i].colli_wall = TRUE;
		robot[i].count_collision = 0;
	}
}


void collision_food(int i, int p){
	double dis_ac	= sqrt(pow(robot[i].x - food[p].x, 2) + pow(robot[i].y - food[p].y, 2));
	double dis_r	= Food_scale + scale_argos;
	
	if(dis_ac <= dis_r){
		robot[i].ang_NL = atan2(robot[i].y - food[p].y, robot[i].x - food[p].x);
		robot[i].dx = robot_v * cos(robot[i].ang_NL);
		robot[i].dy = robot_v * sin(robot[i].ang_NL);
	}
}

void robot_collision_dynamics(void){
	int i, j, p;

	for(i = 0; i < robots; i++){
		for(j = 0; j < robots; j++)
			collision_robot(i,j);
		for(p = 0; p < foods; p++)
			collision_food(i,p);
		collision_wall(i);
	}
}


void robot_collision_algorithm(void){
	int i;

	#pragma omp parallel for
	for(i = 0; i < robots; i++){
		if(robot[i].colli_wall == TRUE || robot[i].colli_food == TRUE)
			robot_back(i);
		if(robot[i].colli_robot == TRUE){
			switch(robot[i].state){
			case 1:
				if (robot[i].count_collision == 0) {
					collision_rand = (double)rand() / ((double)RAND_MAX + 1);
					if (collision_rand <= collision[swarm][0])
						robot_back(i);
					else
						robot_stop(i);
				}
				else {
					if (collision_rand <= collision[swarm][0])
						robot_back(i);
					else
						robot_stop(i);
				}
				break;
			case 2:
				if (robot[i].count_collision == 0) {
					collision_rand = (double)rand() / ((double)RAND_MAX + 1);
					if (collision_rand <= collision[swarm][1])
						robot_back(i);
					else
						robot_stop(i);
				}
				else {
					if (collision_rand <= collision[swarm][1])
						robot_back(i);
					else
						robot_stop(i);
				}
				break;
			case 3:
				if (robot[i].count_collision == 0) {
					collision_rand = (double)rand() / ((double)RAND_MAX + 1);
					if (collision_rand <= collision[swarm][2])
						robot_back(i);
					else
						robot_stop(i);
				}
				else {
					if (collision_rand <= collision[swarm][2])
						robot_back(i);
					else
						robot_stop(i);
				}
				break;
			}
		}
	}
}