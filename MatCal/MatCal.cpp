#include <iostream>
#include "MatCal.h"
/*
Type 3 FINAL Version 5
+MULT Fixed
+Changed Float->double for matrices
+dealt with -nan, Inverse void->int condition
+INVERSE&DETERMINATE FIX when Pivot is Zero -Big Error
+disallowed addition of different size matrix (opition to reallow)
*/

int main(){
int CODE = -1;
while(CODE != 0){
	std::cout << "Matrix Menu\n";
	std::cout << "Choice 1: Addition\n";
	std::cout << "Choice 2: Subtraction\n";
	std::cout << "Choice 3: Multiplication\n";
	std::cout << "Choice 4: Determinant\n";
	std::cout << "Choice 5: Transpose\n";
	std::cout << "Choice 6: Inverse\n";
	std::cout << "Choice 0: Exit\n";
	std::cout << "Enter your choice: ";
	std::cin >> CODE;
	switch (CODE){
		case 1	:{}
		case 2	:{ 	
			if(CODE == 1)	//ADDITON
				std::cout << "Task:[Matrix 1] + [Matrix 2]\n";
			else		//SUBTRACTION
				std::cout << "Task:[Matrix 1] - [Matrix 2]\n";
			//MATRIX USER INPUT CREATION
			int n, m, x, y;
			std::cout << "Please input size of Matrix 1 Ex: '3 5' for 3x5 without the quotes:\n";
			std::cin >> n >> m;
			std::cout << "Please input size of Matrix 2 Ex: '4 5' for 4x5 without the quotes:\n";
			std::cin >> x >> y;
			if((n<0)||(m<0)||(x<0)||(y<0)){
				std::cout << "WARNING: NEGATIVE BOUNDS\nRETURNED TO MENU\n\n";
			break;
			}
			if((n!=x)||(m!=y)){
				int tempkey = -1; // bound check
				std::cout << "WARNING: Sizes of matrices does not match!\n Do you want to combine them together? 1 for yes 0 for no\n This will combine them together to a bigger matrix with Zero placeholders.\n\n";
				while((tempkey != 0)&&(tempkey != 1))
				{
				std::cin >> tempkey;
				}
				if(tempkey == 0){
					std::cout << "WARNING: MisMatch Bounds\nRETURNED TO MENU\n\n";
				break;	
				}
			}	
			//MATRIX CREATION 
			int LNum1s,LNum2s;
			(x>=n?(LNum1s=x):(LNum1s=n));
			(y>=m?(LNum2s=y):(LNum2s=m));
			double* mat1s = new double[n*m];
			double* mat2s = new double[x*y];
			double* matFs = new double[LNum1s*LNum2s];
			std::cout << "MATRIX 1:";
			 InputMAT(n,m,1, mat1s);			// Matrix 1 Creation
			std::cout << "MATRIX 2:";			
			 InputMAT(x,y,1, mat2s);			// Matrix 2 Creation
			 InputMAT(LNum1s,LNum2s,0, matFs);		// Matrix Result Creation Combined Size.	

			//Start
			if(CODE == 1)	//ADDITON
				Addition(mat1s,mat2s,matFs,n,m,x,y);
			else		//SUBTRACTION
			{
				MuliplicationSCAR(mat2s,matFs,n,m,-1); //-1*mat2
				Addition(mat1s,matFs,matFs,n,m,x,y);
			}
			//DISPLAY MATRICES
			std::cout << "Matrix 1:\n";
			DisplayMAT(mat1s,n,m);
			std::cout << "Matrix 2:\n";
			DisplayMAT(mat2s,x,y);
			
			if(CODE == 1){	//ADDITON
				std::cout << "Addtion:\n";
				if((n>0)&&(m>0)&&(x>0)&&(y>0)){
					DisplayMAT(matFs,LNum1s,LNum2s);
				}else if((n>0)&&(m>0)){
					DisplayMAT(mat1s,n,m);
				}else{
					DisplayMAT(mat2s,x,y);
				}
			}
			else{		//SUBTRACTION
				std::cout << "Subtraction:\n";
				if((n>0)&&(m>0)&&(x>0)&&(y>0)){
					DisplayMAT(matFs,LNum1s,LNum2s);
				}else if((n>0)&&(m>0)){
					DisplayMAT(mat1s,n,m);
				}else{
					MuliplicationSCAR(mat2s,matFs,LNum1s,LNum2s,-1);
					DisplayMAT(matFs,LNum1s,LNum2s);
				}
			}
			//DELETE MATRICES
				delete[] mat1s;
				delete[] mat2s;
				delete[] matFs;
			//COMPLETED
			break;
		}
		case 3	:{ 	//MULTIPLICATION
			int T;
			std::cout << "Please input:\n 1 for Scalar Multplication\n 2 for Matrix Multplication\n 3 for Entrywise Product\nChoice: ";
			std::cin >> T;
			std::cout << "\n";
			if(T==1){		//SCALAR
				std::cout << "Task: Scalar Matrix Multplication\n";
				//MATRIX USER INPUT CREATION
				int n, m, x;
				std::cout << "Please input size of Matrix Ex: '3 5' for 3x5 without the quotes:\n";
				std::cin >> n >> m;
				std::cout << "Please input scalar Multipler Ex: '4' for 4:\n";
				std::cin >> x;
				//MATRIX CREATION 
				double* mat1mS = new double[n*m]; 			// Stored Matrix
				double* mat2mR = new double[n*m]; 			// Resultant Matrix
				std::cout << "MATRIX:";
				 InputMAT(n,m,1, mat1mS);			// Matrix Creation
				//Start
				MuliplicationSCAR(mat1mS,mat2mR,n,m,x);

				//DISPLAY MATRICES
				std::cout << "Matrix:\n";
				DisplayMAT(mat1mS,n,m);
				std::cout << "Result:\n";
				DisplayMAT(mat2mR,n,m);
				//DELETE MATRICES
				 delete[] mat1mS;
				 delete[] mat2mR;
				//COMPLETED
				break;
			}else switch (T){
				case 2 : {}
				case 3 : {		
					if(T == 2)	//MATRIX MULT
						std::cout << "Task: Matrix Multplication \n(CONDITION: Number of Columns of Matrix 1 MUST equal number rows of Matrix 2)\n";
					else		//ELEMENT MULT
						std::cout << "Task: Element by Element Multplication\n";
					//MATRIX USER INPUT CREATION
					int n, m, x, y;
					std::cout << "Please input size of Matrix 1 Ex: '3 5' for 3x5 without the quotes:\n";
					std::cin >> n >> m;
					std::cout << "Please input size of Matrix 2 Ex: '4 5' for 4x5 without the quotes:\n";
					std::cin >> x >> y;
					if((n<0)||(m<0)||(x<0)||(y<0)){
						std::cout << "WARNING: NEGATIVE BOUNDS\nRETURNED TO MENU\n\n";
					break;
					}
					if(T == 2){	//MATRIX MULT
						if(m!=x){
							std::cout << "WARNING: Matrix 1's Columns doesn't equal Matrix 2's Rows.\n RETURNED TO MENU\n\n";
							break;
						}
					}else{		//ELEMENT MULT
						if((n!=x)||(m!=y)){
							std::cout << "WARNING: Sizes of matrices does not match!\n This will combine them together to a bigger matrix with Zero placeholders.\n\n";
						}
					}
					//MATRIX CREATION 
					int LNum1m,LNum2m;		
					if(T == 2){	//MATRIX MULT
						LNum1m=n;
						LNum2m=y;
					}else{		//ELEMENT MULT
						(x>=n?(LNum1m=x):(LNum1m=n));
						(y>=m?(LNum2m=y):(LNum2m=m));
					}
					double* mat1m = new double[n*m];
					double* mat2m = new double[x*y];
					double* matFm = new double[LNum1m*LNum2m];
					std::cout << "MATRIX 1:";
					 InputMAT(n,m,1, mat1m);			// Matrix 1 Creation
					std::cout << "MATRIX 2:";		
					 InputMAT(x,y,1, mat2m);			// Matrix 2 Creation		
					if(T == 2)	//MATRIX MULT
					 	InputMAT(n,y,0, matFm);			// Matrix Result Creation Combined Size.
					else		//ELEMENT MULT
					 	InputMAT(LNum1m,LNum2m,0, matFm);	// Matrix Result Creation Combined Size.

					//Start
					if(T == 2)	//MATRIX MULT
						Muliplication(mat1m,mat2m,matFm,n,m,x,y,1);
					else		//ELEMENT MULT
						Muliplication(mat1m,mat2m,matFm,n,m,x,y,2);

					//DISPLAY MATRICES
					std::cout << "Matrix 1:\n";
					DisplayMAT(mat1m,n,m);
					std::cout << "Matrix 2:\n";
					DisplayMAT(mat2m,x,y);
					std::cout << "Multiplied:\n";		
					if(T == 2)	//MATRIX MULT
					DisplayMAT(matFm,n,y);
					else		//ELEMENT MULT
					DisplayMAT(matFm,LNum1m,LNum2m);
					//DELETE MATRICES
					 delete[] mat1m;
					 delete[] mat2m;
					 delete[] matFm;
					//COMPLETED
					break;
				}
				default :{
				 	std::cout << "INVAILD INPUT: RETURNED TO MENU.\n\n";
				break;
				}
			}
			break;
		}
		case 4	:{	//DETERMINANT
			std::cout << "Task:Determinant of [Matrix]\n";
			//MATRIX USER INPUT CREATION
			int n,m;
			std::cout << "Please input size of Matrix Ex: '4 4' for 4x4 without the quotes:\nDUE TO RESTRICTIONS: only Perfect Squares Allowed.\n Warning: unable to handle Not-a-number problems.\n";
			std::cin >> n >> m;
			if((n<=0)||(m<=0)){
				std::cout << "WARNING: BOUNDS LESS THEN OR EQUAL TO ZERO\nRETURNED TO MENU\n\n";
			break;
			}
			if((n!=m)){
				std::cout << "WARNING: Sizes of matrices does not match RESTRICTIONS\n RETURNED TO MENU:\n\n";
				break;
			}
			//MATRIX CREATION 
			double* mat1D = new double[n*m];
			std::cout << "MATRIX:";
			 InputMAT(n,m,1, mat1D);			// Matrix Determinant Creation

			//START
			double Output = Determinant(mat1D,n,m);		

			//DISPLAY MATRICES
			std::cout << "Matrix:\n";
			DisplayMAT(mat1D,n,m);
			std::cout << "Determinant:\n" << Output << "\n";
			//DELETE MATRICES
			 delete[] mat1D;
			//COMPLETED
			break;
		}	
		case 5	:{	//TRANSPOSE
			std::cout << "Task:[Matrix 1] Diagnal Flip -> [Matrix 2]\n";
			//MATRIX USER INPUT CREATION
			int n,m;
			std::cout << "Please input size of Matrix Ex: '3 5' for 3x5 without the quotes:\n";
			std::cin >> n >> m;
			if((n<0)||(m<0)){
				std::cout << "WARNING: NEGATIVE BOUNDS\nRETURNED TO MENU\n\n";
			break;
			}
			//MATRIX CREATION 
			double* mat1T = new double[n*m];
			double* mat1F = new double[n*m];
			std::cout << "MATRIX:";
			 InputMAT(n,m,1, mat1T);			// Matrix Creation
			 InputMAT(m,n,0, mat1F);			// Matrix Transposed Creation
			//Start
			Transpose(mat1T,mat1F,n,m);
			//DISPLAY MATRICES
			std::cout << "Matrix:\n";
			DisplayMAT(mat1T,n,m);
			std::cout << "Transposed:\n";
			DisplayMAT(mat1F,m,n);
			//DELETE MATRICES
			 delete[] mat1T;
			 delete[] mat1F;
			//COMPLETED
			break;
		}
		case 6	:{	//INVERSE
			std::cout << "Task:Inverse of [Matrix]\n";
			//MATRIX USER INPUT CREATION
			int n,m;
			std::cout << "Please input size of Matrix Ex: '5 5' for 5x5 without the quotes:\nDUE TO RESTRICTIONS: only Perfect Squares Allowed\nWarning: unable to handle Not-a-number problems.\n";
			std::cin >> n >> m;
			if((n<=0)||(m<=0)){
				std::cout << "WARNING: BOUNDS LESS THEN OR EQUAL TO ZERO\nRETURNED TO MENU\n\n";
				break;
			}
			if((n!=m)){
				std::cout << "WARNING: Sizes of matrices does not match RESTRICTIONS\n RETURNED TO MENU:\n\n";
				break;
			}
			//MATRIX CREATION 
			double* mat1I = new double[n*m];		//matrix to be inverted
			double* mat1Is = new double[n*m];		//copy of matrix
			double* mat1Io = new double[n*m];		//Inverted matrix
			std::cout << "MATRIX:";
			 InputMAT(n,m,1, mat1I);				// Matrix Creation
			 InputMAT(n,m,0, mat1Is);				// Matrix Copy Creation
			 InputMAT(n,m,0, mat1Io);				// Matrix Inversed Creation
			//Copy Set:
			for(int k = 0; k<n;k++){
				for(int l = 0; l<m;l++){
					mat1Is[k*m+l] = mat1I[k*m+l];			// Creates copy
				}
			}
			//Inverse Set:
			for(int k = 0; k<n;k++){
				for(int l = 0; l<m;l++){
					if(k==l){
						mat1Io[k*m+l] = 1;			// Creates diagonal 1's 
					}else;
				}
			}
			//Start
			int Pass = Inverse(mat1I,mat1Io,n,m);

			//DISPLAY MATRICES
			if(Pass==1){
			std::cout << "Matrix:\n";
			DisplayMAT(mat1Is,n,m);
			std::cout << "Inverse:\n";
			DisplayMAT(mat1Io,n,m);
			}			
			//DELETE MATRICES
			 delete[] mat1I;
			 delete[] mat1Is;
			 delete[] mat1Io;
			//COMPLETE
			break;
		}
		case 0	: std::cout << "Goodbye!\n";
			break;
		default	: std::cout << "\nINVAILD CHOICE!";
		std::cout << "\n\n\n";
	}

}
return 0;
}