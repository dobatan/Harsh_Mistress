#include "stdafx.h"


void init_argos(void){
	if(argos == FALSE)
		scale_argos = 11.5;
	else if(argos == TRUE)
		scale_argos = 7.5;
}


void init_robot(void){
	//宣言
	int i;

	robot_v = AGENT_V * dt;

	srand((unsigned)time(NULL));

	//Robotの初期化
	//#pragma omp parallel for
	for(i = 0; i < robots; ++i)	{
		//座標
		robot[i].x			=	rand() / (RAND_MAX + 1.0) * WIDTH;
		robot[i].y			=	rand() / (RAND_MAX + 1.0) * HEIGHT;
//		robot[i].x			=	0;
//		robot[i].y			=	HEIGHT / 2;
		robot[i].dx			=	0;
		robot[i].dy			=	0;
		//角度
		robot[i].ang_r		=	rand() / (RAND_MAX + 1.0) * 2 * M_PI;
		robot[i].ang_d		=	0;
		robot[i].ang_NL		=	0;
		robot[i].ang_OA		=	0;
		//その他
		robot[i].state		=	1;
		robot[i].aSA_ID		=	9999;
		robot[i].Food_ID	=	9999;
		robot[i].SA_root	=	9999;

		robot[i].flag_phe_l = FALSE;
		robot[i].flag_phe_r = FALSE;
		robot[i].flag_phe_b = FALSE;
		robot[i].count_p_trace = 0;
		robot[i].count_collision = 0;
	}
}


void init_food(void){
	int p;

	for(p = 0; p < foods; p++){
		food[p].dx		=	0;
		food[p].dy		=	0;
		food[p].ang_d	=	0;
		food[p].ang_r	=	0;
		food[p].dis		=	0;
		food[p].state	=	0;
	}
	if(opposite == 0){
		food[0].x		=	WIDTH - Food_scale;
		food[0].y		=	HEIGHT/2;
	}
	else if(opposite == 1){
		food[0].x		=	WIDTH - Food_scale;
		food[0].y		=	HEIGHT - Food_scale;
	}
}


void init_nest(void){
	if(opposite == 0){
		nest_x		=	0;
		nest_y		=	HEIGHT/2;
	}
	else if(opposite == 1){
		nest_x		=	0;
		nest_y		=	0;
	}
}


void init_pheromone(void){
	//宣言
	int i;
	int j;
	
	dF_p = FALSE;
	dA_p = FALSE;

	//フェロモンの初期化
	for(i = 0; i < WIDTH; ++i){	
		for(j = 0; j < HEIGHT; ++j){
			p_grid1[i][j][T].F_p = 0;
			p_grid1[i][j][T].A_p = 0;
			p_grid1[i][j][T_1].F_p = 0;
			p_grid1[i][j][T_1].A_p = 0;
		}
	}

	//フェロモンの初期化	
	for(i = 0; i < WIDTH / GRID_SPAN; ++i){
		for(j = 0; j < GRID_SPAN; ++j){
			p_grid2[i][j].F_p = 0;
			p_grid2[i][j].A_p = 0;
		}
	}
}


void init_eva_dif(void){
	double eva;

	//蒸発係数の決定
	eva		= -0.0443 * pow(p_density, 2) + 0.0039 * p_density + 0.993;
	c_eva	= 1 - ((1 - eva) / (10 / dt));	//実験は10秒単位
	
	//拡散係数の決定
	dif		= (p_density * COE_DIF) / 0.4;
}


void init_setting(void){
	//光と反射の初期化
	GLfloat light_position0[] = {0.0,	0.0,	500.0,	0.0};//光源位置（１）
	GLfloat light_position1[] = {WIDTH, HEIGHT,	500.0,	0.0};//光源位置（２）

	//Windowを塗りつぶす時の色の指定
	glClearColor(1.0, 1.0, 1.0, 0.0);

	//初期化
	step = 0;		//ステップの初期化
	
	//描画
	if(WIDTH == 180)
		view_z = 300;
	if(WIDTH == 360)
		view_z = 500;
	if(WIDTH == 540)
		view_z = 700;
	if(WIDTH == 720)
		view_z = 900;
	if(WIDTH == 900)
		view_z = 1200;

	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);

	//光
	glEnable(GL_LIGHTING);						//光を扱えるようにする
	glEnable(GL_LIGHT0);						//ライト0を有効にする
	glEnable(GL_LIGHT1);						//ライト1を有効にする
	glEnable(GL_COLOR_MATERIAL);				//材質パラメータを現在のカラーに追従
	
	//隠面処理
	glEnable(GL_DEPTH_TEST);					//デプステストを有効にする
	glDepthFunc(GL_LEQUAL);
	
	//混合処理
	glEnable(GL_BLEND);							//混合処理
		
	//法線の算出
	glEnable(GL_NORMALIZE);						//法線の正規化
}


void init_log(void){
	int i, j, p;
	
	//Robot-Logの初期化
	//#pragma omp parallel for
	//for(i = 0; i < robots; i++){
	//	#pragma omp parallel for
	//	for(j = 0; j < TimeLimit; j++){
	//		//座標
	//		robot_log[i][j].step	= 0;
	//		robot_log[i][j].x		= 0;
	//		robot_log[i][j].y		= 0;
	//		robot_log[i][j].ang_r	= 0;
	//		robot_log[i][j].state	= 0;
	//	}
	//}

	//Food-Logの初期化
	for(p = 0; p < foods; p++){
		for(j = 0; j < TimeLimit; j++){
			//座標
			food_log[p][j].step		= 0;
			food_log[p][j].x		= 0;
			food_log[p][j].y		= 0;
			food_log[p][j].dis		= 0;
			food_log[p][j].state	= 0;
		}
	}
}


void init(void){
	idle_f = TRUE;
	foodcount = 0;
	Lay_down_a = 0;					//敷設回数
	Reinforce_a = 0;				//強化回数
	Lay_down_b = 0;					//敷設回数
	Reinforce_b = 0;				//強化回数
	Collision_total = 0;			//衝突回数の初期化

	srand((unsigned)time(NULL));
	init_argos();
	init_robot();
	init_food();
	init_nest();
	init_pheromone();
	init_eva_dif();
	init_log();
	init_setting();
}