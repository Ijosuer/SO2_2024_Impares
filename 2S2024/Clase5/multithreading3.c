#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>


struct args{

  int numero;
  char* cadena; 

};


void* myFunction(void* input){

  printf("Inicial el Hilo\n");
  printf("Cadena: %s\n", ((struct args *)input)->cadena );
  printf("Numero: %d\n", ((struct args *)input)->numero );
  sleep(5);

  printf("TRABAJO TERMINADO\n");

}


int main(){

  // Declaracion
  pthread_t thread;
  int err;
  char cadena [] = "Hola mundo";

  struct args myArgs;
  myArgs.cadena = cadena;
  myArgs.numero = 12;


  err = pthread_create(&thread, NULL, myFunction, (void *) &myArgs);

  if (err)
  {
    printf("Error al crear el hilo: %d\n", err);
    return 1;
  }
  

  pthread_join(thread,NULL);
  
  printf("Hilo Terminado \n");

  return 0;

}


