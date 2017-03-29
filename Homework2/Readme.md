#Homework 2 :  Discrete-Event Simulation Assignment

## IDS6938-Simulation Techniques - [University of Central Florida](http://www.ist.ucf.edu/grad/)

[University of Central Florida](http://www.ist.ucf.edu/grad/)
This is the framework for homework #2. 



Requesting an Extra Day! Using my extra day and/or extra event day: 03/29/2017 due on 11:59PM (EST)


asdfasdf
sadfsad


# Introduction
A Discrete-event Model simulates a complex system as an ordered sequence of well-defined events. Mathematically Discrete-event models use Markov Processes, Queuing systems, events, probability / statistics, and random variables. The purpose of this assignment is to learn the mathematical foundations, how to program these models, and how to simulate them. The assignment is due Tuesday, March 28, 2017 at 11:59 P.M.

Major parts for the Assignment
You can think of the assignment broken up to 4 major parts:
* Empirical Tests of Randomness
* Snakes and Ladders (Discrete Event Markov Chains and Monte Carlo Simulations)
* Discrete Event Simulation - Queue Simulation
* Composing a final report

The goal of this assignment is to become familiar with the concepts in the second third of the class. You will be expected to compose a *final report* which demonstrates your understanding on the material in each section of the assignment. Be visual! - Pictures say a thousand words so you do not have to. Show off your different configurations and really explore the assignment.

# Assignment
~##Part 0 - Getting Started
Read the assignment. Sync your fork with the [main IDS6938 repository](https://github.com/hepcatjk/IDS6938-SimulationTechniques). Use CMake to create project files for the Homework 2 assignment (*Hint: and Discrete Lecture folders*). Set your *startup project* to the correct project. Test building and executing the homework 2 project. Look over and understand the framework and find the functions you need to edit for the assignment.~



##Part 1: Empirical Tests of Randomness (20 pts).
~We looked at different ways to generate [pseudo-random numbers](https://en.wikipedia.org/wiki/Pseudorandom_number_generator) and [quasi random numbers](https://en.wikipedia.org/wiki/Low-discrepancy_sequence). Generating random numbers are crucial to Discrete-Event simulations which rely on random variables and stochastic processes. This problem explores different random number generators, distributions, and statistics. Different [C++ pseudo-random numbers engines are instantiated](http://www.cplusplus.com/reference/random/) already for you. Also a a wide variety of standard distributions are implemented. Two quasi random number generators are also provided.~
* **(a) - 3pts:** Output the results of five different random number engines, using a uniform distribution for values between [0-100]. Generate useful charts and statistics from the output to analyze how uniform these values truly are. You are expected to look at some advanced statistics and test, for example: tests like the Kolmogorov-Smirnov test, Chi-square test, Autocorrelation test, and Spearman’s Rank Correlation Coefficient are a few examples of ones you could use.)


The following were selected for random number engines: Sobol, Mersenne, Knuth B, Ranlux, and Min Std. 

Histogram plots and line plots were used to measure the random generation of numbers (frequency) between the values 0-100 for each random engine. These plots exemplify that all random number engines construct similar uniform discrete distributions as shown through the means and standard deviations of each plot. Using a Spearman RHO (two-tailed) there is a high chance that there is weak correlation between the values due to the uniformity of the distributions. Using a Kolmogorov-Smirnov test (goodness of fit for one sample data), for each random engine, the test shows a high probability of residuals being normally distributed.


1) Sobol - 

~~~
Spearman RHO: 1.0276e-05
Kolmogorov-Smirnov (KS): 0.9695
Critical Value of KS: 0.0043
Standard DV: 28.86751
Mean: 49.99933
~~~

Histogram showing the range of values:
![](images/Part1A_Sobol_Hist.jpg?raw=true) 


Line Plot showing the density of the random number generation:
![](images/Part1A_Sobol.jpg?raw=true)


Histogram of Frequency Count Values between 0-100
![](images/Part1A_Sobol_Uniform.jpg?raw=true)




2) Mersenne Twister

~~~
Spearman RHO: 4.1768e-04
Kolmogorov-Smirnov (KS): 0.9693 
Critical Value of KS: 0.0014
Standard DV: 28.88464 
Mean: 50.01418
~~~

Histogram showing the range of values:
![](images/Part1A_Mersenne_Hist.jpg?raw=true) 


Line Plot showing the density of the random number generation:
![](images/Part1A_Mersenne.jpg?raw=true)


Histogram of Frequency Count Values between 0-100
![](images/Part1A_Mersenne_Uniform.jpg?raw=true)



3) Knuth B

~~~
Spearman RHO: 2.7192e-04
Kolmogorov-Smirnov test: 0.9693
Critical Value of KS: 0.0014 
Standard Dv: 28.86350
Mean: 49.92638
~~~

Histogram showing the range of values:
![](images/Part1A_Knuth_Hist.jpg?raw=true) 


Line Plot showing the density of the random number generation:
![](images/Part1A_Knuth.jpg?raw=true)


Histogram of Frequency Count Values between 0-100
![](images/Part1A_KnuthB_Uniform.jpg?raw=true)


4) RanLux

~~~
Spearman RHO: -1.6082e-04
Kolmogorov-Smirnov (KS): 0.9698
Critical Value of KS: 0.0014
Standard Dv: 28.85609
Mean: 50.03906
~~~

Histogram showing the range of values:
![](images/Part1A_Ranlux_Hist.jpg?raw=true) 


Line Plot showing the density of the random number generation:
![](images/Part1A_Ranlux.jpg?raw=true)


Histogram of Frequency Count Values between 0-100
![](images/Part1A_Ranlux_Uniform.jpg?raw=true)


5) Min Std

~~~
Spearman RHO: -0.0015
Kolmogorov-Smirnov (KS): 0.9696
Critical Value of KS: 0.0014
Standard Dv: 28.87423
Mean: 49.95904
~~~

Histogram showing the range of values:
![](images/Part1A_Minstd_Hist.jpg?raw=true) 


Line Plot showing the density of the random number generation:
![](images/Part1A_Minstd.jpg?raw=true)


Histogram of Frequency Count Values between 0-100
![](images/Part1A_Min_Uniform.jpg?raw=true)




* **(b) - 2pts:**  Vary *N* (amount of samples). How do things change.

Original: N = 100,000

Change N = 1,000

Change N  = 100,000,000

When you decrease N, the range of number generation decreases for each of the values between 0-100. This means that there are far lesser points that will show up in a histogram/scatter plot. When you increase N, the number generator increases for the N range for each of the values between 0-100. The computing power is also higher.


* **(c) - 3pts:** Fix a random engine of your choice from part (a), and now vary five different [distributions](http://www.cplusplus.com/reference/random/) for just the psedo-random numbers. Again, analyze your results with graphs and statistics of choice.


Line and histogram plots were used to represent each distribution to show the "frequency" as the number of random values increases. The distribution for all were set as close to the values of 0-100. These graphs are able to show how each distribution varies in shape and how it can be used in queue systems. Mean and standard deviation were calculated. Spearman RHO (two tailed), was used to calculate the overall correlation of the values.  Kolmogorov-Smirnov (goodness of fit for 1 sample) was used to calculate a specified distribution.

The following are seven different distributions used for Mersenne Twister random engine:

1) Normal Distribution

~~~
Spearman RHO: 0.0013
Kolmogorov-Smirnov (KS): 1.0000
Critical Value of KS: 0.0043
Standard Dv: 10.02621
Mean: 50.00305


Spearman displays a weak correlation, while the Kolmogorov-Smirnov displays a strong goodnes to fit to the KS statistical distribution.
~~~

Line Plot
![](images/Part1C_Norm.jpg?raw=true)

Histogram
![](images/Part1C_Norm_Hist.jpg?raw=true)



2) Fisher F Distribution

~~~
Spearman RHO: 1.4367e-04
Kolmogorov-Smirnov (KS): 0.5817
Critical Value of KS: 0.0043
Standard Dv: 1.61137
Mean: 1.49947

Spearman: Strong negative correlation; Kolmogorov-Smirov displays a moderate similarity to the KS distribution.
~~~

Line Plot
![](images/Part1C_Fisher.jpg?raw=true)

Histogram
![](images/Part1C_Fisher_Hist.jpg?raw=true)



3) Chi Square Distribution

~~~
Spearman RHO: 9.5335e-04
Kolmogorov-Smirnov (KS): 0.9851 
Critical Value of KS: 0.0043
Standard Dv: 4.47145
Mean: 9.98966

Spearman: A strong negative correlation; KS: strong support for similarity to KS distribution
~~~

Line Plot
![](images/Part1C_Chi.jpg?raw=true)

Histogram 
![](images/Part1C_Chi_Hist.jpg?raw=true)



4) Binomial Distribution

~~~
Spearman RHO: -0.0024
Kolmogorov-Smirnov (KS): 1 
Critical Value of KS: 0.0043
Standard Dv: 3.53172
Mean: 24.99208

Spearman: not a strong relationship, KS: strong similiarity to KS distribution curve. 
~~~

Line Plot
![](images/Part1C_Binomial.jpg?raw=true)

Histogram 
![](images/Part1C_Binomial_Hist.jpg?raw=true)



5) Poisson Distribution

~~~
Spearman RHO: 0.0023
Kolmogorov-Smirnov (KS): 1 
Critical Value of KS: 0.0043
Standard Dv: 7.08603
Mean: 50.03232

Spearman: not a very strong relationship between the values; KS: strong similarity between KS distribution for goodness of fit.
~~~

Line Plot
![](images/Part1C_Poisson.jpg?raw=true)

Histogram 
![](images/Part1C_Poisson_Hist.jpg?raw=true)



6) Exponential Distribution

~~~
Spearman RHO: 0.0016
Kolmogorov-Smirnov (KS): 0.7991
Critical Value of KS: 0.0043
Standard Dv: 9.99942
Mean: 10.01414

Spearman: not a very strong relationship between the values; KS: slightly strong relationship between KS goodness of fit curve.
~~~

Line Plot
![](images/Part1C_Exponential.jpg?raw=true)

Histogram 
![](images/Part1C_Exponential_Hist.jpg?raw=true)



7) LogNormal Distribution 

~~~
Spearman RHO: -0.0026
Kolmogorov-Smirnov (KS): 0.7362
Critical Value of KS: 0.0043
Standard Dv: 3.55935
Mean: 3.76900
~~~

Line Plot
![](images/Part1C_Log.jpg?raw=true)

Histogram 
![](images/Part1C_Log_Hist.jpg?raw=true)



8) Gamma Distribution

~~~
Spearman RHO: -0.0024
Kolmogorov-Smirnov (KS): 0.9665
Critical Value of KS: 0.0043
Standard Dv: 14.10126
Mean: 19.97375

Spearman: not a very strong correlation between the values; KS: strong relationship between KS goodness of fit curve and values.
~~~

Line Plot
![](images/Part1C_Gamma.jpg?raw=true)


Histogram 
![](images/Part1C_Gamma_Hist.jpg?raw=true)



9) Weibull Distribution

~~~
Spearman RHO: 0.0019
Kolmogorov-Smirnov (KS): 0.9890
Critical Value of KS: 0.0043
Standard Dv: 13.88102
Mean: 26.55862 

Spearman: not a very strong relationship; KS: strong relationship between values and KS goodness of fit distribution.
~~~

Line Plot
![](images/Part1C_Wei.jpg?raw=true)

Histogram 
![](images/Part1C_Wei_Hist.jpg?raw=true)






* **(d)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different random number engines. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines.

~~~
For N Values:
First Row - 500
Second Row - 1500
Third Row - 2500
Uniform Distribution was used for this part.
~~~

![](images/Part1D.jpg?raw=true)





* **(e)- 4pts:** Generate random numbers in two-dimensions for a unit square. Plot the results for the different distributions. The vertical axis should vary N in increasing order. The horizontal axis should show of the random number engines. (See [Random Numbers Webcourse page](https://webcourses.ucf.edu/courses/1246518/pages/random-numbers?module_item_id=10541423) for a rough idea what you should produce.)

~~~
N Values from Top to Bottom:
N = 500
N = 1500
N = 2500
~~~

Normal Distribution
![](images/Part1E_Norm.jpg?raw=true)

Fisher F Distribution
![](images/Part1E_Fisher.jpg?raw=true)

Chi Square Distribution
![](images/Part1E_Chi.jpg?raw=true)

Binomial Distribution
![](images/Part1E_Binomial.jpg?raw=true)

Exponential Distribution
![](images/Part1E_Exponential.jpg?raw=true)

Poisson Distribution
![](images/Part1E_Poisson.jpg?raw=true)

Lognormal Distribution
![](images/Part1E_Log.jpg?raw=true)

Gamma Distribution
![](images/Part1E_Gamma.jpg?raw=true)

Weibull Distribution
![](images/Part1E_Weibull.jpg?raw=true)


* **(f)- 4pts:** Repeat parts (d) and (e) with a unit circle.

~~~
N Values from Top to Bottom:
N = 500
N = 1500
N = 2500
~~~

Uniform Distribution
![](images/PartF_D_Uniform.jpg?raw=true)

Normal Distribution
![](images/PartF_D_Norm.jpg?raw=true)

Fisher F Distribution
![](images/PartF_Fisher.jpg?raw=true)

Chi Square Distribution
![](images/PartF_Chi.jpg?raw=true)

Binomial Distribution
![](images/PartF_Binomial.jpg?raw=true)

Exponential Distribution
![](images/PartF_Exponential.jpg?raw=true)

Poisson Distribution
![](images/PartF_Poisson.jpg?raw=true)

Lognormal Distribution
![](images/PartF_Log.jpg?raw=true)

Gamma Distribution
![](images/PartF_Gamma.jpg?raw=true)

Weibull Distribution
![](images/PartF_Weibull.jpg?raw=true)




##Part 2 - Snakes and Ladders (Discrete Event Markov Chains and Monte Carlo Simulations) (30 pts)

We all love board games. A board game can be viewed mathematically as a Markov chain, where the probability of moving to the next position depends only on the position you are currently at and the chances provided by tossing a dice. For this part of the homework we will simulate the game "*Snakes and Ladders*" (This goes by other names: Chutes and Ladders, Moksha Patam but all essentially the same gameplay.)

| Moksha Patam  | Snakes and Ladders |
| ------------- | ------------- |
| ![](images/snake1.jpg?raw=true)  | ![](images/snake2.jpg?raw=true) |

~##### Background~
~The classic game has 100 positions on the board. You toss one die, and move squares based on the result of the die. If you land on a ladder you move up the ladder to a higher numbered square. If you land on a snake's mouth, you descend to a lower numbered square. For purposes of simulation, we will add one extra square 0 (starting position). So there are 101 positions on the board.~

~The game is **memoryless** - your progression to the next position is independent of how you arrived there (opposed to Blackjack or Candyland where your progression is based on what cards have been drawn). A Markov Chain defines the probability of a move from state *i* to state *j* by a **Transition Matrix**, *T*. So in the case of *Snakes and Ladders* the dimensions of a transition matrix is 101x101.~

* **(a) Null State Game transition matrix - 10pts:** The *null state game* is defined by a game with no snakes and no ladders. This simplifies the game to just the moves of the two dice rolls. Create the transition matrix for the null state game. The Transition Matrix would be decided by the roll of a fair, six-sided die, so it would start to look like:
<BR>![](images/null.png?raw=true)<BR>
From state 0 it is equally probable of landing on squares 1-6. From state 1 t is equally probable of landing on squares 2-7, and so on. Create this transition matrix. The end is trickier, we will consider any roll past 100 a win case. (Opposed to rolling exactly onto square 100.) Confirm you have a well formed stochastic matrix (Write checks for confirming each row of T sums to one and all elements are non-negative). The Transition Matrix methods can be found in the TransitionMatrix.h file.

~~~
The following code I used to generate the Transition Matrix. Have not yet figured out how to write the checks.

int size = 101.0;
igen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);
unsigned int ROLLS = 0;
double prob = 1.0/6.0;  

void SetTransitionMatrix()
{
	TransitionMatrix.setZero();

	//change for int i = 1
	for (int i = 0; i < TransitionMatrix.rows() - 6; i++)
	{

		TransitionMatrix(i, i + 1) = prob;
		TransitionMatrix(i, i + 2) = prob;
		TransitionMatrix(i, i + 3) = prob;
		TransitionMatrix(i, i + 4) = prob;
		TransitionMatrix(i, i + 5) = prob;
		TransitionMatrix(i, i + 6) = prob;
	}

		TransitionMatrix(TransitionMatrix.rows() - 6, TransitionMatrix.rows() - 6 + 1) = prob;
		TransitionMatrix(TransitionMatrix.rows() - 6, TransitionMatrix.rows() - 6 + 2) = prob;
		TransitionMatrix(TransitionMatrix.rows() - 6, TransitionMatrix.rows() - 6 + 3) = prob;
		TransitionMatrix(TransitionMatrix.rows() - 6, TransitionMatrix.rows() - 6 + 4) = prob;
		TransitionMatrix(TransitionMatrix.rows() - 6, TransitionMatrix.rows() - 6 + 5) = prob * 2;

		TransitionMatrix(TransitionMatrix.rows() - 5, TransitionMatrix.rows() - 5 + 1) = prob;
		TransitionMatrix(TransitionMatrix.rows() - 5, TransitionMatrix.rows() - 5 + 2) = prob;
		TransitionMatrix(TransitionMatrix.rows() - 5, TransitionMatrix.rows() - 5 + 3) = prob;
		TransitionMatrix(TransitionMatrix.rows() - 5, TransitionMatrix.rows() - 5 + 4) = prob * 3;

		TransitionMatrix(TransitionMatrix.rows() - 4, TransitionMatrix.rows() - 4 + 1) = prob;
		TransitionMatrix(TransitionMatrix.rows() - 4, TransitionMatrix.rows() - 4 + 2) = prob;
		TransitionMatrix(TransitionMatrix.rows() - 4, TransitionMatrix.rows() - 4 + 3) = prob * 4;

		TransitionMatrix(TransitionMatrix.rows() - 3, TransitionMatrix.rows() - 3 + 1) = prob;
		TransitionMatrix(TransitionMatrix.rows() - 3, TransitionMatrix.rows() - 3 + 2) = prob * 5;

		TransitionMatrix(TransitionMatrix.rows() - 2, TransitionMatrix.rows() - 2 + 1) = prob * 6;

		TransitionMatrix(TransitionMatrix.rows() - 1, TransitionMatrix.rows() - 1) = prob * 6;

}

~~~


* **(b) Simulate and analyze the results of Null State Game - 10pts:** What is the modal number of moves required by a single player to finish the game? We will be simulating the game two different ways. 



**(1) Markov Chain**: The game can be analyzed with a row vector, *v* with 101 components, representing the probabilities that the player is on each of the positions. V(0) is (1,0,0,...,0) since we know we start at square 0. v evolves by: <BR>![](images/prob.png?raw=true)<BR>
For this part (1) use the *Markov project* in the Snake and Ladders starter code.<BR>

~~~
int main(){

	SetTransitionMatrix();

	//Output Vector
	v.setZero();
	v(0) = 1.0;

	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");

	
   // TODO add Markov vector - Matrix multiplication //v(k+1) = v(k) T.
	v = v.transpose() * TransitionMatrix;
	
	std::cout <<  v << std::endl;
	myfile << v << std::endl; 
	
	myfile.close();
}


~~~




**(2) Monte Carlo**: he will will use a monte carlo process to solve our Discrete Time Markov Chains. Here (2) use the DTMC project, and utilize the DTMC method similar to what we did in class. <BR><BR>Produce graphs to analyze the results and show how the game evolves over time for both methods. Plot useful statistics of the results such as percentage chance of finishing the game in n-moves, cumulative probability of finishing the game in n-moves, and other ways to convey useful information of the results.

~~~
Added DTMC method code to test_DTMC.cpp file.


for (unsigned int i = 0; i < N; ++i) {
		
		discreteMC = DTMC(TransitionMatrix, ROLLS, start);
			  ++hist[std::round(discreteMC.back())];
		  
			  for (auto elem : discreteMC)
				  std::cout << elem << std::endl;
	}

	for (auto p : hist) {
		std::cout << p.first << "\t" << (double)p.second / N << std::endl;
	}

	myfile.close();
}


~~~

* **(c) Simulate and analyze the results of Snakes and Ladders -10pts:**  Construct a new transition matrix based on the table:


Ladders From  | Ladders To | |  Snakes From  | Snakes To 
-------- | -------- | ------------- | -------- | -------- 
3|19| |11|7
15|37| |18|13
22|42| |28|12
25|64| |36|34
41|73| |77|16
53|74| |47|26
63|86| |83|39
76|91| |92|75
84|98| |99|70



Run the same simulation and analyze your results similar to part (b) for the proper game of *Snakes and Ladders* for both methods. How often are the snakes and ladders used, how do the probability of finishing change, etc? What is the maximum and expected amount of moves for the game? Use charts and graphs to illustrate these points.



* **(d) Think - 0pts:** If these games are built entirely on chance, do they require any strategy? Is it really a *game*, would you rather play games of chance or games of strategy?

~~~
I do not think that games of chance require any strategy. If anything, it depends on timing and the order of when events occur. So, there may be some luck involved. I would rather play a game of strategy, but playing by chance is also pretty fun because you do not know the outcome and the play can be very fluid. It's interesting seeing what comes up. 
~~~

##Part 3 - Discrete Event Simulation - Queue Simulation (30 pts)

~This problem will look at queues and commonly used performance measures. For this problem we will look to design a simple airport security check. We will make the following assumptions: (1) there is only one airline - Southwest; (2) passengers' interarrival times are independent and identically distributed (IID) with an exponential distribution with mean 1 / lambda. The service times are also assumed to be IID and exponentially distributed random variables with mean 1 / mu.~
<BR>![](images/queue.png?raw=true)<BR>
~When a passanger arrives they have to wait in a queue to present their ID and ticket to the gate agent with all the other passengers. Once approved by the agent they will have to pass through a security check. Since this is Orlando, there are only 3 open metal/screening devices open and again passangers have to wait in a queue. After passing through security you again have to wait in a queue to board your plane.~

* **(a) - 4pts:** To start create the senario in the figure above in *main.cpp*. Checkin will have a *mu* of 53 and accept new arrivals, the security gates will have a *mu* of 20, and will not accept new arrivials, boarding will have a *mu* of 80. You will have to set up  the appropriate *MM1_Queue* objects to capture the functionality above.

~~~
Completed in queues main.cpp file.


	   MM1_Queue    IDCHECK;
	   IDCHECK.set_file_names("IDCHECK_log.txt", "IDCHECK_wait.txt", "IDCHECK_service.txt");
	   IDCHECK.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   IDCHECK.set_mu(53);
	   IDCHECK.autogenerate_new_arrivals(true);
	   IDCHECK.initialize();
	   IDCHECK.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())


	   // 2nd Queue - 1st station metal detector
	   MM1_Queue    MetalDetector1;
	   MetalDetector1.set_file_names("MetalDetector1_log.txt", "MetalDetector1_wait.txt", "MetalDetector1_service.txt");
	   MetalDetector1.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   MetalDetector1.set_mu(20);
	   MetalDetector1.autogenerate_new_arrivals(false);
	   MetalDetector1.initialize();
	   MetalDetector1.set_seed(rd(), rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())


	   //3rd Queue - 2nd station metal detector
	   MM1_Queue    MetalDetector2;
	   MetalDetector2.set_file_names("MetalDetector2_log.txt", "MetalDetector2_wait.txt", "MetalDetector2_service.txt");
	   MetalDetector2.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   MetalDetector2.set_mu(20);
	   MetalDetector1.autogenerate_new_arrivals(false);
	   MetalDetector2.initialize();
	   MetalDetector2.set_seed(rd(), rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   //4th Queue - 3rd station metal detector
	   MM1_Queue    MetalDetector3;
	   MetalDetector3.set_file_names("MetalDetector3_log.txt", "MetalDetector3_wait.txt", "MetalDetector3_service.txt");
	   MetalDetector3.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   MetalDetector3.set_mu(20);
	   MetalDetector3.initialize();
	   MetalDetector1.autogenerate_new_arrivals(false);
	   MetalDetector3.set_seed(rd(), rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   //5th Queue - Boarding
	   MM1_Queue    Boarding;
	   Boarding.set_file_names("Boarding_log.txt", "Boarding_wait.txt", "Boarding_service.txt");
	   Boarding.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Boarding.set_mu(80);
	   Boarding.autogenerate_new_arrivals(false);
	   Boarding.initialize();
	   Boarding.set_seed(rd(), rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())



~~~



* **(b) - 4pts:** You want to add a check that your process is within an error range *is_within_error_range(float)* where the error range will be 0.002. You also want to process the next event, and add an external arrival where marked.

~~~
Completed in queues main.cpp file.

   std::cout << std::endl;

	   std::cout << "IDCheck is within CI:" << IDCHECK.is_within_confidence_interval() << endl;
	   std::cout << "MetalDetector_1 is within CI:" << MetalDetector1.is_within_confidence_interval() << endl;
	   std::cout << "MetalDetector_2 is within CI:" << MetalDetector2.is_within_confidence_interval() << endl;
	   std::cout << "MetalDetector_3 is within CI:" << MetalDetector3.is_within_confidence_interval() << endl;
	   std::cout << "Boarding is within CI:" << Boarding.is_within_confidence_interval() << endl;

	   std::cout << "IDCheck is in error range:" << !IDCHECK.is_within_error_range(0.002) << endl;
	   std::cout << "MetalDetector_1 is in error range:" << !MetalDetector1.is_within_error_range(0.002) << endl;
	   std::cout << "MetalDetector_2 is in error range:" << !MetalDetector2.is_within_error_range(0.002) << endl;
	   std::cout << "MetalDetector_3 is in error range:" << !MetalDetector3.is_within_error_range(0.002) << endl;
	   std::cout << "Boarding is in error range:" << !Boarding.is_within_error_range(0.002) << endl;

	   std::cout << std::endl;
	   for (;
		   //TODO: add is_within_error_range check
		   !IDCHECK.is_within_error_range(0.002) ||
		   !MetalDetector1.is_within_error_range(0.002) ||
		   !MetalDetector2.is_within_error_range(0.002) ||
		   !MetalDetector3.is_within_error_range(0.002) ||
		   !Boarding.is_within_error_range(0.002)
		   ;)
	   {

		   Customer cust = IDCHECK.process_next_event();    // =  TODO: process next event;
		   Customer cust2 = MetalDetector1.process_next_event();   // =  TODO: process next event;
		   Customer cust3 = MetalDetector2.process_next_event();   // =  TODO: process next event;
		   Customer cust4 = MetalDetector3.process_next_event();   // =  TODO: process next event;
		   Customer cust5 = Boarding.process_next_event();   // =  TODO: process next event;
		   //TODO: one more process_next_event for the last object.


		   if (cust.get_type() == Customer::COMPLETED())
		   {
			   switch (next)
			   {
			   case 0:
				   //TODO add_external_arrival() for your security gates;
				   MetalDetector1.add_external_arrival();

				   break;
			   case 1:
				   //TODO add_external_arrival() for your security gates;
				   MetalDetector2.add_external_arrival();
				   break;
			   case 2:
				   //TODO add_external_arrival() for your security gates;
				   MetalDetector3.add_external_arrival();
				   break;
			   }
			   next++;
			   if (next % 3 == 0) next = 0;
		   }
		   if (cust2.get_type() == Customer::COMPLETED() || cust3.get_type() == Customer::COMPLETED() || cust4.get_type() == Customer::COMPLETED())
		   {
			   //TODO add_external_arrival(); on your final boarding MM1_Queue object
			   Boarding.add_external_arrival();
		   }
	   }

~~~

~~~
Output of these Checks:
IDCheck is within CI:0
MetalDetector_1 is within CI:0
MetalDetector_2 is within CI:0
MetalDetector_3 is within CI:0
Boarding is within CI:0
IDCheck is in error range:1
MetalDetector_1 is in error range:1
MetalDetector_2 is in error range:1
MetalDetector_3 is in error range:1
Boarding is in error range:1

~~~




* **(c) - 3pts:** in *mm1_queue.cpp* : add code to caculate the expected results for: 
  *  expected_server_utilization 
  *    expected idle prob
  *   expected queue length 
  *  expected number customers 
  * expected waiting time
  * expected response time 

~~~
Completed in mm1_queue.cpp

      expected_server_utilization_ = (lambda_/mu_); 
      expected_idle_prob_ = 1.0 - expected_server_utilization_;
      expected_queue_length_ = ((expected_server_utilization_* expected_server_utilization_)/(expected_idle_prob_));
      expected_number_customers_ = expected_server_utilization_ / expected_idle_prob_;
      expected_waiting_time_ = expected_server_utilization_*expected_idle_prob_* (1/expected_idle_prob_* expected_idle_prob_);
      expected_response_time_ = 1.0 / (mu_ - lambda_);

~~~

  
*  **(d) - 4pts:** Write code to call the functions to output and generate data from the airport senario. Plot and analyze the useful statistics/results in the program of your choice.  (Hint -  basically call  *.output();* on the MM1_Queue objects you create. Hint2 - two other use functions are *get_current_time()* and  *plot_results_output()* call intially on your intial MM1_Queue object.)  

~~~
Code:
	   IDCHECK.get_current_time();
	   IDCHECK.output(); cout << "*****************" << endl;
	   IDCHECK.plot_results_output();

	   MetalDetector1.plot_results_output();
	   MetalDetector2.plot_results_output();
	   MetalDetector3.plot_results_output();
	   Boarding.plot_results_output();

	   MetalDetector1.output(); cout << "*****************" << endl;
	   MetalDetector2.output(); cout << "*****************" << endl;
	   MetalDetector3.output(); cout << "*****************" << endl;
	   Boarding.output(); cout << "*****************" << endl;

~~~

Graphs:

~~~
1) Overall

Service:
Mean - 0.0021
St Dv - 0.0086
Max - 0.1549
Min - 0
Variance - 7.4550e-05


Wait:
Mean - 0.0191
St Dv - 0.0192
Max - 0.2753
Min - 1.0000e-06
Variance - 3.6782e-04
~~~


![](images/Part3_Overall.jpg?raw=true)


~~~
2) IDCheck

Service:
Mean - 0.0022
St Dv -  0.0089
Max - 0.1658
Min - 0 
Variance - 8.0093e-05


Wait:
Mean - 0.0191
St Dv - 0.0192
Max - 0.2188
Min - 0
Variance - 3.7040e-04
~~~

![](images/Part3_IDCheck.jpg?raw=true)

~~~
3) Metal Detector 1

Service:
Mean - 0.0147
St Dv -  0.0359
Max - 0.4613
Min -  0
Variance - 0.0013


Wait:
Mean - 0.0553
St Dv - 0.0584
Max - 0.4430
Min - 7.0000e-06
Variance - 0.0034
~~~

![](images/Part3_Metal1.jpg?raw=true)

![](images/Part3_Metal1_Serv.jpg?raw=true)

![](images/Part3_Metal1_Wait.jpg?raw=true)


~~~
3) Metal Detector 2

Service: 
Mean - 0.0119
St Dv -  0.0354
Max - 1.0764
Min -  0
Variance - 0.0013


Wait:
Mean - 0.0533
St Dv - 0.0530
Max - 0.4532
Min - 0
Variance - 0.0028
~~~

![](images/Part3_Metal2.jpg?raw=true)

![](images/Part3_Metal2_Serv.jpg?raw=true)

![](images/Part3_Metal2_Wait.jpg?raw=true)


~~~
3) Metal Detector 3

Service: 
Mean - 0.0170
St Dv - 0.0395
Max - 0.3721
Min -  0
Variance - 0.0016
 

Wait:
Mean - 0.0571
St Dv - 0.0596
Max - 0.5407
Min - 3.2000e-05
Variance - 0.0036
~~~

![](images/Part3_Metal3.jpg?raw=true)

![](images/Part3_Metal3_Serv.jpg?raw=true)

![](images/Part3_Metal3_Wait.jpg?raw=true)

~~~
3) Boarding

Service: 
Mean - 0.0065
St Dv -  0.0349
Max - 1.1860
Min -  0
Variance - 0.0012


Wait:
Mean - 0.0198
St Dv - 0.0227
Max - 0.1972
Min - 1.0000e-06
Variance - 5.1396e-04
~~~

![](images/Part3_Board.jpg?raw=true)

![](images/Part3_Board_Serv.jpg?raw=true)

![](images/Part3_Board_Wait.jpg?raw=true)





* **(e) - 15pts:** Download the personal edition of **[Anylogic](http://www.anylogic.com/)**, read through the [documentation](http://www.anylogic.com/learn-simulation) as needed, and set up the same type of simulation discussed above.

Has been difficult for me to complete. Unable to simulate setup, but was able to formulate a 2D setup for extra credit.


![](images/AnyLogic_2D.jpg?raw=true)


##Part 4 - Implementing Extra Features (10 pts)
Implementing 2 features on the extra features list. Pick any feature on the "*extra features*" list below to customize your assignment to fit your interests. Please document this in your writeup. (*Note: These should total 10pts. You could successfully implement a feature worth 10pts or greater. This also fulfills this requirement. The features are assigned points based on difficulty. The 5pt features are more straightforward.*)


~~~
Extra Features: 
1. I implemented 4 distributions (Exponential, Lognormal, Gamma, and Weibull) in addition to the 5 distributions that were required. A total of 9 distributions were used for Part 1.

2. Added 2D visualization to AnyLogic for Part 3 --- it is on the file.





~~~

##Part 5 - Final Report (10 pts)
Write up the results to the previous sections in the main *readme.md* in your forked repository. Turn in the URL for your fork in webcourses. Be visual. The report should contain the graphs and analysis requested. I have high expectations for the documentation here and you should allot the proper time to compose the writeup.


##Extra Features (Extra Credit - 25pts)
You have to implement two features from this list for Part 4. You may choose any two features you wish from this list. (Please explicitly note them in your *Readme.md*)

If you feel like going beyond the scope of the assignment, you should consider implementing more of the following extra features. *Get the assignment working without them first.* You can get a maximum of 25 points in extra credit. Simply implementing these things doesn't guarantee you a 25; you really need to go above and beyond to get the full amount. (*The instructor reserves the right to hand out extra credit as his he sees fit.*)

* **(5 Points)** - Implement and compare Halton, Hammersley, (Or another quasi method) Quasi sequences and add them to your analysis for appropriate subparts of Part 1.
* **(5 Points)** - Implement different distributions inside the Quasi random sequences and add them to your analysis for appropriate subparts of Part 1.
* **(5 Points)** - Implement and compare another (advanced) psedo random sequences and add them to your analysis for all subparts of Part 1 (Examples include: [PCG](http://www.pcg-random.org/), or [Random123](https://github.com/DEShawResearch/Random123-Boost)).
* **(20 Points)** - Complete Part 2 with a different board game. Construct the game's transition matrix, simulate the game, and analyze the results (Run the game past the instructor).
* **(20 Points)** - Complete Part 2 with a 3D version of Snakes and Ladders. Construct the game's transition matrix, simulate the game, and analyze the results.
* **(10 Points)** - Provide code in (Python, R, Matlab...) that demonstrates an animation of the board itself evolving overtime for Snakes in Ladder for part 2. 
* **(10 Points)** - Add a 2D visualization to AnyLogic for Part 3.
* **(10 Points)** - Add a 3D visualization to AnyLogic for Part 3.
* **(5 Points)** - Pick a research problem (from your dissertation, Energy Microgrids, Missle Defence...). Compare and contrast different software packages (AnyLogic, Simio, Simulu8, Arena etc). Convince me as your "manager/advisor" what advantages, weaknesses, and costs each program has. Come to a conclusion. Roughly sketch out how you would formulate the problem in the framework.
* **(10 Points)** - Create an Anylogic simulation for Part 2 - Snakes and Ladders.
* **(10 Points)** - Setup another resource allocation / queueing problem related to your research in Anylogic with a basic visualization
* **(10 Points)** - Setup up SmartGrid or a Microgrid System that creates resources of power from wind, solar, and electric grid. Set up various devices in your house to draw power. [Reference 1](http://www.sciencedirect.com/science/article/pii/S1877050916301740),   [Reference 2](http://www.tandfonline.com/doi/full/10.1080/19401493.2013.866695?src=recsys&).
* **(25 Points)** - Set up a discrete simulation of your choice that uses an approved real-time data source and visualizes the results. (See instructor for approval).
* **(N Points)** - You are welcome to make suggestions for a feature of your own choosing, but they must be approved by instructor before implementing.




References:
---
Abu-Taieh, E., & El Sheikh, A. (2007). Commercial simulation packages: a comparative study. International Journal of Simulation, 8(2), 66-76.

ClassMates: Olivia

Friend: software engineer from cisco.