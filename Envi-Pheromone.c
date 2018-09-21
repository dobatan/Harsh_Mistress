#include "stdafx.h"


void evaporation(void){
	//宣言
	int i, j;
	//double eva;		//蒸発フェロモン量
	//double P_dif;

	#pragma omp parallel for
	for (i = 0; i < WIDTH; ++i){
		#pragma omp parallel for
		for (j = 0; j < HEIGHT; ++j){
			//c = 1;
			//P_dif = 0;

			//蒸発
			p_grid1[i][j][t].F_p = c_eva * p_grid1[i][j][t_1].F_p;
			//eva = p_grid1[i][j][t_1].F_p - p_grid1[i][j][t].F_p;

			////拡散
			//if(i > 0){
			//	P_dif += p_grid1[i-1][j][t_1].A_p;
			//	c++;
			//}
			//if(i < WIDTH - 1){
			//	P_dif += p_grid1[i+1][j][t_1].A_p;
			//	c++;
			//}
			//if(j > 0){
			//	P_dif += p_grid1[i][j-1][t_1].A_p;
			//	c++;
			//}
			//if(j < HEIGHT - 1){
			//	P_dif += p_grid1[i][j+1][t_1].A_p;
			//	c++;
			//}

			//p_grid1[i][j][t].A_p = p_grid1[i][j][t_1].A_p + dif * (P_dif - c * p_grid1[i][j][t_1].A_p) + eva;

			//if(p_grid1[i][j][t].A_p < 0)
			//	p_grid1[i][j][t].A_p = 0;
		}
	}
}


void pheromone_detector(void){
	int i;
	int S_L_x, S_L_y;	//センサー（左）のあるグリッド
	int S_R_x, S_R_y;	//センサー（右）のあるグリッド
	
	#pragma omp parallel for
	for (i = 0; i < robots; ++i){
		//センサーの位置決め
		S_L_x = (int)(robot[i].x + (scale_argos / 2) * cos(robot[i].ang_r + M_PI / 6));
		S_L_y = (int)(robot[i].y + (scale_argos / 2) * sin(robot[i].ang_r + M_PI / 6));
		S_R_x = (int)(robot[i].x + (scale_argos / 2) * cos(robot[i].ang_r - M_PI / 6));
		S_R_y = (int)(robot[i].y + (scale_argos / 2) * sin(robot[i].ang_r - M_PI / 6));

		//各センサーの入力
		//robot[i].L_sensor = p_grid1[S_L_x][S_L_y][t].A_p;
		//robot[i].R_sensor = p_grid1[S_R_x][S_R_y][t].A_p;
		robot[i].L_sensor = p_grid1[S_L_x][S_L_y][t].F_p;
		robot[i].R_sensor = p_grid1[S_R_x][S_R_y][t].F_p;
	}
}


void envi_pheromone(void){//フェロモンの計算
	evaporation();
	pheromone_detector();
}
