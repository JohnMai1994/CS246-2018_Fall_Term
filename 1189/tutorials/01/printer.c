#include <stdio.h>

int main(){
  int i;
  for(i = 0; i < 20; ++i){
    if(i % 2 == 0) fprintf(stdout,"%d\n",i);
    else fprintf(stderr,"%d\n",i);
  }
}
