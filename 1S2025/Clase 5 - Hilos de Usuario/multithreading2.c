#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  
#include <sys/wait.h>

struct args {
    int numero;
    char* cadena;
}; 

void* myFunction(void* id){

    int *thread_id = (int*)id;

    printf("Imprimiendo desde Hilo %d\n", *thread_id);

    sleep(5);
    
    printf("Trabajo realizado - Hilo %d\n", *thread_id);
}

int main(){

    pthread_t threads[5];
  
    for(int i = 0; i < 5; i++){ 

        int *a = malloc(sizeof(int));
        *a = i;

        pthread_create(&threads[i], NULL, myFunction, (void *) a);
    }   
    


    // printf("Esperando a los hilos...\n");

    for(int i = 0; i < 5; i++){
        pthread_join(threads[i], NULL);
    }   

    // printf("Trabajo terminado\n");

    return 0;
}
