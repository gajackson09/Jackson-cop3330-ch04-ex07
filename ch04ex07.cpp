/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Gabrielle Jackson
 */

#include <iostream>
#include "std_lib_facilities.h"
using namespace std;

//declaring functions
void SimpleCalcutator(double, char, double);
bool Number(const string&);
int WordtoDigit(const string&);

int main(){
	cout <<"Simple calculator; exit with ""|""\n";

	string sentinel = "|";
	string input;

	cout <<"Type two floating point numbers followed by a binary algebraic operator, separated by white space:\n>>";
	while(getline(cin, input) && input != sentinel){
		cout <<"Type two floating point numbers followed by a binary algebraic operator, separated by white space:\n>>";
		stringstream ss(input);

		string operand1, operand2;
		char operation;

		if (ss >> operand1 >> operand2 >> operation){
			double x, y;

			// check if operand is digit or string
			if (Number(operand1)){
				x = atof(operand1.c_str());
			}
			else{
				x = WordtoDigit(operand1);

				int invalid_value = -1;
				if (x == invalid_value) {
					cout << "Name not supported!.";
				}
			}

			if (Number(operand2)){
				y = atof(operand2.c_str());
			}
			else{
				y = WordtoDigit(operand2);

				int invalid_value = -1;
				if (y == invalid_value) {
					cout <<"Name not supported!.";
				}
			}

			// calculate result
			SimpleCalcutator(x, operation, y);
		}
		else {
			cout <<"Wrong input format!\n";
		}
	}
	getchar(); 
}//end of main

//simple calutor function
void SimpleCalcutator(double first_operand, char binary_operation, double second_operand){
	if (binary_operation == '+'){
		cout <<"The sum of: "<< first_operand <<" and "<< second_operand <<" is: "<< first_operand + second_operand <<"\n";
	}
	else if (binary_operation == '-'){
		cout <<"The subtaction between: "<< first_operand <<" and "<< second_operand <<" is: "<< first_operand - second_operand <<"\n";
	}
	else if (binary_operation == '*'){
		cout <<"The multiplication between: "<< first_operand <<" and "<< second_operand <<" is: "<< first_operand * second_operand <<"\n";
	}
	else if (binary_operation == '/'){
		cout <<"The division of: "<< first_operand <<" with "<< second_operand <<" is: "<< first_operand / second_operand <<"\n";
	}
	else if (binary_operation == '%'){
		int x2, y2;
		if (int (first_operand) != first_operand){
			cout <<"First operand truncated!\n";
			x2 = int (first_operand);
		}
		else{
			x2 = first_operand;
		}

		if (int (second_operand) != second_operand){
			cout <<"Second operand truncated!\n";
			y2 = int (second_operand);
		}
		else{
			y2 = second_operand;
		}
		cout <<"The modulo of: "<< x2 <<" to "<< y2 <<" is: "<< x2 % y2 <<"\n";
	}
	else {
		cout <<"Not supported operation\n";
	}
}//end of calulator function

//number function
bool Number(const string& s){
    string::const_iterator it = s.begin();

	// stop traversal if there is a non-digit char  
    while (it != s.end() && isdigit(*it)){
		++it;
	}
    return !s.empty() && it == s.end();
}//end of number function

//wordtodigit function
int WordtoDigit(const string& number){
	vector<string> numword(10);
	numword[0] = "zero";
	numword[1] = "one";
	numword[2] = "two";
	numword[3] = "three";
	numword[4] = "four";
	numword[5] = "five";
	numword[6] = "six";
	numword[7] = "seven";
	numword[8] = "eight";
	numword[9] = "nine";

	for (unsigned int i = 0; i < numword.size(); ++i){
		if (number == numword[i]){
			return i;
		}
	}
	return -1;
}//end wordtodigit