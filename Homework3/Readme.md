# Homework 3 : Agent based Simulation Assignment 

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #3. 

The assignment is due: **Monday, April  24 at 11:59PM (EST)**

### Part 1: Behaviors

The goal of this assignment is to enable the steering behavioral animation of agents.

We represent an agent as a two-dimensional disk with mass (**m**) and moment-of-inertia (**I**) that is capable of generating a force **F** along body x-axis with a torque about the z-axis. For this assignment assume that the agent only translates in the world x-y plane and rotates about the body z-axis.

![](images/behavior.png?raw=true)

**(a) - 10 points** :

~~~
Notes are included in the Agent.cpp file.

void SIMAgent::FindDeriv()
{
	
	deriv[0] = (input[0] / Mass);
	deriv[1] = (input[1] / Inertia); 
	deriv[2] = state[2]; 
	deriv[3] = state[3]; 

}

~~~

You also must implement *SIMAgent::InitValues()*: Try to figure out appropriate values for control and behavior settings. You need to find out appropriate values for: *SIMAgent::Kv0, SIMAgent::Kp1, SIMAgent::Kv1, SIMAgent::KArrival, SIMAgent::KDeparture,
SIMAgent::KNoise,	SIMAgent::KWander, SIMAgent::KAvoid, SIMAgent::TAvoid, SIMAgent::RNeighborhood, SIMAgent::KSeparate, SIMAgent::KAlign, SIMAgent::KCohesion.*


**(b) - 20 points**: 

* Seek
~~~

	vec2 tmp;
	double thetad;
	tmp = goal - GPos;
	tmp.Normalize(); 
	thetad = atan2(tmp[1], tmp[0]);
	double vn = SIMAgent::MaxVelocity; 
	return vec2(cos(thetad)*vn, sin(thetad)*vn);
~~~

* Flee
~~~
	vec2 tmp;
	double thetad;
	tmp = goal - GPos; 
	tmp.Normalize();	
	thetad = atan2(tmp[1], tmp[0]); 
	thetad = thetad + M_PI; 
	float vn = SIMAgent::MaxVelocity; 
	return vec2(cos(thetad)*vn, sin(thetad)*vn);
~~~

* Arrival
~~~
	vec2 tmp = goal - GPos; /*Vd = goal - position*/
	tmp.Normalize();
	thetad = atan2(tmp[1], tmp[0]) + M_PI; 

	double vn = SIMAgent::MaxVelocity;
	vn = tmp.Length() *KArrival;

	double vd = SIMAgent::MaxVelocity * (vn/ radius); 

	if (tmp.Length() > 0.0)
	{
		return vec2(cos(thetad)*vd, sin(thetad)*vd);
	}
	else {

		return vec2(cos(thetad)*vn, sin(thetad) * vn);
	}

	return tmp;
}
~~~

* Departure
~~~
	vec2 tmp = goal - GPos; 
	tmp.Normalize();
	thetad = atan2(tmp[1], tmp[0]) + M_PI; 

	double vn = SIMAgent::MaxVelocity;
	vn = tmp.Length() *KDeparture;

	double vd = SIMAgent::MaxVelocity * (vn / radius); 

	if (tmp.Length() > 0.0)
	{
		return vec2(cos(thetad)*vn, sin(thetad)*vn);
	}
	else {

		return vec2(cos(thetad)*vd, sin(thetad) * vd);
	}

	return tmp;
}
~~~

* Wander
* Obstacle Avoidance

**(c) - 20 points**: Implement the functions for the following group behaviors: 
* Seperation
* Cohesion 
* Alignment 
* Flocking
* Leader Following

# Part 2 - Simulating a simple pedestrian flow

**(a) - 0 points**:

AnyLogic Model Available on files:

Phase 1: Simulating a Simple Pedestrian Flow

![](images/Subway_pt1.JPG?raw=true)


Phase 2: Adding Fare Gates

![](images/Subway_Fares.JPG?raw=true)

Phase 2: PDM

![](images/Subway_Density.JPG?raw=true)

Phase 3: Adding Ticket Vending Machines

![](images/Subway_Vending.JPG?raw=true)

3D Animation and Comparison with 2D PDM

![](images/Subway_3D.JPG?raw=true)

~~~

Statistics:
 - working on Excel sheet
~~~

**(b) - 20 points**: 

AnyLogic Model Available on files:

The map used in this exercise was Tolman's Maze (Tolman & Honzik, 1930; Tolman, 1948), originally used for psychology experiments of rats.  

Using AnyLogic, the image below displays 2D, 3D animations, as well as the Pedestrian Density Map. 

![](images/PDM_3D.JPG?raw=true)



As seen below, 8 "False Paths" were given to the pedestrians with varying degrees of probabilities for taking the false paths and true path. 
![](images/Output1.JPG?raw=true)

![](images/Output2.JPG?raw=true)

~~~
Stats in the works
~~~

**(c) - 30 points**: 

AnyLogic Model Available on files:

The model that is analyzed in this assignment is the Harris Corporation Engineering Center at the University of Central Florida. Below are simulated images of the building's front view from close-up and aerial. 


(I claim no rights to this image, This image was produced by UCF and 3D Warehouse software. See references)

![](images/sim1.JPG?raw=true)

(I claim no rights to this image, This image was produced by UCF and 3D Warehouse software. See references)

![](images/sim2.JPG?raw=true)

My aim was to observe the floor plan in the first floor. The following two images display the entire floor plan of the first floor:

![](images/layout1.jpg?raw=true)

![](images/layout2.jpg?raw=true)

On closer inspection, I decided to analyze the second layout (image above this text, left-hand side corner). The scenario that we will observe is an emergency exit route for the following rooms:

  ![](images/primarylayout.jpg?raw=true)

I took images of the outside of both exits, as well as the inside.


First Exit:

![](images/scenario1prim.jpg?raw=true)


Side View of First Exit:

![](images/scenario2.jpg?raw=true)

Inside First Exit (hallway from Dean's Conference Room)

![](images/scenario4.jpg?raw=true)

Hallway (looking at First Exit):

![](images/scenario6.jpg?raw=true)

Second Exit:

![](images/scenario3.jpg?raw=true)

Hallway (looking at Second Exit):

![](images/scenario5.jpg?raw=true)

Observing the Emergency Exit Route again, I estimated that on a given day, there are 21 individuals in the yellow portion and 12 individuals in the blue portion (Total 33):

![](images/primarylayout.jpg?raw=true)

I do realize that this Emergencency Exit Route is designed to help faculty/students/reception area individuals from exiting the building. If other rooms are taken into consideration, i.e., classroom 111, classroom 117, and classroom 118, and Maintenance Rooms, the Emergency Route Exits may not be as viable. I will first model what is on the Emergency Exit Route. 

You will notice that I drew walls across some open areas. I am simulating the scenario to assume that the only way to exit would be through the yellow and blue routes instead of through windows/other doors. 

~~~
Scenario: Faculties are all in their offices and a conference meeting is being held in the dean's conference room. Students are getting advice in the reception area or are studying in certain rooms. A Fire Alarm was sounded, indicating an evacuation in progress. The following indicates the rooms and how many individuals are getting out:

Yellow Area - Exit 1: 9 target lines, 21 people
114C - 1
114D - 1
114E - 1
114B - 1
114A - 1
Reception Area 114 - 5
Dean's Conference Room 113 - 11 

Blue Area - Exit 2: 9 target lines, 12 people
115D - 1
115C - 1
115E - 2
115F - 1
115B - 1
115A - 1
115I Storage - 1
115H - 1
115G Students - 3
~~~
 
Original Model with starting lines, exits, and pathway markers:

![](images/route.JPG?raw=true)


PDM:

![](images/PDM_route.JPG?raw=true)


Video of PDM:

https://www.youtube.com/watch?v=YI_aCFKoDA0


3D Animation:

![](images/3D_route.JPG?raw=true)


Statistics and Graphs - For this portion, I used time as a component to measure when an individual from a certain room exited the building. If there was more than 1 person in a room, I calculated the final time when the last individual (from that room) crossed the exit line.


Statistics for Yellow Region:

![](images/yellow.jpg?raw=true)

![](images/statsyellow.JPG?raw=true)


Statistics for Blue Region:

![](images/Blue.jpg?raw=true)

![](images/statsblue.JPG?raw=true)


Statistics for All Routes:

![](images/Overall.JPG?raw=true)

![](images/statsoverall.JPG?raw=true)


From these analyses, we conclude that the yellow region was more faster at reaching the exit than the blue region, though all evacuation plans seem to relatively level out. In terms of overall time to evacuate the building, according to University of Central Florida's Office of Emergency Management (2015), a time less than 5 minutes is a "prompt and orderly evacuation" as seen below.

(I do not claim ownership to this image. See references)

![](images/Fire2.JPG?raw=true)

Typically, a fire may get out of control "in three to five minutes" and a fire extinguisher can be dishcharged in "less than one minute" (2015). See below.

(I do not claim ownership to this image. See references.)

![](images/Fire1.JPG?raw=true)

Therefore, we can conclude with such evidence that this Emergency Evacuation plan may be successful. 




Let's initialize more individuals for the Server Room 116, ClassRoom 117, and Classroom 111. 
~~~
For this scenario, I added a few constraints, such as arrival time of 
inividuals. Due to the setup of the floor plan, most individuals would be 
inclined to go to Exit 1. Further, this Exit 1 is lit up and has lots of lighting due to the glass structure, while Exit 2 seems a bit obscure (look at real life images again). 

Server Room - 5 people - Exit 2

ClassRoom 117 - 50 people - 30 go to Exit 2, 20 go to Exit 1 (I split these because naturally - students will exit these two doors and search for the nearest exit)

ClassRoom 111 - 40 people - Exit 1

~~~

AnyLogic target lines in rooms, pathfinders, and Exit lines:

![](images/Addroute.JPG?raw=true)

PDM of the map:

![](images/pdm_newroute.JPG?raw=true)

Video of PDM:

https://www.youtube.com/watch?v=NhYpF3Pnv5c

3D Animation Layout:

![](images/3d_newroute.JPG?raw=true)


Statistics and Graphs - Again, I used time as a variable to measure exit times. If there was more than 1 person in a room, I calculated the final time when the last individual (from that room) crossed the exit line. 

Yellow Region:

![](images/yellownew.JPG?raw=true)

![](images/yellowstatsnew.JPG?raw=true)


Blue Region:

![](images/bluenew.JPG?raw=true)

![](images/bluestatsnew.JPG?raw=true)


The yellow area took less time to exit the building than the blue area, even though the yellow area had more assigned people.  

Based on these analyses, it took these rooms a little less than 2 minutes to get out of the building. These conditions detail an optimal exit plan. In more realistic scenarios, I would imagine that it would take between 5-15 minutes to evacuate this emergency floor plan because it is not often that all individuals exit at once. Human behavior varies, with some people walking much slower than others, and other individuals running to the exit. Therefore, this model would need to add wait times to people. 

This Emergency Route will probably work in the case of a real emergency, but other areas need to be taken into account.


### References

University of Central Florida Office of Emergency Management. (2015). http://emergency.ucf.edu/Plans/Fire%20Plan.pdf

https://map.ucf.edu/locations/116/harris-corporation-engineering-center-hec/

https://3dwarehouse.sketchup.com/model.html?id=6888378c9c3beed3dd417b8d039eee23

McLeod, S. A. (2013). Tolman - Latent Learning. Retrieved from www.simplypsychology.org/tolman.html

Tolman, E. C., & Honzik, C. H. (1930). Introduction and removal of reward, and maze performance in rats. University of California Publications in Psychology.

Tolman, E. C. (1948). Cognitive maps in rats and men. Psychological review, 55(4), 189.
