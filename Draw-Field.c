#include "stdafx.h"


void draw_field(void){
	int i;
	int x;
	int y;

	glDisable(GL_LIGHTING);

	//Draw Field
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_LINES);

	for (y = 0; y < HEIGHT / 10; y++){
		for (x = 0; x < WIDTH / 10; x++){
			//x axis
			glVertex3d(x*10,	y*10,		0);
			glVertex3d(x*10+10,	y*10,		0);
			glVertex3d(x*10,	y*10+10,	0);
			glVertex3d(x*10+10,	y*10+10,	0);
			//y axis			
			glVertex3d(x*10,	y*10,		0);
			glVertex3d(x*10,	y*10+10,	0);
			glVertex3d(x*10+10,	y*10,		0);
			glVertex3d(x*10+10,	y*10+10,	0);
		}
	}
	glEnd();

	//Draw Grids
	glColor3d(0.5, 0.5, 0.5);
	for (y = 0; y < HEIGHT / 10; ++y){
		for (x = 0; x < WIDTH / 10; ++x){
			for (i = 0; i < WIDTH; ++i){
				if (y*5+x == 2*i){
					glBegin(GL_POLYGON);
						glVertex3d(x*10,	y*10,		0);
				 		glVertex3d(x*10+10,	y*10,		0);
						glVertex3d(x*10+10,	y*10+10,	0);
						glVertex3d(x*10,	y*10+10,	0);
					glEnd();
				}
			}
		}
	}
	glEnable(GL_LIGHTING);
}


void draw_nest1(void){
	int i;

	//Draw Nest
	glPushMatrix();
		glTranslated(nest_x, nest_y, -G1_scale + 1);
		glRotated(0.0, 0.0, 0.0, 1.0);
		glRotated(90.0, 1.0, 0.0, 0.0);
		glScaled(G1_scale, G1_scale, G1_scale);

		glEnable(GL_NORMALIZE);

		if(opposite == 0){
			glColor4d(1.0, 0.0, 0.0, 0.5);
			glBegin(GL_POLYGON);
			glNormal3f(0.0, 1.0, 0.0);
			glVertex3f(0,1,0);
			for(i = 0; i <= G1_div; i++){
				glVertex3f((double)cos((double)i * 2.0 * M_PI / G1_div), 1.0, (double)sin((double)i * 2.0 * M_PI / G1_div));
			}
			glEnd();
		}

		else if(opposite == 1){
			glColor4d(1.0, 0.0, 0.0, 0.5);
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
