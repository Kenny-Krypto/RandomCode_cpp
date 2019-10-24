#ifndef MAT_CAL
#define MAT_CAL
void Addition(double*,double*,double*,int,int,int,int);
void Muliplication(double*,double*,double*,int,int,int,int,int);
void MuliplicationSCAR(double*,double*,int,int,int);
double Determinant(double*,int,int);
void Transpose(double*,double*,int,int);
int Inverse(double*,double*,int,int);
void InputMAT(int,int,int, double*);
void DisplayMAT(double*, int, int);
void RowSwap(double*, int, int, int, int); 
#endif