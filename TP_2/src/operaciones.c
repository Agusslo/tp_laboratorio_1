#include "ArrayPassenger.h"

static int idIncremental = 1000;
static int obtenerID();
static int obtenerID()
{
    return idIncremental++;
}

int pasajeros(ePassenger list[], int tam,int contador)
{
	int error;
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;

	id=obtenerID();

	printf("ingrese su nombre:");
	fflush(stdin);
	scanf("%s",name);
	printf("ingrese su apellido:");
	fflush(stdin);
	scanf("%s",lastName);
	printf("ingrese el precio:");
	fflush(stdin);
	scanf("%f",&price);
	typePassenger=tiposPasajeros();
	printf("ingrese codigo de vuelo:");
	fflush(stdin);
	scanf("%s",flyCode);
	statusFlight=estadoDelVuelo();
	printf("%d", statusFlight);
	error=addPassenger(list,tam,id,name,lastName,price,typePassenger,flyCode,statusFlight);
	if(error==-1)
	{
		printf("error\n");
	}
	else
	{
		printf("no hay error\n");
	}
	contador++;
	return contador;
}

int tiposPasajeros(void)
{
	int opcion;
	printf("ingrese el tipo de pasajero\n");
	printf("1 clase\n");
	printf("2 clase ejecutiva\n");
	printf("3 clase economica\n");
	fflush(stdin);
	scanf("%d",&opcion);

	while(opcion>3&&opcion<1)
	{
		printf("ingrese el tipo de pasajero\n");
		printf("1 clase\n");
		printf("2 clase ejecutiva\n");
		printf("3 clase economica\n");
		fflush(stdin);
		scanf("%d",&opcion);
	}
	return opcion;
}

int estadoDelVuelo(void)
{
	int opcion;

	printf("ingrese estado de vuelo\n");
	printf("1. en vuelo\n");
	printf("2. retrasado\n");
	printf("3. en horario\n");
	printf("4. por partir\n");
	fflush(stdin);
	scanf("%d",&opcion);

	while(opcion>4&&opcion<1)
	{
		printf("ingrese el tipo de pasajero\n");
		printf("1. en vuelo\n");
		printf("2. retrasado\n");
		printf("3. en horario\n");
		printf("4. por partir\n");
		fflush(stdin);
		scanf("%d",&opcion);
	}
		return opcion;
}



void modificarPasajero(ePassenger list[],int tam)
{
	ePassenger pasajero;
	int opcion;
	int index;
	int idIngresado;
	printf("ingrese id de la persona a modificar");
	scanf("%d", &idIngresado);

	index=findPassengerById(list,tam,idIngresado);
	if(index!=-1)
	{
		do{
			printf("que desea modificar\n");
			printf("1. nombre\n");
			printf("2. apellido\n");
			printf("3. precio\n");
			printf("4. tipo pasajero\n");
			printf("5. codigo vuelo\n");
			printf("6. ninguna modificacion\n");
			scanf("%d", &opcion);

			switch(opcion)
			{
			case 1:
				printf("ingrese su nombre");
				fflush(stdin);
				scanf("%s",pasajero.name);
				strcpy(list[index].name,pasajero.name);
				break;
			case 2:
				printf("ingrese su apellido");
				scanf("%s",pasajero.lastName);
				strcpy(list[index].lastName,pasajero.lastName);
				break;
			case 3:
				printf("ingrese el precio");
				fflush(stdin);
				scanf("%f",&pasajero.price);
				list[index].price=pasajero.price;
				break;
			case 4:
				pasajero.typePassengerId=tiposPasajeros();
				list[index].typePassengerId=pasajero.typePassengerId;
				break;
			case 5:
				printf("ingrese codigo de vuelo");
				fflush(stdin);
				scanf("%s",pasajero.flyCode);
				strcpy(list[index].flyCode,pasajero.flyCode);
				break;
			case 6:
				printf("saliendo de modificacion");
				break;
			default:
			printf("ingrese una opcion valida");
				break;
			}
		}while(opcion!=6);
	}

}

int buscarLibre(ePassenger list[], int tam)
{
    int index;

        for(int i=0;i<tam;i++)
        {
            if(list[i].isEmpty==0)
                {
                index=i;
                break;
                return index;
                }
            else
            {
                index=-1;
            }
        }
        return index;
}
int buscarEspacioLibre(ePassenger pasajero[], int tam)
{
    int rtn = -1;
    int indice;

    if(pasajero != NULL)
    {
        if (tam >= 0)
        {
            for (indice = 0; indice < tam; indice++)
            {
                //BUSCA EL PRIMER ESPACIO LIBRE DE MI ARRAY
                if(pasajero[indice].isEmpty == VACIO)
                {
                    rtn = indice;
                    break;
                }
            }
        }
    }
    return rtn;
}
void TotalYPromedio(ePassenger list[], int tam)
{
	float acumulador=0;
	int contador=0;
	int contadorSuperaPromedio=0;
	float promedio=0;
	for(int i=0;i<tam;i++)
	{
		if(list[i].isEmpty==LLENO)
		{
			acumulador=list[i].price+acumulador;
			contador++;
			promedio=acumulador/contador;

		}
	}
	for(int j=0;j<tam;j++)
				{
					if(list[j].price>promedio)
					{
						contadorSuperaPromedio++;
					}

				}
	printf("TOTAL:%.2f \nPROMEDIO:%.2f \nPersonas que superan el promedio:%d",acumulador,promedio,contadorSuperaPromedio);
}

void hardcodeo(ePassenger* list,int tam)
{
    int id[] = {1,2,3,4};
    char name[][51]= {"pedro","facundo","Lucas","Agustin"};
    char lastName[][51]= {"cancayo","Facundo","Avalos","Ledesma"};
    float price[]={10000,20000,30000,40000};
    char flycode[][10]= {"10a15z","15bc30","tlm500","czx700"};
    int typePassenger[]= {1,3,4,2};
    int statusFlight[]= {1,2,3,4};
    int isEmpty[]= {1,1,1,1};

    for(int i=0;i<4;i++)
    {
        list[i].id = id[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);
        list[i].price = price[i];
        strcpy(list[i].flyCode,flycode[i]);
        list[i].typePassengerId = typePassenger[i];
        list[i].statusFlightId = statusFlight[i];
        list[i].isEmpty = isEmpty[i];
    }
}



int informar(ePassenger list[], int tam,eTypePassenger Tipos[],int tamTipos,eStatusFlight estadoVuelo[],int tamVuelo)
{
	int order;
	int opcion;
	int respuesta=-1;
	printf("ordenar por: \n");
	printf("1.listado de los pasajeros ordenados alfabeticamente por apellido y tipo de pasajero\n ");
	printf("2. total y promedio de los precios de los pasajes y cuantos pasajeros superan el precio promedio\n ");
	printf(	"3.listado de los pasajeros por codigo de vuelo y estados de vuelo ACTIVO");
	scanf("%d", &opcion);
	do
	{
		switch(opcion)
		{
		case 1:
			printf("seleccione orden asc(1) desc(0)");
			scanf("%d", &order);
			sortPassengers(list, tam, order);
			printPassenger(list, tam, Tipos,3, estadoVuelo, 4);;
			break;
		case 2:
			TotalYPromedio(list,tam);
			break;
		case 3:
		printf("seleccione orden asc(1) desc(0)");
		scanf("%d", &order);
		sortPassengersByCode(list, tam, order);
		printPassenger(list, tam, Tipos,3, estadoVuelo, 4);
		break;
		}
	}while(opcion!=6);
	respuesta=0;
	return respuesta;
}

void mostrarUnPasajero(ePassenger list)
{
	printf("\n%4d 		%4s 		%4s 		%4.2f 		%4s 		%4d 		%4d\n",
						list.id,
						list.name,
						list.lastName,
						list.price,
						list.flyCode,
						list.typePassengerId,
						list.statusFlightId);
}
void mostarListaPasajero(ePassenger list[], int tam)
{
	for(int i=0;i<tam;i++)
	{
		if(list[i].isEmpty==LLENO)
		{
			mostrarUnPasajero(list[i]);
		}
	}
}

void mostrarConTipoYEstado(ePassenger list,eStatusFlight estadoVuelo[],eTypePassenger Tipos[])
{
	int indexTipo;
	int indexVuelo;
	if(list.isEmpty==LLENO)
			{
				indexTipo=printType(list, Tipos, TAMTIPOS);
				indexVuelo=printVuelo(list, estadoVuelo, TAMVUELOS);

				printf("\n%5d		%-5s	%-5s			%-5.2f		%-5s 			%-5s  %-5s\n",
						list.id,
						list.name,
						list.lastName,
						list.price,
						list.flyCode,
						Tipos[indexTipo].tipoPasajero,
						estadoVuelo[indexVuelo].estadoVuelo);

			}
}

int printType(ePassenger pasajero,eTypePassenger Tipos[],int tamTipos)
{
	int index;
	for(int i=0;i<tamTipos;i++)
	{
		if(pasajero.typePassengerId==Tipos[i].id)
		{
			index=i;
			break;
		}
	}
	return index;
}
int printVuelo(ePassenger pasajero,eStatusFlight estadoVuelo[], int tamVuelo)
{
	int index;
	for(int i=0;i<tamVuelo;i++)
	{
		if(pasajero.statusFlightId==estadoVuelo[i].id)
		{
			index=i;
			break;
		}
	}
	return index;
}
