#include "stdafx.h"


void random_walk(int i){
	if(robot[i].count_RW == 0){
		robot[i].random = ((double)rand() / ((double)RAND_MAX + 1.0) * 99);

		if(robot[i].random >= 0 && robot[i].random <= 81)
			robot[i].flag_RW = 0;	//直進
		if(robot[i].random >= 82 && robot[i].random <= 87)
			robot[i].flag_RW = 1;	//左超信地旋回
		if(robot[i].random >= 88 && robot[i].random <= 93)
			robot[i].flag_RW = 2;	//右超信地旋回
		if(robot[i].random >= 94 && robot[i].random <= 99)
			robot[i].flag_RW = 3;	//後進
	}

	if(robot[i].count_RW <= 10){//10step同じ行動をする
		switch(robot[i].flag_RW){
			case 0:	//直進
				robot[i].dx = robot_v * cos(robot[i].ang_r);
				robot[i].dy = robot_v * sin(robot[i].ang_r);
				robot[i].ang_r = atan2(robot[i].dy, robot[i].dx);
				robot[i].ang_d = robot[i].ang_r * 180 / M_PI;
				robot[i].count_RW++;
				break;
			case 1:	//左超信地旋回
				robot[i].ang_r = robot[i].ang_r + M_PI / 20;
				robot[i].ang_d = robot[i].ang_r * 180 / M_PI;
				robot[i].dx = 0;
				robot[i].dy = 0;
				robot[i].count_RW++;
				break;
			case 2:	//右超信地旋回
				robot[i].ang_r = robot[i].ang_r - M_PI / 20;
				robot[i].ang_d = robot[i].ang_r * 180 / M_PI;
				robot[i].dx = 0;
				robot[i].dy = 0;
				robot[i].count_RW++;
				break;
			case 3:	//後進
				robot[i].dx = -robot_v * cos(robot[i].ang_r);
				robot[i].dy = -robot_v * sin(robot[i].ang_r);
				robot[i].ang_r = atan2(-robot[i].dy, -robot[i].dx);
				robot[i].ang_d = robot[i].ang_r * 180 / M_PI;
				robot[i].count_RW++;
				break;
		}
	}
	if(robot[i].count_RW > 10)
		robot[i].count_RW = 0;
}


void go2nest(int i){
	//速度ベクトル
	robot[i].ang_nest	=	atan2(nest_y - robot[i].y, nest_x - robot[i].x);
	robot[i].dx			=	robot_v * cos(robot[i].ang_nest);
	robot[i].dy			=	robot_v * sin(robot[i].ang_nest);
	//Robot方向
	robot[i].ang_r = atan2(robot[i].dy, robot[i].dx);
	robot[i].ang_d = robot[i].ang_r * 180 / M_PI;
}



void add_pheromone(int i){
	if(robot[i].colli_robot == FALSE && robot[i].colli_wall == FALSE && robot[i].colli_food == FALSE)
		p_grid1[robot[i].grid_x][robot[i].grid_y][t_1].F_p += ADD_P;
}


void follow_pheromone(int i){
	double nest_ang;

	robot[i].ang_r = atan2(robot[i].dy, robot[i].dx);
	robot[i].ang_nest = atan2(nest_y - robot[i].y, nest_x - robot[i].x);

	if(robot[i].ang_r < 0)
		robot[i].ang_r = 2 * M_PI + robot[i].ang_r;
	if(robot[i].ang_nest < 0)
		robot[i].ang_nest = 2 * M_PI + robot[i].ang_nest;

	nest_ang = robot[i].ang_nest - robot[i].ang_r;

	//flagとcounterの初期化
	if(robot[i].p_phero_L == TRUE && robot[i].p_phero_R == FALSE){
		robot[i].flag_phe_l = TRUE;
		robot[i].flag_phe_r = FALSE;
		robot[i].flag_phe_b = FALSE;
		robot[i].count_p_trace = 0;
		robot[i].p_sc_timer = 0;
	}
	if(robot[i].p_phero_L == FALSE && robot[i].p_phero_R == TRUE){
		robot[i].flag_phe_l = FALSE;
		robot[i].flag_phe_r = TRUE;
		robot[i].flag_phe_b = FALSE;
		robot[i].count_p_trace = 0;
		robot[i].p_sc_timer = 0;
	}
	if(robot[i].p_phero_L == TRUE && robot[i].p_phero_R == TRUE){
		robot[i].flag_phe_l = FALSE;
		robot[i].flag_phe_r = FALSE;
		robot[i].flag_phe_b = TRUE;
		robot[i].count_p_trace = 0;
		robot[i].p_sc_timer = 0;
	}


	if(robot[i].flag_phe_l == TRUE){
		robot_mem1_in(i);
		left_turn(i);
		//if(nest_ang > M_PI / 6 && nest_ang < M_PI * 5/6){		//Nest is left side
		if(nest_ang > 0 && nest_ang < M_PI * 5/6){		//Nest is left side
			robot_mem1_out(i);
			right_turn(i);
		}
		//if(nest_ang > M_PI * 7/6 && nest_ang < M_PI * 11/6){	//Nest is right side
		if(nest_ang > M_PI * 7/6 && nest_ang < M_PI * 2){	//Nest is right side
			robot_mem1_out(i);
			left_turn(i);
		}
	}

	if(robot[i].flag_phe_r == TRUE){
		robot_mem1_in(i);
		right_turn(i);
		if(nest_ang > 0 && nest_ang < M_PI * 5/6){		//Nest is left side
			robot_mem1_out(i);
			right_turn(i);
		}
		if(nest_ang > M_PI * 7/6 && nest_ang < M_PI * 2){	//Nest is right side
			robot_mem1_out(i);
			left_turn(i);
		}
	}

	if(robot[i].flag_phe_b == TRUE){
		//robot_mem1_in(i);
		//robot_back(i);
		
		if(nest_ang > 0 && nest_ang < M_PI * 5/6){		//Nest is left side
			//robot_mem1_out(i);
			right_turn(i);
		}
		if(nest_ang > M_PI * 7/6 && nest_ang < M_PI * 2){	//Nest is right side
			//robot_mem1_in(i);
			left_turn(i);
		}
	}
}
