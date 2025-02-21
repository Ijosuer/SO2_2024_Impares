#include <stdio.h>
#include <sys/mman.h> //Libreria para el mapeo de archivos en memoria
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){

  //Abrir archivo
  const char *filepath = "/home/ijosuer/Escritorio/my_file.txt";
  int fd = open(filepath, O_RDONLY);
  if (fd < 0){
    perror("No se puede abrir el archivo");
    exit(1);
  }

  //Estructura con la informacion del archivo
  struct stat statbuf;
  int err = fstat(fd, &statbuf);
  if(err < 0){

    perror("No se pudo abrir el archivo");
    exit(1);
  }

  //Mapeo del contenido del archivo a la memoria
  char *ptr = mmap(NULL, statbuf.st_size,
               PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
  
  if (ptr == MAP_FAILED){
    perror("Mapped Failed");
    return 1;
  }

  //El archivo ya esta mapeado en memoria, se puede cerrar el descriptor
  close(fd);

  //Imprime el archivo
  printf("%s\n", (char *)ptr);

  //Eliminar el Mapeo
  err = munmap(ptr, statbuf.st_size);
  if (err != 0)
  {
    perror("Unmapped Failed");
    return 0;
  }


}

