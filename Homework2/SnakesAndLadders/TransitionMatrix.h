int size = 101.0;  //TODO----- 101 x 101 matrix
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);
Eigen::MatrixXf SnakesLaddersTransitionMatrix(size, size);
Eigen::VectorXf v_SnakesLadder(size);

unsigned int ROLLS = 0; //TODO

double prob = 1.0/6.0;  

//TODO


void SetTransitionMatrix()
{
	TransitionMatrix.setZero();

	//TODO

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

		//TransitionMatrix(i, i + 7) = prob;
		//TransitionMatrix(i, i + 8) = prob;
		//TransitionMatrix(i, i + 9) = prob;
		//TransitionMatrix(i, i + 10) = prob;
		//TransitionMatrix(i, i + 11) = prob;
		//TransitionMatrix(i, i + 12) = prob;
		//TransitionMatrix(i, i + 13) = prob;
		//TransitionMatrix(i, i + 14) = prob;
		//TransitionMatrix(i, i + 15) = prob;
		//TransitionMatrix(i, i + 16) = prob;
		//TransitionMatrix(i, i + 17) = prob;
		//TransitionMatrix(i, i + 18) = prob;
		//TransitionMatrix(i, i + 19) = prob;
		//TransitionMatrix(i, i + 20) = prob;
		//TransitionMatrix(i, i + 21) = prob;
		//TransitionMatrix(i, i + 22) = prob;
		//TransitionMatrix(i, i + 23) = prob;
		//TransitionMatrix(i, i + 24) = prob;
		//TransitionMatrix(i, i + 25) = prob;
		//TransitionMatrix(i, i + 26) = prob;
		//TransitionMatrix(i, i + 27) = prob;
		//TransitionMatrix(i, i + 28) = prob;
		//TransitionMatrix(i, i + 29) = prob;
		//TransitionMatrix(i, i + 30) = prob;
		//TransitionMatrix(i, i + 31) = prob;
		//TransitionMatrix(i, i + 32) = prob;
		//TransitionMatrix(i, i + 33) = prob;
		//TransitionMatrix(i, i + 34) = prob;
		//TransitionMatrix(i, i + 35) = prob;
		//TransitionMatrix(i, i + 36) = prob;
		//TransitionMatrix(i, i + 37) = prob;
		//TransitionMatrix(i, i + 38) = prob;
		//TransitionMatrix(i, i + 39) = prob;
		//TransitionMatrix(i, i + 40) = prob;
		//TransitionMatrix(i, i + 41) = prob;
		//TransitionMatrix(i, i + 42) = prob;
		//TransitionMatrix(i, i + 43) = prob;
		//TransitionMatrix(i, i + 44) = prob;
		//TransitionMatrix(i, i + 45) = prob;
		//TransitionMatrix(i, i + 46) = prob;
		//TransitionMatrix(i, i + 47) = prob;
		//TransitionMatrix(i, i + 48) = prob;
		//TransitionMatrix(i, i + 49) = prob;
		//TransitionMatrix(i, i + 50) = prob;
		//TransitionMatrix(i, i + 51) = prob;
		//TransitionMatrix(i, i + 52) = prob;
		//TransitionMatrix(i, i + 53) = prob;
		//TransitionMatrix(i, i + 54) = prob;
		//TransitionMatrix(i, i + 55) = prob;
		//TransitionMatrix(i, i + 56) = prob;
		//TransitionMatrix(i, i + 57) = prob;
		//TransitionMatrix(i, i + 58) = prob;
		//TransitionMatrix(i, i + 59) = prob;
		//TransitionMatrix(i, i + 60) = prob;
		//TransitionMatrix(i, i + 61) = prob;
		//TransitionMatrix(i, i + 62) = prob;
		//TransitionMatrix(i, i + 63) = prob;
		//TransitionMatrix(i, i + 64) = prob;
		//TransitionMatrix(i, i + 65) = prob;
		//TransitionMatrix(i, i + 66) = prob;
		//TransitionMatrix(i, i + 67) = prob;
		//TransitionMatrix(i, i + 68) = prob;
		//TransitionMatrix(i, i + 69) = prob;
		//TransitionMatrix(i, i + 70) = prob;
		//TransitionMatrix(i, i + 71) = prob;
		//TransitionMatrix(i, i + 72) = prob;
		//TransitionMatrix(i, i + 73) = prob;
		//TransitionMatrix(i, i + 74) = prob;
		//TransitionMatrix(i, i + 75) = prob;
		//TransitionMatrix(i, i + 76) = prob;
		//TransitionMatrix(i, i + 77) = prob;
		//TransitionMatrix(i, i + 78) = prob;
		//TransitionMatrix(i, i + 79) = prob;
		//TransitionMatrix(i, i + 80) = prob;
		//TransitionMatrix(i, i + 81) = prob;
		//TransitionMatrix(i, i + 82) = prob;
		//TransitionMatrix(i, i + 83) = prob;
		//TransitionMatrix(i, i + 84) = prob;
		//TransitionMatrix(i, i + 85) = prob;
		//TransitionMatrix(i, i + 86) = prob;
		//TransitionMatrix(i, i + 87) = prob;
		//TransitionMatrix(i, i + 88) = prob;
		//TransitionMatrix(i, i + 89) = prob;
		//TransitionMatrix(i, i + 90) = prob;
		//TransitionMatrix(i, i + 91) = prob;
		//TransitionMatrix(i, i + 92) = prob;
		//TransitionMatrix(i, i + 93) = prob;
		//TransitionMatrix(i, i + 94) = prob;
		//TransitionMatrix(i, i + 95) = prob;
		//TransitionMatrix(i, i + 96) = prob;
		//TransitionMatrix(i, i + 97) = prob;
		//TransitionMatrix(i, i + 98) = prob;
		//TransitionMatrix(i, i + 99) = prob;
		//TransitionMatrix(i, i + 100) = prob;
		//TransitionMatrix(i, i + 101) = prob;

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

//		std::cout << TransitionMatrix << std::endl;
//		int x;
//		std::cin >> x;
//		exit(1);
}



void SetSnakesLaddersTransitionMatrix()
{
	//SnakesLaddersTransitionMatrix.setZero();
	SnakesLaddersTransitionMatrix = TransitionMatrix;

	for (int i = 0; i < size; i++)
	{
		if (SnakesLaddersTransitionMatrix(i, 3) > 0) //ladder
		{
			SnakesLaddersTransitionMatrix(i, 3) = 0;
			SnakesLaddersTransitionMatrix(i, 19) = prob; //step into
		}

		if (SnakesLaddersTransitionMatrix(i, 15) > 0) //ladder
		{
			SnakesLaddersTransitionMatrix(i, 15) = 0;
			SnakesLaddersTransitionMatrix(i, 37) = prob; //step into
		}

		if (SnakesLaddersTransitionMatrix(i, 22) > 0) //ladder
		{
			SnakesLaddersTransitionMatrix(i, 22) = 0;
			SnakesLaddersTransitionMatrix(i, 42) = prob; //step into
		}

		if (SnakesLaddersTransitionMatrix(i, 25) > 0) //ladder
		{
			SnakesLaddersTransitionMatrix(i, 25) = 0;
			SnakesLaddersTransitionMatrix(i, 64) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 41) > 0) //ladder
		{
			SnakesLaddersTransitionMatrix(i, 41) = 0;
			SnakesLaddersTransitionMatrix(i, 73) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 53) > 0) //ladder
		{
			SnakesLaddersTransitionMatrix(i, 53) = 0;
			SnakesLaddersTransitionMatrix(i, 74) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 63) > 0) //ladder
		{
			SnakesLaddersTransitionMatrix(i, 63) = 0;
			SnakesLaddersTransitionMatrix(i, 86) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 76) > 0) //ladder
		{
			SnakesLaddersTransitionMatrix(i, 3) = 0;
			SnakesLaddersTransitionMatrix(i, 91) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 84) > 0) //ladder
		{
			SnakesLaddersTransitionMatrix(i, 84) = 0;
			SnakesLaddersTransitionMatrix(i, 98) = prob;
		}

		//~~~~~~~~~ Snakes -- numbers decrease
		if (SnakesLaddersTransitionMatrix(i, 11) > 0) // would it be > or <...
		{
			SnakesLaddersTransitionMatrix(i, 11) = 0;
			SnakesLaddersTransitionMatrix(i, 7) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 18) > 0) // would it be > or <...
		{
			SnakesLaddersTransitionMatrix(i, 18) = 0;
			SnakesLaddersTransitionMatrix(i, 13) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 28) > 0) // would it be > or <...
		{
			SnakesLaddersTransitionMatrix(i, 28) = 0;
			SnakesLaddersTransitionMatrix(i, 12) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 36) > 0) // would it be > or <...
		{
			SnakesLaddersTransitionMatrix(i, 36) = 0;
			SnakesLaddersTransitionMatrix(i, 34) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 77) > 0) // would it be > or <...
		{
			SnakesLaddersTransitionMatrix(i, 77) = 0;
			SnakesLaddersTransitionMatrix(i, 16) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 47) > 0) // would it be > or <...
		{
			SnakesLaddersTransitionMatrix(i, 47) = 0;
			SnakesLaddersTransitionMatrix(i, 26) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 83) > 0) // would it be > or <...
		{
			SnakesLaddersTransitionMatrix(i, 83) = 0;
			SnakesLaddersTransitionMatrix(i, 39) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 92) > 0) // would it be > or <...
		{
			SnakesLaddersTransitionMatrix(i, 92) = 0;
			SnakesLaddersTransitionMatrix(i, 75) = prob;
		}

		if (SnakesLaddersTransitionMatrix(i, 99) > 0) // would it be > or <...
		{
			SnakesLaddersTransitionMatrix(i, 99) = 0;
			SnakesLaddersTransitionMatrix(i, 70) = prob;
		}

	}
}
