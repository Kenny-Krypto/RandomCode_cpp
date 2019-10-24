#include <iostream>

void Addition(double* mat1,double* mat2, double* matF,int n,int m,int x,int y){
//Initialize Vars
 int i,j;
 int LNum1,LNum2,SNum1,SNum2;
//MATRIX BOUNDS USED FOR MIX MATRIX SIZES
(x>=n?(LNum1=x):(LNum1=n)); 	   // Largest Row Number
(x>=n?(SNum1=n):(SNum1=x));	  // Smallest Row Number
(y>=m?(LNum2=y):(LNum2=m));	 // Largest Column Number
(y>=m?(SNum2=m):(SNum2=y));	// Smallest Column Number
//DEBUG:
//std::cout << "\nLN1Row:" << LNum1 << " LN2Col:" << LNum2 << " SN1Row:" << SNum1 << " SN2Col:" << SNum2 << std::endl;
//ADDITION:
for(i = 0; i<LNum1;i++){			// if i is less then the Bigger number of (n or x)
	for(j = 0; j<LNum2;j++){		// if j is less then the Bigger number of (m or y)

		if((n==x)&&(m==y)){
			matF[i*n+j] = mat1[i*n+j] + mat2[i*x+j];
		}
		else{
			if( (i < (SNum1))&&(j < SNum2) )		// while i < Smaller Limit and j < Smaller Limit
				matF[i*LNum2+j] = mat1[i*m+j] + mat2[i*y+j];	// Add into Matrix Result			
			
			else if( (i >= SNum1)&&(j < SNum2) ){ 	// while i < Larger Limit and j < Smaller Limit
				if(n > x) matF[i*LNum2+j] = mat1[i*m+j];	// If n is bigger take number from Matrix 1 (Row)
				else matF[i*LNum2+j] = mat2[i*y+j];		// If x is bigger take number from Matrix 2
			}
			
			else if( (i < SNum1)&&(j >= SNum2) ){	// while i < Smaller Limit and j < Larger Limit
				if(m > y) matF[i*LNum2+j] = mat1[i*m+j];	// If m is bigger take number from Matrix 1 (Col)
				else matF[i*LNum2+j] = mat2[i*y+j];		// If y is bigger take number from Matrix 2
			}
			else{					// while i < Larger Limit and j < Larger Limit ZERO placeholder (No change)
			
			}
		}
	}
}
//COMPLETED
}