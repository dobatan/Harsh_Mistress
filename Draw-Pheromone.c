#include "stdafx.h"



void draw_pheromone(void)
{
	//宣言
	int i, j, k, l;


	//Pheromoneの可視化計算
	for (i = 0; i < WIDTH / GRID_SPAN; i++){
		for (j = 0; j < HEIGHT / GRID_SPAN; j++){
			p_grid2[i][j].F_p = 0;
			p_grid2[i][j].A_p = 0;
			for (k = 0; k < GRID_SPAN; k++){
				for (l = 0; l < GRID_SPAN; l++){
					p_grid2[i][j].F_p	+=	p_grid1[GRID_SPAN*i+k][GRID_SPAN*j+l][t].F_p;
					p_grid2[i][j].A_p	+=	p_grid1[GRID_SPAN*i+k][GRID_SPAN*j+l][t].A_p;
				}
			}
		}
	}
	
	glDisable(GL_LIGHTING);

	//地表のPheromone
	if(dF_p == TRUE){
		glColor3d(1.0, 0.0, 0.0);//フェロモンの色の設定
		//F_pの描画
		glBegin(GL_LINES);
		for (i = 0; i < WIDTH / GRID_SPAN - 1; ++i){//x軸方向の線
			for (j = 0; j < HEIGHT / GRID_SPAN; ++j){
				glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i][j].F_p / 50);
				glVertex3d(GRID_SPAN*(i+1) + GRID_SPAN/2,	GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i+1][j].F_p / 50);
			}
		}
		glEnd();

		glBegin(GL_LINES);
		for (j = 0; j < HEIGHT / GRID_SPAN - 1; ++j){//y軸方向の線
			for (i = 0; i < WIDTH / GRID_SPAN; ++i){
				glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i][j].F_p / 50);
				glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*(j+1) + GRID_SPAN/2,	p_grid2[i][j+1].F_p / 50);
			}
		}
		glEnd();
	}
	
	////大気中のPheromone
	//if(dA_p == TRUE){
	//	glColor3d(1.0, 0.0, 0.0);//フェロモンの色の設定
	//	//A_pの描画
	//	glBegin(GL_LINES);
	//	for(i = 0; i < WIDTH / GRID_SPAN - 1; ++i){//x軸方向の線
	//		for(j = 0; j < HEIGHT / GRID_SPAN; ++j){
	//			glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i][j].A_p / 2);
	//			glVertex3d(GRID_SPAN*(i+1) + GRID_SPAN/2,	GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i+1][j].A_p / 2);
	//		}
	//	}
	//	glEnd();

	//	glBegin(GL_LINES);
	//	for(j = 0; j < HEIGHT / GRID_SPAN - 1; ++j){//y軸方向の線
	//		for(i = 0; i < WIDTH / GRID_SPAN; ++i){
	//			glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*j + GRID_SPAN/2,		p_grid2[i][j].A_p / 2);
	//			glVertex3d(GRID_SPAN*i + GRID_SPAN/2,		GRID_SPAN*(j+1) + GRID_SPAN/2,	p_grid2[i][j+1].A_p / 2);
	//		}
	//	}
	//	glEnd();
	//}

	glEnable(GL_LIGHTING);
}
