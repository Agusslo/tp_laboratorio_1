//tp3 actualizado, ya compila y hace todo bien =D
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "InputsDatos.h"
#include "parser.h"
#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int result;
	int retorna = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorna = 0;
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			result = parser_PassengerFromText(pArchivo, pArrayListPassenger);
			if(result == 1)
			{
				retorna = 1;
			}
			fclose(pArchivo);
		}
	}

	return retorna;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int result;
	int retorna = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		retorna = 0;
		pArchivo = fopen(path, "rb");
		if(pArchivo != NULL)
		{
			result = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
			if(result == 1)
			{
				retorna = 1;
			}
			else
			{
				printf("ERROR\n");
			}
			fclose(pArchivo);
		}
	}

	return retorna;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int lastId)
{
	Passenger* nuevoPasajero;
	int retorna = -1;

	if(pArrayListPassenger != NULL)
	{
		retorna = 0;
		nuevoPasajero = Passenger_requestData(lastId);
		if(nuevoPasajero != NULL)
		{
			ll_add(pArrayListPassenger, nuevoPasajero);
			retorna = 1;
		}
	}
    return retorna;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* lecturaPasajeros;
	int cantidadPasajeros;
	int retorna = -1;

	if(pArrayListPassenger != NULL)
	{
		retorna = 0;
		cantidadPasajeros = ll_len(pArrayListPassenger);
		printf("**//////**///////////////////**////////////////**/////////////////**//////////////**///////////////**///////////////////**\n");
		printf("||   ID   ||     NOMBRE     ||    APELLIDO    ||     PRECIO     ||CODIGO DE VUELO||TIPO DE PASAJERO||ESTADO DEL VUELO||\n");
		printf("**//////**///////////////////**////////////////**/////////////////**//////////////**///////////////**//////////////////**\n");
		for(int i=0; i<cantidadPasajeros; i++)
		{
			lecturaPasajeros = ll_get(pArrayListPassenger, i);
			if(lecturaPasajeros != NULL)
			{
				Passenger_listOne(lecturaPasajeros);
				retorna = 1;
			}
		}
	}

	return retorna;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int opcion;
	int orden;
	int result;
	int retorna = -1;

	if(pArrayListPassenger != NULL)
	{
		retorna = 0;
		do
		{
			printf("1. Ordenar por ID.\n");
			printf("2. Ordenar por Nombre.\n");
			printf("3. Ordenar por Apellido.\n");
			printf("4. Ordenar por Precio.\n");
			printf("5. Ordenar por Codigo de vuelo.\n");
			printf("6. Ordenar por Tipo de Pasajero.\n");
			printf("7. Ordenar por Estado de vuelo.\n");
			PedirEntero(&opcion, "8. Regresar.", "Opcion invalida! Intente nuevamente.", 0, 9);
			switch(opcion)
			{
				case 1:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						result = ll_sort(pArrayListPassenger, Passenger_compareByID, orden);
						if(result == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 2:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						result = ll_sort(pArrayListPassenger, Passenger_compareByName, orden);
						if(result == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 3:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						result = ll_sort(pArrayListPassenger, Passenger_compareByLastName, orden);
						if(result == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 4:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						result = ll_sort(pArrayListPassenger, Passenger_compareByPrice, orden);
						if(result == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 5:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						result = ll_sort(pArrayListPassenger, Passenger_compareByFlyCode, orden);
						if(result == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 6:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						result = ll_sort(pArrayListPassenger, Passenger_compareByTypePassenger, orden);
						if(result == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
				case 7:
					PedirEntero(&orden, "Ingrese el tipo de orden:\n0.Descendente\n1.Ascendente\n2.Cancelar", "Opcion invalida! Intente nuevamente.", -1, 3);
					if(orden!=2)
					{
						printf("Ordenando...\n");
						result = ll_sort(pArrayListPassenger, Passenger_compareByStatusFlight, orden);
						if(result == 0)
						{
							printf("Ordenamiento realizado correctamente.\n");
						}
					}
					break;
			}
		}while(opcion != 8);
	}

	return retorna;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	Passenger* pPassenger;
	int retorna = -1;
	int cantidadPasajeros;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	char tipoPasajeroAuxiliar[50];
	char estadoVueloAuxiliar[50];

	pArchivo = fopen(path, "w");
	if(pArchivo != NULL)
	{
		retorna = 1;
		cantidadPasajeros = ll_len(pArrayListPassenger);
		for(int i=1; i<cantidadPasajeros; i++)
		{
			pPassenger = ll_get(pArrayListPassenger, i);
			if(Passenger_getId(pPassenger, &id)==0 &&
			   Passenger_getNombre(pPassenger, nombre)==0 &&
			   Passenger_getApellido(pPassenger, apellido)==0 &&
			   Passenger_getPrecio(pPassenger, &precio)==0 &&
			   Passenger_getCodigoVuelo(pPassenger, codigoVuelo)==0 &&
			   Passenger_getTipoPasajero(pPassenger, &tipoPasajero)==0 &&
			   Passenger_getEstado(pPassenger, &estadoVuelo)==0 &&
			   Passenger_showTipoPasajero(tipoPasajeroAuxiliar, tipoPasajero)==1 &&
			   Passenger_showEstadoVuelo(estadoVueloAuxiliar, estadoVuelo)==1)
			{
				fprintf(pArchivo, "%d,%s,%s,%f,%s,%s,%s\n", id,
															nombre,
															apellido,
															precio,
															codigoVuelo,
															tipoPasajeroAuxiliar,
															estadoVueloAuxiliar);
			}
			else
			{
				printf("No se pudo guardar un pasajero\n");
				retorna = 0;
			}
		}
		fclose(pArchivo);
	}

    return retorna;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorna;
    int i;
    int len;
    FILE* pArchivo;
    Passenger* auxiliarPasajero;
    retorna = -1;
    auxiliarPasajero = NULL;
    if(path!=NULL && pArrayListPassenger!=NULL)
    {
        len = ll_len(pArrayListPassenger);
        pArchivo = fopen(path,"wb");

        if(pArchivo!= NULL && len>0)
        {
            for(i=0; i<len ;i++)
            {
            	auxiliarPasajero = (Passenger*) ll_get(pArrayListPassenger,i);
                if(auxiliarPasajero!=NULL)
                {
                    fwrite(auxiliarPasajero,sizeof(Passenger),1,pArchivo);
                    retorna=1;
                }
            }
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
        fclose(pArchivo);
    }
    return retorna;
}

int controller_getLastID(char* path)
{
	FILE* pArchivo;
	int ultimoId = -1;
	if(path != NULL)
	{
		pArchivo = fopen(path, "rb");
		if(pArchivo != NULL)
		{
			fread(&ultimoId, sizeof(int), 1, pArchivo);
			fclose(pArchivo);
		}
	}

	return ultimoId;
}

int controller_saveLastID(char* path, LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	Passenger* pPasajero;
	int id = 0;
	int ultimoId = 0;
	int maxId = 0;
	int cantidadPasajeros;
	int flag = 0;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		ultimoId = controller_getLastID(path);
			if(ll_isEmpty(pArrayListPassenger)==0)
			{
				cantidadPasajeros = ll_len(pArrayListPassenger);
				for(int i=0; i<cantidadPasajeros; i++)
				{
					pPasajero = ll_get(pArrayListPassenger, i);
					if(pPasajero != NULL)
					{
						Passenger_getId(pPasajero, &id);
						if(id>maxId)
						{
							maxId = id;
						}
					}
				}
				if(maxId > ultimoId)
				{
					pArchivo = fopen(path, "wb");
					if(pArchivo != NULL)
					{
						fwrite(&maxId, sizeof(int), 1, pArchivo);
						fclose(pArchivo);
						flag = 1;
					}
				}
			}
			if(flag == 0)
			{
				maxId = ultimoId;
			}
	}

	return maxId;
}
