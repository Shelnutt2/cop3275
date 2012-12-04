//Seth Shelnutt 42941969
//COP3275
//All code is released under the terms of the gpl v2 or later.

#include <stdio.h>
#include <stdlib.h>

void makeMagic(N){
   int MagicSquare[N][N];
   int i,j,row,column;
   int middle = (int)(N/2);
   int start = 0;
   for(i=0;i<(N*N);i++){
      row =((start-i)%N); //wrap around rows
      if (row != 0){ //Work around because C can't handle negative mod like python.
         row += N;
      }
      column = (middle+i)%N; //wrap around columns
      printf("Current Values are: %d  %d   %d \n",i+1,row,column); //debug output
      MagicSquare[row][column] = (i+1);
   }
   printf("First digit is: %d\n",MagicSquare[0][1]); //print magic square
   for(i = 0; i < N; i++) {
      for(j = 0; j < N; j++) {
         printf("%3d ", MagicSquare[i][j]);
      }
      printf("\n");
   } 
}

int main(void){ //initialize main with void return type.

int N=1; //user inputed x


char buf[BUFSIZ]; //create a buffer with the defined buffer size
char *c; //character used for checking to make sure user entered an integer



while(1<2){
printf("Please input an integer value for x: "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
    N = strtol(buf, &c, 10); //convert to long

    if (buf[0] != '\n' && (*c == '\n' || *c == '\0')){ //check to make sure user actually entered a value and that value is an integer
      if(N<1 || N>15 || (N%2==0)){
      printf ("Please enter only an odd interger from 1-15.\n"); //user entered and invalid integer, loop repeats.
      }
      else{
         printf ("The value entered is: %d\n", N); //display output
         makeMagic(N);

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
