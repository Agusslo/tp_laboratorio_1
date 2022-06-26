#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"


int initPassengers( Passenger list[], int len)
{
	int i;
	int estado;

	estado = -1;
	if(len == limit)
	{
		estado=0;
		for(i=0;i<len; i++)
		{
			list[i].isEmpty = Empty;
		}
	}
	return estado;
}

int addPassengers(Passenger list[], int len, int id, char name[],char lastname[],float price,int typePassenger, char flycode [],int statusflight)
{

	int retorno= -1;
	int indice;
	if(list != NULL && len > 0)
	{
		indice=buscarlibre(list,len);
		if(indice != -1)
		{
			list[indice].id = id;
			strcpy(list[indice].name,name);
			strcpy(list[indice].lastname,lastname);
			list[indice].price = price;
			strcpy(list[indice].flycode,flycode);
			list[indice].typePassenger = typePassenger;
			list[indice].statusflight = statusflight;
			list[indice].isEmpty = Full;
			retorno = 0;
		}
	}

	return retorno;
}

int findPassengersById( Passenger list[], int len ,int id)
{
	int respuesta=0;

	for(int i = 0;i<len;i++)
	{
		if(list[i].id == id)
		{
			respuesta=id;
			break;
		}
	}
	return respuesta;
}

int removePassenger( Passenger list[], int len ,int id)
{
	int respuesta=0;
	for(int i = 0;i<len;i++)
		{
			if(list[i].id == id)
			{
				list[i].isEmpty = Empty;
				respuesta=1;
				break;
			}
		}
	return respuesta;
}

int printPassengers(Passenger list[], int len)
{
	int respuesta = 0;
	printf("ID       NOMBRE     APELLIDO       PRECIO      CODIGO      TIPO     ESTADO\n");
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == Full && list != NULL)
		{
			mostrar(&list[i]);
		}
	}
    respuesta = 1;
	return respuesta;
}

int sortPassenger(Passenger list[],int len,int order)
{
	order= ordenarPorApellido(list,len);
		return 0;
}


int sortPassengersByCode( Passenger list[], int len ,int order)
{
	order=ordenarPorcodigo(list,len);
	return 0;
}
