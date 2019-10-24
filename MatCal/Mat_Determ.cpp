#include "MatCal.h"
#include <iostream>
double Determinant(double* mat1IN,int n, int m){
//MATRIX CREATION / Var Cration 
double pivot,S1, Output = 1;
double* mat1D = new double[n*m];
double* mat1Ds = new double[n*m];
  InputMAT(n,m,0, mat1D);			// Matrix Determinant Creation
  InputMAT(n,m,0, mat1Ds);			// Matrix Determinant Storage Creation
for(int r = 0; r<n;r++){
	for(int w = 0; w<m;w++){
 	   	mat1D[r*m+w] = mat1IN[r*m+w]; 		// Stores values into Determinant Matrix
	}
}
int Chk = 0;
int SIGN = 1;
//Determinant:
for(int k = 0; k < n; k++){
	pivot = mat1D[k*m+k];
	// SWAP ROW IF PIVOT = 0
	if((pivot==0)&&(k!=(n-1))){
		for(int L = k; L<n; L++){
			pivot = mat1D[L*m+k];
			if(pivot != 0){
				RowSwap(mat1D,n,m,k,L);
				SIGN++;
				break;
			}
			if(L==(n-1)){
				Chk=1;
			}
		}
	}
	if(Chk==1){ //CHECK FOR ALL ZERO COLUMN, Determinant = 0;
		break;
	}
	// SWAP ROW END
	for(int j = 0; j < m; j++){
		mat1Ds[k*m+j] = mat1D[k*m+j];		// Saves kth Row Values
		mat1D[k*m+j] = mat1D[k*m+j]/pivot;	// Creates the Pivot divides row by Pivot
							// Pivot at position kxk
	}
	for(int i = 0; i < n; i++){
		if(i > k){
			S1 = mat1D[i*m+k];		// Stored Number 1: number below Pivot based on ith row
			for(int j = 0; j < m; j++){
				mat1D[i*m+j] = mat1D[i*m+j]-mat1D[k*m+j]*S1; 	// Multiply Kth Row with Stored Number 1
									  	// then subtract from ith row
			}
		}
	}
	for(int j = 0; j < m; j++){
		mat1D[k*m+j] = mat1Ds[k*m+j];		// REsubs stored values
	}
}
if(Chk==0){
	for(int O = 0; O < n; O++)
		Output *= mat1D[O*m+O]; 		// Output of all diagonals mulitplied together
}
else Output = 0;
if((SIGN%2)==0) Output *=-1;
//DISPLAY
std::cout << "Determinant Matrix:\n";
DisplayMAT(mat1D,n,m);

//DELETE MATRIX
 delete[] mat1D;
 delete[] mat1Ds;
//COMPLETED
return Output;
}