#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>


sem_t semaforo;

void * thread(void * arg){ //Seccion critica

  //Wait
  sem_wait(&semaforo);
  printf("Inicio - %s\n", (char*)arg);
  
  sleep(4); // Puede ocurrir condiciones de carrera

  printf("Termino - %s\n", (char*)arg);
  sem_post(&semaforo);

  return;
}

int main(){

  sem_init(&semaforo,0,2);
  pthread_t threads[4];

  for (int i = 0; i < 4; i++)
  {
    char * thread_name = (char *) malloc(12*sizeof(char));
    sprintf(thread_name,"Hilo %d",i );
    pthread_create(&threads[i],NULL,thread,thread_name);

  }
  for (int i = 0; i < 4; i++)
  {
    pthread_join(threads[i],NULL);
  }
   
  sem_destroy(&semaforo);
  return 0;

}