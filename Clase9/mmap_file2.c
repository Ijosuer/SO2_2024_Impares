#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
	// Abre el archivo
    const char *filepath = "/home/ijosuer/Escritorio/my_file.txt";
    int fd = open(filepath, O_RDWR);
    if(fd < 0){
        perror("Could not open file");
        exit(1);
    }
	
	// Estructura con la informacion del archivo
    struct stat statbuf;
    int err = fstat(fd, &statbuf);
    if(err < 0){
        perror("Could not open file");
        exit(2);
    }
	
	// Mapea el contenido del archivo a memoria
    char *ptr = mmap(NULL, statbuf.st_size,
            PROT_READ|PROT_WRITE, MAP_SHARED ,fd ,0);

    if(ptr == MAP_FAILED){
        perror("Mapping Failed");
        return 1;
    }
	
	// El archivo ya esta mapeado en memoria, se puede cerrar el descriptor
    close(fd);
	
	// Imprime el archivo
    printf("\nLeer archivo =>\n");
    printf("%s\n", (char *) ptr);

    // Le da vuelta al archivo, estos cambios se verán reflejados en el archivo original
    for(size_t i = 0; i < statbuf.st_size/2; i++){
        int j = statbuf.st_size - i - 1;
        int t = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = t;
    }
	
	// Imprimir el nuevo contenido
    printf("\nLeer archivo invertido =>\n");
    printf("%s\n", (char *) ptr);
	
	// Elimina el mapeo
    err = munmap(ptr, statbuf.st_size);
    if(err != 0){
         printf("UnMapping Failed\n");
         return 1;
     }
     return 0;
}