//Seth Shelnutt 42941969
//COP3275
//All code is released under the terms of the gpl v2 or later.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int fgcd(int a, int b){ //function to find gcd
   int larger =  ( a > b ) ? a : b ; //determine which input is alrger
   int smaller = ( a < b ) ? a : b ; //determine which input is smaller
   int temp = -1; //temp value holder
   while(temp != 0){ //while Euler condition is not met
      temp = larger % smaller; //Use modulous division to find remainer
      if(temp != 0){ //continue and swap values if gcd not found
        larger = smaller; 
        smaller = temp;
      }
   }
   return smaller;
}

int main(void){ //initialize main with void return type.

char buf[BUFSIZ]; //create a buffer with the defined buffer size

while(1<2){ //loop incase of bad input
printf("Enter a fraction of natural numbers: "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
   int good = 0; //is input good?
   int reallygood = 0; //Does input pass second checks?
   char *result = NULL; //used for seperating input
   char *garbage = NULL; //collect bad input
   char delims[] = "/"; //delimiter
   result = strtok( buf,delims  ); //get each input integer
   int k = 0; //count input
   int fraction[2];
   while( result != NULL ) {
       if (k>1){ //check if anything beyond the date was inputed
          printf("Please enter only fraction in the form integer/interger\n");
          good = -1;
          break;
       }
       int i = strtol( result, &garbage, 10);
       if (i == 0){ //catch invalid characters, aka non-integers
          printf("Please enter only valid integers\n");
          good = -1;
          break;
       }

       else{ //add integers to the array
       fraction[k] = i;
       result = strtok( NULL, delims );
       }
       k++;
    }

   if(good==0){ //if all was good display and compute data
      if(fraction[0] < 0){
         printf("Please make sure numerator is non-negative\n");
         reallygood =  -1;
      }
      else if(fraction[1] <= 0 ){
         printf("Please make sure the denominator is greater than zero.\n");
         reallygood =  -1;
       }
      
     if(reallygood==0){
        int gcd = fgcd(fraction[0],fraction[1]); //compute gcd
        
        printf("The lowest term is: %d/%d\n",fraction[0]/gcd,fraction[1]/gcd); //print output
        break;
     }  

   }
 

  }
 }
return(0); //return zero value, aka indicate everything worked as expected
}
