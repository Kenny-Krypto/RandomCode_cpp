#include <iostream>
/* IDEA:
I have two bounds Variables I.E. Con1 and Con2, that gets closer to the middle
as counting Var i loops but reverses when it reaches the middle.

Using this i am able to see how many thimes to decrease the output number or
increase the outputnumber via subtracting a changing Variable
*/
main(){
int Input, Con1, Int1, Con2, Int2, i, j;
std::cout << "Input a number from 1 to 1000:"
std::cin >> Input; 	// Input Number
Con1 = 0;		// Condition 1 Left Bounds for changing Input Number
Con2 = (Input*2-2);	// Condition 2 Right Bounds for changing Input Number
			// Input*2-2 because J-Loop starts at 0 and counts to Con2
if ((Input>=1) || (Input<=1000)) // Resriction
  for(i = 0; i < (Input*2-1); i++){	// 0 to Input*2-1
    Int2 = 0;	// Resets Number that subtracts Input Number

    for(j = 0; j < (Input*2-1); j++){ // 0 to Input*2-1

      if (j < Con1){
          // IF j < Left Bound Display number and 
        std::cout << (Input-Int2) << " ";	
        Int2++; // then Increase subtracting number
      }
      else if(j >= Con2){ // IF j >= Right Bound Bound Display number
        std::cout << (Input-Int2) << " "; // and
        Int2--;	    // then decrease subtracting number
      }

      else	// if theres no need to change subtracting number keep displaying
        std::cout << (Input-Int2) << " ";
    }
    std::cout << std::endl;
    if (i < Input-1){ // each loop change the bounds
      Con1++; // Move Left bound in once
      Con2--; // Move right bound in once
    }
    else{
      Con1--; // Move Left bound away once
      Con2++; // Move Left bound away once
    /
}
return 0; 
}
