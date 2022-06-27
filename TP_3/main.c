//compilacion arreglada
//tp3 actualizado*
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "InputsDatos.h"
#include "parser.h"

int main()
{
	setbuf(stdout, NULL);

	LinkedList* listaPasajeros;
	listaPasajeros = ll_newLinkedList();

	int opcion = 0;
	int result = 0;
	int flagListaCargada = 0;
	int flagUnPasajero = 0;
	int ultimoId;
	int flagDatosGuardados = 0;
	char* idPath = {"./lastID.txt"};
	char* path = {"./data.csv"};
	char* binaryPath = {"./new_data.bin"};
	do{
		ultimoId = controller_saveLastID(idPath, listaPasajeros);

		printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
		printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
		printf("3. Alta de pasajero.\n");
		printf("4. Modificar datos de pasajero.\n");
		printf("5. Baja de pasajero.\n");
		printf("6. Listar pasajeros.\n");
		printf("7. Ordenar pasajeros.\n");
		printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
		printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).\n");
		result = PedirEntero(&opcion, "10. Salir.", "Opcion invalida! Intente nuevamente.", 0, 11);
		if(result != 0)
		{
			printf("ERROR!\n");
		}
		switch(opcion)
		{
			case 1:
				if(flagListaCargada == 0)
				{
					result = controller_loadFromText(path,listaPasajeros);
					if(result == 1)
					{
						printf("Carga de datos exitosa!\n");
						flagListaCargada = 1;

						result = ll_len(listaPasajeros);
						printf("Elementos de la lista: %d\n", result);
					}
					else
					{
						printf("ERROR!\n");
					}
				}
				else
				{
					printf("Los datos ya fueron cargados.\n");
				}
				break;
			case 2:
				if(flagListaCargada == 0)
				{
					result = controller_loadFromBinary(binaryPath, listaPasajeros);
					if(result == 1)
					{
						printf("Carga de datos exitosa.\n");
						flagListaCargada = 1;
						result = ll_len(listaPasajeros);
						printf("Elementos de la lista: %d\n", result);
					}
					else
					{
						printf("ERROR!\n");
					}
				}
				else
				{
					printf("Los datos ya estan cargados.\n");
				}
				break;
			case 3:
				result = controller_addPassenger(listaPasajeros, ultimoId);
				if(result == 1)
				{
					printf("Pasajero cargado de forma exitosa.\n");
					flagUnPasajero = 1;
					flagDatosGuardados = 0;
				}
				else
				{
					printf("ERROR!\n");
				}
				break;
			case 4:
				if(flagListaCargada == 1 || flagUnPasajero == 1)
				{
					result = controller_editPassenger(listaPasajeros);
					if(result == 1)
					{
						flagDatosGuardados = 0;
					}
					else
					{
						printf("ERROR!\n");
					}
				}
				else
				{
					printf("No hay elementos para modificar.\n");
				}
				break;
			case 5:
				if(flagListaCargada == 1 || flagUnPasajero == 1)
				{
					result = controller_removePassenger(listaPasajeros);
					if(result == 1)
					{
						flagDatosGuardados = 0;
					}
					else
					{
						printf("ERROR!\n");
					}
				}
				else
				{
					printf("No hay elementos para eliminar.\n");
				}
				break;
			case 6:
				if(flagListaCargada == 1 || flagUnPasajero == 1)
				{
					result = controller_ListPassenger(listaPasajeros);
					if(result != 1)
					{
						printf("ERROR!\n");
					}
				}
				else
				{
					printf("No hay elementos para mostrar.\n");
				}
				break;
			case 7:
				if(flagListaCargada == 1 || flagUnPasajero == 1)
				{
					result = controller_sortPassenger(listaPasajeros);
					if(result != 0)
					{
						printf("ERROR!\n");
					}
				}
				else
				{
					printf("No hay elementos para ordenar.\n");
				}
				break;
			case 8:
				controller_saveAsText("data.csv",listaPasajeros);
				flagDatosGuardados = 1;
				break;
			case 9:
				if(!ll_isEmpty(listaPasajeros))
				{
					controller_saveAsBinary("new_data.bin",listaPasajeros);
					flagDatosGuardados = 1;
				}
				break;
			case 10:
				if(flagDatosGuardados == 0)
				{
					printf("Los datos no fueron guardados.\n");

				}
				else
				{
					printf("Cerrando aplicacion\n");
				}
				break;
		}
	}while(opcion != 10);

    return 0;
}
