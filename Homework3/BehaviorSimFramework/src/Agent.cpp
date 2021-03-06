// Agent.cpp: implementation of the SIMAgent class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Behavior.h"
#include "Agent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//Construct static variables
//Their real values are set in static function SIMAgent::InitValues()
vector<SIMAgent*> SIMAgent::agents;
bool SIMAgent::debug = false;
float SIMAgent::radius = 20.0;
float SIMAgent::Mass = 1.0;
float SIMAgent::Inertia = 1.0;
float SIMAgent::MaxVelocity = 20.0;
float SIMAgent::MaxForce = 10.0;
float SIMAgent::MaxTorque = 40.0;
float SIMAgent::MaxAngVel = 10.0;
float SIMAgent::Kv0 = 1.0;
float SIMAgent::Kp1 = 1.0;
float SIMAgent::Kv1 = 1.0;
float SIMAgent::KArrival = 1.0;
float SIMAgent::KDeparture = 1.0;
float SIMAgent::KNoise = 1.0;
float SIMAgent::KWander = 1.0;
float SIMAgent::KAvoid = 1.0;
float SIMAgent::TAvoid = 1.0;
float SIMAgent::RNeighborhood = 1.0;
float SIMAgent::KSeparate = 1.0;
float SIMAgent::KAlign = 1.0;
float SIMAgent::KCohesion = 1.0;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
////////////////////////////////////////////////////////////////////// 
vec2 SIMAgent::WorldToLocal(vec2 &w)
{
	vec2 l;
	float s = sin(state[1]);
	float c = cos(state[1]);
	l[0] = c * w[0] + s * w[1];
	l[1] = -s * w[0] + c * w[1];
	return l;
}

vec2 SIMAgent::LocalToWorld(vec2 &l)
{
	vec2 w;
	float s = sin(state[1]);
	float c = cos(state[1]);
	w[0] = c * l[0] - s * l[1];
	w[1] = s * l[0] + c * l[1];
	return w;
}

void SIMAgent::SetVTheta(vec2 &V)
{
	vd = V.Length();
	if (vd < 0.0001) {
		thetad = 0.0;
	}
	else {
		if (abs(V[0]) < 0.0001) {
			if (V[1] > 0)
				thetad = M_PI / 2.0;
			else
				thetad = M_PI / -2.0;
		}
		else
			thetad = atan2(V[1], V[0]);
	}

	ClampAngle(thetad);
}

SIMAgent::SIMAgent()
{
}

SIMAgent::~SIMAgent()
{
}

void SIMAgent::Display()
{
	glPushMatrix();
	glTranslatef(GPos[0], rootHeight[frameNum], GPos[1]);
	if (showLeader && this == SIMAgent::agents[0]) {
		float red[] = { 1.0, 0.0, 0.0 };
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
		glPushMatrix();
		glTranslatef(0.0, 100.0, 0.0);
		glRotatef(90.0, 1.0, 0.0, 0.0);
		glutSolidCone(10.0, 20.0, 24, 24);
		glPopMatrix();
	}

	float specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, 50);

	if (SIMAgent::debug) {
		glutSolidSphere(10.0, 24, 24);
		glDisable(GL_LIGHTING);
		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glRotatef(-state[1] / M_PI * 180.0, 0.0, 1.0, 0.0);
		glLineWidth(3.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0); glVertex3f(12 + state[2], 0.0, 0.0);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glColor3f(0.0, 1.0, 0.0);
		glRotatef(-thetad / M_PI * 180.0, 0.0, 1.0, 0.0);
		glLineWidth(3.0);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0); glVertex3f(12 + vd, 0.0, 0.0);
		glEnd();
		glPopMatrix();
		glLineWidth(1.0);
		glEnable(GL_LIGHTING);
	}
	else {
		glRotatef(90.0f - state[1] * Rad2Deg, 0.0, 1.0, 0.0);
		//glutSolidSphere(6.0f, 12, 12);
		glCallList(AgentDisplay::listNames + frameNum);
	}
	glPopMatrix();
}

void SIMAgent::ClearAgents() {
	for (unsigned int i = 0; i < agents.size(); i++)
		delete SIMAgent::agents[i];
	SIMAgent::agents.clear();
}

SIMAgent::SIMAgent(float* color, CEnvironment* env) {
	memcpy(this->color, color, sizeof(float) * 3);
	dimState = 4;
	dimInput = 2;
	frameNum = rand() % totalFrames;
	this->env = env;
	float angle = float(rand() % 360) / 180.0 * M_PI;
	vWander[0] = cos(angle) * SIMAgent::KWander;
	vWander[1] = sin(angle) * SIMAgent::KWander;
	angle = float(rand() % 360) / 180.0 * M_PI;
	v0[0] = cos(angle) * SIMAgent::MaxVelocity / 2.0;
	v0[1] = sin(angle) * SIMAgent::MaxVelocity / 2.0;
	SIMAgent::agents.push_back(this);
}

void SIMAgent::SetInitState(float pos[], float angle)
{
	int i;
	GPos[0] = pos[0];
	GPos[1] = pos[1];
	for (i = 0; i < dimState; i++) {
		state[i] = 0.0;
	}
	for (i = 0; i < dimInput; i++)
		input[i] = 0.0;
	state[1] = angle;
}

void SIMAgent::Sense(int type)
{
	showLeader = (type == LEADER);
	goal = env->goal;
	switch (type) {
	case SEEK: Seek(); break;
	case FLEE: Flee(); break;
	case ARRIVAL: Arrival(); break;
	case DEPARTURE: Departure(); break;
	case WANDER: Wander(); break;
	case AVOID: Avoid(); break;
	case SEPARATION: Separation(); break;
	case ALIGNMENT: Alignment(); break;
	case COHESION: Cohesion(); break;
	case FLOCKING: Flocking(); break;
	case LEADER: Leader(); break;
	}
}

void SIMAgent::Act(float deltaT)
{
	int dframe;
	this->deltaT = deltaT;
	FindDeriv();
	UpdateState();
	if (abs(state[2]) < 0.001)
		dframe = 0;
	else {
		dframe = int(state[2] / SIMAgent::MaxVelocity * 2 + 1);
	}
	frameNum += dframe;
	if (frameNum >= totalFrames) {
		frameNum = frameNum - totalFrames;
	}
}

void SIMAgent::SetV0()
{
	v0 = env->goal - GPos;
	v0 = v0.Normalize() * SIMAgent::MaxVelocity / 2;
}

/*
Sets the intial Values
*/
void SIMAgent::InitValues()
{
	/*********************************************
	// TODO: Add code here
	Set initial value for control and behavior settings
	You need to find out appropriate values for:

	SIMAgent::Kv0, SIMAgent::Kp1, SIMAgent::Kv1, SIMAgent::KArrival, SIMAgent::KDeparture,
	SIMAgent::KNoise, SIMAgent::KWander, SIMAgent::KAvoid, SIMAgent::TAvoid, SIMAgent::RNeighborhood,
	SIMAgent::KSeparate, SIMAgent::KAlign, SIMAgent::KCohesion.
	*********************************************/
	Kv0 = 12.0;
	Kp1 = 150.0;
	Kv1 = 25.0;
	KArrival = 0.1;
	KDeparture = 7000.0;
	KNoise = 15.0;
	KWander = 3.0;
	KAvoid = 0.5;
	TAvoid = 10.0;
	RNeighborhood = 500.0;
	KSeparate = 900.0;
	KAlign = 15.0;
	KCohesion = 0.015;
}

void SIMAgent::Control()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	/*
	* You should apply the control rules given desired velocity vd and desired orientation thetad.
	* Velocity control: input[0] = f = m * Kv0 * (vd - v)
	* Heading control: input[1] = tau = I * ( -Kv1 * thetaDot - Kp1 * theta + Kp1 * thetad)
	* This function sets input[0] and input[1] appropriately after being called.
	*/

		Truncate(vd, -SIMAgent::MaxVelocity, SIMAgent::MaxVelocity);
		input[0] = SIMAgent::Mass * SIMAgent::Kv0 * (vd - state[2]);
		Truncate(input[0], -SIMAgent::MaxForce, SIMAgent::MaxForce);

		double dangle = AngleDiff(state[1], thetad);
		input[1] = SIMAgent::Inertia * (Kp1 * dangle - Kv1 * state[3]);
		Truncate(input[1], -SIMAgent::MaxTorque, SIMAgent::MaxTorque);
}



/*
*	Compute derivative vector given input and state vectors
*  This function sets derive vector to appropriate values after being called
*/
void SIMAgent::FindDeriv()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	deriv[2] = (input[0] / Mass); /*the force local body coordinates need to be divied by the mass*/
	deriv[3] = (input[1] / Inertia); /*torque in local body corrdinates divided by inertia is equal to angular velocity */
	deriv[0] = state[2]; /*velocity of the agent(s) using the local body coordinates*/
	deriv[1] = state[3]; /*the angular velocity of the agent among the world coordinates*/

}

void SIMAgent::UpdateState()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	/*
	*	Update the state vector given derivative vector
	*  Compute global position and store it in GPos
	*  Perform validation check to make sure all values are within MAX values
	*/
		for (int i = 0; i < dimState; i++) {
			state[i] += deriv[i] * deltaT;
		}
		state[0] = 0.0;

		ClampAngle(state[1]);
		Truncate(state[2], -SIMAgent::MaxVelocity, SIMAgent::MaxVelocity);

		vec2 GVelocity;
		GVelocity[0] = state[2] * cos(state[1]);
		GVelocity[1] = state[2] * sin(state[1]);
		GPos += GVelocity;

		Truncate(GPos[0], -1.0 * env->groundSize, env->groundSize);
		Truncate(GPos[1], -1.0 * env->groundSize, env->groundSize);
		
		Truncate(state[3], -SIMAgent::MaxAngVel, SIMAgent::MaxAngVel);
}


/*
*	Seek behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Seek()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	double thetad;
	tmp = goal - GPos; /*Vd = goal - position, global goal position minus agent global position--moves closer to target*/
	tmp.Normalize(); 
	thetad = atan2(tmp[1], tmp[0]); /*theta d is equal to arctan (Vdy, and Vdx */
	double vd = SIMAgent::MaxVelocity; /*vd = maxvelocity*/
	return vec2(cos(thetad)*vd, sin(thetad)*vd); /*cos thetad times vd, sin theta d tims vd*/
}

/*
*	Flee behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Flee()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	/*same as Seek except you  need to add 180 degree to the seek desired velocity angle theta d
	theta d = theta d + pi*/
	vec2 tmp;
	double thetad;
	tmp = goal - GPos; /*Vd = goal - position, global goal position minus agent global position--moves closer to target*/
	tmp.Normalize();	
	thetad = atan2(tmp[1], tmp[0]) + M_PI; /*theta d is equal to arctan (Vdy, and Vdx */ 
	float vd = SIMAgent::MaxVelocity; /*vd = maxvelocity*/
	return vec2(cos(thetad)*vd, sin(thetad)*vd); /*cos thetad times vd, sin theta d tims vd*/

}

/*
*	Arrival behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  Arrival setting is in SIMAgent::KArrival
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Arrival()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 Vn;
	Vn = goal - GPos; /*Vd = goal - position*/
	thetad = atan2(Vn[1], Vn[0]) + M_PI; /*theta d = arctan (vdy, vdx)*/

	vd = Vn.Length() *KArrival;
	return -vec2(cos(thetad)*vd, sin(thetad) * vd);
}

/*
*	Departure behavior
*  Global goal position is in goal
*  Agent's global position is in GPos
*  Departure setting is in KDeparture
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Departure()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/

	/* similar to arrival but departure needs to be in */
	vec2 Vn = goal - GPos; /*Vd = goal - position*/
	Vn.Normalize();
	thetad = atan2(Vn[1], Vn[0]) + M_PI; /*theta d = arctan (vdy, vdx)*/
	
	vd = Vn.Length() *KDeparture;
	return vec2(cos(thetad) *vd, sin(thetad) *vd);
}


/*
*	Wander behavior
*  VWander is in vWander
*  V0(nominal velocity) is in v0
*  Wander setting is in KWander
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Wander()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 Outer;
	vec2 Inner;
	double vd = SIMAgent::MaxVelocity;

	float largetheta = float(rand() % 360 - 180 / 180 *M_PI);
	float tinytheta = float(rand() % 360 - 180 / 180 * M_PI);

	Inner = vec2(cos(largetheta)* vd, sin(largetheta)*vd);
	Outer = vec2(cos(tinytheta)*vd, sin(tinytheta)*vd);

	vec2 VDis = 2.0 * (Outer + Inner);
	thetad = atan2(VDis[1], VDis[0]);
	return VDis;
}

/*
*	Avoid behavior
*  Obstacles are in env->obstacles
*  Number of obstacles is env->obstaclesNum
*  env->obstacles[i][0] and env->obstacles[i][1] are the global position of the ith obstacle
*  env->obstacles[i][2] is the radius of the ith obstacle
*  Agent bounding sphere radius is in SIMAgent::radius
*  Avoidance settings are in SIMAgent::TAvoid and SIMAgent::KAvoid
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Avoid()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 tmp;
	vec2 vd;
	vec2 vvoid1;
	vec2 vvoid2;


	for (int i = 0; i < env->obstaclesNum; i++)
	{
		vd[0] = env->obstacles[i][0];
		vd[1] = env->obstacles[i][1];

		float distfir = (vd - vvoid1).Length();
		float distsec = (vd - vvoid2).Length();

		if (distfir <= env->obstacles[i][2] || distsec <= env->obstacles[i][2])
		{
			thetad = thetad + TAvoid;
			double vd = SIMAgent::MaxVelocity;
			return vec2(cos(thetad)*vd, sin(thetad)*vd);
		}

		else
		{
			return tmp;
		}
	}
}

/*
*	Separation behavior
*  SIMAgent::agents[i] gives the pointer to the ith agent in the environment
*  Separation settings are in SIMAgent::RNeighborhood and SIMAgent::KSeperate
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Separation()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	/*Cisco bud help*/
	
	vec2 agentV = vec2(0.0, 0.0);
	double agentx = 0.0;
	double agenty = 0.0;
	vec2 agentvecpos;
	vec2 velseparation;

	for (int i = 0; i < agents.size(); i++)
	{
		agentx = GPos[0] - agents[i]->GPos[0];
		agenty = GPos[1] - agents[i]->GPos[1];
		agentvecpos = vec2(agentx, agenty);


		if (((agentx != 0.0) || (agenty != -0.0)) && (agentvecpos.Length() < RNeighborhood))
		{
			agentV[0] += (agentx / (agentvecpos.Length() * agentvecpos.Length()));
			agentV[1] += (agenty / (agentvecpos.Length() * agentvecpos.Length()));

		}

	}

	velseparation = KSeparate * agentV;

	thetad = atan2(velseparation[1], velseparation[0]);
	vd = velseparation.Length();
	return vec2 (cos(thetad) *vd, sin(thetad) *vd);
}

/*
*	Alignment behavior
*  SIMAgent::agents[i] gives the pointer to the ith agent in the environment
*  Alignment settings are in SIMAgent::RNeighborhood and SIMAgent::KAlign
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Alignment()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/
	vec2 agentv = Arrival();
	double agentx = 0.0;
	double agenty = 0.0;
	vec2 agentvecpos;
	vec2 velalignment;
	vec2 agentnorm;

	/*similar to above*/
	for (int i = 0; i < agents.size(); i++)
	{
		agentx = GPos[0] - agents[i]->GPos[0];
		agenty = GPos[1] - agents[i]->GPos[1];
		agentvecpos = vec2(agentx, agenty);

		if (((agentx != 0.0) || (agenty != -.0)) && (agentvecpos.Length() < RNeighborhood))
		{
			agentv[0] += cos(agents[i]->state[1]) * agents[i]->state[2];
			agentv[1] += sin(agents[i]->state[1]) * agents[i]->state[2];


			agentnorm += agentv.Normalize();
		}

		velalignment = KAlign * agentnorm;
		thetad = atan2(velalignment[1], velalignment[0]);

		vd = velalignment.Length();
		return vec2(cos(thetad) *vd, sin(thetad) *vd);
	}
}

/*
*	Cohesion behavior
*  SIMAgent::agents[i] gives the pointer to the ith agent in the environment
*  Cohesion settings are in SIMAgent::RNeighborhood and SIMAgent::KCohesion
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Cohesion()
		{
			/*********************************************
			// TODO: Add code here
			*********************************************/
			
	vec2 agentv = vec2(0.0, 0.0);
	double agentx = 0.0;
	double agenty = 0.0;
	vec2 agentvecpos;
	vec2 veccoh;

	for (int i = 0; i < agents.size(); i++)
	{
		agentx = GPos[0] - agents[i]->GPos[0];
		agenty = GPos[1] - agents[i]->GPos[1];
		agentvecpos = vec2(agentx, agenty);

		if (agentvecpos.Length() < RNeighborhood)
		{
			agentv[0] += GPos[0] - agents[i]->GPos[0];
			agentv[1] += GPos[1] - agents[i]->GPos[1];

		}
	}

	veccoh = KCohesion * (agentv / agents.size() - GPos);

	thetad = atan2(veccoh[1], veccoh[0]);
	vd = veccoh.Length();

	return vec2 (cos(thetad)*vd, sin (thetad) *vd);
		}
		
/*
*	Flocking behavior
*  Utilize the Separation, Cohesion and Alignment behaviors to determine the desired velocity vector
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/
vec2 SIMAgent::Flocking()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/

	vec2 vecflock;

	vecflock = KSeparate * Separation() + KCohesion * Cohesion() + KAlign * Alignment();
	thetad = atan2(vecflock[1], vecflock[0]);

	double vd = vecflock.Length();

	return vec2(cos(thetad) *vd, sin (thetad) *vd);
}

/*
*	Flocking behavior
*  Utilize the Separation, Arrival behaviors to determine the desired velocity vector
*  You need to find the leader, who is always the first agent in SIMAgent::agents
*  You need to compute the desired velocity and desired orientation
*  Store them into vd and thetad respectively
*  return a vec2 that represents the goal velocity with its direction being thetad and its norm being vd
*/

vec2 SIMAgent::Leader()
{
	/*********************************************
	// TODO: Add code here
	*********************************************/

	vec2 vecleader;

	vecleader = KSeparate * Separation() + KArrival * Arrival();
	thetad = atan2(vecleader[1], vecleader[0]);
	
	double vd = vecleader.Length();
	return vec2(cos(thetad) *vd, sin (thetad) * vd);
}