#include "stdafx.h"


void robot_back(int i){
	int back_count = 10;

	if(robot[i].count_collision <= back_count){		
		if(robot[i].ang_OS < M_PI/2){
			robot[i].dx = - robot_v * cos(robot_mem[i].ang_r_mem2);
			robot[i].dy = - robot_v * sin(robot_mem[i].ang_r_mem2);
			robot[i].ang_r = robot_mem[i].ang_r_mem2;
		}
		else{
			robot[i].dx = robot_v * cos(robot_mem[i].ang_r_mem2);
			robot[i].dy = robot_v * sin(robot_mem[i].ang_r_mem2);
			robot[i].ang_r = robot_mem[i].ang_r_mem2;
		}
		robot[i].count_collision++;
	}

	if(robot[i].count_collision > back_count){
		robot[i].dx = robot_v * cos(robot_mem[i].ang_r_mem2);
		robot[i].dy = robot_v * sin(robot_mem[i].ang_r_mem2);

		robot[i].colli_robot = FALSE;
		robot[i].colli_food = FALSE;
		robot[i].colli_wall = FALSE;
		robot[i].count_collision = 0;

		//if(robot[i].state == 2)
		//	robot[i].count_lay_failure += 1;
	}
}


void robot_stop(int i){
	//Stop for 10 steps
	if(robot[i].count_collision <= 10){
		robot[i].dx = 0;
		robot[i].dy = 0;
		robot[i].count_collision++;
	}
	else if(robot[i].count_collision > 10){
		if(robot[i].dis_pot > scale_argos * 2){
			robot[i].dx = 0;
			robot[i].dy = 0;
			robot[i].colli_robot = FALSE;
			robot[i].colli_food = FALSE;
			robot[i].colli_wall = FALSE;
			robot[i].count_collision = 0;
		}
	}
}


void left_turn(int i){
	double wd = 10;				//Distance between wheels
	double z = 4.0 * M_PI / 180;		//Unit rotation angle

	double a = wd/2 * sin(z);
	double b = wd/2 * (1 - cos(z));
	double c = sqrt(pow(a, 2) + pow(b, 2));

	if(robot[i].count_p_trace <=60){
		robot[i].dx = c * cos(robot[i].ang_r + z);
		robot[i].dy = c * sin(robot[i].ang_r + z);
		robot[i].ang_r = atan2(robot[i].dy, robot[i].dx);
		robot[i].count_p_trace++;
	}
	if(robot[i].count_p_trace > 60){
		robot[i].flag_phe_l = FALSE;
		robot[i].flag_phe_b = FALSE;
		robot[i].count_p_trace = 0;
	}
}


void right_turn(int i){
	double wd = 10;				//Distance between wheels
	double z = 4.0 * M_PI / 180;		//Unit rotation angle

	double a = wd/2 * sin(z);
	double b = wd/2 * (1 - cos(z));
	double c = sqrt(pow(a, 2) + pow(b, 2));

	if(robot[i].count_p_trace <=60){
		robot[i].dx = c * cos(robot[i].ang_r - z);
		robot[i].dy = c * sin(robot[i].ang_r - z);
		robot[i].ang_r = atan2(robot[i].dy, robot[i].dx);
		robot[i].count_p_trace++;
	}
	if(robot[i].count_p_trace > 60){
		robot[i].flag_phe_r = FALSE;
		robot[i].flag_phe_b = FALSE;
		robot[i].count_p_trace = 0;
	}
}
