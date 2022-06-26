/*
Agustin Lopez
TP2 actualizado
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"


int main(void)
{
	setbuf(stdout,NULL);

	Passenger list[limit];
	int opcion;
	int decision;
	int error;
	float total;
	float promedio;
	int cantidad;
	int bandera = 0;

	initPassengers(list,limit);


	do
	{
		printf("ingrese la opcion que quiera\n");
		printf("1 ALTAS \n");
		printf("2 MODIFICAR\n");
		printf("3 BAJA\n");
		printf("4 informe de resultados:\n");
		printf("5 alta forzada:\n");
		printf("6 salir\n");

		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			agregarPasajero(list,limit);
			bandera = 1;
			break;
		case 2:
			if(bandera == 1)
			{
				error=modificar(list,limit);
				if(error == 0)
				{
					printf("no se a encontrado el id\n");
				}
				else
				{
					printf("modificacion exitosa\n");
				}
			}
			else
			{
				printf("nesecita ingresar un pasajero primero\n");
			}
			break;
		case 3:
			if(bandera == 1)
			{
				error=eliminarPasajero(list,limit);
				if(error == 0)
				{
					printf("no se a encontrado el id\n");
				}
				else
				{
					printf("se a eliminado el pasajero con exito.\n");
				}
			}
			else
			{
				printf("nesecita ingresar un pasajero primero\n");
		    }
			break;
		case 4:
			if(bandera == 1)
			{
				pedirEntero(&decision,"ingrese el listado que desea 1: ordenado por apellido 2: listado de precios y promedio, precios que superan el promedio. 3:ordenado por codigo y estado activo(1)","no se a ingresado un numero valido",1,3);
				switch(decision)
				{
				case 1:
					ordenarPorApellido(list,limit);
					error=printPassengers(list,limit);
					break;
				case 2:
					printf("la suma total de precios es:\n");
					total=totalPrecio(list,limit);
					printf("%2.f",total);
					printf("el promedio de precios es:\n");
					promedio=promedioPrecios(list,limit);
					printf("%2.f",promedio);
					printf("la cantidad de pasajeros que superan el precio promedio es:\n");
					cantidad=cantPasajeros(list,limit);
					printf("%d",cantidad);
					break;
				case 3:
					ordenarPorcodigo(list,limit);
					error=printPassengers(list,limit);
					break;
				}
			}
			else
			{
				printf("nesecita ingresar un pasajero primero\n");
			}

			break;
		case 5:
			hardcodeo(list,tamHardcodeo);
			printPassengers(list,tamHardcodeo);
			printf("carga forzada...\n");


			break;
		case 6:
			printf("saliendo del programa, hasta la proxima.\n");
			system("pause");
			break;
		default:
			printf("elegi una opcion valida...\n");
			break;

		}
	}while(opcion!=6);


	return 0;
}
