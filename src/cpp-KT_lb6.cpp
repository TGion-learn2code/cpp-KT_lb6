//============================================================================
// Name        : cpp-KT_lb6.cpp
// Author      : Tobias Gion <tgion>
// Version     :
// Copyright   : Your copyright notice
// Description : Karriere Tutor Übungsblatt LB6 - Guter Code, Kommentare
//============================================================================

#include <iostream>
#include <cmath>       	// fabs()
#include <vector>

using namespace std;

// 3.1
/// @brief	asks user to input a number and tells if the number is positive, negative or zero
void eingabe () {
	int eingabe;
	cout << "Bitte geben Sie eine Zahl ein: ";
	cin >> eingabe;							// user inputs valid number

	// decide whether its postitive, negative or zero
	if (eingabe > 0)
		cout << "Sie haben eine positive Zahl eingegeben.";
	else if (eingabe < 0)
		cout << "Sie haben eine negative Zahl eingegeben.";
	else
		cout << "Sie haben eine Null eingegeben.";

	cout << endl;
}

// 2.4
/// @brief	calculates the product value of given numbers
/// @param	const float zahlen[]: an array of numbers
/// @param	int anzahl: number of numbers in array			-> !!! better use array::size,
///									-> !!! if # of elements != int anzahl, we are in trouble
/// @return	float product value of all the numbers given
float produkt (const float zahlen[], int anzahl) {
	float ergebnis = 1;
	for (int i = 0; i < anzahl; ++i) {
		ergebnis *= zahlen[i];
	}
	return ergebnis;
}

// 2.4A
/// @brief	calculates the product value of given numbers
/// @param	const float zahlen[]: an array of numbers - use of vectors
/// @return	float product value of all the numbers given
float produkt_vector (vector<float> zahlen) {
	float ergebnis = 1;
	for (auto i = zahlen.begin(); i != zahlen.end(); ++i) {
		ergebnis *= *i;
	}
	return ergebnis;
}

// 2.3
/// @brief	prints the parameter to stdout
/// @param	const char *str: char array to print
/// @return	!!! no return value !!! 				-> ??? do we have to write return if void or not ???
void ausgabe (const char *str[]) {

									// ??? why use a pointer and not const char str[] ???
									// we dont have to access str to print it
	cout << str << "\n";
}

// 2.2
/// @brief	calculates the volume of x,y,z
/// @param	int x: first value
/// @param	int y: second value
/// @param	int z: third value
/// @return	int return: the product value of x*y*z
int volumen(int x, int y, int z) {

	// return the int value of the volume of x,y,z
	return x * y * z;
}

// 2.1
/// @brief 	Main function; params are arguments from programm call
/// @param	int argc: # of arguments; at least one argument (program name) is given
/// @param	const char *argv: array of arguments
/// @return	int return; 0 if succeded; !0 if aborted with error
int main (int argc, const char *argv[]) {

	int i;

	// print every program argument to stdout
	for (i = 0; i < argc; i++) {
		cout << argv[i] << "\n";
	}

	// 1.1
	const int null {0};	// Initialize constant (cannot be changed) variable null with 0

	// 1.2
	double 	e = 0.01;	// Use e to compare the following floats with fabs()
	float 	a = 1, 		// Initialize two floats with values 1 and 2
		b = 2;

	if (fabs(a - b) < e) {	// Check whether absolute difference of (a - b) is < e
				// If true: we can assume a and b are the same value
				// If false: they are different values

		cout << a << " == " << b << endl;	// cout a and b are the same value

	} else {

		cout << a << " != " << b << endl;	// cout a and b are NOT the same value

	}

	// 1.3
	int sum = 0;
	for (i = 0; i < 100; i++) {		// Add up all numbers from 0 to 99 and save it in sum
		sum += i;
	}

	// 1.4
	unsigned u = 1;			// Initialize unsigned (integer ???) with 1
	u = UINT32_MAX - u;		// Set value for u = UINT32_MAX - 1
	i = u + 1u;			// Initialize integer i with (UINT32_MAX - 1) + 1, which is for some reason -1 ???
	cout << i << endl;

	/*
	cout << "UINT32_MAX " << UINT32_MAX << endl;
	cout << "u " << u << endl;
	cout << "1u " << 1u << endl;
	*/

	// 1.5
	float f;			// Initialize float f
	float *z = &f;			// Initialize float point *z with address of &f
	*z = 3.3;			// Set value of pointer *z to 3.3 -> sets value of f to 3.3
	cout << f << endl;

	// 1.6
	int o = INT32_MAX + 1;		// Initialize integer o with value of INT32_MAX + 1
					// which means we will get an overflow
	cout << o << endl;

	// 1.7
	// Nothing to do!

	// 2.4
	float result;
	float arrNumbers[3] = {1, 2, 3};

	result = produkt(arrNumbers, 3);
	cout << "Produkt - array: ";
	cout << result;
	cout << endl;

	// 2.4A - better solution with vector
	result = produkt_vector({1, 2, 3});		// call function with an array of numbers, size is calculated internally
							// so user errors are unlikely
	cout << "Produkt - vector: ";
	cout << result;
	cout << endl;

	return 0;
}
