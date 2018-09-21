#include "stdafx.h"
#pragma warning(disable:4996)


void make_file(void){
	errno_t error;
	FILE *Initial_Log;
	FILE *result;
	char str[100];

	sprintf_s(str, 100, "result_%d.csv", gen);
	if (error = fopen_s(&result, str, "a+") != 0) {
		printf("%sファイルが開けません\n", str);
		return -1;
	}

	time_t now = time(NULL);
	struct tm *pnow = localtime(&now);

	fprintf(result, "%d, %d, %d, %d, %d, %d, %d, %d, %d, %1.2lf, %lf, %lf, %lf, %lf, %d, %d, %d, %d, %d:%d:%d\n", swarm, argos, draw, robots, foods, food_mass, food_dis, foodlimit, opposite, p_density, collision[swarm][0], collision[swarm][1], collision[swarm][2], P_p[swarm], Lay_down_a, Reinforce_a, step, Collision_total, pnow->tm_hour, pnow->tm_min, pnow->tm_sec);
	fclose(result);

	//Initial_log
	Initial_Log = fopen("Initial_log.csv", "w");
	fprintf(Initial_Log, "Robot数,robots,%d\n", robots);			//robots
	fprintf(Initial_Log, "Robotの質量,AGENT_mass,%d\n", AGENT_mass);		//AGENT_mass
	fprintf(Initial_Log, "Robotのスケール,scale_argos,%d\n", scale_argos);	//scale_argos
	fprintf(Initial_Log, "添加アルコール量,ADD_P,%d\n", ADD_P);			//Amount of pheromone added
	fprintf(Initial_Log, "Pull Timer,TMR_PULL,%d\n", TMR_PULL);			//TMR_PULL
	fprintf(Initial_Log, "SA Timer,TMR_SA,%d\n", TMR_SA);				//TMR_SA
	fprintf(Initial_Log, "Robotの出力,AGENT_F,%d\n", AGENT_F);				//Robot output
	fprintf(Initial_Log, "Robotの速度,AGENT_V,%d\n", AGENT_V);				//Robot speed
	fprintf(Initial_Log,"\n");
	fprintf(Initial_Log, "Foodの質量,food_mass,%d\n", food_mass);			//food_mass
	fprintf(Initial_Log, "Foodのスケール,Food_scale,%d\n", Food_scale);		//Food_scale
	fprintf(Initial_Log,"\n");
	fprintf(Initial_Log,"Fieldの横幅,WIDTH,%d\n", WIDTH);					//FieldWidth
	fprintf(Initial_Log,"Fieldの縦幅,HEIGHT,%d\n", HEIGHT);					//FieldHeight
}


void sys_make_dir_file(void){
	make_file();
}
