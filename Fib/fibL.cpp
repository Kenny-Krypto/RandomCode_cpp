#include <iostream>
//using Double since int can not contain extremely large values compared to integers
double fibL(int n)
{
double F1=1, F2=1, F3=0, t=1;
//CONDITIONS for F(0) = 1, F(1) = 1, F(2) = 2
if(n == 2) 
	return 2;
if(n == 1) 
	return 1;
if(n == 0) 
	return 1;
//No Negative allowed
if(n < 0){
	std::cout << "Why you so NEGATIVE!! (╯°□°)╯︵ ┻━┻\n No negative numbers allowed\n";
	return 1;
}
//when input is above two:
while(t < n)
{
t++; 	// is number of iterations using n as a comparator
F3 = F1 + F2; 	//F3 final number is sum of both
F2 = F1;	//F2 stores F1 for the next iteration
F1 = F3;	//F1 stores F3 for the next iteration
}
return F3; 	//Returns final number

}