#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  
#include <sys/wait.h>

struct args {
    int numero;
    char* cadena;
}; 

void* myFunction(void* name){

    printf("Imprimiendo desde %s\n", (char*) name);

    sleep(5);
    printf("Trabajo realizado - %s\n", (char*) name);
}

int main(){

    pthread_t thread1, thread2;
    
    pthread_create(&thread1, NULL, myFunction, "Hilo 1");
    pthread_create(&thread2, NULL, myFunction, "Hilo 2");


    printf("Esperando a los hilos...\n");

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    

    printf("Trabajo terminado\n");

    return 0;
}
