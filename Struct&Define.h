#ifndef STRUCTURE_AND_DEFINE
#define STRUCTURE_AND_DEFINE

//構造体の定義
#include "struct.h"

//定数の設定
#include "Def-Physics.h"

//グローバル変数
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


extern int step;		//ステップ数の表示
extern int t;
extern int t_1;
extern int view_z;		//視点のZ軸方向
extern int act_trace;
extern double robot_v;
extern double c_eva;	//蒸発係数
extern double dif;		//拡散係数
extern int dA_p;
extern int dF_p;
extern char dir_name[1000];
extern FILE *State_log;
extern FILE *result;


//Log
extern int Lay_down_a;					//Food_aの敷設回数
extern int Reinforce_a;					//Food_aの強化回数
extern int Lay_down_b;					//Food_bの敷設回数
extern int Reinforce_b;					//Food_bの強化回数
extern unsigned long Collision_total;	//衝突回数のカウント

//配列（実計算）
extern Robot robot[1000];									//Robot数分の配列の作成
extern Robot_mem robot_mem[1000];							//Robot数分の配列の作成
extern SA sa[100];
extern P_grid1 p_grid1[WIDTH][HEIGHT][2];					//Fieldをセルに分割する
extern P_grid2 p_grid2[WIDTH/GRID_SPAN][HEIGHT/GRID_SPAN];	//Fieldをセルに分割する
extern Food food[100];										//Foodの構造体

////配列（Log保存）
//extern Robot_Log robot_log[1000][TimeLimit];
extern Food_Log food_log[100][TimeLimit];
extern int state_log[TimeLimit][1000];


#endif
