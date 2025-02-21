#include <stdio.h>
#include <stdlib.h>

int size = 3;

void increment(int *p)
{
    (*p)++; // acceder o modificar el valor almacenado en esa ubicación eliminando la referencia al puntero
}

void push(int *arr, int value)
{
	// Realloc es otra forma de obtener memoria
	// Este es utilizado normalmente pare realocar un segmento de memoria, normalmente para que aumente de tamaño
    // A realloc le pasamos el puntero del segmento a realocar asi como su nuevo tamaño, en este caso, el largo de arr + 1
	int *arr2 = (int *)realloc(arr, (size + 1) * sizeof(int));
	
	// Si el nuevo puntero, arr2 no es null significa que si existia memoria sufucuente para realocar arr
    if (arr2 != NULL)
    {
        arr = arr2;
        *(arr + size) = value;
        size++;
		// Con esto logramos hacer crecer en uno arr y colocar el nuevo valor en este nuevo espacio
    }
    else
    {
        printf("Error: No se pudo re-asignar memoria\n");
    }
}

int main()
{
    int x = 42;
    int *p = &x; // inicializa un puntero  que apunte a una variable o ubicación de memoria específica

    printf("%d\n", x); // Imprime el valor, 42
    printf("%p\n", p); // Imprime el puntero
    
    *p = 12; // Usar * significa que se modifica el valor que esta en esa
			 // posicion de memoria
			 
    printf("%d\n", x);
    printf("%p\n", p);

    // ERROR - Sin el * se modifica directamente el puntero,   
    // p = 12; // En este caso 12 no es un punterto valido
    // printf("%d\n", *p);
    // printf("%p\n", p);

    printf("x = %d\n", x); // imprime x = 12
    increment(p);
    printf("x = %d\n", x); // imprime x = 13

    printf("Address: %p\n", p);
    printf("\n");

    int *arr = (int *)malloc(3 * sizeof(int)); // void *
    // Definimos el puntero arr que apunta a un bloque de memoria de 3 enteros
    // malloc devuelve un puntero a la dirección de memoria asignada
    // (int *) es un casting que convierte el puntero genérico (void *) a un puntero de tipo entero

    // int *arr = (int *)calloc(size, sizeof(int)); // void *
    // calloc define n bloques de memoria contiguos de tamaño size
    // y devuelve un puntero a la dirección de memoria asignada
	
	// Memoria asignada con malloc o calloc puede ser leida como un arreglo
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
	
	// Esto es ya que utilizar arr[i] es traducido por el compilador como *(arr + i)
	
	// En memoria al acceder a 'arr' nos colocamos al inicio del arreglo, 
	// si se esta accediendo a una direccion de memoria y se le suma un numero entero
	// no se  esta suma un numero entero al puntero, si no que se le suma la cantidad de bytes
	// del tipo del puntero, por lo que si 'arr' es un puntero tipo integer, al sumarle 1
	// se accederia al siguiente integer
	
    int *q = arr;
    printf("arr[0] = %d\nq = %p\n\n", *q, q); // prints arr[0] = 1
    q++;
    printf("arr[1] = %d\nq = %p\n\n", *q, q); // prints arr[1] = 2
    q++;
    printf("arr[2] = %d\nq = %p\n\n", *q, q); // prints arr[2] = 3
	
	// Esto tambien produce algo interesante:
	// arr[1] == 1[arr]
	// Tiene sentido, por que arr + 1 == 1 + arr. 
	
	// Entonces
	//a[i] = ∗(a+i)
    //i[a] = *(i+a)
    printf("%d = %d = %d\n", arr[1], 1[arr], *(arr + 1));
	
	
	// Usando memoria dinamica en C se puede simular un arreglo dinamico como se usaria en python
    push(arr, 4);

    int *p = arr;
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d - p = %p\n", i, *p, p);
        p++;
    }

    printf("arr[3] = %d\nq = %p\n\n", *q, q);

	
	// Siempre que se trabaja con malloc, calloc o realloc es importante liberar la memoria
    free(arr);

    return 0;
}