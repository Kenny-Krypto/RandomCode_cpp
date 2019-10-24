#include "MatCal.h"

void MuliplicationSCAR(double* mat1mS,double* mat2mR,int n,int m,int x){
//SCALAR
for(int r = 0; r<n;r++){
	for(int w = 0; w<m;w++){
 	   	mat2mR[r*m+w] = mat1mS[r*m+w]*x; 	// Calulates for Resultant Matrix
	}
}
//COMPLETED
}