#include "MatCal.h"

void Transpose(double* mat1,double* matT,int n,int m){
int i,j; //START
//Transpose:
for(i = 0; i < m; i++ ){
	for(j = 0; j < n; j++ ){
		matT[i*n+j]=mat1[j*m+i];
	}
}
//COMPLETED
}