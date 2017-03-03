#Homework 1 : The Jello Cube (Continuous Simulation Assignment
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)


This is the framework for homework #1. Please first read the [homework writeup](HomeWork%231.pdf).

The assignment is due: Monday, February 27 at 11:59PM (EST)

| undeformed jello  | deformed jello |
| ------------- | ------------- |
| ![](images/undeformed3.png?raw=true)  | ![](images/deformed3.png?raw=true) |

hi hi

Cintya: going to request an additional day to complete hw1. 
Due date: 03/02/2017


Part 1 Results
---
####A)

~~~
y(x) = e ^ (x/2) sin (5x)
~~~

####B)
~~~
double df(double x, double y)            
{
    return y - (1.0/ 2.0)*exp(x / 2.0)*sin(5.0 * x) + 5.0 * exp(x / 2.0)*cos(5.0 * x);
}

double exact(double x)            
{
    return exp(x / 2.0)*sin(5.0 * x);
}

~~~

####Result Values - C)

| RK1           | RK2          | RK4           | Exact        |
|------|--------|------|-------|------|--------|------|-------|
| 0.5           | 0.5090369272 | 0.5040147599  | 0.5040062116 |
| 0.9860882804  | 0.9418917554 | 0.9299833736  | 0.9299692608 |
| 1.336761843	| 1.178280127  | 1.158938591   | 1.158923832  |
| 1.453584287   | 1.136380907  | 1.110627992   | 1.110618385  |
| 1.28927035    | 0.7981592984 | 0.7684526188  | 0.7684534442 |
| 0.8654303303  | 0.2207680347 | 0.1904774691  | 0.1904920858 |
| 0.2742737135  | -0.470402004 | -0.4978138899 | -0.497785095 |
| -0.3378573082 | -1.107144704 | -1.129056656  | -1.129016654 |
| -0.8027530548 | -1.517667616 | -1.533117725  | -1.533072395 |
| -0.971671551  | -1.570878628 | -1.581041974  | -1.580998849 |


  ![](images/NIPart1C.jpg?raw=true)  



####Error Values for Numerical Integrations - D)

|Error (RK1) | Error (RK2) | Error (RK4) |
|-----|------| -----|------|------|------|
| 0.0079487  |  0.0099815  |  1.6961e-05 |
| 0.060345   |  0.01282    |  1.5176e-05 |
| 0.15345    |  0.016702   |  1.2735e-05 |
| 0.30881    |  0.023197   |  8.6499e-06 |
| 0.67775    |  0.038657   |  1.0742e-06 |


 ![](images/ErrorValueNIs.jpg?raw=true) 


####Step Size Variations - E) H=1.0, H=0.8, H=0.5 (in order below)

| (RK4)        | Exact          | Error (RK4) |
|-----|--------| -----|---------|------|------|
| -3.17515995  |  -1.580998849  |  -1.01e-00  |
| -6.043489728 |  -1.4788027    |  -3.09e-00  |
| -5.346117367 |  2.914387906   |  2.83e-00   |
| -11.11750527 |  6.745803673   |  2.6481     |

  ![](images/ValueH1.jpg?raw=true) 


| (RK4)        | Exact          | Error (RK4) |
|-----|--------| -----|---------|------|------|
| -1.520493899 |  -1.129016654  |  -0.34674   |
| 2.071810169  |  2.201857271   |  0.059062   |
| -2.642378236 |  -1.781484825  |  -0.48324   |
| -3.87078297  |  -1.425994463  |  -1.7144    |

  ![](images/ValueH8.jpg?raw=true) 


| (RK4)        | Exact         | Error (RK4) |
|-----|--------| -----|--------|------|------|
| 0.762834386  |  0.768453444  | 0.0073122   |
| -1.616611002 |  -1.580998849 | -0.022525   |
| 1.99051666   |  1.985745966  | 0.0024025   |
| -1.558087801 |  -1.4788027   | -0.053614   |

 ![](images/ValueH5.jpg?raw=true) 


Error Rate:
 ![](images/ErrorRateRK4s.jpg?raw=true) 


#### F) Analyze your results: 

1) Describe how varying the integration method changes the accuracy.

With variations in the integration method, the accuracy becomes more precise to the exact solution. As shown in the numerical integration graph, Euler is the least accurate, followed by Midpoint, and Runge-Kutta. 


2) What happens as you increase the x value to the accuracy?

As you increase the x value, the accuracy becomes less precise. For each integration method, the accuracy decreases with respect to the exact solution.

3) How does varying the step size effect the accuracy?

As you increase the step size (e.g., 0.1 to 1.0), the accuracy becomes less precise. As shown with RK4 step sizes, 1.0 is less accurate than 0.5.

4) Which method is the most accurate and why (in particular explain what is taken to account in the solution)?

The most accurate method is the Runge-Kutta Method (RK4) because it is a fourth order approximator, whereas Euler considers only a 1st order approximation of the slope and the Midpoint considers a 2nd order approximation of the slope. Thus, having more estimates of the slope will produce results that are more accurate to the exact solution.



Part 3 Written Questions
---

1) What is the effect of the Ks and Kd parameters on the jello?

The effect of the Ks (stiffness constant) parameter allows the jello to increase it's ocsillation/bounce, whereas the Kd ( damping constant) parameter decreases the oscillation/bounce of the jello. 

2) What are the benefits and the drawbacks of the collision system used here? What are some different ways in which it could be improved?

The benefits of the collision system used here is that at the start of the simulation, there is a force that is acting to pull the jello cube down. In other words, there is control over the force mechanisms that drive the movement of the jello cube and it's shape is already constructed. On the other hand, this anistropic nature can have set backs. The drawbacks are that you need to configure good springs to the jello cube for it to precisely maintain it's shape while it hits the ground and bounces back. How it can be improved is to have a different kind of mass-spring (tetrahedron, big hexahedron etc) that will need only few tweaks to make the jello cube move and maintain shape.    

3) What are some example systems you could model with Mass-spring simulations? Explain how you would construct the model.

Several example systems to model with a mass-spring simulation would be a pendulum(s) swing, curtains moving against a 'wind', planetary force fields, or falling rocks from a hill side. If I were to construct a moving curtain, I would first have particles that make up a thin 3D square shape. In order for the curtain to move, you would need to add more shear springs and a force that hits the curtain to it's side.  


4) Does the jello behave realistically? What integration method did you choose to make the Jello stable?

My jello cube does not behave in a realistic fashion due to it's explosive nature. However, this simulation can be enhanced to be more realistic by having the jello bounce and maintain it's shape while it hits the cylinders. Midpoint and RK4 are better integration methods that maintain the jello stable. 

5) How would you model and simulate water (in terms of a continuous simulation)?

How I would simulate water would be to make tetrahedron mass springs to connect to each other to make up a large rectangular shape in the ground. You can then play around with the mass and force of particular regions in the rectangle in order to simulate 'water' movement.  


Part 4 Final Report
---

#### Euler

 ![](images/Euler_Code.JPG?raw=true) 


#### Midpoint (with formula)

![](images/midpoint1.JPG?raw=true) 

![](images/midpoint2.JPG?raw=true) 



#### RK4

![](images/rk4.JPG?raw=true) 


#### Compute Forces

![](images/computeforces.JPG?raw=true)

#### Spring Constants

 Two Different Sets of Spring Constants Used (for video in extra credit):

![](images/kdks.JPG?raw=true)


#### CheckforCollisions 

![](images/checkforcollisions.JPG?raw=true)

#### CylinderIntersection
![](images/cylinderintersection.JPG?raw=true)

#### FloorIntersection

![](images/floorintersection.JPG?raw=true)

#### Resolve Contacts

![](images/resolvecontacts.JPG?raw=true)

#### Resolve Collisions

![](images/resolvecollisions.JPG?raw=true)

#### Shear and Bend Springs

![](images/structurespringbend.JPG?raw=true)

#### Extra Features

Sphere Intersection (Code and Environment - 4 spheres implemented)

![](images/sphereintersection.JPG?raw=true)

![](images/spherenvironment.JPG?raw=true)


VelocityVerlet Code (look at entire code; freezes in simulation :( )

![](images/velocityvelvet.JPG?raw=true)


#### Ks, Kd, and best integration method
The more I increased the Ks, the more movement and oscillation the cube had. If I increased the Kd too much, it either did not run or just exploded. I also tried decreasing the Ks to stabilize the jellocube more, but this did not work out too well either. The jello cube kept exploding, but it is able to have contact and collision. The best integration method in my simulation is the midpoint and perhaps rk4. Either way, the jellocube kept exploding with the exception of velocity verlet. 

Extra Credit
---

#### Different Colored Cubes (did not get instructor permission, but just posting)

Yellow-White Cube

![](images/yellowwhitecolor.JPG?raw=true)

Dark Red Cube

![](images/darkred.JPG?raw=true)

#### Videos

Created a movie of the jello cube environment (super high speed!! whyyy :( ))
~~~
https://youtu.be/qABC3cQ1NE4 
~~~

Created a movie of the jello cibe with different integration methods and spring stiffness
~~~
https://www.youtube.com/watch?v=d2e-_o3dY4U
~~~

Poor quality :( and no matter what I do, the jellocube explodes. However, there are differences in the way that they are morphed.

In order: Euler, MidPoint, RK4, Velocity Verlet

Stiffness changes:

1)

double JelloMesh::g_structuralKs =5000.0;
double JelloMesh::g_structuralKd = 10.0;
double JelloMesh::g_attachmentKs = 5000.0;
double JelloMesh::g_attachmentKd = 10.0;
double JelloMesh::g_shearKs = 5000.0;
double JelloMesh::g_shearKd = 10.0;
double JelloMesh::g_bendKs = 8000.0;
double JelloMesh::g_bendKd = 10.0;
double JelloMesh::g_penaltyKs = 5000.0;
double JelloMesh::g_penaltyKd = 2.0;

2) 

double JelloMesh::g_structuralKs = 500.0;
double JelloMesh::g_structuralKd = 2.0;
double JelloMesh::g_attachmentKs = 0.0;
double JelloMesh::g_attachmentKd = 0.0;
double JelloMesh::g_shearKs = 500.0;
double JelloMesh::g_shearKd = 2.0;
double JelloMesh::g_bendKs = 500.0;
double JelloMesh::g_bendKd = 2.0;
double JelloMesh::g_penaltyKs = 0.0;
double JelloMesh::g_penaltyKd = 0.0;


References:
---
I completed this homework with the help of the following students in class:
Olivia, Karla, Rebecca, Joe, Ashley, Sarah

I utilized Piazza and any helpful tips on Google Hangouts

I got some outside help from my friend (electrical and computer engineer)

VelocityVerlet Help:
http://stackoverflow.com/questions/22748196/solar-system-simulation-project-velocity-verlet-help