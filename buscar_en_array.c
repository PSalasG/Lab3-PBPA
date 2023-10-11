/*
 * Este código se encarga de realizar distintos tipos de búsquedas en un arreglo
 * para verificar si un número indicado por el usuario está en el arreglo.
 */

#include <stdio.h>
#include <stdbool.h> // Se usaron estos headers para utilizar el booleano true y la función de redondeo floor.
#include <math.h>

// La búsqueda lineal se realizó iterando en cada una de las entradas del arreglo y comparando con el número deseado.
int busqueda_lineal (int array[], int numero) {
	for (int i = 0; i < 6; i++) {
		if (array[i] == numero) {
			return i;
		}
	}
	return -1; // El -1 se usó en todo el código para representar cuando no se encontró el número.
}

// Para la búsqueda binaria se usó un bucle infinito que termina cuando se encuentra el número o cuando se revisó todo el arreglo y no se encontró
int busqueda_binaria (int array[], int numero) {
	int valor_min = 0;
	int valor_max = 5;

	while (true) {
		if (valor_min != valor_max) {
			int valor_medio = floor((valor_min + valor_max) / 2);
			if (array[valor_medio] == numero) {
                        	return valor_medio;
                	}

			else {
				if (array[valor_medio] < numero) {
					valor_min = valor_medio + 1;
				}

				if (array[valor_medio] > numero) {
					valor_max = valor_medio - 1;
				}
			}
        	}

		else { // Cuando se llega al caso de que el valor minimo y el maximo son iguales solo se itera en ese valor ya que sería la última opción en la búsqueda.
			if (array[valor_max] == numero) {
                                return valor_max;
              		}

			else {
				return -1;
			}
		}
	}
}

// La busqueda recursiva es parecida a la binaria solo que vuelve a invocarla funcion para cambiar el valor minimo o maximo.
int busqueda_recursiva (int array[], int numero, int min, int max) {
	int valor_medio = floor((min + max) / 2);

	if (min == max) { // Igualmente es necesario añadir un caso extra cuando solo queda un valor posible.
		if (array[valor_medio] == numero) {
			return valor_medio;
                }

                else {
                        return -1;
                }
	}

	else {
		if (array[valor_medio] == numero) {
			return valor_medio;
		}
	
		if (array[valor_medio] < numero) {
			return busqueda_recursiva(array, numero, valor_medio + 1, max);
		}

		if (array[valor_medio] > numero) {
			return busqueda_recursiva(array, numero, min, valor_medio - 1);
		}
	}
}

// En el main se invocan las funciones y se imprimen los resultados según el valor retornado por cada función.
int main () {
	int lista[] = {2, 4, 6, 23, 56, 79};
	int numero = 0;

	printf("Ingrese el número que desea buscar:\n");
	scanf("%d", &numero);

	int encontrado_lineal = busqueda_lineal(lista, numero);
	if (encontrado_lineal == -1) {
		printf("No se encontró el número en el arreglo usando búsqueda lineal.\n");
	}
	else {
		printf("El número indicado se encontró en la posición %d del arreglo usando búsqueda lineal.\n", encontrado_lineal);
	}

	int encontrado_binario = busqueda_binaria(lista, numero);
        if (encontrado_binario == -1) {
                printf("No se encontró el número en el arreglo usando búsqueda binaria.\n");
        }
        else {
                printf("El número indicado se encontró en la posición %d del arreglo usando búsqueda binaria.\n", encontrado_binario);
        }

	int encontrado_recursivo = busqueda_recursiva(lista, numero, 0, 5);
	if (encontrado_recursivo == -1) {
                printf("No se encontró el número en el arreglo usando búsqueda recursiva.\n");
        }
        else {
                printf("El número indicado se encontró en la posición %d del arreglo usando búsqueda recursiva.\n", encontrado_recursivo);
        }
}
