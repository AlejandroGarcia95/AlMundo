#ifndef CIUDADES_H
#define CIUDADES_H

#define CANT_CIUDADES 41011

typedef struct ciudad{
	int id;
	float coord_x;
	float coord_y;
} ciudad_t;


typedef struct viaje{
	char agencia;
	int ciudad_orig;
	int ciudad_dest;
} viaje_t;

typedef struct solucion{
	viaje_t viajes[CANT_CIUDADES];
	float costo;
} solucion_t;


float distancia_ciudades(ciudad_t orig, ciudad_t dest);

float calcular_costo_solucion(solucion_t sol);


#endif
