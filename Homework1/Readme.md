#Homework 1 : The Jello Cube (Continuous Simulation Assignment
## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)


This is the framework for homework #1. Please first read the [homework writeup](HomeWork%231.pdf).

The assignment is due: Monday, February 27 at 11:59PM (EST)

| undeformed jello  | deformed jello |
| ------------- | ------------- |
| ![](images/undeformed3.png?raw=true)  | ![](images/deformed3.png?raw=true) |


hi hi

Part 1 Results
---
####A)

y(x) = e ^ (x/2) sin (5x)

####B)

double df(double x, double y)            
{
    return y - (1.0/ 2.0)*exp(x / 2.0)*sin(5.0 * x) + 5.0 * exp(x / 2.0)*cos(5.0 * x);
}

double exact(double x)            
{
    return exp(x / 2.0)*sin(5.0 * x);
}


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


| ![](images/NIPart1C.jpg?raw=true)  | 



####Error Values for Numerical Integrations - D)

|Error (RK1) | Error (RK2) | Error (RK4) |
|-----|------| -----|------|------|------|
| 0.0079487  |  0.0099815  |  1.6961e-05 |
| 0.060345   |  0.01282    |  1.5176e-05 |
| 0.15345    |  0.016702   |  1.2735e-05 |
| 0.30881    |  0.023197   |  8.6499e-06 |
| 0.67775    |  0.038657   |  1.0742e-06 |


| ![](images/ErrorValueNIs.jpg?raw=true) |


####Step Size Variations - E) H=1.0, H=0.8, H=0.5 (in order below)

| (RK4)        | Exact          | Error (RK4) |
|-----|--------| -----|---------|------|------|
| -3.17515995  |  -1.580998849  |  -1.01e-00  |
| -6.043489728 |  -1.4788027    |  -3.09e-00  |
| -5.346117367 |  2.914387906   |  2.83e-00   |
| -11.11750527 |  6.745803673   |  2.6481     |

| ![](images/ValueH1.jpg?raw=true) |


| (RK4)        | Exact          | Error (RK4) |
|-----|--------| -----|---------|------|------|
| -1.520493899 |  -1.129016654  |  -0.34674   |
| 2.071810169  |  2.201857271   |  0.059062   |
| -2.642378236 |  -1.781484825  |  -0.48324   |
| -3.87078297  |  -1.425994463  |  -1.7144    |

| ![](images/ValueH8.jpg?raw=true) |


| (RK4)        | Exact         | Error (RK4) |
|-----|--------| -----|--------|------|------|
| 0.762834386  |  0.768453444  | 0.0073122   |
| -1.616611002 |  -1.580998849 | -0.022525   |
| 1.99051666   |  1.985745966  | 0.0024025   |
| -1.558087801 |  -1.4788027   | -0.053614   |

| ![](images/ValueH5.jpg?raw=true) |



Error Rate:
| ![](images/ErrorRateRK4s.jpg?raw=true) |



#### F) Analyze your results: 

1) Describe how varying the integration method changes the accuracy.
With variations in the integration method, the accuracy becomes more precise to the exact solution. As shown in the numerical integration graph, Euler is the least accurate, followed by Midpoint, and Runge-Kutta. 


2) What happens as you increase the x value to the accuracy?
As you increase the x value, the accuracy becomes less precise. For each integration method, the accuracy decreases with respect to the exact solution.

3) How does varying the step size effect the accuracy?
As you increase the step size (e.g., 0.1 to 1.0), the accuracy becomes less precise. As shown with RK4 step sizes, 1.0 is less accurate than 0.5.

4) Which method is the most accurate and why (in particular explain what is taken to account in the solution)?
The most accurate method is the Runge-Kutta Method (RK4) because it considers the curvature of the exact solution and is a fourth order series that derives the first, second, and third error orders to increase the accuracy. The other integration methods are first and second order series that vary in their accuracy estimates, thus have increasingly large error rates than Runge-Kutta.  

