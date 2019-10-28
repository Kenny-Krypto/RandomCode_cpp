#include <iostream>
#include "fib.h"
int main()
{
//Obtain iteration position:
std::cout << "input Fibonacci Sequence Iteration:\n";
int y;
std::cin >> y;
//Find Fib number using loop method, faster.
double x = fibL(y);
//display number obtained
std::cout << x << "\n";
//END PROGRAM
return 1337;
}
