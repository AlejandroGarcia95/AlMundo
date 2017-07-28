#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "archivo.h"
#include "ciudades.h"


/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */
void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}


void generar_solucion_random(solucion_t* sol, ciudad_t* ciudades_vec){
	srand(time(NULL));
	char agencias[] = {'A', 'B', 'C', 'D'};
	int i, ciudades[CANT_CIUDADES];
	for(i = 0; i < CANT_CIUDADES; i++)
		ciudades[i] = i;
		
	shuffle(ciudades, CANT_CIUDADES);
	
	for(i = 0; i < CANT_CIUDADES-1; i++){
		viaje_t v_act;
		v_act.id_ciudad_orig = ciudades[i];
		v_act.id_ciudad_dest = ciudades[i+1];
		v_act.agencia = agencias[rand() % 4];
		cargar_viaje_en_solucion(sol, &v_act);
		}
		
	viaje_t v_act;
	v_act.id_ciudad_orig = ciudades[CANT_CIUDADES-1];
	v_act.id_ciudad_dest = ciudades[0];
	v_act.agencia = agencias[rand() % 4];
	cargar_viaje_en_solucion(sol, &v_act);
	
	calcular_costo_solucion(sol, ciudades_vec);
}


int main(int argc, char **argv){
	
	ciudad_t ciudades[CANT_CIUDADES];
	leer_archivo("problem.csv", ciudades);
	
	solucion_t sol = {};
	
	generar_solucion_random(&sol, ciudades);
	
	imprimir_solucion(sol);

	return 0;
}

