#include "stdafx.h"
#pragma warning(disable:4996)

void draw_text(void){
	int i;
	char str[256];

	sprintf(str, "%d", step / 10/*food[0].ang_d*/);

	glColor3d(0.0, 0.0, 0.0);
	glPushMatrix();
		glTranslated(0.0, -20.0, 0.0);
		glRotated(0.0, 0.0, 0.0, 1.0);
		glScalef(0.1, 0.1, 1.0);
		for(i = 0; str[i] != '\0' ; i++){
			glutStrokeCharacter(GLUT_STROKE_ROMAN,str[i]);
		}
	glPopMatrix();
}


void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Windowを塗りつぶす
	glLoadIdentity();
	
	gluLookAt(WIDTH, -WIDTH, WIDTH + view_z, WIDTH/2, HEIGHT/2, 0.0, 0.0, 0.0, 1.0);//視点の設定
	
	//Draw関数の呼び出し
	draw_field();			//Fieldを描画(光を当てない)
	draw_pheromone();		//Pheromoneを描画(光を当てない)
	draw_robot();			//Robotを描画
	draw_robotvector();		//Robotの進行方向の表示
	draw_robot_number();
	draw_food();			//Foodの描画
	draw_text();			//Step数の表示
	draw_nest1();			//Nest

	glutSwapBuffers();		//ダブルバッファ
}
