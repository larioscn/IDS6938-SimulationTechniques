#include <iostream>
#include <functional>   
#include <numeric> 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <Eigen\dense>

#include "markov.h"
#include "TransitionMatrix.h"

int main(){

	SetTransitionMatrix();

	//Output Vector
	v.setZero();
	v(0) = 1.0;
	//v(1) = 1.0*(1.0/6.0);
	//v(2) = (1.0/6.0)*(1.0/6.0);
	//v(3) = (1.0/6.0)*(1.0/6.0)*(1.0/6.0);
	//v(4) = (1.0 / 6.0)*(1.0 / 6.0)*(1.0 / 6.0)*(1.0 / 6.0);


	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");

	
   // TODO add Markov vector - Matrix multiplication //v(k+1) = v(k) T.
	v = v.transpose() * TransitionMatrix;
	
	std::cout <<  v << std::endl;
	myfile << v << std::endl;  //this is just a sample, becareful how you print to file so you can mine useful stats
	
	myfile.close();
}