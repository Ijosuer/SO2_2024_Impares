#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>


struct args{

  char* cadena; 

};


void* myFunction(void* id){

  int *thread_id = (int*)id;

  printf("Imprmiendo desde Hilo %d\n", *thread_id );
  sleep(5);
  printf("Trabajo realizado - Hilo %d\n", *thread_id );
}


int main(){

  // Declaracion
  pthread_t thread[5];

  for (int i = 0; i < 5; i++)
  {
    int *a = malloc(sizeof(int));
    *a = i;
    // Creacion de Hilos
    pthread_create(&thread[i], NULL, myFunction, (void *) a);

  }
  

  // Esperar a los Hilos
  // printf("Esperando que terminen los hilos... \n");

  for (int i = 0; i < 5; i++)
  {
    pthread_join(thread[i],NULL);
  }
  
  printf("TRABAJO TERMINADO \n");

  return 0;

}


