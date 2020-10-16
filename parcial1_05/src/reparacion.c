/*
 * reparacion.c
 *
 *  Created on: 15 oct. 2020
 *      Author: marti
 */

#include "electrodomestico.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"


//***************************************************************
//Init
/** \brief Indica que todas las posiciones del array estan vacias inicializando el campo isEmpty en TRUE
* \param array Musico Array de Musico
* \param size int Array length
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*
*/
int reparacion_inicializar(Reparacion array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>=0;size--)
        {
            array[size].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [tamaño invalido o NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int reparacion_buscarEmpty(Reparacion array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [tamaño invalido o NULL pointer] - (0) si encuentra el valor buscado
*
*/
int reparacion_buscarID(Reparacion array[], int size, int valosBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valosBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int reparacion_alta(Reparacion array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(reparacion_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if( utn_getUnsignedInt("\nSerie: ","\nError",1,3,1,&array[posicion].serie) == 0 &&
                utn_getDate("\nFecha: ","\nError",3, &array[posicion].fecha) == 0 &&
                utn_getUnsignedInt("\nID Servicio: ","\nError",1,sizeof(int),1,&array[posicion].idServicio) == 0 )
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;
                array[posicion].isEmpty=0;

                printf("\n ID: %d\n Serie: %d\n IdServicio : %d\n Fecha: %s\n",
                       array[posicion].idUnico,array[posicion].serie,array[posicion].idServicio,array[posicion].fecha);
                retorno=0;
            }
            else
            {
                printf("\nAlta no exitosa");
            }
        }
    }
    return retorno;
}




//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int reparacion_listar(Reparacion array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d   Serie: %d  IdServicio: %d    Fecha :[%d]",
                array[i].idUnico,array[i].serie,array[i].idServicio,array[i].fecha);
        }
        retorno=0;
    }
    return retorno;
}


//***************************************************************
//Init
/** \brief Indica que todas las posiciones del array estan vacias inicializando el campo isEmpty en TRUE
* \param array Servicio Array de Servicio
* \param size int Array length
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*
*/
int servicio_inicializar(Servicio array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>=0;size--)
        {
            array[size].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Servicio Array de Servicio
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int servicio_listar(Servicio array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d   Descripcion: %s  Precio: %f",
                       array[i].idUnico,array[i].descripcion,array[i].precio);
        }
        retorno=0;
    }
    return retorno;
}

/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se buscar imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
/*
int servicio_listar(Servicio* pElemento)
{
	int retorno = -1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno = 0;
		printf("\nID: %d - Descripcion:  %s - Precio: %f",pElemento->idUnico,pElemento->descripcion,pElemento->precio);
	}

	return retorno;
}*/

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna = (EXITO) y -1 (ERROR)
 *
 */
/*
int servicio_listarArray(Servicio* array, int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			con_imprimir(&array[i]);
		}
	}

	return respuesta;
}*/
