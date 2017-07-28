#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "ciudades.h"


viaje_t* crear_viaje(){
	viaje_t* v = (viaje_t*) malloc(sizeof(viaje_t));
	return v;
}

void destruir_viaje(viaje_t* viaje){
	free(viaje);
}


void imprimir_viaje(viaje_t viaje){
	printf("%d,%c,%d\n", viaje.id_ciudad_orig, viaje.agencia, viaje.id_ciudad_dest);
}



solucion_t* crear_solucion(){
	solucion_t* s = (solucion_t*) malloc(sizeof(solucion_t));
	return s;
}

void destruir_solucion(solucion_t* sol){
	free(sol);
}

void imprimir_solucion(solucion_t sol){
	int i;
	for(i = 0; i < CANT_CIUDADES; i++)
		imprimir_viaje(sol.viajes[i]);
		
	printf("Costo total: %.20f\n", sol.costo_total);
}



bool ciudad_esta_en_solucion_orig(int ciudad_id, solucion_t sol){
	return sol.ciudad_es_origen[ciudad_id];
}


bool ciudad_esta_en_solucion_dest(int ciudad_id, solucion_t sol){
	return sol.ciudad_es_destino[ciudad_id];
}

bool cargar_viaje_en_solucion(solucion_t* sol, viaje_t* viaje){
	if(ciudad_esta_en_solucion_orig(viaje->id_ciudad_orig, *sol))
		return false;
	if(ciudad_esta_en_solucion_dest(viaje->id_ciudad_dest, *sol))
		return false;
	if(viaje->id_ciudad_dest == viaje->id_ciudad_orig)
		return false;
	sol->viajes[sol->cant_ciudades_origen] = *viaje;
	sol->ciudad_es_origen[viaje->id_ciudad_orig] = true;
	sol->ciudad_es_destino[viaje->id_ciudad_dest] = true;
	sol->cant_ciudades_origen++;
	return true;
}


double distancia_ciudades(ciudad_t orig, ciudad_t dest){
	double delta_x = orig.coord_x - dest.coord_x;
	double delta_y = orig.coord_y - dest.coord_y;
	return sqrt(delta_x * delta_x + delta_y * delta_y);
}

/*
Agencia A : Cada 3 viajes consecutivos, el tercero tiene 35% de descuento
Agencia B: Si el vuelo es de más de 200km, tiene 15% de descuento
Agencia C: Si el vuelo anterior era B, recibe 20% de descuento
Agencia D: Acumula km. Cada 10000km acum, te regalan 15$

Costo de 1km: 0.01$
*/
double calcular_costo_solucion(solucion_t* sol, ciudad_t* ciudades){
	double costo_acum = 0.0;
	int i;
	double km_acum_d = 0.0;
	int vuelos_consec_a = 0;
		
	for(i = 0; i < CANT_CIUDADES; i++){
		viaje_t v_act = sol->viajes[i];
		char agencia = v_act.agencia;
		double dist = distancia_ciudades(ciudades[v_act.id_ciudad_orig], ciudades[v_act.id_ciudad_dest]);
		double costo_act = dist / 100.0;
		
		switch(agencia){
			case 'A':
				vuelos_consec_a++;
				if(vuelos_consec_a == 3){
					costo_act *= 0.65;
					vuelos_consec_a = 0;
					}	
				break;
			
			case 'B':
				vuelos_consec_a = 0;
				if(dist > 200.0)
					costo_act *= 0.85;
				break;
				
			case 'C':
				vuelos_consec_a = 0;
				if((i > 0) && (sol->viajes[i-1].agencia == 'B'))
					costo_act *= 0.8;
				break;
				
			case 'D':
				vuelos_consec_a = 0;
				km_acum_d += dist;
				while(km_acum_d > 10000.0){
					km_acum_d -= 10000.0;
					costo_acum -= 15.0;
					}
				break;
			}
			
			costo_acum += costo_act;
		}
		
	sol->costo_total = costo_acum;
		
	
	
}

