#include "stdafx.h"


void draw_field(void)
{
	//宣言
	int i;
	int x;
	int y;


	//設定
	glDisable(GL_LIGHTING);

	//Fieldの描画
	glColor3d(0.0, 0.0, 0.0);//これから描画するものの色を指定
	glBegin(GL_LINES);

	for (y = 0; y < HEIGHT / 10; y++){
		for (x = 0; x < WIDTH / 10; x++){
			//x軸方向
			glVertex3d(x*10,		y*10,			0);	//x軸下辺
			glVertex3d(x*10+10,		y*10,			0);
			glVertex3d(x*10,		y*10+10,		0);	//x軸上辺
			glVertex3d(x*10+10,		y*10+10,		0);
			//y軸方向			
			glVertex3d(x*10,		y*10,			0);	//y軸左辺
			glVertex3d(x*10,		y*10+10,		0);
			glVertex3d(x*10+10,		y*10,			0);	//y軸右辺
			glVertex3d(x*10+10,		y*10+10,		0);
		}
	}
	glEnd();

	//升目の描画
	glColor3d(0.5, 0.5, 0.5);//これから描画するものの色を指定
	for (y = 0; y < HEIGHT / 10; ++y){
		for (x = 0; x < WIDTH / 10; ++x){
			for (i = 0; i < WIDTH; ++i){
				if (y*5+x == 2*i){
					glBegin(GL_POLYGON);
						glVertex3d(x*10,		y*10,			0);
				 		glVertex3d(x*10+10,		y*10,			0);
						glVertex3d(x*10+10,		y*10+10,		0);
						glVertex3d(x*10,		y*10+10,		0);
					glEnd();
				}
			}
		}
	}
	glEnable(GL_LIGHTING);
}


void draw_nest1(void)//Nest
{
	int i;

	//描画
	glPushMatrix();
		glTranslated(nest_x, nest_y, -G1_scale + 1);	//並進
		glRotated(0.0, 0.0, 0.0, 1.0);												//回転
		glRotated(90.0, 1.0, 0.0, 0.0);												//Z軸を上に
		glScaled(G1_scale, G1_scale, G1_scale);

		glEnable(GL_NORMALIZE);

		if(opposite == 0){
			//でかいまま
			glColor4d(1.0, 0.0, 0.0, 0.5);//Objectの色の設定
			glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(0,1,0);
			for(i = 0; i <= G1_div; i++){
				glVertex3f((double)cos((double)i * 2.0 * M_PI / G1_div), 1.0, (double)sin((double)i * 2.0 * M_PI / G1_div));
			}
			glEnd();
		}

		else if(opposite == 1){
			//左下用
			glColor4d(1.0, 0.0, 0.0, 0.5);//Objectの色の設定
			glBegin(GL_POLYGON);
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(0,1,0);
				for(i = G1_div * 3/4; i < G1_div + 1; i++)
					glVertex3f((double)cos((double)i * 2.0 * M_PI / G1_div), 1.0, (double)sin((double)i * 2.0 * M_PI / G1_div));
			glEnd();
		}
		glDisable(GL_NORMALIZE);
	glPopMatrix();
}
