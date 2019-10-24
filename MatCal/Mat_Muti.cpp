#include "MatCal.h"

void Muliplication(double* mat1,double* mat2, double* matF,int n,int m,int x,int y,int Con1){
if(Con1 == 1){ 	//MATRIX MULT
//Initialize Vars
int k, i, j;
for( i = 0; i<n; i++){			//Mat 1 Row
	for( j = 0; j<y; j++){		//Mat 2 Col
		for( k = 0; k<x; k++){ 	//Common Ground
			matF[i*y+j] += mat1[i*m+k]*mat2[k*y+j];	//Resultant Colm Action
		}
	}
}
//COMPLETED

}else if(Con1 == 2){ //ENTRYWISE
//Initialize Vars
 int i,j;
 int LNum1,LNum2,SNum1,SNum2;
//MATRIX BOUNDS
(x>=n?(LNum1=x):(LNum1=n)); 				// Largest Row Number
(x>=n?(SNum1=n):(SNum1=x));				// Smallest Row Number
(y>=m?(LNum2=y):(LNum2=m));				// Largest Column Number
(y>=m?(SNum2=m):(SNum2=y));				// Smallest Column Number
//DEBUG:
//std::cout << "\nLN1Row:" << LNum1 << " LN2Col:" << LNum2 << " SN1Row:" << SNum1 << " SN2Col:" << SNum2 << std::endl;
//MULTPLY:
for(i = 0; i<LNum1;i++){				// if i is less then the Bigger number of (n or x)
	for(j = 0; j<LNum2;j++){			// if j is less then the Bigger number of (m or y)

		if((n==x)&&(m==y)){
			matF[i*n+j] = mat1[i*n+j] * mat2[i*x+j];
		}
		else{
			if( (i < (SNum1))&&(j < SNum2) )		// while i < Smaller Limit and j < Smaller Limit
				matF[i*LNum2+j] = mat1[i*m+j] * mat2[i*y+j];		// Add into Matrix Result			
			
			else{ 						// while i < Larger Limit OR j < Larger Limit Zero*(Mat1 or Mat2) = Zero

			}
		}
	}
}
}
//COMPLETED
}