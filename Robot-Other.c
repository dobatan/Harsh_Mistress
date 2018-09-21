#include "stdafx.h"


void robot_parallelism_check(int i, int p){
	//Flag indicating touch to food
	if(robot[i].state == 1){
		if(p == 0){
			robot[i].f_laydown_a = TRUE;
			robot[i].f_reinforce_a = FALSE;
		}
		if(p == 1){
			robot[i].f_laydown_b = TRUE;
			robot[i].f_reinforce_b = FALSE;
		}
	}
	if(robot[i].state == 3){
		if(p == 0){
			robot[i].f_laydown_a = FALSE;
			robot[i].f_reinforce_a = TRUE;
		}
		if(p == 1){
			robot[i].f_laydown_b = FALSE;
			robot[i].f_reinforce_b = TRUE;
		}
	}
}


void robot_parallelism_flagdown(int i){
	//Lay down
	if(robot[i].f_laydown_a == TRUE){
		Lay_down_a += 1;
		robot[i].f_laydown_a = FALSE;
		robot[i].f_reinforce_a = FALSE;
	}
	if(robot[i].f_laydown_b == TRUE){
		Lay_down_b += 1;
		robot[i].f_laydown_b = FALSE;
		robot[i].f_reinforce_b = FALSE;
	}

	//Reinforce
	if(robot[i].f_reinforce_a == TRUE){
		Reinforce_a += 1;
		robot[i].f_laydown_a = FALSE;
		robot[i].f_reinforce_a = FALSE;
	}
	if(robot[i].f_reinforce_b == TRUE){
		Reinforce_b += 1;
		robot[i].f_laydown_b = FALSE;
		robot[i].f_reinforce_b = FALSE;
	}
}


void robot_mem1_in(int i){//Memory for Pheromone trace
	robot_mem[i].dx_mem1 = robot[i].dx;
	robot_mem[i].dx_mem1 = robot[i].dy;
	robot_mem[i].ang_r_mem1 = robot[i].ang_r;
}

void robot_mem2_in(int i){//Memory for collision processing algorithm
	robot_mem[i].dx_mem2 = robot[i].dx;
	robot_mem[i].dx_mem2 = robot[i].dy;
	robot_mem[i].ang_r_mem2 = robot[i].ang_r;
}


void robot_mem1_out(int i){
	robot[i].dx = robot_mem[i].dx_mem1;
	robot[i].dy = robot_mem[i].dy_mem1;
	robot[i].ang_r = robot_mem[i].ang_r_mem1;	
}

void robot_mem2_out(int i){
	robot[i].dx = robot_mem[i].dx_mem2;
	robot[i].dy = robot_mem[i].dy_mem2;
	robot[i].ang_r = robot_mem[i].ang_r_mem2;	
}
