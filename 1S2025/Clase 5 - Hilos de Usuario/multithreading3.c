#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>  
#include <sys/wait.h>

struct args {
    int numero;
    char* cadena;
}; 

void* myFunction(void* input){

    printf("Cadena: %s\n", ((struct args*)input)->cadena);
    printf("Numero: %d\n", ((struct args*)input)->numero);

    sleep(5);
    printf("Trabajo realizado\n");
}

int main(){

    pthread_t thread;
    int err;
    char cadena[] = "Hola Mundo";

    struct args myArgs;
    myArgs.cadena = cadena;
    myArgs.numero = 24;

    err = pthread_create(&thread, NULL, myFunction, (void *) &myArgs);
    if(err){
        printf("Error al crear el hilo: %d\n", err);
        return 1;
    }

    printf("Esperando al hilo...\n");

    pthread_join(thread, NULL);

    printf("Hilo terminado\n");

    return 0;
}
