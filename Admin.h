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


void checkout(char room[10],char name[10]){
    FILE *cuFile,*file;
    int check_first = 1,check = 1;
    char buffer[255];
    char a[20] = "";
    strcat(a,name);
    cuFile = fopen("Customer.txt","r");
    file = fopen("buffer.txt","w");
<<<<<<< HEAD
<<<<<<< HEAD
    char bname[25],bphone[10],bdate[10],broom[10],btype[30],type[100],droom[10];
=======
=======
    char bnombre[25],bphone[10],bfecha[10],broom[10],btype[30],type[100],droom[10];
    char bname[25],bphone[10],bfecha[10],broom[10],btype[30],type[100],droom[10];
>>>>>>> branch 'master' of https://github.com/ikergallar/SearchTel.git
    char bnombre[25],btelefono[10],bfecha[10],broom[10],btipo[30],tipo[100],droom[10];
>>>>>>> branch 'master' of https://github.com/ikergallar/SearchTel.git
    while(fgets(buffer,255,cuFile)){
        fputs(buffer,file);
    }
    fclose(file);
    fclose(cuFile);
    cuFile = fopen("Customer.txt","w");
    file = fopen("buffer.txt","r");
    fseek(file,-1,SEEK_CUR);
    while(fgets(buffer,255,file)!= NULL){
        char nn[100];
<<<<<<< HEAD
<<<<<<< HEAD
        sscanf(buffer,"%s : %s : %s : %s : %[^\n]",nn,bphone,bdate,broom,btype);
        if(!strcmp(name,nn)&& !strcmp(broom,room)){
=======
=======

        sscanf(buffer,"%s : %s : %s : %s : %[^\n]",nn,bphone,bfecha,broom,btype);


        sscanf(buffer,"%s : %s : %s : %s : %[^\n]",nn,bphone,bfecha,broom,btype);
        if(!strcmp(nombre,nn)&& !strcmp(broom,room)){

>>>>>>> branch 'master' of https://github.com/ikergallar/SearchTel.git
        sscanf(buffer,"%s : %s : %s : %s : %[^\n]",nn,btelefono,bfecha,broom,btipo);
        if(!strcmp(nombre,nn)&& !strcmp(broom,room)){
>>>>>>> branch 'master' of https://github.com/ikergallar/SearchTel.git
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
        if(strcmp(s,"Avalible") == 0)
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
            strcat(buffer, "Avalible");
        }
        else {
            if (ar->status == 1)
                strcat(buffer, "Avalible");
            else
                strcat(buffer, "Full");
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

    char hotelname[255];
    printf("Enter Hotelname :");
    scanf("%s", hotelname);
    seek_to_next_line();
    if(check_duplicate(hotelname)) {
        strcat(hotelname, "\n");
        fputs(hotelname, hotelfile);
        strtok(hotelname, "\n");
    }
    fclose(hotelfile);

    char *hotel_room = (char*)malloc(sizeof(hotelname));
    hotel_room = hotelname;
    strcat(hotel_room,"_room.txt");
    room = fopen(hotel_room,"a");
    strtok(hotel_room,"_");

    char moreRoom;

    do{
        char tiporoom[] = "Tipo de Habitación : ";
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

<<<<<<< HEAD
        strcat(hotelname,".txt");
        hotel = fopen(hotelname,"a");
        strcat(roomtype,buffer);
        strcat(roomtype,"\n");
        fputs(roomtype,hotel);
=======
        strcat(hotelnombre,".txt");
        hotel = fopen(hotelnombre,"a");
        strcat(tiporoom,buffer);
        strcat(tiporoom,"\n");
        fputs(tiporoom,hotel);
>>>>>>> branch 'master' of https://github.com/ikergallar/SearchTel.git

        int check = 0;
        do {
            char des[50];
            if(firstdes)
                strcpy(des,"     Description :  ");
            else
                strcpy(des,"                 :  ");
            printf("Introduzca una describcion(1 linea por 1 opcion) : ");
            scanf("%[^\n]", buffer);
            seek_to_next_line();

            strcat(buffer, "\n");
            strcat(des, buffer);
            fputs(des, hotel);

<<<<<<< HEAD
            char more;
            printf("Do you want to add more description? (y to add more):");
            scanf("%c",&more);
=======
            char algoMas;
            printf("Quieres anyadir algo mas a la descripcion? (teclea a para añadir mas):");
            scanf("%c",&algoMas);
>>>>>>> branch 'master' of https://github.com/ikergallar/SearchTel.git
            seek_to_next_line();
<<<<<<< HEAD
            printf("You entered %c\n",more);
=======
            printf("Introduciste %c\n",algoMas);
>>>>>>> branch 'master' of https://github.com/ikergallar/SearchTel.git

<<<<<<< HEAD
            if(more == 'y') {
=======
            if(algoMas == 'a') {
>>>>>>> branch 'master' of https://github.com/ikergallar/SearchTel.git
                firstdes = 0;
                check = 1;
            }
            else {
                firstdes = 1;
                check = 0;
            }
        }while (check == 1);

        char persona[] = "     People suggest: ";
        char detail[255];
        printf("Introduzca el numero de personas: ");
        scanf("%s",detail);
        seek_to_next_line();
        strcat(detail,"\n");
        strcat(persona,detail);
        fputs(persona,room);

        char precio[] = "     Precio: ";
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
            printf("Introduce el primer numero de la habitacion: ");
            scanf("%s", sroom);
            seek_to_next_line();

            for(int i =0;i < strlen(sroom);i++){
                if(!isdigit(sroom[i])){
                    printf("Prueba otra vez\n");
                    continue;
                }
            }

            printf("Introduce el ultimo numero de la habitacion: ");
            scanf("%s", eroom);
            seek_to_next_line();

            for(int i =0;i < strlen(eroom);i++){
                if(!isdigit(sroom[i])){
                    printf("Prueba otra vez\n");
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
        printf("Has introducido %c\n",moreRoom);
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
        else if(command == 2) {
<<<<<<< HEAD
=======
        else if(command == 2) {
>>>>>>> branch 'master' of https://github.com/ikergallar/SearchTel.git
            char room[10],name[25];
        else if(comando == 2) {
            char room[10],nombre[25];
>>>>>>> branch 'master' of https://github.com/ikergallar/SearchTel.git
            printf("Introduzca la habitacion para realizar el check out: ");
            scanf("%s",room);
            seek_to_next_line();

            printf("Introducir el nombre del cliente:");
            scanf("%s",name);
            seek_to_next_line();

            checkout(room,name);
        }
        else if(comando == 3)
            check = 1;
        else
            printf("Comando invalido!!!");
    }while(check == 0);

}

void login(){
    char usuario[10],contraseña[10];
    int check = 0;
    do {
        printf("Usuario(b para volver): ");
        scanf("%s", usuario);
        if (strcmp(usuario, "b") == 0)
            return;
        printf("Introduzca la contraseña: ");
        scanf("%s", contraseña);
        int check_usuario = strcmp(usuario, "Admin"),
                check_contraseña = strcmp(contraseña, "rootAdmin");
        if (check_usuario && check_contraseña) {
            printf("Usuario o contraseña incorrecto\n");

        } else {
            menuAdmin();
            check = 1;
        }
    }while(check == 0);
}





#endif /* ADMIN_H_ */
