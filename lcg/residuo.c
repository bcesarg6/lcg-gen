/* Testando o método de geração aleatória por residuo em C*/
/* Autores: Bruno Cesar, Cristofer Oswald */

#include <stdio.h>
#include <time.h>

unsigned long int seed = 1, z = 0;
unsigned long int m = 2147483647; /* M = 2^31 -1 */
unsigned long int a = 25717;
unsigned long int c = 0;

void initRand(unsigned long int n_a,
              unsigned long int n_c,
              unsigned long int n_m,
              unsigned long int n_seed){
  a = n_a;
  c = n_c;
  m = n_m;
  seed = n_seed;
  z = seed;
}

double nextRand(){
  if(!z)
    z = seed;

  z = (a * z + c) % m;

  return (double)z/(m-1);
}


int main(int arg, char** argv){
  unsigned int n_a, n_c, n_m, n_seed;
  int hist_param;
  int read, i, n = 10000;
  double random_number;
  int random_number_i;
  int hist_vec[100];

  scanf("%d", &read);

  if(read){
    scanf("%d", &n);

    scanf("%ud", &n_a);
    scanf("%ud", &n_c);
    scanf("%ud", &n_m);
    scanf("%ud", &n_seed);
    scanf("%d", &hist_param);

    initRand(n_a, n_c, n_m, n_seed);
  }

  if (hist_param){
    for (i = 0; i < 100; i++) {
      hist_vec[i] = 0;
    }
  }

  for (i = 0; i < n; i++) {
    random_number = nextRand();

    if(hist_param){
      random_number_i = random_number * 100;
      hist_vec[random_number_i]++;
    }
    else
      printf("%lf\n", random_number);
  }

  if(hist_param){
    for (i = 0; i < 100; i++) {
      printf("%d\n",hist_vec[i]);
    }
  }
}
