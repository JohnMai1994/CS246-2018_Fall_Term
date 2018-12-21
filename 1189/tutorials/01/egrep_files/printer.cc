#include <stdio.h>

int main(){
  int count;
  for(count = 0; count < 20; ++count){
    if(count % 2 == 0) fprintf(stdout,"%d\n",count);
    else fprintf(stderr,"%d\n",count);
  }

}
