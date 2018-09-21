//Physical constants
#ifndef dt			//Unit time
#define dt			0.1
#endif
#ifndef G			//Gravitational acceleration
#define G			9.8
#endif
#ifndef M_PI		//Pi
#define M_PI		3.14159265358979323846
#endif
#ifndef GRID_SPAN	//Grid span
#define GRID_SPAN	2
#endif
#ifndef T			//Current time step
#define T			0
#endif
#ifndef T_1			//t-1 step
#define T_1			1
#endif
#ifndef COE_EVA		//Evaporation coefficient
#define COE_EVA		0.999
#endif
#ifndef COE_DIF		//Diffusion coefficient
#define COE_DIF		0.001
#endif
#ifndef Fri_o_f		//Friction coefficient between Food and Field
#define Fri_o_f		0.5
#endif
#ifndef TimeLimit	//Foraging duration
#define TimeLimit	12000
#endif


//Robot attributes
#ifndef AGENT_mass	//Robot mass [kg]
#define AGENT_mass	1.5		
#endif
#ifndef ADD_P		//Pheromone added
#define ADD_P		100	
#endif
#ifndef TMR_PULL	//[Obsolete] Waiting time for Pull [sec]
#define TMR_PULL	5
#endif
#ifndef TMR_SA		//[Obsolete] Waiting time for Self-Assembly [sec]
#define TMR_SA		100
#endif
#ifndef TMR_AT		//Time to attract [sec]
#define TMR_AT		100
#endif
#ifndef AGENT_F		//Unit power of a robot [N]
#define AGENT_F		0.75
#endif
#ifndef AGENT_V		//Unit speed of a robot [cm/sec]
#define AGENT_V		10
#endif
//#ifndef P_Det 	//Lower threshold of pheromone detection
//#define P_Det		2.274776
//#endif
#ifndef P_Det	  //Lower threshold of pheromone detection (remain 5 min)
#define P_Det		68.678207
#endif


//Environment attributes
#ifndef WIDTH   //Field width [cm]
#define WIDTH		900
#endif
#ifndef HEIGHT    //Field Length [cm]
#define HEIGHT		90
#endif


#ifndef G1_div    //n-sided polygon of nest shape
#define G1_div		20
#endif
#ifndef G1_scale	//Nest size [cm in radius]
#define G1_scale	60
#endif
#ifndef G2_div		//[Obsolete] n-sided polygon of food shape
#define G2_div		20
#endif
#ifndef G2_scale	//[Obsolete] Food size [cm in radius]
#define G2_scale	100
#endif


//Food attributes
#ifndef Food_scale	//Food size [cm in radius]
#define Food_scale	26
#endif
//#ifndef Food_scale	//Food size [cm in radius]
//#define Food_scale	16
//#endif
#ifndef Food_div	//n-sided polygon of food shape
#define Food_div	20
#endif
