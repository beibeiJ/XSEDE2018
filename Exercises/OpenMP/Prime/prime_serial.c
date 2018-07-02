# include <stdlib.h>
# include <stdio.h>

int main ( int argc, char *argv[] ){

  int n = 500000;
  int not_primes=0;
  int i,j;
  
#pragma omp parallel for private(i,j) \
firstprivate(not_primes) reduction(+: not_primes) \
schedule(dynamic)
  for ( i = 2; i <= n; i++ ){
    for ( j = 2; j < i; j++ ){
      if ( i % j == 0 ){
	not_primes++;
	break;
      }
    }
  }

  printf("Primes: %d\n", n - not_primes);

}

