#include <sys/mman.h>
#include <stddef.h>  // Para NULL
#include <stdio.h>   // Para printf y perror

#define ARRAY_SIZE 5

int main(){
  
  // Crea un mapeo de memoria de tamaño 5
  int *ptr = mmap ( NULL, ARRAY_SIZE*sizeof(int),
      PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0 );

  if(ptr == MAP_FAILED){
    perror("Mapping Failed");
    return 1;
  }

  // Llena el arreglo
  for(int i=0; i < ARRAY_SIZE; i++)
     ptr[i] = i*10;

  // Imprime el arreglo
  printf("Elementos: ");
  for(int i=0; i < ARRAY_SIZE; i++){
      printf("[%d] ",ptr[i]);
  }

  printf("\n");
  
  // Elimina el mapeo
  int err = munmap(ptr, 10*sizeof(int));
  if(err != 0){
     perror("UnMapping Failed");
     return 1;
  }

  return 0;
}