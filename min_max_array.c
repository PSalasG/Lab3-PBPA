/*
 * Este código busca el número máximo y mínimo en una función sin usar punteros y usandolos.
 */

#include <stdio.h>

// Esta función itera en cada entrada para encontrar el valor máximo y lo retorna.
int buscar_max (int array[], int size, int max_local) {
	for (int i = 0; i < size; i++) {
		if (array[i] > max_local) {
			max_local = array[i];
		}
	}
	return max_local;
}

// Esta función itera en cada entrada para encontrar el valor minimo y lo retorna.
int buscar_min (int array[], int size, int min_local) {
        for (int i = 0; i < size; i++) {
                if (array[i] < min_local) {
                        min_local = array[i];
                }
        }
        return min_local;
}

// Se usó la función propuesta por la profesora y no se retorna nada.
void encontrarMinMax(int *array, int *min, int *max, int size) {
	*max = *min = *array;
	for (int i = 1; i < size; i++) {
		if (*(array + i) > *max) {
			*max = *(array + i);
		}

		if (*(array + i) < *min) {
			*min = *(array + i);
		}
	}
	printf("El valor máximo en el arreglo con punt es: %d.\n", *max);
        printf("El valor mínimo en el arreglo con punt es: %d.\n", *min);
}

// En la función main se invocan las funciones y se crean los punteros a utilizar.
int main () {
	int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
	int tamano = sizeof(arreglo) / sizeof(arreglo[0]);

	int max = arreglo[0];
	int min = arreglo[0];
	
	max = buscar_max(arreglo, tamano, max);
	min = buscar_min(arreglo, tamano, min);

	printf("El valor máximo en el arreglo es: %d.\n", max);
	printf("El valor mínimo en el arreglo es: %d.\n", min);
	
	/* int *punt_arr = &arreglo[0];
	 * int *punt_min = &min;
	 * int *punt_max = &max;
	 * encontrarMinMax(punt_arr, punt_min, punt_max, tamano);
	 */
	// En el anterior comentario se guardan las pruebas realizadas para comprobar el funcionamiento de la función con punteros.
}
