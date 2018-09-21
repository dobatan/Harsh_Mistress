#ifndef STRUCTURE_AND_DEFINE
#define STRUCTURE_AND_DEFINE

//Define struct
#include "struct.h"

//Setting constants
#include "Def-Physics.h"

//Global variables
extern int gen;
extern int trial;
extern int argos;
extern int swarm;
extern int draw;
extern int idle_f;
extern int robots;
extern int foods;
extern int food_mass;
extern int food_dis;
extern double p_density;
extern int opposite;
extern int foodlimit;
extern int foodcount;
extern double collision_rand;
extern double P_p_rand;
extern double P_p[9999999];
extern double collision[9999999][3];
extern double scale_argos;

extern int nest_x;
extern int nest_y;


extern int step;		//Display #steps
extern int t;
extern int t_1;
extern int view_z;		//Z-axis of viewpoint
extern int act_trace;
extern double robot_v;
extern double c_eva;	//Evaporation coef.
extern double dif;		//Diffucion coef.
extern int dA_p;
extern int dF_p;
extern char dir_name[1000];
extern FILE *State_log;
extern FILE *result;


//Log
extern int Lay_down_a;					//# Laying down for Food_a
extern int Reinforce_a;					//# Reinforcing for Food_a
extern int Lay_down_b;					//# Laying down for Food_b
extern int Reinforce_b;					//# Reinforcing for Food_b
extern unsigned long Collision_total;	//Counting #collision events

//配列（実計算）
extern Robot robot[1000];									//Creating array of the length = #Robots
extern Robot_mem robot_mem[1000];							//Creating array of the length = #Robots
extern SA sa[100];
extern P_grid1 p_grid1[WIDTH][HEIGHT][2];					//Splitting field into cells
extern P_grid2 p_grid2[WIDTH/GRID_SPAN][HEIGHT/GRID_SPAN];	//Splitting field into cells
extern Food food[100];										//Food Struct

////Array (save Log)
//extern Robot_Log robot_log[1000][TimeLimit];
extern Food_Log food_log[100][TimeLimit];
extern int state_log[TimeLimit][1000];


#endif
