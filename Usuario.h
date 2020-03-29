/*
 * User.h
 *
 *  Created on: 28 mar. 2020
 *      Author: ikerg
 */

#ifndef USUARIO_H_
#define USUARIO_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void informacion(char habitacion_numero[10],char tipo_habitacion[50]){
    char nombre[128],numero[128],fecha[128];

    printf("Introduce tu nombre:");
    scanf("%s",nombre);

    printf("Introduce tu numero de telefono:");
    scanf("%s",numero);

    printf("Introduce la fecha de reserva");
    scanf("%s",fecha);


    char inf[255] =  "";
    strcat(inf,nombre);
    strcat(inf," : ");
    strcat(inf,numero);
    strcat(inf," : ");
    strcat(inf,fecha);
    strcat(inf," : ");
    strcat(inf,habitacion_numero);
    strcat(inf," : ");
    strcat(inf,strtok(tipo_habitacion,"."));
    strcat(inf,"\n");


    FILE *file;
    file  = fopen("cliente.txt","a");
    fputs(inf,file);
    fclose(file);
}

void buscar(int version){
    FILE *file;
    file  = fopen("cliente.txt","r");
    char nombre[128],numero[128],fecha[128],input[128],habitacion[128],tipo[128];
    char c;

    do {
        if (version == 0) {
            printf("Introduce un nombre para buscar:");
            scanf("%s", input);
        } else if (version == 1) {
            printf("Introduce un telefono para buscar");
            scanf("%s", input);
        }

        int check = 0;
        while (fscanf(file, "%s : %s : %s : %s : %[^\n]", nombre, numero, fecha, habitacion, tipo) != EOF) {
            if (version == 0) {
                if (strcmp(nombre, input) == 0) {
                    printf("%s : %s : %s : %s : %s\n", nombre, numero, fecha, habitacion, tipo);
                    check = 1;
                }
            } else if (version == 1) {
                if (strcmp(numero, input) == 0) {
                    printf("%s : %s : %s : %s : %s\n", nombre, numero, fecha, habitacion, tipo);
                    check = 1;
                }
            }
        }

        if (check == 0 && version == 0) {
            printf("Nombre no disponible !!!\n");
        }
        else if (check == 0 && version == 1){
            printf("Nombre no disponible  !!!\n");
        }


        printf("¿Desea realizar otra busqueda?(teclea a para avanzar o b para volver)");
        getchar();
        scanf("%c", &c);
        if(c == 'b')
            return;
    }while(c == 'a');


}

#endif /* USUARIO_H_ */
