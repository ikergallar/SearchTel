/*
 * Admin.h
 *
 *  Created on: 28 mar. 2020
 *      Author: alegr
 */

#ifndef ADMIN_H_
#define ADMIN_H_


#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Hotel.h"



void seek_to_next_line( void )
{
    int c;
    while( (c = fgetc( stdin )) != EOF && c != '\n' );
}


void checkout(char room[10],char nombre[10]){
    FILE *cuFile,*file;
    int check_first = 1,check = 1;
    char buffer[255];
    char a[20] = "";
    strcat(a,nombre);
    cuFile = fopen("cliente.txt","r");
    file = fopen("buffer.txt","w");
    char bnombre[25],btelefono[10],bfecha[10],broom[10],btipo[30],tipo[100],droom[10];
    while(fgets(buffer,255,cuFile)){
        fputs(buffer,file);
    }
    fclose(file);
    fclose(cuFile);
    cuFile = fopen("cliente.txt","w");
    file = fopen("buffer.txt","r");
    fseek(file,-1,SEEK_CUR);
    while(fgets(buffer,255,file)!= NULL){
        char nn[100];






        sscanf(buffer,"%s : %s : %s : %s : %[^\n]",nn,btelefono,bfecha,broom,btipo);
        if(!strcmp(nombre,nn)&& !strcmp(broom,room)){
            check = 0;
            strcpy(droom,broom);
            strcpy(tipo,btipo);
            continue;
        }
        else{
            char sub[255] = "";
            strcat(sub,nn);
            strcat(sub," : ");
            strcat(sub,btelefono);
            strcat(sub," : ");
            strcat(sub,bfecha);
            strcat(sub," : ");
            strcat(sub,broom);
            strcat(sub," : ");
            strcat(sub,btipo);
            strcat(sub,"\n");
            fputs(sub,cuFile);
        }
    }

    fclose(cuFile);
    if(check){
        printf("Can not check out ,can not find your log");
        return;
    }

    cuFile = fopen(strcat(tipo,".txt"), "r");
    char n[25];
    char s[25];
    Room *r, *ar;
    int first = 1;

    while (fscanf(cuFile, "%s : %s", n,s) != EOF) {
        char *n_in = (char*)malloc(sizeof(n));
        strcpy(n_in,n);
        Room *in = (Room *) malloc(sizeof(Room));
        in->room_num = n_in;
        int st;
        if(strcmp(s,"Disponible") == 0)
            st = 1;
        else
            st = 0;
        in->status = st;
        in->next = NULL;
        if (first) {
            r = in;
            ar = r;
            first = 0;
        } else {
            r->next = in;
            r = r->next;
        }
    }

    fseek(cuFile, 0, SEEK_SET);
    fclose(cuFile);

    fopen(tipo, "w");
    while (ar != NULL) {
        char buffer[255] = "";
        strcat(buffer, ar->room_num);
        strcat(buffer, " : ");

        if (strcmp(ar->room_num, droom) == 0) {
            strcat(buffer, "Disponible");
        }
        else {
            if (ar->status == 1)
                strcat(buffer, "Disponible");
            else
                strcat(buffer, "Lleno");
        }
        ar = ar->next;
        strcat(buffer, "\n");
        fputs(buffer, cuFile);
    }
    fclose(cuFile);
    printf("Check Out Success\n");
}


int check_duplicate(char* filename){
    FILE *file;
    file = fopen("Hotelname.txt","r");
    char buffer[strlen(filename)+1];
    while (fgets(buffer, sizeof(buffer),file)){
        if(strcmp(filename,buffer) == 0)
            return 0;
    }
    return 1;
}

void addHotel(){
    int firstdes =1;
    FILE *hotelfile,*room,*hotel;
    hotelfile = fopen("Hotelname.txt","a");

    char hotelnombre[255];
    printf("Enter Hotelname :");
    scanf("%s", hotelnombre);
    seek_to_next_line();
    if(check_duplicate(hotelnombre)) {
        strcat(hotelnombre, "\n");
        fputs(hotelnombre, hotelfile);
        strtok(hotelnombre, "\n");
    }
    fclose(hotelfile);

    char *hotel_room = (char*)malloc(sizeof(hotelnombre));
    hotel_room = hotelnombre;
    strcat(hotel_room,"_room.txt");
    room = fopen(hotel_room,"a");
    strtok(hotel_room,"_");

    char moreRoom;

    do{
        char tiporoom[] = "Room Type : ";
        char buffer[255];
        char rt[255] = "";
        printf("Introduzca el tipo de habitacion : ");
        scanf("%s",buffer);
        seek_to_next_line();

        strcat(buffer,".txt\n");
        strcat(rt,buffer);
        fputs(buffer,room);
        strtok(buffer,".");
        fclose(room);

        strcat(hotelnombre,".txt");
        hotel = fopen(hotelnombre,"a");
        strcat(tiporoom,buffer);
        strcat(tiporoom,"\n");
        fputs(tiporoom,hotel);

        int check = 0;
        do {

        	char des[50];
            if(firstdes)
                strcpy(des,"     Descripcion :  ");
            else
                strcpy(des,"                 :  ");
            printf("Introduzca una descripcion(1 linea por 1 opcion) : ");
            scanf("%[^\n]", buffer);
            seek_to_next_line();

            strcat(buffer, "\n");
            strcat(des, buffer);
            fputs(des, hotel);

            char algoMas;
            printf("Quieres anyadir algo mas a la descripcion? (teclea a para añadir mas):");
            scanf("%c",&algoMas);
            seek_to_next_line();
            printf("Introduciste %c\n",algoMas);
            if(algoMas == 'a') {
                firstdes = 0;
                check = 1;
            }
            else {
                firstdes = 1;
                check = 0;
            }
        }while (check == 1);

        char people[] = "     Personas recomendadas: ";
        char detail[255];
        printf("Introduzca el numero de personas: ");
        scanf("%s",detail);
        seek_to_next_line();
        strcat(detail,"\n");
        strcat(people,detail);
        fputs(people,room);

        char precio[] = "     precio: ";
        char p[10];
        printf("Introduzca el precio :");
        scanf("%s",p);
        seek_to_next_line();

        strcat(p,"\n");
        strcat(precio,p);
        fputs(precio,room);

        int check_digit = 1;
        do {
            char sroom[10], eroom[10];
            printf("Enter strating room number: ");
            scanf("%s", sroom);
            seek_to_next_line();

            for(int i =0;i < strlen(sroom);i++){
                if(!isdigit(sroom[i])){
                    printf("Invalid Starting room\n");
                    continue;
                }
            }

            printf("Enter ending room number: ");
            scanf("%s", eroom);
            seek_to_next_line();

            for(int i =0;i < strlen(eroom);i++){
                if(!isdigit(sroom[i])){
                    printf("Invalid Ending room\n");
                    continue;
                }
            }

            if (check_digit) {
                FILE *roomCheck;
                roomCheck = fopen(strtok(rt,"\n"), "w");
                int s = atoi(sroom),e = atoi(eroom);
                if(s < e){
                    while (s <= e){
                        char b[10];
                        itoa(s,b,10);
                        strcat(b," : Disponible\n");
                        fputs(b,roomCheck);
                        s++;
                    }
                }
                else{
                    check_digit = 0;
                    printf("starting room is less than ending room\n");
                }
            }
            else{
                printf("Habitacion no disponible\n");
            }
        }while (check_digit == 0);



        printf("Quiere añadir otro tipo de habitacion(y para añadir): ");
        scanf("%c",&moreRoom);
        seek_to_next_line();
        printf("You entered %c\n",moreRoom);
    }while (moreRoom == 'y');

    fclose(hotelfile);
    fclose(room);
    fclose(hotel);
}

void menuAdmin(){
    int comando , check = 0;
    do {
        printf("1.Añadir hotel\n");
        printf("2.Check out\n");
        printf("3.Volver\n");
        printf("Introduzca el numero de comandos :");
        scanf("%d", &comando);
        if(comando == 1)
            addHotel();

        else if(comando == 2) {
            char room[10],nombre[25];
            printf("Introduzca la habitacion para realizar el check out: ");
            scanf("%s",room);
            seek_to_next_line();

            printf("Introducir el nombre del cliente:");
            scanf("%s",nombre);
            seek_to_next_line();

            checkout(room,nombre);
        }
        else if(comando == 3)
            check = 1;
        else
            printf("Comando invalido!!!");
    }while(check == 0);

}

void login(){
    char user[10],pass[10];
    int check = 0;
    do {
        printf("Usuario(b para volver): ");
        scanf("%s", user);
        if (strcmp(user, "b") == 0)
            return;
        printf("Introduzca la contraseña: ");
        scanf("%s", pass);
        int check_user = strcmp(user, "Admin"),
                check_pass = strcmp(pass, "rootAdmin");
        if (check_user && check_pass) {
            printf("Usuario o contraseña incorrecto\n");

        } else {
            menuAdmin();
            check = 1;
        }
    }while(check == 0);
}





#endif /* ADMIN_H_ */
