/*
 ============================================================================
 Name        : parcial1_02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "electrodomestico.h"
#include "utn.h"
#include "reparacion.h"


#define QTY_ELE 50
#define QTY_SER 20
#define QTY_REP 100
#define QTY_MAR 100


int cargarDatos(Electrodomestico arrayE[], Reparacion arrayR[], Marca arrayM[],Servicio arrayS[], int *contadorE, int *contadorR, int *contadorIdM, int* contadorIdS);

int main()
{
	setbuf(stdout, NULL);
    int contadorIdE=0;
    int contadorIdR=0;
    int contadorIdM=0;
    int contadorIdS=0;
    int flagE=0;
    int flagR=0;
    int opcion;

    Electrodomestico arrayE[QTY_ELE];
    electrodomestico_inicializar(arrayE,QTY_ELE);

    Reparacion arrayR[QTY_REP];
    reparacion_inicializar(arrayR,QTY_REP);

    Servicio arrayS[QTY_SER];
    servicio_inicializar(arrayS,QTY_SER);

    Marca arrayM[QTY_MAR];
    marca_inicializar(arrayM,QTY_MAR);

    //Marca arrayM[QTY_MAR] = {{1000,"Wirpool"},{1001,"Sony"},{1002,"Liliana"},{1003,"Gafa"},{1004,"Philips"}};
    //Servicio arrayS[QTY_SER] = {{20001,{"Garantia:",250}},{20002,{"Mantenimiento:",500}},{20003,{"Repuesto: ",400}},{20004{"Refaccion:",600}}};




    do
    {
        if(utn_getUnsignedInt("\n\n1) Alta Electrodomestico \n2) Baja Electrodomestico \n3) Lista Electrodomestico \n4) Modificar Electrodomestico \n5) Lista Marca \n6) Lista Servicio \n7) Alta Reparacion\n8) Lista Reparaciones\n9) Salir\n",                   //cambiar
                                "\nError",1,3,1,&opcion)!=0)
            opcion=8;   //salir
        else
        {
            switch(opcion)
            {
                case 1: //Alta electro
                    if(electrodomestico_alta(arrayE,QTY_ELE,&contadorIdE)==0)
                        flagE=1;
                    break;

                case 2: //Baja electro
                    if(flagE==0)
                    {
                        printf("\nAun no se ha dado de alta ninguna orquesta");
                    }
                    else
                        electrodomestico_baja(arrayE,QTY_ELE,arrayR,QTY_REP);
                    break;

                case 3: //Listar electro
                    electrodomestico_listar(arrayE,QTY_ELE);
                    break;

                case 4:
                	if(flagE==0)
                	{
                	   printf("\nAun no se ha dado de alta ningun electrodomestico");
                	}
                	else
                		electrodomestico_modificar(arrayE, QTY_ELE);
                    break;


                case 5:
                	marca_listar(arrayM,QTY_MAR);
                	break;

                case 6:
                	servicio_listar(arrayS, QTY_SER);
					break;

                case 7: //Alta reparacion
                    if(reparacion_alta(arrayR,QTY_REP,&contadorIdR)==0)
                        flagR=1;
                    break;

                case 8: //Listar reparacion
                    reparacion_listar(arrayR, QTY_REP);
                    break;

                default:
                    printf("\nOpcion no valida");
            }
        }
    }while(opcion!=10);
    return 0;
}

int cargarDatos(Electrodomestico arrayE[], Reparacion arrayR[], Marca arrayM[],Servicio arrayS[], int *contadorE, int *contadorR, int *contadorIdM, int* contadorIdS)
{
    int i=1000;
//Marca
    (*contadorIdM)++;
    arrayM[i].isEmpty=0;
    arrayM[i].idUnico=*contadorIdM;
    strcpy(arrayM[i].descripcion,"Wirpool");
    (*contadorIdM)++;
    i++;

    arrayM[i].isEmpty=0;
    arrayM[i].idUnico=*contadorIdM;
    strcpy(arrayM[i].descripcion,"Sony");
    (*contadorIdM)++;
    i++;

    arrayM[i].isEmpty=0;
    arrayM[i].idUnico=*contadorIdM;
    strcpy(arrayM[i].descripcion,"Liliana");
    (*contadorIdM)++;
    i++;

    arrayM[i].isEmpty=0;
    arrayM[i].idUnico=*contadorIdM;
    strcpy(arrayM[i].descripcion,"Gafa");
    (*contadorIdM)++;
    i++;

    arrayM[i].isEmpty=0;
    arrayM[i].idUnico=*contadorIdM;
    strcpy(arrayM[i].descripcion,"Philips");

    i=20000;
//Servicio
    (*contadorIdS)++;
    arrayS[i].isEmpty=0;
    arrayS[i].idUnico=*contadorIdS;
    strcpy(arrayS[i].descripcion,"Garantia");
    arrayS[i].precio=250.00;
    (*contadorIdS)++;
    i++;

    arrayS[i].isEmpty=0;
    arrayS[i].idUnico=*contadorIdS;
    strcpy(arrayS[i].descripcion,"Mantenimiento");
    arrayS[i].precio=500.00;
    (*contadorIdS)++;
    i++;

    arrayS[i].isEmpty=0;
    arrayS[i].idUnico=*contadorIdS;
    strcpy(arrayS[i].descripcion,"Respuesto");
    arrayS[i].precio=400.00;
    (*contadorIdS)++;
    i++;

    arrayS[i].isEmpty=0;
    arrayS[i].idUnico=*contadorIdS;
    strcpy(arrayS[i].descripcion,"Refaccion");
    arrayS[i].precio=250.00;
    (*contadorIdS)++;
    i++;

    return 0;
}
