/*
 * registro.c
 *
 *  Created on: 27 mar. 2020
 *      Author: alegr
 */
#include <stdio.h>
#include "registro.h"
#include <string.h>


void registrarUsuario(){

	FILE *pf;
	REGISTRO r;
	if(!(pf = fopen("Registros.txt", "wb"))){
		printf("\nError de apertura");
	}else{

	printf("\nIntroduce el tu nombre:");
	fflush(stdin);
	gets(r.nombre);
	printf("\nIntroduce el nombre de usuario deseado:");
	fflush(stdin);
	gets(r.usuario);
	printf("\nIntroduce la contraseña:");
	fflush(stdin);
	gets(r.contra);
	fwrite(&r, sizeof(r), 1, pf);
	printf("\nRegistrado con exito!");
    	printf("\nPresiona cualquier tecla para continuar...");
     	getch();
        fclose(pf);
	}

}

