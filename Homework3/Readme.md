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

**(a) - 0 points**: Follow the Anylogic example for the [Subway Entrance example](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/tutorial/Subway_Entrance.html). Create the appropriate [boundaries and walls](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/markup/Wall.html), and the display ther pedestrian density map, [statistics](https://help.anylogic.com/index.jsp?nav=/4_1_5), [2D and 3D animations](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Animation.html).


![](images/Subway_pt1.JPG?raw=true)

![](images/Subway_Fares.JPG?raw=true)

![](images/Subway_Density.JPG?raw=true)

![](images/Subway_Vending.JPG?raw=true)

![](images/Subway_3D.JPG?raw=true)

~~~

Statistics:
 - working on Excel sheet
~~~

**(b) - 20 points**: Create a maze. Generate the pdm, stats, and animations like before. Vary [parameters in your agents](https://help.anylogic.com/index.jsp?topic=/com.xj.anylogic.help/html/_PL/reference/Attributes.html) to give them different behaviors and show the pedistrians change how they navigate the maze.


The map used in this exercise was Tolman's Maze (Tolman & Honzik, 1930; Tolman, 1948), originally used for psychology experiments of rats.  

Using AnyLogic, the image below displays 2D, 3D animations, as well as the Pedestrian Density Map. 

![](images/PDM_3D.JPG?raw=true)



As seen below, 8 "False Paths" were given to the pedestrians with varying degrees of probabilities for taking the false paths and true path. 
![](images/Output1.JPG?raw=true)

![](images/Output2.JPG?raw=true)

~~~
Stats in the works
~~~

**(c) - 30 points**: Model and analyze a building (or floor/outdoor space/stadium) on campus. (There is help on piazza how to find rough building plans - we expect something plausible). Create a senario: evacuation, daily office routine, special event, normal egress.... etc., and model and design your own experiment to determine if the building design suits the needs of its users. Start with photographs of your site, describe your site, describe your senario and hypothesis. Then use an agent-based pedistrian simulation to visualize your experiment's results.


Th model that is analyzed in this assignment is the Harris Corporation Engineering Center at the University of Central Florida. Below are simulated images of the building's front view from close-up and aerial. 


(I claim no rights to this image, This image was produced by UCF and 3D Warehouse software. See references)
![](images/sim1.JPG?raw=true)

(I claim no rights to this image, This image was produced by UCF and 3D Warehouse software. See references)
![](images/sim2.JPG?raw=true)

My aim was to observe the floor plan in the first floor. The following two images display the entire floor plan of the first floor:

![](images/layout1.JPG?raw=true)

![](images/layout2.JPG?raw=true)

On closer inspection, I decided to analyze the second layout (image above this text, left-hand side corner). The scenario that we will observe is an emergency exit route for the following rooms:

  ![](images/primarylayout.JPG?raw=true)

I took images of the outside of both exits, as well as the inside.


First Exit:
![](images/scenario1prim.JPG?raw=true)


Side View of First Exit:
![](images/scenario2.JPG?raw=true)

Inside First Exit (hallway from Dean's Conference Room)
![](images/scenario4.JPG?raw=true)

Hallway (looking at First Exit):
![](images/scenario6.JPG?raw=true)

Second Exit:
![](images/scenario3.JPG?raw=true)

Hallway (looking at Second Exit):
![](images/scenario5.JPG?raw=true)

Observing the Emergency Exit Route again, I estimated that on a given day, there are about 20 individuals in the yellow portion and about 12 individuals in the blue portion:

![](images/primarylayout.JPG?raw=true)

I do realize that this Emergencency Exit Route is designed to help faculty and reception area individuals from exiting the building. If other rooms are taken into consideration, i.e., classroom 111, classroom 117, and classroom 118, and Maintenance Rooms, the Emergency Route Exits may not be as viable. I will first model what is on the Emergency Exit Route. 




### References

https://map.ucf.edu/locations/116/harris-corporation-engineering-center-hec/

https://3dwarehouse.sketchup.com/model.html?id=6888378c9c3beed3dd417b8d039eee23

McLeod, S. A. (2013). Tolman - Latent Learning. Retrieved from www.simplypsychology.org/tolman.html

Tolman, E. C., & Honzik, C. H. (1930). Introduction and removal of reward, and maze performance in rats. University of California Publications in Psychology.

Tolman, E. C. (1948). Cognitive maps in rats and men. Psychological review, 55(4), 189.
