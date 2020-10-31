#include<stdio.h>
#include<stdlib.h>


int *sieve(int limit);

int main( int argc, char *argv[] ) {

  if (argc < 2) {
    fprintf(stderr, "Usage: main limit\n");
    exit(EXIT_FAILURE);
  }

  int limit = strtol(argv[1], NULL, 10);

  int *primes = sieve(limit);

  for (int i = 2; i < limit; i++) {
    if (primes[i] == 1) {
      printf("%d ", i);
    }
  }
  printf("\n"); 
  free(primes);
  return 0;
}

int *sieve(int limit) {

  int *primes = calloc(limit, sizeof(int));

  for (int i = 2; i < limit; i++) {
    primes[i] = 1;
  }

  for (int i = 2; i < limit; i++) {
    for (int j = 2*i; j < limit; j += i) {
      primes[j] = 0;
    }
  }

  return primes;
}
