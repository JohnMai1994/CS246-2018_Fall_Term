#include "stdio.h"
#include "unistd.h"



int main(int argc, char * argv[]){
   int count = 0;
   while (1){
     if ( count == 0){
       printf("ZeroCool: Hacking the Gibson!\n");
       count = 1;
     } else {
       printf("AcidBurn: Hacking the planet!\n");
       count = 0;
     }
     usleep(1000000); 
   }
   return 0;
}
