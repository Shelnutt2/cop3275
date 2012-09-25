//Seth Shelnutt 42941969
//COP3275
//All code is released under the terms of the gpl v2 or later.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//Small function to calculate f(x)
long int fofx(long int x){
 long int yvalue = pow(x,5) - 5*pow(x,4) + 10*pow(x,3) - 10*pow(x,2) + 5*x + 1;
return yvalue;

}
int main(void){ //initialize main with void return type.

long int userx; //user inputed x
long int yval; //yvalue

char buf[BUFSIZ]; //create a buffer with the defined buffer size
char *c; //character used for checking to make sure user entered an integer



while(1<2){
printf("Please input an integer value for x: "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
    userx = strtol(buf, &c, 10); //convert to long

    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ //check to make sure user actually entered a value and that value is an integer
      yval = fofx(userx); //get y value
      printf ("The value of the polynomial for x = %ld is: %ld\n", userx,yval); //display output
      break; //exit loop
    } 
    else  {
      printf ("Please enter only an integer value\n"); //user entered and invalid integer, loop repeats.
    }
  }  
}


return(0); //return zero value, aka indicate everything worked as expected
}
