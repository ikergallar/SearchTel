/*
 * Hotel.h
 *
 *  Created on: 28 mar. 2020
 *      Author: alegr
 */

#ifndef HOTEL_H_
#define HOTEL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Usuario.h"

void informaciónHabitación(char* hotelnombre);
void hotel();

typedef struct hotel {
    char* nombre;
    struct hotel * next;
}Hotel;

typedef  struct tipo_habitacion{
    char *nombre;
    int status;
    struct tipo_habitacion *next;
}tipo_habitacion;

typedef  struct room{
    char *room_num;
    int status;
    struct room *next;
}Room;


void hacerListaHotel(Hotel **lst, char *hotelnombre){
    Hotel* nuevo_Hotel = (Hotel*)malloc(sizeof(Hotel)); ;
    nuevo_Hotel->nombre = hotelnombre;
    nuevo_Hotel->next = NULL;
    if(*lst == NULL) {
        *lst = nuevo_Hotel;
    }
    else{
        Hotel* buffer = *lst;
        Hotel* head = buffer;
        while(buffer->next != NULL) {
            buffer = buffer->next;
        }
        buffer->next = nuevo_Hotel;
        *lst = head;
    }
}

void hacertipo_listaHabitación(tipo_habitacion **lst, char *roomnombre, int s){
    tipo_habitacion* nueva_Habitacion = (tipo_habitacion*)malloc(sizeof(tipo_habitacion)); ;
    nueva_Habitacion->nombre = roomnombre;
    nueva_Habitacion->next = NULL;
    nueva_Habitacion->status = s;

    if(*lst == NULL) {
        *lst = nueva_Habitacion;
    }
    else{
        tipo_habitacion* buffer = *lst;
        tipo_habitacion* head = buffer;
        while(buffer->next != NULL) {
            buffer = buffer->next;
        }
        buffer->next = nueva_Habitacion;
        *lst = head;
    }
}

void makeRoomList(Room **lst, char *room_num, int s){
    Room* nueva_Habitacion = (Room*)malloc(sizeof(Room)); ;
    nueva_Habitacion->room_num = room_num;
    nueva_Habitacion->next = NULL;
    nueva_Habitacion->status = s;

    if(*lst == NULL) {
        *lst = nueva_Habitacion;
    }
    else{
        Room* buffer = *lst;
        Room* head = buffer;
        while(buffer->next != NULL) {
            buffer = buffer->next;
        }
        buffer->next = nueva_Habitacion;
        *lst = head;
    }
}

void write_file(Room* room,char* filenombre){
    Room* sub = room;
    FILE *f;
    f = fopen(strcat(filenombre,".txt"),"w");

    while (sub != NULL) {
        char* new_room = (char*)malloc(sizeof(sub->room_num));
        new_room = sub->room_num;
        strcat(new_room," : ");
        if(sub->status == 1){
            strcat(new_room,"Disponible\n");
            fputs(new_room,f);
        }
        else if(sub->status == 0){
            strcat(new_room,"Full\n");
            fputs(new_room,f);
        }
        sub = sub->next;
    }
    fclose(f);
}

void booking(char* all_room, char* hotelnombre){
    FILE * all;
    all  = fopen(all_room,"r+");
    Room *room = NULL;
    char room_number[10],room_status[10];

    while (fscanf(all,"%s : %s",room_number,room_status)!= EOF){
        printf("%s : %s\n",room_number,room_status);
        int status;
        if(strcmp(room_status,"Disponible") == 0)
            status = 1;
        else
            status = 0;

        char *sub_room = (char*)malloc(sizeof(room_number));
        strcpy(sub_room,room_number);
        makeRoomList(&room,sub_room,status);
    }

    char n[10];
    int check = 0, invalid = 0;


    do {
        printf("Enter the room number that Disponible( b to back):");
        scanf("%s", n);
        Room *sub = room;
        if(strcmp(n,"b")== 0){
            char* hotel = hotelnombre;
            strtok(hotel,"_");
            strcat(hotel,".txt");
            informaciónHabitación(hotel);
            return;
        }
        while (sub != NULL) {
            if (strcmp(sub->room_num, n) == 0 && sub->status == 1) {
                char cf;
                printf("¿Esta seguro de querer reservar esta habitacion?(y, para confirmar)");
                getchar();
                scanf("%c",&cf);
                if(cf == 'y'){
                    information(n,all_room);
                    sub->status = 0;
                }
                check = 1;
                break;
            }
            else if (strcmp(sub->room_num, n) == 0 && sub->status == 0){
                printf("Esta habitacion ya esta reservada\n");
                invalid = 0;
                break;
            }
            else
                invalid = 1;

            sub = sub->next;
        }
        if(invalid == 1)
            printf("Tu seleccion es invalida o no esta disponible\n");

        invalid = 0;

    }while (check == 0);

    if(check == 1){
        write_file(room,all_room);
        printf("Success!!!\n");
    }
}

void checkStatus(char* room_nombre,int choice,tipo_habitacion **r){
    FILE *room,*type;
    int status;
    char room_number[10],room_status[10];

    room = fopen(room_nombre,"r");
    char type_nombre[255];
    for(int i =0;i< choice;i++){
        fgets(type_nombre, sizeof(type_nombre),room);
    }
    strtok(type_nombre,"\n");

    type = fopen(type_nombre,"r");
    while (fscanf(type,"%s : %s",room_number,room_status)!= EOF){
        if(strcmp(room_status,"Full")!= 0){
            printf("\nStatus : Disponible\n");
            status = 1;
            char* sub = malloc(sizeof(type_nombre));
            strcpy(sub,type_nombre);
            sub = strtok(sub,"\n");
            hacertipo_listaHabitación(r, sub, status);
            fclose(room);
            fclose(type);
            return;
        }
    }
    printf("\nStatus : Full\n");
    status = 0;
    hacertipo_listaHabitación(r, type_nombre, status);
    fclose(room);
    fclose(type);
}


void informaciónHabitación(char* hotelnombre){
    FILE *roomlst;
    roomlst = fopen(hotelnombre,"r");
    if(roomlst == 0){
        return;
    }
    tipo_habitacion *roomLink = NULL;

    char buffer[255];
    char* n = strtok(hotelnombre,".");
    n = strcat(n,"_room.txt");

    int order = 1;
    int number = 0;

    printf("-------Room Detail---------\n");
    while (fgets(buffer, sizeof(buffer),roomlst)){
        if(strcmp(buffer,"\n") == 0){
            checkStatus(n,order,&roomLink);
            order++;
        }
        printf("%s",buffer);
        number++;
    }
    checkStatus(n,order,&roomLink);

    fclose(roomlst);

    char* room_nombre;
    char c[2];
    int room_status,command,check = 1;

    do {
        tipo_habitacion *select_room = roomLink;
        printf("\nIntroduce el tipo de habitacion (o b para volver ): ");
        scanf("%s", c);
        if(strcmp(c,"b")== 0){
            hotel();
            return;
        }
        command = atoi(c);
        if(command < 0 || command > number || strlen(c)> 1){
            printf("Tipo de habitacion no disponible\n");
            continue;
        }

        for (int i = 0; i < command; i++) {
            room_nombre = select_room->nombre;
            room_status = select_room->status;
            select_room = select_room->next;
        }
        if (!room_status)
            printf("No disponible!!!\n");
        else
            check = 0;

    }while(check);

    booking(room_nombre,hotelnombre);

}

void hotel() {
    FILE *hotelst;
    char buffer[255];
    Hotel *hotel = NULL;
    int len_hotel = 0;

    printf("\n---------Hotel nombre---------\n");
    hotelst = fopen("Hotelnombre.txt","r");
    while (fgets(buffer, sizeof(buffer),hotelst)){
        printf("%d.%s",len_hotel+1,buffer);
        char* sub = malloc(sizeof(buffer));
        strcpy(sub,buffer);
        sub = strtok(sub,"\n");
        hacerListaHotel(&hotel, sub);
        len_hotel++;
    }


    fclose(hotelst);

    int command;
    char c[1];
    Hotel* selecthotel = hotel;
    char* hotelnombre;
    int check = 1;

    do{
    printf("\nElija Hotel(o b para volver ): ");
    scanf("%s",c);
    if(strcmp(c,"b")== 0) {
        return;
    }
    command = atoi(c);
    if(command != 0 && command > len_hotel) printf("Hotel invalido!!!");
    else check = 0;
    }while (check);

    for(int i = 0;i<command ;i++){
        hotelnombre = selecthotel->nombre;
        selecthotel = selecthotel->next;
    }

    hotelnombre = strcat(hotelnombre,".txt");
    informaciónHabitación(hotelnombre);

}



#endif /* HOTEL_H_ */
