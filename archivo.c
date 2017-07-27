#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"
#include "ciudades.h"

void leer_archivo(char* arch){
	FILE* fp = fopen(arch, "r+");
	int id, i;
	float coord_x, coord_y;
	 
	for (i = 0; i < CANT_CIUDADES; i++){
		fscanf(fp, "%d,%f,%f\n", &id, &coord_x, &coord_y);
		printf(" %d %f %f \r\n", id, coord_x, coord_y);
		}
}


