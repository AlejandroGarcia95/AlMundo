#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"
#include "ciudades.h"

void leer_archivo(char* arch, ciudad_t* ciudades){
	FILE* fp = fopen(arch, "r+");
	int i;
	 
	for (i = 0; i < CANT_CIUDADES; i++){
		fscanf(fp, "%d,%f,%f\n", &ciudades[i].id, &ciudades[i].coord_x, &ciudades[i].coord_y);
	//	printf(" %d %.20f %.20f \r\n", ciudades[i].id, ciudades[i].coord_x, ciudades[i].coord_y);
		}
}


