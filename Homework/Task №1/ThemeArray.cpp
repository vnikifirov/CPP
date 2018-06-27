// Edited [30-12-17] by Vadim N.
// Created [undefined] by Vadim N.
/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
								TASK DESC ON ENG									    \\\
	Given an integer matrix A(15.15).Find in the matrix a minimal positive element.		\\\
	If there is no element above the main diagonal of the matrix equal to twice			\\\
	the minimum positive element of the matrix, then order the elements of the main		\\\
	diagonal in descending order.														\\\
																						\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
								   TASK DESC ON RUS									    \\\
Дана целочисленная матрица A(15.15).Найти в матрице минимальный положительный элемент.	\\\
Если над главной диагональю матрицы нет элемента, равного удвоенному минимальному		\\\
положительному элементу матрицы, то упорядочить элементы главной диагонали по убыванию.	\\\
																						\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

#include <iostream> // input /output / namespace.
#include <cstdlib> // Math rand. 

using namespace std;

// Options matrix.(Constant).
const int H = 15; // Size string.
const int W = 15; // Size row.
const int RAND_NUM = 10; // Randomly range of numbers (to num < 0 of num > 0).

						 // It's basic variables (They is global!!!).
int	matrix[H][W]; // Storage for random numbers.
int	minNum; // Blank to store min of rundom numbers.
int	resSearchMinTwice; // Blank to store a random 2x number.
int	tmp; // Need for sorting algorithm.

// Process creates a matrix.
void createMatrix() {
	for (int i(0); i < H; i++) {
		for (int j(0); j < W; j++) {
			if (rand() % 2) {
				matrix[i][j] = rand() % RAND_NUM;
			}
			else {
				matrix[i][j] = rand() % RAND_NUM * (-1);
			}
		}
	}

	return;
}

// Process search for a minimum positive number.
void seachMinNum() {
	minNum = matrix[0][0];

	for (int i(H); i > 0; i--) {
		for (int j(W); j > 0; j--) {
			if ((minNum > matrix[i][j]) && (matrix[i][j] > 0)) {
				minNum = matrix[i][j];
			}
		}
	}

	return;
}

// Process looking for a minimum positive 2x number above the main diagonal.
void searchMinTwiceNumber() {
	for (int i(0); i < H; i++) {
		for (int j(i + 1); j < W; j++) {
			if (matrix[i][j] == (minNum * 2)) {
				resSearchMinTwice = matrix[i][j];
				break;
			}
		}
	}

	return;
}

// Sort the main diagonal.
void sortingMainDiagonalElement() {
	if (!resSearchMinTwice) {
		for (int i(0); i < H; i++) {
			for (int j(H); j > i; j--) {
				if (matrix[i][i] < matrix[j][j]) {
					tmp = matrix[i][i];
					matrix[i][i] = matrix[j][j];
					matrix[j][j] = tmp;
				}
			}
		}
	}

	return;
}

// Displays a matrix on the screen.
void displayMatrixOnScreenAndInformation() {
	cout << endl << '\t' << '\t' << "The matrix" << endl << endl;

	// Display on screen the matrix.
	for (int i(0); i < H; i++) {
		for (int j(0); j < W; j++) {
			if (matrix[i][j] >= 0) {
				cout << "  " << matrix[i][j];
			}
			else {
				cout << " " << matrix[i][j];
			}
		}
		cout << endl;
	}

	cout << endl << '\t' << "Information about the template matrix:" << endl
		<< "The size of " << H << " string of " << W << " columns." << endl
		<< "The minimum positive number in the matrix is " << minNum << "." << endl
		<< "The minimum positive twice number in the matrix is " << resSearchMinTwice << "." << endl << endl;

	// Did matrix have sorted?
	if (!resSearchMinTwice) {
		cout << "The matrix was sorted." << endl << endl;
	}
	else {
		cout << "The matrix was not sorted" << endl << endl;
	}

	return;
}

// Entry point.
int main() {
	createMatrix();
	seachMinNum(); // Search for a minimum positive number.
	searchMinTwiceNumber(); // Search for a minimum positive 2x
	sortingMainDiagonalElement(); // If minimum 2x number was not found. 
	displayMatrixOnScreenAndInformation(); // Display result on the screen.

	system("pause");
	return 0;
}