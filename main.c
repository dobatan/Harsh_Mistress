#include "stdafx.h"

//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

//parameter
int gen;
int argos;
int swarm;
int swarm_MAX;
int draw;
int robots;					//number of Robot
int foods;					//number of Food
int food_mass;					//Food mass
int food_dis;					//Food distance
double p_density;				//Pheromone density
int opposite;					//Food location
int foodlimit;
int idle_f = TRUE;
int foodcount;
double collision_rand = 0;
double P_p_rand = 0;
double scale_argos;				//Scale of ARGOS

double collision[9999999][3];
double P_p[9999999];

FILE *result;



//Nest position
int nest_x;
int nest_y;


//global value
int step;						//step counter
int t;
int t_1;
int view_z;
int act_trace;
double robot_v;
double c_eva;
double dif;
int dA_p;
int dF_p;
unsigned long Collision_total;
char dir_name[1000];			//Directory name
								//FILE *State_Log;
								//FILE *Initial_Log;
								//FILE *Food_log;
//FILE *Robot_log;
//FILE *Pheromone_log;

//Log
int Lay_down_a;
int Reinforce_a;
int Lay_down_b;
int Reinforce_b;


Robot robot[1000];
Robot_mem robot_mem[1000];
P_grid1 p_grid1[WIDTH][HEIGHT][2];
P_grid2 p_grid2[WIDTH / GRID_SPAN][HEIGHT / GRID_SPAN];
Food food[100];
SA sa[100];

Food_Log food_log[100][TimeLimit];
int state_log[TimeLimit][1000];


void idle(void) {
	//System
	sys_step_memo();
	sys_log_save();

	//Robot
	robot_perceptual_cues();
	robot_state_transition_rules();
	robot_state_behavior();
	robot_collision_dynamics();
	robot_collision_algorithm();
	robot_final_action();

	//Environment
	envi_other();				//position
	envi_pheromone();			//pheromone

	if (draw == TRUE)
		glutPostRedisplay();		//Redisplay
	step++;

	if (foodcount >= foodlimit || step >= TimeLimit) {
		idle_f = FALSE;
		sys_make_dir_file();

		if (draw == 1) {
			glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
			glutLeaveMainLoop();
		}
	}
}


void resize(int w, int h) {
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (double)w / (double)h, 1.0, 10000.0);

	glMatrixMode(GL_MODELVIEW);
}


void mouse(int button, int state, int x, int y) {
	switch (button) {
	case GLUT_LEFT_BUTTON:
		glutIdleFunc(idle);
		if (state == GLUT_LEFT_BUTTON)
			glutIdleFunc(0);
		break;

	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(0);
		break;
	default:
		break;
	}
}


void keyboard(unsigned char key, int x, int y) {
	glutIdleFunc(idle);

	switch (key) {
	case '\r':
		glutIdleFunc(idle);
		break;
	case ' ':
		glutIdleFunc(0);
		break;
	case 'q':
	case 'Q':
	case '\033':
		exit(0);
		break;

	default:
		break;
	}
}


void specialkeyboard(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_F1:
		dF_p = !dF_p;
		break;
	case GLUT_KEY_F2:
		dA_p = !dA_p;
		break;
	case GLUT_KEY_UP:
		view_z += 10;
		break;
	case GLUT_KEY_DOWN:
		view_z -= 10;
		break;

	default:
		break;
	}
}


void input_file(void)
{
	int i, j;

	FILE *param;
	FILE *swarminput;
	errno_t error;
	char str[100];
	char *p_fname = "param.csv";

	char param_name1[100];
	char param_name2[100];
	char param_name3[100];
	char param_name4[100];
	char param_name5[100];
	char param_name6[100];
	char param_name7[100];
	char param_name8[100];
	char param_name9[100];
	char param_name10[100];

	if (error = fopen_s(&param, p_fname, "r") != 0) {
		printf("%sファイルが開けません\n", p_fname);
		//return -1;
	}
	fscanf_s(param, "%[^,],%d", param_name1, _countof(param_name1), &argos);
	fscanf_s(param, "%[^,],%d", param_name2, _countof(param_name2), &swarm_MAX);
	fscanf_s(param, "%[^,],%d", param_name3, _countof(param_name3), &draw);
	fscanf_s(param, "%[^,],%d", param_name4, _countof(param_name4), &robots);
	fscanf_s(param, "%[^,],%d", param_name5, _countof(param_name5), &foods);
	fscanf_s(param, "%[^,],%d", param_name6, _countof(param_name6), &food_mass);
	fscanf_s(param, "%[^,],%d", param_name7, _countof(param_name7), &food_dis);
	fscanf_s(param, "%[^,],%d", param_name8, _countof(param_name8), &foodlimit);
	fscanf_s(param, "%[^,],%d", param_name9, _countof(param_name9), &opposite);
	fscanf_s(param, "%[^,],%lf", param_name10, _countof(param_name10), &p_density);
	fclose(param);

	for (i = 0; i < 16000; ++i) {
		P_p[i] = 0;
		for (j = 0; j < 2; ++j) {
			collision[i][j] = 0;
		}
	}
	sprintf_s(str, 100, "SwarmInput_%d.csv", gen);
	if (error = fopen_s(&swarminput, str, "r") != 0) {
		printf("%sファイルが開けません\n", str);
		return -1;
	}

	for (swarm = 0; swarm < swarm_MAX; swarm++) {
		fscanf_s(swarminput, "%lf,%lf,%lf,%lf", &collision[swarm][0], &collision[swarm][1], &collision[swarm][2], &P_p[swarm]);
	}
	fclose(swarminput);
}


void output_file(void){
	errno_t error;
	char str[100];

	sprintf_s(str, 100, "result_%d.csv", gen);
	if (error = fopen_s(&result, str, "w") != 0) {
		printf("%sファイルが開けません\n", str);
		return -1;
	}
}


int main(int argc, char *argv[]) {
	//gen = atoi(argv[1]);	//Generation
	gen = 1;	//Generation

	input_file();
	output_file();

	for (swarm = 0; swarm < swarm_MAX; swarm++) {
		time_t now = time(NULL);
		struct tm *pnow = localtime(&now);
		printf("Trial = %d, %d:%d:%d\n", swarm, pnow->tm_hour, pnow->tm_min, pnow->tm_sec);

		printf("%s: %d\n", "gen", gen);
		printf("%s: %d\n", "ARGOS", argos);
		printf("%s: %d\n", "swarms", swarm_MAX);
		printf("%s: %d\n", "draw", draw);
		printf("%s: %d\n", "Robots", robots);
		printf("%s: %d\n", "Foods", foods);
		printf("%s: %d\n", "Food_mass", food_mass);
		printf("%s: %d\n", "Food_dis", food_dis);
		printf("%s: %d\n", "Food_lim", foodlimit);
		printf("%s: %d\n", "opposite", opposite);
		printf("%s: %1.1f\n", "p_density", p_density);
		printf("%s: %1.1f\n", "S_1-B/S", collision[swarm][0]);
		printf("%s: %1.1f\n", "S_2-B/S", collision[swarm][1]);
		printf("%s: %1.1f\n", "S_3-B/S", collision[swarm][2]);
		printf("%s: %1.1f\n\n", "P_p", P_p[swarm]);

		fprintf(result, "TRIALS, ARGOS, DISPLAY, ROBOTS, FOODS, FOOD_MASS, FOOD_DIS, FOOD_LIM, OPPOSITE, P_DENSITY, S_1-B/S, S_2-B/S, S_3-B/S, P_p, laying_down, reinforce, finish_step, collision_total\n");
		fclose(result);

		if (draw == 1) {
			glutInitWindowPosition(0, 0);
			glutInitWindowSize(800, 600);
			glutInit(&argc, argv);
			glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
			glutCreateWindow("Harsh Mistress22");
			glutDisplayFunc(display);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glutReshapeFunc(resize);
			glutMouseFunc(mouse);
			glutKeyboardFunc(keyboard);
			glutSpecialFunc(specialkeyboard);
			init();
			while (idle_f == TRUE) {
				glutIdleFunc(idle);
				glutMainLoop();
			}
		}
		else {
			init();
			while (idle_f == TRUE) {
				idle();
			}
		}
	}
	exit(0);
}
