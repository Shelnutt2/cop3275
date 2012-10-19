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
printf("Enter numbers 1 - 16 in any order: "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
   int good = 0; //is input good?
   long int marray[4][4]; //4x4 matrix array
   char *result = NULL; //used for seperating input
   char *garbage = NULL; //collect bad input
   char delims[] = " "; //delimiter
   int x; //used for iterating the matrix
   int j; //used for iterating the matrix
   result = strtok( buf,delims  ); //get each input integer
   int k = 0; //count input
   while( result != NULL ) {
       if (k>15){ //check if more than 16 enters were inputed
          printf("Please enter 16 integers\n");
          good = -1;
          break;
       }
       long int i = strtol( result, &garbage, 0);
       if (i == 0){ //catch invalid characters, aka non-integers
          printf("Please enter only integers from 1-16\n");
          good = -1;
          break;
       }
       else if(i > 16 || i<1){ //make sure no integers outside 1-16 were inputed
          printf("Please enter only integers from 1-16\n");
          good = -1;
          break; 
       }
       else{ //add integers to the 4x4 matrix
       marray[k == 0 ? 0 : (int)floor((k)/4)][(k % 4)] = i;
       result = strtok( NULL, delims );
       }
       k++;
    }
   if(k != 16){ //make sure 16 integers were inputed
      printf("please enter all 16 integers from 1-16\n");
      good = -1;
   }
   if(good==0){ //if all was good display and compute data
   int colsum[4]; //create array for column sums
   int rowsum[4]; //create array for row sums
   int diagsum[2]; //create array for diagonal sums
   printf("%3ld %3ld %3ld %3ld\n",marray[0][0],marray[0][1],marray[0][2],marray[0][3]); //output matrix
   printf("%3ld %3ld %3ld %3ld\n",marray[1][0],marray[1][1],marray[1][2],marray[1][3]);
   printf("%3ld %3ld %3ld %3ld\n",marray[2][0],marray[2][1],marray[2][2],marray[2][3]);
   printf("%3ld %3ld %3ld %3ld\n",marray[3][0],marray[3][1],marray[3][2],marray[3][3]);

   for(x = 0; x < sizeof(marray)/sizeof(marray[0]);x++){ //iterate through matrix to calculate sums
      for(j = 0; j < sizeof(marray)/sizeof(marray[0]);j++){
         rowsum[x] += marray[x][j]; //add up row sums
         if(x == j){
            diagsum[0] += marray[x][j]; //add diagonals
         }

      }
      k = 4-1;
      if(k > 0){
         diagsum[1] += marray[x][k]; //add reverse diagonals
         k--;
         }
     colsum[0] += marray[x][0]; //add columns
     colsum[1] += marray[x][1];
     colsum[2] += marray[x][2];
     colsum[3] += marray[x][3];
   }
   printf("Row sums: %d %d %d %d\n", rowsum[0], rowsum[1], rowsum[2], rowsum[3]); //print output
   printf("Column sums: %d %d %d %d\n", colsum[0], colsum[1], colsum[2], colsum[3]);
   printf("Diagonal sums: %d %d\n", diagsum[0], diagsum[1]);
   break;
   }
  }  
}


return(0); //return zero value, aka indicate everything worked as expected
}
