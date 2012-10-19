//Seth Shelnutt 42941969
//COP3275
//All code is released under the terms of the gpl v2 or later.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Small function to calculate f(x)

int main(void){ //initialize main with void return type.

long int userx; //user inputed x
//long int yval; //yvalue

char buf[BUFSIZ]; //create a buffer with the defined buffer size
int iarr[4][4];




while(1<2){
printf("Enter numbers 1 - 16 in any order: "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
   long int marray[4][4];
   char *result = NULL;
   char *garbage = NULL;
   char delims[] = " ";
   int x;
   result = strtok( buf,delims  );
   int k = 0;
   while( result != NULL ) {
       if (k>16){
          printf("Please enter 16 intergers\n");
          break;
       }
       long int i = strtol( result, &garbage, 0);
       if (i == 0){
          printf("Please enter only integers from 1-16\n");
          break;
       }
       else{
       printf("k is: %i\n",k);
       printf("x is: %i\n",(k % 4));
       printf("x really is: %i\n",x);
       marray[k == 0 ? 0 : (int)floor((k)/4)][(k % 4)] = i;
       result = strtok( NULL, delims );
       printf("value of marray at [%i],[%i] is %ld \n", x, (k % 4), marray[k == 0 ? 0 : (int)floor((k)/4)][(k % 4)]);
       }
       k++;
    }

   printf("%3ld %3ld %3ld %3ld\n",marray[0][0],marray[0][1],marray[0][2],marray[0][3]);
   printf("%3ld %3ld %3ld %3ld\n",marray[1][0],marray[1][1],marray[1][2],marray[1][3]);
   printf("%3ld %3ld %3ld %3ld\n",marray[2][0],marray[2][1],marray[2][2],marray[2][3]);
   printf("%3ld %3ld %3ld %3ld\n",marray[3][0],marray[3][1],marray[3][2],marray[3][3]);
   break;

  }  
}


return(0); //return zero value, aka indicate everything worked as expected
}
