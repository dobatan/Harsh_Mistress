//////////////////////////////////////////
// Setting Robot variables
//////////////////////////////////////////
typedef struct{
	//Internal State of Robot
	int state;

	//Coordinates, speed, power of Robot
	int	grid_x, grid_y;		//Position of Robot on the Grid
	double x, y;			//Position of Robot
	double dx, dy;			//Velocity of Robot
	double F;
	double Fn, Fnx, Fny;
	double Ft;
	
	//Robot angle
	double ang_d;			//Direction of Robot(Degree)
	double ang_r;			//Direction of Robot(radian)
	double ang_dr;
	double ang_go;

	//Robot and other angles
	double ang_NL;			//Direction of normal line when touching with food
	double ang_OA;			//Inverse of ang_NL, angle of robot from the viewpoint of COG of cylinder
	double ang_nest;		//Direction of Nest
	double ang_ij;			//Direction of collision counterpart (absolute)
	double ang_OS;			//Direction of collision counterpart (relative; against moving direction of self)
	double ang_col;

	//Marking perception events
	int p_touch_food;		//Marking Food perception
	int p_arrival_nest;		//Marking Nest arrival
	int p_phero_L;			//Marking pheromone detection
	int p_phero_R;			//Marking pheromone detection
	int p_sc_timer;			//Internal timer
	int p_lay_miss;			//Marking of failed pheromone-laying

	//Others
	int aSA_ID;			//ID of SA counterpart
	int Food_ID;			//ID of holding food
	int SA_root;			//ID of root robot
	int grip;			//Grabbing Food v Robot
	int grip_Robot;			//Grabbing Robot
	int grip_Food;			//Grabbing Food
	double dis_pot;			//Distance to other robot
	
	//Counter
	int random;			//Generating random numbers (0-99)
	int count_RW;			//RW counter
	int count_p_trace;		//Pheromone-following counter
	int count_collision;		//Collision-processing counter
	int count_lay_failure;		//Counter on stopping laying down
	int count_move;			//Counter for transport

	//Flag
	int flag_RW;			//Flagging RW
	int flag_phe_l, flag_phe_r, flag_phe_b;	//Flagging initiation/termination of behaviors

	//Determining collision
	int colli_robot;
	int colli_wall;
	int colli_food;

	//Pheromone sensors
	double L_sensor, R_sensor;		//Pheromone sensors

	//Flagging Pheromone reinforcement
	int f_laydown_a;				//Flagging laying down (S1→S2)
	int f_reinforce_a;				//Flagging reinforcing 1 (S1→S3)
	int f_laydown_b;				//Flagging laying down (S1→S2)
	int f_reinforce_b;				//Flagging reinforcing 1 (S1→S3)

	FILE *Log;
} Robot;


//////////////////////////////////////////
// Struct of Robot_mem
//////////////////////////////////////////
typedef struct {
	double dx_mem1, dy_mem1;		//Distance per step (=speed)
	double dx_mem2, dy_mem2;		//Distance per step (=speed)
	double ang_r_mem1, ang_r_mem2;		//Degree

	FILE *Log;
} Robot_mem;


//////////////////////////////////////////
// Struct of Food
//////////////////////////////////////////
typedef struct {
	double x, y;			//Coordinates
	double dx, dy;			//Distance per step (=speed)
	double ang_d;			//Angle (radian)
	double ang_r;			//Angle
	double dis;
	int state;

	double Food_Tx;			//Force x-direction (translation)
	double Food_Ty;			//Force y-direction (translation)
	double Food_T;			//Force of translation
	double Food_ang;		//Angle
	double Food_R;			//

	FILE *Log;
} Food;


//////////////////////////////////////////
// Struct of Nest
//////////////////////////////////////////
typedef struct {
	int nest_x;
	int nest_y;
	int nest_div;
	int nest_scale;
} Nest;


//////////////////////////////////////////
// Struct of Self-Assembly(SA) calc.
//////////////////////////////////////////
typedef struct
{
	double sa;
	double sa_x;
	double sa_y;
	double ang_r;
} SA;



//////////////////////////////////////////
// Log
//////////////////////////////////////////
//typedef struct{
//	int step;
//	double x;
//	double y;
//	double ang_r;
//	int state;
//} Robot_Log;


typedef struct{
	int step;
	double x;
	double y;
	double dis;
	int state;
} Food_Log;


typedef struct{//Setting grid variables of actual field
	double F_p;		//Pheromone on the floor
	double A_p;		//Pheromone in the air
	double P_dif;		//Pheromone coming from surroundings
} P_grid1;



typedef struct{//Setting grid variables of field for display
	double F_p;		//Pheromone on the floor
	double A_p;		//Pheromone in the air
} P_grid2;

