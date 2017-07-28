#ifndef CIUDADES_H
#define CIUDADES_H

#include <stdbool.h>

#define CANT_CIUDADES 41011
//#define CANT_CIUDADES 8

typedef struct ciudad{
	int id;
	float coord_x;
	float coord_y;
} ciudad_t;


typedef struct viaje{
	char agencia;
	int id_ciudad_orig;
	int id_ciudad_dest;
} viaje_t;


typedef struct solucion{
	viaje_t viajes[CANT_CIUDADES];
	bool ciudad_es_origen[CANT_CIUDADES];
	bool ciudad_es_destino[CANT_CIUDADES];
	int cant_ciudades_origen;
	double costo_total;
} solucion_t;

// Primitivas de viaje_t

viaje_t* crear_viaje();

void destruir_viaje(viaje_t* viaje);

void imprimir_viaje(viaje_t viaje);

// Primitivas de solucion

solucion_t* crear_solucion();

void destruir_solucion(solucion_t* sol);

bool cargar_viaje_en_solucion(solucion_t* sol, viaje_t* viaje);

void imprimir_solucion(solucion_t sol);

// Otras útiles

double distancia_ciudades(ciudad_t orig, ciudad_t dest);

bool ciudad_esta_en_solucion_orig(int ciudad_id, solucion_t sol);
bool ciudad_esta_en_solucion_dest(int ciudad_id, solucion_t sol);

double calcular_costo_solucion(solucion_t* sol, ciudad_t* ciudades);


#endif
