#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){

  printf("\nSoy el proceso HIJO! \n");

  // Se leer los argumentso de argv[]

  printf("Argumento 1:,%s\n", argv[1]);
  printf("Argumento 2: %s\n", argv[2]);

  // Se duerme el proceso 3 segundos

  sleep(3);
}

