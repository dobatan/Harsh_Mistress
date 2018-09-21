//Robot
void robot_perceptual_cues(void);		//Perception labeling of Robot
void robot_state_transition_rules(void);	//State transition rule
void robot_state_behavior(void);		//Dynamics of robots
void robot_collision_dynamics(void);		//calculating robot collision
void robot_collision_algorithm(void);		//Collision algorithm
void robot_final_action(void);

//Behavior
void random_walk(int i);
void go2nest(int i);
void add_pheromone(int i);
void follow_pheromone(int i);
//void eccentric_rotation(void);

//Action
void robot_back(int i);
void robot_stop(int i);
void left_turn(int i);
void right_turn(int i);


//その他の処理
void robot_parallelism_check(int i, int p);
void robot_parallelism_flagdown(int i);


//Environment
void envi_pheromone(void);				//Calculating pheromone
void envi_other(void);					//Calculating current location (cell) of robots


//Initial
void init(void);

//Mem
void robot_mem1_in(int i);
void robot_mem1_out(int i);
void robot_mem2_in(int i);
void robot_mem2_out(int i);

//Display
void display(void);
	void draw_robot(void);
	void draw_robotvector(void);
	void draw_robot_number(void);
	void draw_food(void);
	void draw_field(void);
	void draw_nest1(void);
	//void draw_nest2(void);
	void draw_pheromone(void);

//System
void sys_log_save(void);
void sys_step_memo(void);
void sys_make_dir_file(void);
