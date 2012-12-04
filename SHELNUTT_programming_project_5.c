//Seth Shelnutt 42941969
//COP3275
//All code is released under the terms of the gpl v2 or later.

#include <stdio.h>
#include <stdlib.h>

void makeMagic(N){ //make magic sqaure function.
   int MagicSquare[N][N]; //Create a N by N matrix.
   int i,j,row,column;
   int offset = 0; //needed for when executing the algorithm and you encounter a element which has a number
   int offset2 = 0;
   int middle = (int)(N/2);
   int start = 0;
   for(i = 0; i < N; i++) { //Initialize matrix with negatives so we can tell if we've hit an existing element for not
      for(j = 0; j < N; j++) {
         MagicSquare[i][j] = -1;
      }

   } 
   for(i=0;i<(N*N);i++){//Loop through all numbers of square.
      row =(int)((start-i+offset)%N); //wrap around rows
      if (row != 0){ //Work around because C can't handle negative mod like python.
         row += N;
      }
      column = (int)(middle+i-offset2)%N; //wrap around columns
      if(MagicSquare[row][column] > 0){ //if we run into an exist element
         offset +=2; //go down to rows
         offset2 +=1; //Go back 1 column
         row =(int)((start-i+offset)%N); //set new row
         column = (int)(middle+i-offset2)%N; //set new column
         if (row != 0){ //Work around because C can't handle negative mod like python.
            row += N;
         }
         MagicSquare[row][column] = (i+1); //Add next value to array, i+1 because i starts at 0 not 1
      }
      else{ 
         MagicSquare[row][column] = (i+1); //Add next value to array, i+1 because i starts at 0 not 1
      }

   }
   for(i = 0; i < N; i++) { //Print Magic Square
      for(j = 0; j < N; j++) {
         printf("%3d ", MagicSquare[i][j]);
      }
      printf("\n"); //Print new line for each new row
   } 
}

int main(void){ //initialize main with void return type.

int N=1; //user inputed x


char buf[BUFSIZ]; //create a buffer with the defined buffer size
char *c; //character used for checking to make sure user entered an integer



while(1<2){
printf("Enter size of magic square: "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
    N = strtol(buf, &c, 10); //convert to long

    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ //check to make sure user actually entered a value and that value is an integer
      if(N<1 || N>15 || (N%2==0)){//Check to make sure it's odd and between 1-15.
      printf ("Please enter only an odd interger from 1-15.\n"); //user entered and invalid integer, loop repeats.
      }
      else{
         makeMagic(N); //Create Magic square

      break; //exit loop
      }
    } 
    else  {
      printf ("Please enter only an odd interger from 1-15.\n"); //user entered and invalid integer, loop repeats.
    }
  }  
}


return(0); //return zero value, aka indicate everything worked as expected
}
