#include "stdafx.h"
#pragma warning(disable:4996)

void draw_robot(void){//Drawing Robots
	//Declaration
	int i;
	
	for(i = 0; i < robots; ++i){
		//Setting colors
		if(robot[i].state == 1){
			glColor3d(1.0, 0.0, 0.0);//Red
			if(robot[i].colli_robot == TRUE || robot[i].colli_wall == TRUE || robot[i].colli_food == TRUE)
				glColor3d(1.0, 1.0, 0.0);//Yellow
		}
		if(robot[i].state == 2){
			glColor3d(0.0, 1.0, 0.0);//Green
			if(robot[i].colli_robot == TRUE || robot[i].colli_wall == TRUE || robot[i].colli_food == TRUE)
				glColor3d(1.0, 1.0, 0.0);//Yellow
		}
		if(robot[i].state == 3){
			glColor3d(0.0, 0.0, 1.0);//Blue
			if(robot[i].colli_robot == TRUE || robot[i].colli_wall == TRUE || robot[i].colli_food == TRUE)
				glColor3d(1.0, 1.0, 0.0);//Yellow
		}

		glPushMatrix();
			glTranslated(robot[i].x, robot[i].y, 4.0);	//Translation
			glRotated(robot[i].ang_d, 0.0, 0.0, 1.0);	//Rotation
			glRotated(90.0, 1.0, 0.0, 0.0);				//Z-axis up
			glutSolidTeapot(scale_argos);				//Drawing teapot
		glPopMatrix();
	}
}

void draw_robotvector(void){
	//Declaration
	int i;

	//Setting
	glDisable(GL_LIGHTING);

	//Drawing field
	glColor4d(0.0, 0.0, 0.0, 1.0);//Setting colors

	for (i = 0; i < robots; i++){
		glBegin(GL_LINES);
			glVertex3d(robot[i].x, robot[i].y, scale_argos * 2);	//x-axis lower side
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
