//Seth Shelnutt 42941969
//COP3275
//All code is released under the terms of the gpl v2 or later.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* setday2(int day){ //Function to set ones ordinal name
   char *dayc = NULL;
   printf("day given is: %d\n",day);
   switch(day){
      case 1:
         dayc = "first";
         break;
      case 2:
         dayc = "second";
         break;
      case 3:
         dayc = "third";
         break;
      case 4:
         dayc = "forth";
         break;
      case 5:
         dayc = "fifth";
         break;
      case 6:
         dayc = "sixth";
         break;
      case 7:
         dayc = "seventh";
         break;
      case 8:
         dayc = "eighth";
         break;
      case 9:
         dayc = "ninth";
         break;
   }
   return dayc;

}
int main(void){ //initialize main with void return type.

char buf[BUFSIZ]; //create a buffer with the defined buffer size

while(1<2){ //loop incase of bad input
printf("Enter a date as mm/dd/yyyy: "); //ask for user input

  if (fgets(buf, sizeof(buf), stdin) != NULL) //get user input and store in buffer
  {
   int good = 0; //is input good?
   int reallygood = 0; //Does input pass second checks?
   char *result = NULL; //used for seperating input
   char *garbage = NULL; //collect bad input
   char delims[] = "/"; //delimiter
   result = strtok( buf,delims  ); //get each input integer
   int k = 0; //count input
   int date[3];
   while( result != NULL ) {
       if (k>3){ //check if anything beyond the date was inputed
          printf("Please enter only the date\n");
          good = -1;
          break;
       }
       int i = strtol( result, &garbage, 10);
       if (i == 0){ //catch invalid characters, aka non-integers
          printf("Please enter only valid dates\n");
          good = -1;
          break;
       }

       else{ //add integers to the 4x4 matrix
       date[k] = i;
       result = strtok( NULL, delims );
       }
       k++;
    }

   if(good==0){ //if all was good display and compute data
      int day = date[1];
      int month = date[0];
      int year = date[2];

      if( month < 1 || month > 12 ){
         printf("Please make sure the month is between 1 and 12\n");
         reallygood =  -1;
       }
      if( month == 2 ){ //February is a special month
         if( year % 4 == 0){
            if( day > 29 ){
               printf("Please make sure the day is between 1 and 29\n"); //Handle leap years
               reallygood = -1;;
            }
         }
         else if( day > 28){
            printf("Please make sure the day is between 1 and 28\n"); //Handle non leap years
              reallygood = -1;
         }
      }
      else if( month == 1 || month == 3 || month == 5 || month  == 7 || month == 8 || month == 10 || month == 12){ //Check months with 31  days
         if( day > 31 || day < 1 ){
            printf("Please make sure the day is between 1 and 31\n");
            reallygood = -1;
         }
      }
      else if( day > 30 || day < 1 ){
         printf("Please make sure the day is between 1 and 30\n"); //Check months with 30 days
         reallygood =  -1;
      }
     if(reallygood==0){
        char *monthc=NULL; //Create pointer for month name
        switch(month){ //Case to set month name
           case 1:
              monthc="January";
              break;
           case 2:
              monthc="February";
              break;
           case 3:
              monthc="March";
              break;
           case 4:
              monthc="April";
              break;
           case 5:
              monthc="May";
              break;
           case 6:
              monthc="June";
              break;
           case 7:
              monthc="July";
              break;
           case 8:
              monthc="August";
              break;
           case 9:
              monthc="September";
              break;
           case 10:
              monthc="October";
              break;
           case 11:
              monthc="November";
              break;
           case 12:
              monthc="December";
              break;
        }
        char *day1c = NULL;
        char *day2c = NULL;
        switch((int)(day / 10)){    //Switch case based on 10 place for day to set ordinal number for day.       
           case 0: //Case for 1-9
              day1c="";
              day2c = setday2(day); //Get ones place day.
              break;

           case 1: //Case for 10-19
              day2c="";
              if(day == 10){
                 day1c = "tenth";
              }
              else if(day == 11){
                 day1c = "eleventh";
              }
              else if(day == 12){
                 day1c = "twelfth";
              }
              else if(day == 13){
                 day1c = "thirteenth";
              }
              else if(day == 14){
                 day1c = "fourteenth";
              }
              else if(day == 15){
                 day1c = "fifteenth";
              }
              else if(day == 16){
                 day1c = "sixteenth";
              }
              else if(day == 17){
                 day1c = "seventeenth";
              }
              else if(day == 18){
                 day1c = "eighteenth";
              }
              else if(day == 19){
                 day1c = "nineteenth";
              }
              break;

           case 2: //Case for 20-29
              if(day-20 == 0){
                 day1c = "twentieth";
                 day2c = "";
              }
              else{
              day1c="twenty ";
              day2c = setday2(day-20); //Get ones place day.
              }
              break;
           
           case 3: //Case for 30-31
              if(day-30 == 0){
                 day1c = "thirtieth";
                 day2c = "";
              }
              else{
              day1c="thirty ";
              day2c = setday2(day-30); //Get ones place day.
              }
              break;

        }
        printf("The day is: %s the %s%s %d.\n",monthc,day1c,day2c,year);
        break;
     }  

   }
 

  }
 }
return(0); //return zero value, aka indicate everything worked as expected
}
