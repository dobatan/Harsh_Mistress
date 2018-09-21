//////////////////////////////////////////
//Robotの変数の設定
//////////////////////////////////////////
typedef struct{
	//Internal State of Robot
	int state;

	//Robotの座標・速度・力
	int	grid_x, grid_y;		//Position of Robot on the Grid
	double x, y;			//Position of Robot
	double dx, dy;			//Velocity of Robot
	double F;
	double Fn, Fnx, Fny;
	double Ft;
	
	//Robotの角度
	double ang_d;			//Direction of Robot(Degree)
	double ang_r;			//Direction of Robot(radian)
	double ang_dr;
	double ang_go;

	//Robotと他の角度
	double ang_NL;			//Foodと接触したときの法線方向
	double ang_OA;			//ang_NLの逆、円柱の重心から見たRobotの角度
	double ang_nest;		//Nestの方向
	double ang_ij;			//接触した個体の方向
	double ang_OS;			//衝突した客体の方向（Robotの進行方向に対して）
	double ang_col;

	//知覚標識
	int p_touch_food;		//Food接触知覚標識
	int p_arrival_nest;		//Nest到着知覚標識
	int p_phero_L;			//フェロモン知覚標識
	int p_phero_R;			//フェロモン知覚標識
	int p_sc_timer;			//内部タイマー
	int p_lay_miss;			//敷設失敗の知覚標識

	//その他
	int aSA_ID;				//SAしている相手のID
	int Food_ID;			//把持しているFoodのID
	int SA_root;			//Root robotのID
	int grip;				//Food∨Robotを掴んでいる
	int grip_Robot;			//Robotを掴んでいる
	int grip_Food;			//Foodを掴んでいる
	double dis_pot;			//他個体との距離
	
	//Counter
	int random;								//乱数生成（0－99）
	int count_RW;							//RWカウンタ
	int count_p_trace;						//フェロモン追従カウンタ
	int count_collision;					//衝突処理カウンタ
	int count_lay_failure;					//敷設停止カウンタ
	int count_move;							//運搬カウンタ

	//Flag
	int flag_RW;							//RWのフラグ
	int flag_phe_l, flag_phe_r, flag_phe_b;	//行動開始・停止フラグ

	//衝突判定
	int colli_robot;
	int colli_wall;
	int colli_food;

	//フェロモンセンサー
	double L_sensor, R_sensor;		//フェロモンセンサー

	//Pheromone強化フラグ
	int f_laydown_a;				//敷設フラグ(S1→S2)
	int f_reinforce_a;				//強化フラグ1(S1→S3)
	int f_laydown_b;				//敷設フラグ(S1→S2)
	int f_reinforce_b;				//強化フラグ1(S1→S3)

	FILE *Log;
} Robot;


//////////////////////////////////////////
//Robot_memの構造体
//////////////////////////////////////////
typedef struct {
	double dx_mem1, dy_mem1;		//1ステップで動く距離（速度）
	double dx_mem2, dy_mem2;		//1ステップで動く距離（速度）
	double ang_r_mem1, ang_r_mem2;	//角度（degree）

	FILE *Log;
} Robot_mem;


//////////////////////////////////////////
//Foodの構造体
//////////////////////////////////////////
typedef struct {
	double x, y;			//座標
	double dx, dy;			//1ステップで動く距離（速度）
	double ang_d;			//角度（radian）
	double ang_r;			//角度（degree）
	double dis;
	int state;

	double Food_Tx;			//X軸方向の力（並進）
	double Food_Ty;			//Y軸方向の力（並進）
	double Food_T;			//並進力
	double Food_ang;		//並進の角度
	double Food_R;			//

	FILE *Log;
} Food;


//////////////////////////////////////////
//Nestの構造体
//////////////////////////////////////////
typedef struct {
	int nest_x;
	int nest_y;
	int nest_div;
	int nest_scale;
} Nest;


//////////////////////////////////////////
//SA計算の構造体
//////////////////////////////////////////
typedef struct
{
	double sa;
	double sa_x;
	double sa_y;
	double ang_r;
} SA;



//////////////////////////////////////////
//Log
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


typedef struct{//実際のFieldのGridの変数の設定
	double F_p;		//地上のフェロモン
	double A_p;		//大気中のフェロモン
	double P_dif;	//周囲から拡散してくるフェロモン
} P_grid1;



typedef struct{//Display用のFieldのGridの変数の設定
	double F_p;		//地上のフェロモン
	double A_p;		//大気中のフェロモン
} P_grid2;

