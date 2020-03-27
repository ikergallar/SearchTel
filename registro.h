/*
 * registro.h
 *
 *  Created on: 27 mar. 2020
 *      Author: alegr
 */

#ifndef REGISTRO_H_
#define REGISTRO_H_

typedef struct registro{
	char nombre[10];
	char usuario[8];
	char contra[15];
}REGISTRO;

void registrarUsuario();
void eliminarUsuario(REGISTRO r);


#endif /* REGISTRO_H_ */
