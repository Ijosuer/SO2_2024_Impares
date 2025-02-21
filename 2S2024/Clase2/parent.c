#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

void main(){

  pid_t pid = fork(); //Crear un proceso Padre

    if (pid == -1)
    {
      perror("Fork");
      exit(1);
    }
  if (pid)
  {
    printf("Hola yo soy el PADRE!");

    // Se espera que el proceso hijo termine
    int status;
    wait(&status);

    // Imprimir el codigo de salida del proeceso hijo
    if(WIFEXITED(status)){
      printf("\nEl proceso hijo termino con estado: %d\n",status);

    }else{

      printf("Ocurrio un error en el proceso hijo");

    }

    printf("Terminando proceso padrino\n");

  }else{
    // Escribir los argumentos para el proceso hijo
    char *arg_Ptr[4];
    arg_Ptr[0] = "child.c";
    arg_Ptr[1] = " Hola :)";
    arg_Ptr[2] = " Soy el proceso Hijo";
    arg_Ptr[3] = NULL; //EL ultimo parametro siempre debe ser NULL


    execv("/home/ijosuer/Escritorio/Ejemplos/child.bin",arg_Ptr);

  }
  

}