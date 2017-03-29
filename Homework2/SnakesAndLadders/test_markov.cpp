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

int main() {

	SetTransitionMatrix();

	//Output Vector
	v.setZero();
	v(0) = 1.0;


	// Print Results to File
	std::ofstream myfile;
	myfile.open("markov_results.txt");


	// TODO add Markov vector - Matrix multiplication //v(k+1) = v(k) T.

	for (int j = 0; j < 20; j++) {

		v = v.transpose() * TransitionMatrix;
		for (int i = 0; i < size; i++) {   //goes through every tranisitionmatrix block
			//help from cisco buddy

			using std::setw;
			std::cout << v(i) << " , "; //aligns every iteration
			myfile << v(i) << " , ";  //this is just a sample, becareful how you print to file so you can mine useful stats
		}

		std::cout << std::endl;
		myfile << std::endl;
		myfile.close();
	}
}