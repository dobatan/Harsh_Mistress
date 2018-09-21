#include "stdafx.h"
#pragma warning(disable:4996)

void draw_robot(void){//Robotの描画
	//宣言
	int i;
	
	for(i = 0; i < robots; ++i){
		//色の設定
		if(robot[i].state == 1){
			glColor3d(1.0, 0.0, 0.0);//レッド
			if(robot[i].colli_robot == TRUE || robot[i].colli_wall == TRUE || robot[i].colli_food == TRUE)
				glColor3d(1.0, 1.0, 0.0);//イエロー
		}
		if(robot[i].state == 2){
			glColor3d(0.0, 1.0, 0.0);//グリーン
			if(robot[i].colli_robot == TRUE || robot[i].colli_wall == TRUE || robot[i].colli_food == TRUE)
				glColor3d(1.0, 1.0, 0.0);//イエロー
		}
		if(robot[i].state == 3){
			glColor3d(0.0, 0.0, 1.0);//ブルー
			if(robot[i].colli_robot == TRUE || robot[i].colli_wall == TRUE || robot[i].colli_food == TRUE)
				glColor3d(1.0, 1.0, 0.0);//イエロー
		}

		glPushMatrix();
			glTranslated(robot[i].x, robot[i].y, 4.0);	//並進
			glRotated(robot[i].ang_d, 0.0, 0.0, 1.0);	//回転
			glRotated(90.0, 1.0, 0.0, 0.0);				//Z軸を上に
			glutSolidTeapot(scale_argos);				//Teapotを描く
		glPopMatrix();
	}
}

void draw_robotvector(void){
	//宣言
	int i;

	//設定
	glDisable(GL_LIGHTING);

	//Fieldの描画
	glColor4d(0.0, 0.0, 0.0, 1.0);//これから描画するものの色を指定

	for (i = 0; i < robots; i++){
		glBegin(GL_LINES);
			glVertex3d(robot[i].x, robot[i].y, scale_argos * 2);	//x軸下辺
			glVertex3d(robot[i].x + 5 * 4*robot[i].dx, robot[i].y + 5 * 4*robot[i].dy, scale_argos * 2);
		glEnd();
	}
	glFlush();
}


void draw_robot_number(void)
{
	int i, j;
	char str[256];

	for (i = 0; i < robots; i++){
		sprintf(str, "%d", i);

		glColor3d(0.0, 0.0, 0.0);
		glPushMatrix();
			glTranslated(robot[i].x, robot[i].y, 10.0);
			glRotated(0.0, 0.0, 0.0, 1.0);
			glScalef(0.05, 0.05, 3.0);

			for (j = 0; str[j] != '\0'; j++)
				glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,str[j]);
		glPopMatrix();
	}
}