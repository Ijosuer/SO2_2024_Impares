#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){

  pid_t pid = fork();  // Crea un proceso Padre

  if (pid == -1)
  {
    perror("Fork");
    exit(1);
  }
  if (pid)
  {
    printf("\nHola soy el proceso Padre!\n");
    
    // Se espera que el proceso hijo termine
    int status;
    wait(&status);
    
    //Imprimir el codigo del proceso hijo
    
    if (WIFEXITED(status))
    {
      printf("\nEl proceso hijo a finalizado con estado: %d\n",status);
    }else{
      printf("Ocurrio un error en el proceso hijo");
    }
  
    
    printf("Soy el padrino otra vez!");
  }else{
    // Escribir los argumentos para el proceso hijo

    char *arg_Ptr[4];
    arg_Ptr[0] = "child.c";
    arg_Ptr[1] = "Hola :D";
    arg_Ptr[2] = "Soy proceso hijo";
    arg_Ptr[3] =  NULL;

    execv("/home/ijosuer/Escritorio/Codigos/child.bin",arg_Ptr);
  }
    
}