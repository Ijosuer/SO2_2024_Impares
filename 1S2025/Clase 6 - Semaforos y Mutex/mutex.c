#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

 pthread_mutex_t lock;

 void *thread(void * arg){ //Seccion Critica

    //wait
    pthread_mutex_lock(&lock);
    printf("Inicio - %s\n",(char*)arg);
    
    sleep(4); //Simular tarea que dura mucho
    
    //Signal
    printf("Termino - %s\n",(char*)arg);
    pthread_mutex_unlock(&lock);
 }

 int main(){{

  pthread_mutex_init(&lock,NULL);

  pthread_t t1, t2;

  pthread_create(&t1,NULL, thread, "Hilo 1");
  pthread_create(&t2,NULL, thread, "Hilo 2");

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  pthread_mutex_destroy(&lock); // Liberar memoria de nuestro sistema

 }}