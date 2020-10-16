/*
 * reparacion.h
 *
 *  Created on: 15 oct. 2020
 *      Author: martin
 */

#ifndef REPARACION_H_
#define REPARACION_H_

#define TEXT_SIZE 20

typedef struct
{
    //-----------------
    int dia;
    int mes;
    int ano;

}Fecha;

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    int serie;
    Fecha fecha;
    int idServicio;

}Reparacion;

#define TEXT_SIZE 20

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char descripcion[TEXT_SIZE];
    float precio;
}Servicio;





#endif /* REPARACION_H_ */

int reparacion_inicializar(Reparacion array[], int size);
int reparacion_buscarEmpty(Reparacion array[], int size, int* posicion);
int reparacion_buscarID(Reparacion array[], int size, int valosBuscado, int* posicion);
int reparacion_alta(Reparacion array[], int size, int* contadorID);
int reparacion_listar(Reparacion array[], int size);
//-------------------------------------------------------------------------------

int servicio_inicializar(Servicio array[],int size);
int servicio_listar(Servicio array[],int size);

//int servicio_listar(Servicio* pElemento);
//int servicio_listarArray(Servicio* array, int limite);
