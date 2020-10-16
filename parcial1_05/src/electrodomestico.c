/*
 * orquesta.c
 *
 *  Created on: 15 oct. 2020
 *      Author: marti
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "electrodomestico.h"
#include "utn.h"
#include "reparacion.h"

/*
Funciones:
    Alta
    Baja elimina tmb musico
    Imprimir
*/

//***************************************************************
//Init
/** \brief Indica que todas las posiciones del array estan vacias inicializando el campo isEmpty en TRUE
* \param array Orquesta Array de Orquesta
* \param size int Array length
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*
*/
int electrodomestico_inicializar(Electrodomestico array[], int size)
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
/** \brief Busca el primer lugar vacio en un array
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [tamaño invalido o NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int electrodomestico_buscarEmpty(Electrodomestico array[], int size, int* posicion)
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
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [tamaño invalido o NULL pointer] - (0) si encuentra el valor buscado
*
*/
int electrodomestico_buscarID(Electrodomestico array[], int size, int valosBuscado, int* posicion)
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
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int electrodomestico_alta(Electrodomestico array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(electrodomestico_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            if( utn_getUnsignedInt("\nSerie: ","\nError",1,sizeof(int),1,&array[posicion].serie) == 0  &&
            	utn_getUnsignedInt("\nidMarca: ","\nError",1,sizeof(int),1,&array[posicion].idMarca) ==0 &&
                utn_getUnsignedInt("\nModelo: ","\nError",1,sizeof(int),1,&array[posicion].modelo) == 0)
            {
                (*contadorID)++;
                array[posicion].idUnico=*contadorID;
                array[posicion].isEmpty=0;

                printf("\nID: %d",array[posicion].idUnico);
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
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int electrodomestico_baja(Electrodomestico array[], int sizeArray, Reparacion arrayMusico[], int sizeMusico)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        electrodomestico_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,&id);
        if(electrodomestico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            array[posicion].serie=0;
            array[posicion].idMarca=0;
            array[posicion].modelo=0;
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array Orquesta Array de Orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int electrodomestico_listar(Electrodomestico array[], int size)
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
            {
                printf("\n ID: %d   Serie: %d  idMarca: %d  Modelo: %d",
                       array[i].idUnico,array[i].serie,array[i].idMarca, array[i].modelo);

                /*
                if(array[i].tipo==1)
                    printf("Sinfonica");
                else if(array[i].tipo==2)
                    printf("Filarmonica");
                else if(array[i].tipo==3)
                    printf("Camara");
                else
                    printf("Desconocido");*/
            }
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array Musico Array de Musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int electrodomestico_modificar(Electrodomestico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        electrodomestico_listar(array,sizeArray);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,&id);
        if(electrodomestico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                printf("\n ID: %d\n Serie: %d\n IdMarca: %d\n Modelo: %d\n ",
                       array[posicion].idUnico,array[posicion].serie,array[posicion].idMarca,array[posicion].modelo);

                utn_getLetra("\nModificar: A: Serie B: IdMarca C :Modelo: S(salir)","\nError",1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\nSerie: ","\nError",1,3,1,&array[posicion].serie);
                        break;
                    case 'B':
                        utn_getUnsignedInt("\nIdMarca: ","\nError",1,sizeof(int),1,&array[posicion].idMarca);
                        break;
                    case 'C':
                       utn_getUnsignedInt("\nModelo: ","\nError",1,sizeof(int),1,&array[posicion].modelo);
                       break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//******************************************
//***************************************************************
//Init
/** \brief Indica que todas las posiciones del array estan vacias inicializando el campo isEmpty en TRUE
* \param array Marca Array de Marca
* \param size int Array length
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*
*/
int marca_inicializar(Marca array[], int size)
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
* \param array Marca Array de Marca
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int marca_listar(Marca array[], int size)
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
                printf("\n ID: %d   Descripcion: %s  ",
                       array[i].idUnico,array[i].descripcion);
        }
        retorno=0;
    }
    return retorno;
}


//*****************************************************************
