int size = 101.0;  //TODO----- 101 x 101 matrix
Eigen::MatrixXf TransitionMatrix(size, size);
Eigen::VectorXf v(size);
//Eigen::MatrixXf ModifyTransitionMatrix(size, size);


unsigned int ROLLS = 0; //TODO

double prob = (1.0/6.0);  


void SetTransitionMatrix()
{
	TransitionMatrix.setZero();

	//TODO

	for (int i = 0; i < TransitionMatrix.rows() - 6; i++)
	{

		TransitionMatrix(i, i + 1) = prob;
		TransitionMatrix(i, i + 2) = prob;
		TransitionMatrix(i, i + 3) = prob;
		TransitionMatrix(i, i + 4) = prob;
		TransitionMatrix(i, i + 5) = prob;
		TransitionMatrix(i, i + 6) = prob;
	}
//
//		//TransitionMatrix(i, i + 7) = prob;
//		//TransitionMatrix(i, i + 8) = prob;
//		//TransitionMatrix(i, i + 9) = prob;
//		//TransitionMatrix(i, i + 10) = prob;
//		//TransitionMatrix(i, i + 11) = prob;
//		//TransitionMatrix(i, i + 12) = prob;
//		//TransitionMatrix(i, i + 13) = prob;
//		//TransitionMatrix(i, i + 14) = prob;
//		//TransitionMatrix(i, i + 15) = prob;
//		//TransitionMatrix(i, i + 16) = prob;
//		//TransitionMatrix(i, i + 17) = prob;
//		//TransitionMatrix(i, i + 18) = prob;
//		//TransitionMatrix(i, i + 19) = prob;
//		//TransitionMatrix(i, i + 20) = prob;
//		//TransitionMatrix(i, i + 21) = prob;
//		//TransitionMatrix(i, i + 22) = prob;
//		//TransitionMatrix(i, i + 23) = prob;
//		//TransitionMatrix(i, i + 24) = prob;
//		//TransitionMatrix(i, i + 25) = prob;
//		//TransitionMatrix(i, i + 26) = prob;
//		//TransitionMatrix(i, i + 27) = prob;
//		//TransitionMatrix(i, i + 28) = prob;
//		//TransitionMatrix(i, i + 29) = prob;
//		//TransitionMatrix(i, i + 30) = prob;
//		//TransitionMatrix(i, i + 31) = prob;
//		//TransitionMatrix(i, i + 32) = prob;
//		//TransitionMatrix(i, i + 33) = prob;
//		//TransitionMatrix(i, i + 34) = prob;
//		//TransitionMatrix(i, i + 35) = prob;
//		//TransitionMatrix(i, i + 36) = prob;
//		//TransitionMatrix(i, i + 37) = prob;
//		//TransitionMatrix(i, i + 38) = prob;
//		//TransitionMatrix(i, i + 39) = prob;
//		//TransitionMatrix(i, i + 40) = prob;
//		//TransitionMatrix(i, i + 41) = prob;
//		//TransitionMatrix(i, i + 42) = prob;
//		//TransitionMatrix(i, i + 43) = prob;
//		//TransitionMatrix(i, i + 44) = prob;
//		//TransitionMatrix(i, i + 45) = prob;
//		//TransitionMatrix(i, i + 46) = prob;
//		//TransitionMatrix(i, i + 47) = prob;
//		//TransitionMatrix(i, i + 48) = prob;
//		//TransitionMatrix(i, i + 49) = prob;
//		//TransitionMatrix(i, i + 50) = prob;
//		//TransitionMatrix(i, i + 51) = prob;
//		//TransitionMatrix(i, i + 52) = prob;
//		//TransitionMatrix(i, i + 53) = prob;
//		//TransitionMatrix(i, i + 54) = prob;
//		//TransitionMatrix(i, i + 55) = prob;
//		//TransitionMatrix(i, i + 56) = prob;
//		//TransitionMatrix(i, i + 57) = prob;
//		//TransitionMatrix(i, i + 58) = prob;
//		//TransitionMatrix(i, i + 59) = prob;
//		//TransitionMatrix(i, i + 60) = prob;
//		//TransitionMatrix(i, i + 61) = prob;
//		//TransitionMatrix(i, i + 62) = prob;
//		//TransitionMatrix(i, i + 63) = prob;
//		//TransitionMatrix(i, i + 64) = prob;
//		//TransitionMatrix(i, i + 65) = prob;
//		//TransitionMatrix(i, i + 66) = prob;
//		//TransitionMatrix(i, i + 67) = prob;
//		//TransitionMatrix(i, i + 68) = prob;
//		//TransitionMatrix(i, i + 69) = prob;
//		//TransitionMatrix(i, i + 70) = prob;
//		//TransitionMatrix(i, i + 71) = prob;
//		//TransitionMatrix(i, i + 72) = prob;
//		//TransitionMatrix(i, i + 73) = prob;
//		//TransitionMatrix(i, i + 74) = prob;
//		//TransitionMatrix(i, i + 75) = prob;
//		//TransitionMatrix(i, i + 76) = prob;
//		//TransitionMatrix(i, i + 77) = prob;
//		//TransitionMatrix(i, i + 78) = prob;
//		//TransitionMatrix(i, i + 79) = prob;
//		//TransitionMatrix(i, i + 80) = prob;
//		//TransitionMatrix(i, i + 81) = prob;
//		//TransitionMatrix(i, i + 82) = prob;
//		//TransitionMatrix(i, i + 83) = prob;
//		//TransitionMatrix(i, i + 84) = prob;
//		//TransitionMatrix(i, i + 85) = prob;
//		//TransitionMatrix(i, i + 86) = prob;
//		//TransitionMatrix(i, i + 87) = prob;
//		//TransitionMatrix(i, i + 88) = prob;
//		//TransitionMatrix(i, i + 89) = prob;
//		//TransitionMatrix(i, i + 90) = prob;
//		//TransitionMatrix(i, i + 91) = prob;
//		//TransitionMatrix(i, i + 92) = prob;
//		//TransitionMatrix(i, i + 93) = prob;
//		//TransitionMatrix(i, i + 94) = prob;
//		//TransitionMatrix(i, i + 95) = prob;
//		//TransitionMatrix(i, i + 96) = prob;
//		//TransitionMatrix(i, i + 97) = prob;
//		//TransitionMatrix(i, i + 98) = prob;
//		//TransitionMatrix(i, i + 99) = prob;
//		//TransitionMatrix(i, i + 100) = prob;
//		//TransitionMatrix(i, i + 101) = prob;
//
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



void ModifyTransitionMatrix() {

	TransitionMatrix(0, 3) = 0;
	TransitionMatrix(1, 3) = 0;
	TransitionMatrix(2, 3) = 0;
	TransitionMatrix(0, 19) = prob;
	TransitionMatrix(1, 19) = prob;
	TransitionMatrix(2, 19) = prob;

	TransitionMatrix(9, 15) = 0;
	TransitionMatrix(9, 37) = prob;
	TransitionMatrix(10, 15) = 0;
	TransitionMatrix(10, 37) = prob;
	TransitionMatrix(11, 15) = 0;
	TransitionMatrix(11, 37) = prob;
	TransitionMatrix(12, 15) = 0;
	TransitionMatrix(12, 37) = prob;
	TransitionMatrix(13, 15) = 0;
	TransitionMatrix(13, 37) = prob;
	TransitionMatrix(14, 15) = 0;
	TransitionMatrix(14, 37) = prob;

	TransitionMatrix(16, 22) = 0;
	TransitionMatrix(16, 42) = prob;
	TransitionMatrix(17, 22) = 0;
	TransitionMatrix(17, 42) = prob;
	TransitionMatrix(18, 22) = 0;
	TransitionMatrix(18, 42) = prob;
	TransitionMatrix(19, 22) = 0;
	TransitionMatrix(19, 42) = prob;
	TransitionMatrix(20, 22) = 0;
	TransitionMatrix(20, 42) = prob;
	TransitionMatrix(21, 22) = 0;
	TransitionMatrix(21, 42) = prob;

	TransitionMatrix(19, 25) = 0;
	TransitionMatrix(19, 64) = prob;
	TransitionMatrix(20, 25) = 0;
	TransitionMatrix(20, 64) = prob;
	TransitionMatrix(21, 25) = 0;
	TransitionMatrix(21, 64) = prob;
	TransitionMatrix(22, 25) = 0;
	TransitionMatrix(22, 64) = prob;
	TransitionMatrix(23, 25) = 0;
	TransitionMatrix(23, 64) = prob;
	TransitionMatrix(24, 25) = 0;
	TransitionMatrix(24, 64) = prob;


	TransitionMatrix(36, 41) = 0;
	TransitionMatrix(36, 74) = prob;
	TransitionMatrix(37, 41) = 0;
	TransitionMatrix(37, 74) = prob;
	TransitionMatrix(38, 41) = 0;
	TransitionMatrix(38, 74) = prob;
	TransitionMatrix(39, 41) = 0;
	TransitionMatrix(39, 74) = prob;
	TransitionMatrix(40, 41) = 0;
	TransitionMatrix(40, 74) = prob;
	TransitionMatrix(41, 41) = 0;
	TransitionMatrix(41, 74) = prob;

	TransitionMatrix(47, 53) = 0;
	TransitionMatrix(47, 74) = prob;
	TransitionMatrix(48, 53) = 0;
	TransitionMatrix(48, 74) = prob;
	TransitionMatrix(49, 53) = 0;
	TransitionMatrix(49, 74) = prob;
	TransitionMatrix(50, 53) = 0;
	TransitionMatrix(50, 74) = prob;
	TransitionMatrix(51, 53) = 0;
	TransitionMatrix(51, 74) = prob;
	TransitionMatrix(52, 53) = 0;
	TransitionMatrix(52, 74) = prob;

	TransitionMatrix(58, 63) = 0;
	TransitionMatrix(58, 86) = prob;
	TransitionMatrix(59, 63) = 0;
	TransitionMatrix(59, 86) = prob;
	TransitionMatrix(60, 63) = 0;
	TransitionMatrix(60, 86) = prob;
	TransitionMatrix(61, 63) = 0;
	TransitionMatrix(61, 86) = prob;
	TransitionMatrix(62, 63) = 0;
	TransitionMatrix(62, 86) = prob;
	TransitionMatrix(63, 63) = 0;
	TransitionMatrix(63, 86) = prob;

	TransitionMatrix(70, 76) = 0;
	TransitionMatrix(70, 91) = prob;
	TransitionMatrix(71, 76) = 0;
	TransitionMatrix(71, 91) = prob;
	TransitionMatrix(72, 76) = 0;
	TransitionMatrix(72, 91) = prob;
	TransitionMatrix(73, 76) = 0;
	TransitionMatrix(73, 91) = prob;
	TransitionMatrix(74, 76) = 0;
	TransitionMatrix(74, 91) = prob;
	TransitionMatrix(75, 76) = 0;
	TransitionMatrix(75, 91) = prob;

	TransitionMatrix(78, 84) = 0;
	TransitionMatrix(78, 98) = prob;
	TransitionMatrix(79, 84) = 0;
	TransitionMatrix(79, 98) = prob;
	TransitionMatrix(80, 84) = 0;
	TransitionMatrix(80, 98) = prob;
	TransitionMatrix(81, 84) = 0;
	TransitionMatrix(81, 98) = prob;
	TransitionMatrix(82, 84) = 0;
	TransitionMatrix(82, 98) = prob;
	TransitionMatrix(83, 84) = 0;
	TransitionMatrix(83, 98) = prob;

	TransitionMatrix(5, 11) = 0;
	TransitionMatrix(5, 7) = prob * 2;
	TransitionMatrix(6, 11) = 0;
	TransitionMatrix(6, 7) = prob * 2;
	TransitionMatrix(7, 11) = 0;
	TransitionMatrix(7, 7) = prob;
	TransitionMatrix(8, 11) = 0;
	TransitionMatrix(8, 7) = prob;
	TransitionMatrix(9, 11) = 0;
	TransitionMatrix(9, 7) = prob;
	TransitionMatrix(10, 11) = 0;
	TransitionMatrix(10, 7) = prob;

	TransitionMatrix(12, 18) = 0;
	TransitionMatrix(12, 13) = prob * 2;
	TransitionMatrix(13, 18) = 0;
	TransitionMatrix(13, 13) = prob;
	TransitionMatrix(14, 18) = 0;
	TransitionMatrix(14, 13) = prob;
	TransitionMatrix(15, 18) = 0;
	TransitionMatrix(15, 13) = prob;
	TransitionMatrix(16, 18) = 0;
	TransitionMatrix(16, 13) = prob;
	TransitionMatrix(17, 18) = 0;
	TransitionMatrix(17, 13) = prob;

	TransitionMatrix(22, 28) = 0;
	TransitionMatrix(22, 12) = prob;
	TransitionMatrix(23, 28) = 0;
	TransitionMatrix(23, 12) = prob;
	TransitionMatrix(24, 28) = 0;
	TransitionMatrix(24, 12) = prob;
	TransitionMatrix(25, 28) = 0;
	TransitionMatrix(25, 12) = prob;
	TransitionMatrix(26, 28) = 0;
	TransitionMatrix(26, 12) = prob;
	TransitionMatrix(27, 28) = 0;
	TransitionMatrix(27, 12) = prob;

	TransitionMatrix(30, 36) = 0;
	TransitionMatrix(30, 34) = prob * prob;
	TransitionMatrix(31, 36) = 0;
	TransitionMatrix(31, 34) = prob * prob;
	TransitionMatrix(32, 36) = 0;
	TransitionMatrix(32, 34) = prob * prob;
	TransitionMatrix(33, 36) = 0;
	TransitionMatrix(33, 34) = prob * prob;
	TransitionMatrix(34, 36) = 0;
	TransitionMatrix(34, 34) = prob;
	TransitionMatrix(35, 36) = 0;
	TransitionMatrix(35, 34) = prob;

	TransitionMatrix(71, 77) = 0;
	TransitionMatrix(71, 16) = prob;
	TransitionMatrix(72, 77) = 0;
	TransitionMatrix(72, 16) = prob;
	TransitionMatrix(73, 77) = 0;
	TransitionMatrix(73, 16) = prob;
	TransitionMatrix(74, 77) = 0;
	TransitionMatrix(74, 16) = prob;
	TransitionMatrix(75, 77) = 0;
	TransitionMatrix(75, 16) = prob;
	TransitionMatrix(76, 77) = 0;
	TransitionMatrix(76, 16) = prob;


	TransitionMatrix(41, 47) = 0;
	TransitionMatrix(41, 26) = prob;
	TransitionMatrix(42, 47) = 0;
	TransitionMatrix(42, 26) = prob;
	TransitionMatrix(43, 47) = 0;
	TransitionMatrix(43, 26) = prob;
	TransitionMatrix(44, 47) = 0;
	TransitionMatrix(44, 26) = prob;
	TransitionMatrix(45, 47) = 0;
	TransitionMatrix(45, 26) = prob;
	TransitionMatrix(46, 47) = 0;
	TransitionMatrix(46, 26) = prob;


	TransitionMatrix(77, 83) = 0;
	TransitionMatrix(77, 39) = prob;
	TransitionMatrix(78, 83) = 0;
	TransitionMatrix(78, 39) = prob;
	TransitionMatrix(79, 83) = 0;
	TransitionMatrix(79, 39) = prob;
	TransitionMatrix(80, 83) = 0;
	TransitionMatrix(80, 39) = prob;
	TransitionMatrix(81, 83) = 0;
	TransitionMatrix(81, 39) = prob;
	TransitionMatrix(82, 83) = 0;
	TransitionMatrix(82, 39) = prob;


	TransitionMatrix(86, 92) = 0;
	TransitionMatrix(86, 75) = prob;
	TransitionMatrix(87, 92) = 0;
	TransitionMatrix(87, 75) = prob;
	TransitionMatrix(88, 92) = 0;
	TransitionMatrix(88, 75) = prob;
	TransitionMatrix(89, 92) = 0;
	TransitionMatrix(89, 75) = prob;
	TransitionMatrix(90, 92) = 0;
	TransitionMatrix(90, 75) = prob;
	TransitionMatrix(91, 92) = 0;
	TransitionMatrix(91, 75) = prob;



	TransitionMatrix(93, 99) = 0;
	TransitionMatrix(93, 70) = prob;
	TransitionMatrix(94, 99) = 0;
	TransitionMatrix(94, 70) = prob;
	TransitionMatrix(95, 99) = 0;
	TransitionMatrix(95, 70) = prob;
	TransitionMatrix(96, 99) = 0;
	TransitionMatrix(96, 70) = prob;
	TransitionMatrix(97, 99) = 0;
	TransitionMatrix(97, 70) = prob;
	TransitionMatrix(98, 99) = 0;
	TransitionMatrix(98, 70) = prob;
}