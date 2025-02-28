#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){

  printf("\n Soy el proceso Hijo\n");

  // Se leen los argumentos de argv[]
  printf("Argumento 1:%s\n",argv[1]);
  printf("Argumento 2:%s\n",argv[2]);

  // Dormimos al proceso hijo

  sleep(3);
}
