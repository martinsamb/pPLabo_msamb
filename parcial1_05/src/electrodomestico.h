/*
 * electrodomestico.h
 *
 *  Created on: 15 oct. 2020
 *      Author: marti
 */

#include "reparacion.h"

#define TEXT_SIZE 20

#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int serie;
    int idMarca;
    int modelo;

}Electrodomestico;

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int serie;
    char descripcion[TEXT_SIZE];
    int modelo;

}Marca;


#endif /* ELECTRODOMESTICO_H_ */

int electrodomestico_inicializar(Electrodomestico array[], int size);
int electrodomestico_buscarEmpty(Electrodomestico array[], int size, int* posicion);
int electrodomestico_buscarID(Electrodomestico array[], int size, int valosBuscado, int* posicion);
int electrodomestico_alta(Electrodomestico array[], int size, int* contadorID);
int electrodomestico_baja(Electrodomestico array[], int sizeArray, Reparacion arrayMusico[], int sizeMusico);
int electrodomestico_listar(Electrodomestico array[], int size);
int electrodomestico_modificar(Electrodomestico array[], int sizeArray);
//---------------------------------------------------------------------
int marca_inicializar(Marca array[],int size);
int marca_listar(Marca array[],int size);
//--------------------------------------------------
