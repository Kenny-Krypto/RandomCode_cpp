#include <iostream>
// Recursive Version
int fibR(int x)
{
if(x < 0){ // IF Negative number
	std::cout << "Why you so NEGATIVE!! (╯°□°)╯︵ ┻━┻\n";
	return 1;
}
if(x > 2){ // IF greater then 2
	std::cout << x << " ";
	return fibR(x-1) + fibR(x-2); // used recursively to calcuate the value
}
if(x == 2)  // IF Equal to 2
	return 2;
return 1;   // IF Less then 2
}
