#include "MatCal.h"
#include <iostream>
void InputMAT(int Row,int Col,int Condition, double* MAT){ //Creates matrix given bounds and Variable name
double Num;
//Matrix creation: Arrays of Arrays
//Input Numbers
if(Condition == 1){ //User-Input Matrix
	std::cout << "\n";
	for(int k = 0; k<Row;k++){
		for(int l = 0; l<Col;l++){
  	  		std::cout<< "Number in Position {" << k << "," << l << "}:\n"; //Position in Matrix
 	   		std::cin >> Num;
 	   		MAT[k*Col+l] = Num;
		}
	}
}

else{ // Zeroed Matrix for Resultant Matrix or Etc.
	for(int k = 0; k<Row;k++){
		for(int l = 0; l<Col;l++){
 	   		MAT[k*Col+l] = 0;
		}
	}
}
//COMPLETED
}
//~~
void DisplayMAT(double* DisMAT,int Row,int Col){ //Displays all numbers in matrix given bounds
for(int k = 0; k<Row;k++){
	for(int l = 0; l<Col;l++){
    		std::cout<< DisMAT[k*Col+l] << "\t";
	}
	std::cout<< std::endl;
}
//COMPLETED
}
//~~
void RowSwap(double* Mat1, int Row, int Col, int CRow, int TRow){ // ROW SWAP FOR SAME MATRIX CRow vs TRow 
double temp;
for(int i=0; i<Row; i++){
	temp = Mat1[CRow*Col+i];
	Mat1[CRow*Col+i] = Mat1[TRow*Col+i];
	Mat1[TRow*Col+i] = temp;
}
//COMPLETED
}