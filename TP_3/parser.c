#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "InputsDatos.h"
#include "parser.h"

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* unPasajero;
	char id[50];
	char nombre[50];
	char apellido[50];
	char precio[50];
	char codigoVuelo[50];
	char tipoPasajero[50];
	char estadoVuelo[50];
	int retornoo = -1;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		retornoo = 0;
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo)==7)
			{
				unPasajero = Passenger_newParametrosTxt(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
				if(unPasajero != NULL)
				{
					ll_add(pArrayListPassenger, unPasajero);
					retornoo = 1;
				}
			}
			else
			{
				break;
			}
		}while(feof(pFile)==0);

	}

    return retornoo;
}

/** \brief Parsea los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* pasajero;
	int retornoo;
	retornoo=0;
	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		printf("Abrio el archivo\n");
		do
		{
			pasajero = Passenger_new();
			if(pasajero!=NULL)
			{
				if(fread(pasajero,sizeof(Passenger),1,pFile))
				{
					ll_add(pArrayListPassenger,pasajero);
					retornoo=1;
				}
				else
				{
					Passenger_delete(pasajero);
				}
			}
		}while(!feof(pFile));
	}

	return retornoo;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retornoo;
    int i;
    int len;
    FILE* pArchivo;
    Passenger* aux;
    retornoo = -1;
    aux = NULL;
    if(path!=NULL && pArrayListPassenger!=NULL)
    {
        len = ll_len(pArrayListPassenger);
        pArchivo = fopen(path,"wb");

        if(pArchivo!= NULL && len>0)
        {
            for(i=0; i<len ;i++)
            {
                aux = (Passenger*) ll_get(pArrayListPassenger,i);
                if(aux!=NULL)
                {
                    fwrite(aux,sizeof(Passenger),1,pArchivo);
                    retornoo=1;
                }
            }
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
        fclose(pArchivo);
    }
    return retornoo;
}
