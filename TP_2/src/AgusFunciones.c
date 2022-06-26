#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"

int agregarPasajero(Passenger list[], int size)
{
	int error;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int typePassenger;
	char flycode[10];
	int statusflight;

	id=buscarlibre(list,size);
	id++;
	pedirCadena(nombre,"ingrese su nombre:","no se a ingresado un nombre valido,reingrese su nombre",51);
	pedirCadena(apellido,"ingrese su apellido:","no se a ingresado un apellido valido,reingrese su apellido",51);
	pedirFlotante(&precio,"ingrese el precio","no se a ingresado un numero valido",1,100000000000);
	pedirEntero(&typePassenger,"ingrese el tipo de pasajero (1 primera clase,2 clase ejecutiva,3 clase economica)","no se a ingresado un numero valido",1,3);
	pedirCadena(flycode,"ingrese el codigo de vuelo:","no se a ingresado un codigo valido,reingrese su codigo",10);
	pedirEntero(&statusflight,"ingrese el estado de vuelo: (1 activo,2 retrasado,3 inactivo)","no se a ingresado un numero valido",1,3);

	error=addPassengers(list,size,id,nombre,apellido,precio,typePassenger,flycode,statusflight);

		if(error == -1)
		{
			printf("ocurrio un error en la carga.\n");
		}
		else
		{
			printf("carga exitosa!\n");
		}


return error;
}

int buscarlibre(Passenger list[], int size)
{

	int i;
	int index;

	index = -1;

	for(i=0;i<size; i++)
	{
		if(list[i].isEmpty == Empty)
		{
			index=i;
			break;
		}
	}
	return index;
}

int modificar(Passenger list[], int len)
{
	int respuesta;
	int id;

	pedirEntero(&id,"ingrese el id del pasajero que quiera modificar:","no se a ingresado un numero valido",1,2000);

	respuesta = findPassengersById(list,len,id);
	if(respuesta != 0)
	{
		modificarPasajero(list,len,respuesta);
	}

return respuesta;
}

void modificarPasajero( Passenger list[], int len ,int id)
{
	Passenger pasajero;
	int opcion;
	char name [51];
	char lastname[51];
	float precio;
	int typePassenger;
	char flycode[10];

	do
	{
		printf("que dato desea modificar?\n");
		printf("1 nombre\n");
		printf("2 apellido\n");
		printf("3 precio\n");
		printf("4 tipo de pasajero\n");
		printf("5 codigo de vuelo\n");
		printf("6 ninguno\n");
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			pedirCadena(name,"ingrese su nombre:","no se a ingresado un nombre valido,reingrese su nombre",51);
			strcpy(pasajero.name,name);
			break;
		case 2:
			pedirCadena(lastname,"ingrese su apellido:","no se a ingresado un apellido valido,reingrese su apellido",51);
			strcpy(pasajero.lastname,lastname);
			break;
		case 3:
			pedirFlotante(&precio,"ingrese el precio","no se a ingresado un numero valido",1,100000000000);
			pasajero.price = precio;
			break;
		case 4:
			pedirEntero(&typePassenger,"ingrese el tipo de pasajero (1 primera clase,2 clase ejecutiva,3 clase economica)","no se a ingresado un numero valido",1,3);
			 pasajero.typePassenger = typePassenger;
			break;
		case 5:
			pedirCadena(flycode,"ingrese el codigo de vuelo:","no se a ingresado un codigo valido,reingrese su codigo",10);
			strcpy(pasajero.flycode,flycode);
			break;
		case 6:
			printf("fin de la modificacion...");
			break;
		default:
			printf("ingrese una opcion valida");
			break;
		}
		list[id]=pasajero;
	}while(opcion != 6);
}
int eliminarPasajero(Passenger list[], int len)
{
	int respuesta;
	int id;
	pedirEntero(&id,"ingrese el id del pasajero que quiera modificar:","no se a ingresado un numero valido",1,2000);

	respuesta = removePassenger(list,len,id);

	return respuesta;
}

void mostrar(Passenger* pasajero)
{

	if(pasajero->isEmpty == Full)
	{
		printf("\n %d %8s %8s %8.2f %8s %8d %8d \n",pasajero->id,pasajero->name,pasajero->lastname,pasajero->price,pasajero->flycode,pasajero->typePassenger,pasajero->statusflight);
	}


}
int hardcodeo(Passenger list[],int len)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		Passenger aux [] =
		{
				{1001,"pedro","armando",5000,"codigo01",1,2,Full},
				{1002,"ivan","messi",6000,"codigo02",3,1,Full},
				{1003,"matias","lopez",8000,"codigo03",2,2,Full},
				{1004,"octavio","villegas",9000,"codigo04",3,4,Full},
				{1005,"marta","tavez",10000,"codigo05",2,3,Full}
		};
		for(int i=0;i<len;i++)//recorro y cargo
		{
			list[i]=aux[i];
		}
		retorno=0;
	}
	return retorno;
}
int ordenarPorApellido(Passenger list[],int len)
{
	Passenger aux;
	int orden;

		int retorno = -1;
		pedirEntero(&orden,"ingrese el orden en que desee ordenarlo 1: descendiente 2: ascendente","no se a ingresado un numero valido",1,2);
		if(orden == 1)
		{
			if(list != NULL && len>0)
			{
			for(int i = 0;i<len-1;i++)
			{
				for(int j = i + 1;j<len;j++)
				{
					if(stricmp(list[i].lastname,list[i+1].lastname) > 0)
					{
						aux=list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno=0;
		}
		else
		{
			if(list != NULL && len>0)
		{
					for(int i = 0;i<len-1;i++)
					{
						for(int j = i + 1;j<len;j++)
						{
							if(stricmp(list[i].lastname,list[i+1].lastname) < 0)
							{
								aux=list[i];
								list[i] = list[j];
								list[j] = aux;
							}
						}
					}
		}

			retorno=0;
		}

		}
			return retorno;
}
int ordenarPorcodigo(Passenger list[],int len)
{
	Passenger aux;
	int orden;
			int retorno = -1;

			pedirEntero(&orden,"ingrese el orden en que desee ordenarlo 1: descendiente 2: ascendente","no se a ingresado un numero valido",1,2);
			if(orden == 1)
			{
				if(list != NULL && len>0)
				{
					for(int i = 0;i<len-1;i++)
						{
							for(int j = i + 1;j<len;j++)
							{
								if(stricmp(list[i].flycode,list[i+1].flycode) > 0)
								{
									if(list[i].statusflight == Full)
									{
										aux=list[i];
										list[i] = list[j];
										list[j] = aux;
									}
								}
							}
						 }
					retorno=0;
				}
			}
			if(orden == 2)
			{
				if(list != NULL && len>0)
				{
					for(int i = 0;i<len-1;i++)
						{
							for(int j = i + 1;j<len;j++)
							{
								if(stricmp(list[i].flycode,list[i+1].flycode) < 0)
								{
									if(list[i].statusflight == Full)
									{
										aux=list[i];
										list[i] = list[j];
										list[j] = aux;
									}
								}
							}
						}
					retorno=0;
				}
			}




		return retorno;
}
int totalPrecio(Passenger list[],int len)
{
	float suma=0;

	for(int i = 0;i<len;i++)
	{
		if(list[i].isEmpty == Full)
		{
			suma+=list[i].price;
		}
	}
	return suma;
}
int promedioPrecios(Passenger list[],int len)
{
	int contador = 0;
	float promedio;
	float total;
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == Full)
		{
			contador++;
		}
	}
	total=totalPrecio(list,len);

	promedio=total/contador;

	return promedio;
}
int cantPasajeros(Passenger list[],int len)
{
	float promedio;
	int contador=0;
	promedio=promedioPrecios(list,len);
	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == Full)
		{
			if(list[i].price > promedio)
			{
				contador++;
			}
		}
	}
	return contador;
}

int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max)
{
    int retorno = -1;
    char buffer[256];
    int tam;

    if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", buffer);
        tam = strlen(buffer);

        while(tam > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%[^\n]", buffer);
            tam = strlen(buffer);
        }

        strcpy(cadena, buffer);
        retorno = 0;
    }

    return retorno;
}
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max)
{
    int retorno = -1;
    float numeroIngresado;

    if(flotante != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%f", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%f", &numeroIngresado);
        }

        *flotante = numeroIngresado;
        retorno = 0;
    }

    return retorno;
}
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
    int retorno = -1;
    int numeroIngresado;

    if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%d", &numeroIngresado);

        while(numeroIngresado < min || numeroIngresado > max)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", &numeroIngresado);
        }

        *entero = numeroIngresado;
        retorno = 0;
    }

    return retorno;
}
