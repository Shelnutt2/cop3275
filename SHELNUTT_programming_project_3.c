//Seth Shelnutt 42941969
//COP3275
//All code is released under the terms of the gpl v2 or later.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){ //initialize main with void return type.

char buf[BUFSIZ]; //create a buffer with the defined buffer size

while(1<2){ //loop incase of bad input
printf("Enter a date as mm/dd/yyyy:: "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
   int good = 0; //is input good?
   char *result = NULL; //used for seperating input
   char *garbage = NULL; //collect bad input
   char delims[] = "/"; //delimiter
   int x; //used for iterating the matrix
   int j; //used for iterating the matrix
   result = strtok( buf,delims  ); //get each input integer
   int k = 0; //count input
   while( result != NULL ) {
       if (k>15){ //check if more than 16 enters were inputer
          printf("Please enter 16 integers\n");
          good = -1;
          break;
       }
       int i = strtol( result, &garbage, 0);
       if (i == 0){ //catch invalid characters, aka non-integers
          printf("\n");
          good = -1;
          break;
       }
      // else if(i > 16 || i<1){ //make sure no integers outside 1-16 were inputed
       //   printf("Please enter only integers from 1-16\n");
         // good = -1;
         // break; 
       //}
       else{ //add integers to the 4x4 matrix
       marray[k] = i;
       result = strtok( NULL, delims );
       }
       k++;
    }
   if(k != 3){ //make sure 16 integers were inputed
      printf("please enter a proper date");
      good = -1;
   }
   if(good==0){ //if all was good display and compute data
      int day = date[0];
      int month = date[1];
      int year = date[2];
      //for(k=0;k<sizeof(date);k++){
        // day = date[0]

      //}
      if( month < 1 || month > 12 ){
         printf("Please make sure the month is between 1 and 12");
         break;
       }
      if( month == 2 ){ //February is a special month
         if( year % 4 == 0){
            if( day > 29 ){
               printf("Please make sure the day is between 1 and 29"); //Handle leap years
               break;
            }
            else{
               printf("Please make sure the day is between 1 and 28"); //Handle non leap years
               break;
            }
         }
      }
      else if( month == 1 || month == 3 || month == 5 || month  == 7 || month == 8 || month = 10 || month == 12){
         if( day > 31 || day < 1 ){
            printf("Please make sure the day is between 1 and 31");
            break;
         }
      }
      else{
         printf("Please mmake sure the day is between 1 and 30");
         break;
      }
      
      switch day {


   }
   printf("Row sums: %d %d %d %d\n", rowsum[0], rowsum[1], rowsum[2], rowsum[3]); //print output
   printf("Column sums: %d %d %d %d\n", colsum[0], colsum[1], colsum[2], colsum[3]);
   printf("Diagonal sums: %d %d\n", diagsum[0], diagsum[1]);
   break;
 }
    



return(0); //return zero value, aka indicate everything worked as expected
}
