#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>


struct args{

  char* cadena; 

};


void* myFunction(void* name){

  printf("Imprmiendo desde %s\n", (char*) name );
  sleep(5);
  printf("Trabajo realizado - %s\n", (char*) name );
}


int main(){

  // Declaracion
  pthread_t thread1, thread2;
  int err;

  // Creacion de Hilos

  pthread_create(&thread1, NULL, myFunction,"Hilo 1");
  pthread_create(&thread2, NULL, myFunction,"Hilo 2");

  // Esperar a los Hilos
  // printf("Esperando que terminen los hilos... \n");

  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);


  printf("TRABAJO TERMINADO \n");

  return 0;

}


