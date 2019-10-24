#include "MatCal.h"
#include <iostream>
int Inverse(double* mat1,double* matI,int n,int m){
//Determinant:
double Output = Determinant(mat1,n,m);
if(Output == 0){
	std::cout << "Determinant is Zero, thus inverse matrix doesn't exist.\n";
return 0;
}
if(Output == Output){}
else{
	std::cout << "Determinant is Not-a-Number, Unable to handle it, Returning to Menu.\n";
return 0;
}
//Inverse Storage and set Values and Vars:
double pivot,S1;
//Inverse:
for(int k = 0; k < n; k++){
	pivot = mat1[k*m+k];
	// SWAP ROW IF PIVOT = 0
	if((pivot==0)&&(k!=(n-1))){
		for(int L = k; L<n; L++){
			pivot = mat1[L*m+k];
			if(pivot != 0){
				RowSwap(mat1,n,m,k,L);
				RowSwap(matI,n,m,k,L);
				break;
			}
		}
	}
	// SWAP ROW END
	for(int j = 0; j < m; j++){
		mat1[k*m+j] = mat1[k*m+j]/pivot;	// Creates the Pivot divides row by Pivot
		matI[k*m+j] = matI[k*m+j]/pivot;	// Pivot at position kxk
	}
	for(int i = 0; i < n; i++){
		if(i != k){
			S1 = mat1[i*m+k];		// Stored Number 1: number above or below Pivot based on ith row
			for(int j = 0; j < m; j++){
				mat1[i*m+j] = mat1[i*m+j]-mat1[k*m+j]*S1; // Multiply Kth Row with Stored Number 1
				matI[i*m+j] = matI[i*m+j]-matI[k*m+j]*S1; // then subtract from ith row
			}
		}
	}
}
//COMPLETED
return 1;
}