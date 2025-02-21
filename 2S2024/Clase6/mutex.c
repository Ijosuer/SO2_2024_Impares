#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


pthread_mutex_t lock;

void * thread(void* arg)
{
  //Wait
  pthread_mutex_lock(&lock);

  //Simular seccion critica
  printf("Inicio - %s\n", (char*) arg);
  
  sleep(4);
  
  //Signal
  printf("Termina - %s\n", (char*) arg);
  pthread_mutex_unlock(&lock);

}


int main(){

  pthread_mutex_init(&lock, NULL); // Inicializar Mutex

  pthread_t t1,t2;

  // Crear Hilos
  pthread_create(&t1, NULL, thread, "Hilo1");
  pthread_create(&t2, NULL, thread, "Hilo2");

  // Esperar que terminen Hilos

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  pthread_mutex_destroy(&lock); // Liberar Mutex

  return 0;

}