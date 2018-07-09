/* Testando o método rand de C */
/* Autores: Bruno Cesar, Cristofer Oswald */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int i;
  int n = 10;
  time_t t;

  //srand((unsigned) time(&t));
  srand(0);

  for (i = 0; i < n; i++) {

    printf("%lf\n", (double)rand() / (RAND_MAX-1));
  }
}
