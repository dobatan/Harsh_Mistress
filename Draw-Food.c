#include "stdafx.h"
//#include <C:\Users\RYUSUKE\Documents\Research\Program\C\Project-Harsh_Mistress\Harsh_Mistress10\stdafx.h>


void draw_food(void){
	//Settings
	int i;
	int p;

	#pragma omp parallel for
	for (p = 0; p < foods; p++){
		//Draw
		glPushMatrix();
			glTranslated(food[p].x, food[p].y, Food_scale + 1);		//Translation
			glRotated(food[p].ang_d, 0.0, 0.0, 1.0);			//Rotation
			glRotated(90.0, 1.0, 0.0, 0.0);					//Z-axis up
			glScaled(Food_scale, Food_scale, Food_scale);			//Setting scale

			glEnable(GL_NORMALIZE);

			//Upper side of cylinder
			glColor4d(0.0, 0.0, 0.0, 0.5);//Setting object colors
			glBegin(GL_POLYGON);
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(0,1,0);
				#pragma omp parallel for
				for(i = 0; i <= Food_div / 4; i++)
					glVertex3f((double)cos((double)i * 2.0 * M_PI / Food_div), 1.0, (double)sin((double)i * 2.0 * M_PI / Food_div));
			glEnd();
			
			glBegin(GL_POLYGON);
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(0,1,0);
				#pragma omp parallel for
				for(i = Food_div / 2; i <= Food_div * 3 / 4; i++)
					glVertex3f((double)cos((double)i * 2.0 * M_PI / Food_div), 1.0, (double)sin((double)i * 2.0 * M_PI / Food_div));
			glEnd();

			glColor4d(0.7, 0.7, 0.0, 0.5);//Setting object colors
				glBegin(GL_POLYGON);
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(0,1,0);
				#pragma omp parallel for
				for(i = Food_div / 4; i <= Food_div / 2; i++)
					glVertex3f((double)cos((double)i * 2.0 * M_PI / Food_div), 1.0, (double)sin((double)i * 2.0 * M_PI / Food_div));
			glEnd();
			
			glBegin(GL_POLYGON);
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(0,1,0);
				#pragma omp parallel for
				for(i = Food_div * 3/4; i < Food_div + 1; i++)
					glVertex3f((double)cos((double)i * 2.0 * M_PI / Food_div), 1.0, (double)sin((double)i * 2.0 * M_PI / Food_div));
			glEnd();

			//Lower side of cylinder
			glColor4d(0.0, 0.0, 0.0, 0.5);//Setting object colors
				glBegin(GL_POLYGON);
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(0,-1,0);
				#pragma omp parallel for
				for(i = 0; i <= Food_div / 4; i++)
					glVertex3f((double)cos((double)i * 2.0 * M_PI / Food_div), -1.0, (double)sin((double)i * 2.0 * M_PI / Food_div));
			glEnd();
			
			glBegin(GL_POLYGON);
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(0,-1,0);
				#pragma omp parallel for
				for(i = Food_div / 2; i <= Food_div * 3 / 4; i++)
					glVertex3f((double)cos((double)i * 2.0 * M_PI / Food_div), -1.0, (double)sin((double)i * 2.0 * M_PI / Food_div));
			glEnd();

			glColor4d(0.7, 0.7, 0.0, 0.5);//Setting object colors
				glBegin(GL_POLYGON);
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(0,-1,0);
				#pragma omp parallel for
				for(i = Food_div / 4; i <= Food_div / 2; i++)
					glVertex3f((double)cos((double)i * 2.0 * M_PI / Food_div), -1.0, (double)sin((double)i * 2.0 * M_PI / Food_div));
			glEnd();
			
			glBegin(GL_POLYGON);
				glNormal3f(0.0, 1.0, 0.0);
				glVertex3f(0,-1,0);
				#pragma omp parallel for
				for(i = Food_div * 3/4; i < Food_div + 1; i++)
					glVertex3f((double)cos((double)i * 2.0 * M_PI / Food_div), -1.0, (double)sin((double)i * 2.0 * M_PI / Food_div));
			glEnd();
		  
			//Side of cylinder
			glColor4d(0.7, 0.7, 0.0, 0.5);//Setting object colors
			glBegin(GL_QUAD_STRIP);
			#pragma omp parallel for
			for (i = 0; i <= Food_div; i++){
				double co,si;
				co = cos(i * 2.0 * M_PI / Food_div);
				si = sin(i * 2.0 * M_PI / Food_div);
				glNormal3f(co, 0.0, si);
				glVertex3f(co, 1.0, si);
				glVertex3f(co,-1.0, si);
			}
			glEnd();
			glDisable(GL_NORMALIZE);
		glPopMatrix();	
	}
}
