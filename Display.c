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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	gluLookAt(WIDTH, -WIDTH, WIDTH + view_z, WIDTH/2, HEIGHT/2, 0.0, 0.0, 0.0, 1.0);
	
	//Call Draw functions
	draw_field();			//Draw Field
	draw_pheromone();		//Draw Pheromone
	draw_robot();			//Draw Robot
	draw_robotvector();		//Draw Direction of Robot
	draw_robot_number();
	draw_food();			//Draw Food
	draw_text();			//Draw Number of Steps
	draw_nest1();			//Draw Nest

	glutSwapBuffers();
}
