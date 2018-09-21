//物理定数
#ifndef dt			//単位時間
#define dt			0.1
#endif
#ifndef G			//重力加速度
#define G			9.8
#endif
#ifndef M_PI		//円周率
#define M_PI		3.14159265358979323846
#endif
#ifndef GRID_SPAN	//グリッド間隔
#define GRID_SPAN	2
#endif
#ifndef T			//現在のステップ
#define T			0
#endif
#ifndef T_1			//t-1ステップ
#define T_1			1
#endif
#ifndef COE_EVA		//蒸発係数
#define COE_EVA		0.999
#endif
#ifndef COE_DIF		//拡散係数
#define COE_DIF		0.001
#endif
#ifndef Fri_o_f		//FoodとField間の摩擦係数
#define Fri_o_f		0.5
#endif
#ifndef TimeLimit	//活動限界時間
#define TimeLimit	12000
#endif


//Robotの定数
#ifndef AGENT_mass	
#define AGENT_mass	1.5			//Robotの質量[kg]
#endif
#ifndef ADD_P
#define ADD_P		100			//添加フェロモン量
#endif
#ifndef TMR_PULL
#define TMR_PULL	5			//Pull待ち時間[sec]
#endif
#ifndef TMR_SA
#define TMR_SA		100			//SA待ち時間[sec]
#endif
#ifndef TMR_AT
#define TMR_AT		100			//誘引時間[sec]
#endif
#ifndef AGENT_F
#define AGENT_F		0.75		//Robotの単位出力[N]
#endif
#ifndef AGENT_V
#define AGENT_V		10			//Robotの単位速度(AGENT_V)[cm/sec]
#endif
//#ifndef P_Det
//#define P_Det		2.274776	//フェロモンの最低検出量
//#endif
#ifndef P_Det
#define P_Det		68.678207	//フェロモンの最低検出量
#endif


//Environmentの定数
#ifndef WIDTH
#define WIDTH		900//Fieldの幅[cm]
#endif
#ifndef HEIGHT
#define HEIGHT		90//Fieldの高さ(奥行き)[cm]
#endif


#ifndef G1_div
#define G1_div		20//Nestの分割数
#endif
#ifndef G1_scale	//Nestのサイズ
#define G1_scale	60//半径[cm]
#endif
#ifndef G2_div		//Foodの目的地の分割数
#define G2_div		20
#endif
#ifndef G2_scale	//Foodの目的地のサイズ
#define G2_scale	100//半径[cm]
#endif


//Foods
#ifndef Food_scale	//Foodスケール
#define Food_scale	26//半径[cm]
#endif
//#ifndef Food_scale	//Foodスケール
//#define Food_scale	16//半径[cm]
//#endif
#ifndef Food_div	//円の分割数
#define Food_div	20
#endif
