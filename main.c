


#include <stdio.h>
#include <string.h>
#include "Hotel.h"
#include "Admin.h"
#include "Usuario.h"
#include "registro.h"

void home(){

    char* nombre;
    char c[2];
    int check = 0;
    printf("---------- Bienvenido a SearchTel ----------\n\n");
    do{
        int comando = 0 ;
        printf("1. Seleccionar por hotel\n");
        printf("2. Buscar Hotel por nombre\n");
        printf("3. Buscar Hotel por número de teléfono\n");
        printf("4. Menu Admin\n");
        printf("5. Salir\n");
        printf("Introduce tu eleccion: ");
        scanf("%s",&c);
        seek_to_next_line();
        comando = atoi(c);
        if(comando > 5 || comando < 0 || strlen(c) > 1){
        	comando = 0 ;
        }
        switch (comando){
            case 1:
                printf("\n");hotel();
                break;
            case 2:
                printf("\n");busqueda(0);
                break;
            case 3:
                printf("\n");busqueda(1);
                break;
            case 4:
                printf("\n");login();  //Username  = Admin , Pass = rootAdmin
                break;
            case 5:
                printf("\n");check = 1;
                break;
            default:
                printf("No se dispone de esa eleccion, por favor, pruebe de nuevo\n");
        }
    }while(check == 0 );
    printf("Gracias por confiar en SearchTel\n");
}

int main() {
    home();

}




