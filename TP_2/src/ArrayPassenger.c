#include "ArrayPassenger.h"


int initPassengers(ePassenger list[], int tam)
{
	int index=-1;
	if(list!=NULL&&tam>0)
	{
		index=0;
		for(int i=0;i<tam;i++)
		{
			list[i].isEmpty=VACIO;
			break;
		}
	}
	return index;
}

int addPassenger(ePassenger list[], int tam, int id, char name[], char lastName[], float price, int typePassengerId, char flyCode[], int statusFlightId)
{
	int pasajero;
	int retorno=-1;
	pasajero=buscarLibre(list,tam);

		if(pasajero!=-1)
		{
			list[pasajero].id=id;
			strcpy(list[pasajero].name,name);
			strcpy(list[pasajero].lastName,lastName);
			list[pasajero].price=price;
			strcpy(list[pasajero].flyCode,flyCode);
			list[pasajero].typePassengerId=typePassengerId;
			list[pasajero].statusFlightId=statusFlightId;
			list[pasajero].isEmpty=LLENO;
			retorno=0;
		}
		else
		{
			retorno=-1;
		}
		return retorno;
}

int findPassengerById(ePassenger list[], int tam,int id)
{
	int respuesta=-1;

	for(int i;i<tam;i++)
	{
		if(list[i].id==id)
		{
			respuesta=i;
			break;
		}
	}
	return respuesta;
}

int removePassenger(ePassenger list[], int tam)
{
    int index;
    int aceptarEliminacion;
    int retorno =-1;
    int idIngresado;
    printf("ingrese id a remover");
    scanf("%d", &idIngresado);

    index = findPassengerById(list, tam, idIngresado);
    if(index != -1)
    {
        printf("\n Vas a eliminar a este pasajero: \n"
                "\n ID: %d \n"
                "\n Nombre: %s \n"
                "\n Apellido: %s \n"
                "\n Código de vuelo: %s \n"
                ,list[index].id
                ,list[index].name
                ,list[index].lastName
                ,list[index].flyCode);

        printf("\n Está usted seguro que es el pasajero que quiere borrar? Si es así, ingrese 1: \n");
        scanf("%d", &aceptarEliminacion);

        if(aceptarEliminacion == 1)
        {
            list[index].isEmpty = VACIO;
            retorno = 0;
        }
    }


    return retorno;

}

int sortPassengers(ePassenger list[],int tam, int order)
{
    ePassenger PasajeroAux;
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            if(((list[i].typePassengerId==list[j].typePassengerId) && strcmp(list[i].lastName,list[j].lastName)>0 && order==1)||
                        (list[i].typePassengerId>list[j].typePassengerId && order==1)||
                     ((list[i].typePassengerId== list[j].typePassengerId) && strcmp(list[i].lastName,list[j].lastName)<0 && order==0)||
                     (list[i].typePassengerId <list[j].typePassengerId && order==0))
            {
                PasajeroAux=list[i];
                list[i]=list[j];
                list[j]=PasajeroAux;
                retorno=0;
            }
        }

    }
    return retorno;
}

int printPassenger(ePassenger list[], int tam,eTypePassenger Tipos[],int tamTipos,eStatusFlight estadoVuelo[],int tamVuelo)
{




	printf("***Estado de Pasajeros****\n");
	printf(" ID	NOMBRE		APELLIDO	PRECIO	    CODIGOVUELO 		TIPO		ESTADO");

	for(int i=0;i<tam;i++)
	{
		if(list[i].isEmpty==LLENO)
		{
			mostrarConTipoYEstado(list[i],estadoVuelo,Tipos);
		}
	}


	return 0;
}

int sortPassengersByCode(ePassenger list[],int tam, int order)
{
    ePassenger PasajeroAux;
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            if(((list[i].statusFlightId==list[j].statusFlightId) && strcmp(list[i].flyCode,list[j].flyCode)>0 && order==1)
                       || (list[i].statusFlightId>list[j].statusFlightId&& order==1)
					   ||((list[i].statusFlightId== list[j].statusFlightId) && strcmp(list[i].flyCode,list[j].flyCode)<0 && order==0)
					   ||(list[i].statusFlightId <list[j].statusFlightId && order==0))
            {
                PasajeroAux=list[i];
                list[i]=list[j];
                list[j]=PasajeroAux;
                retorno=0;
            }
        }
    }
    return retorno;
}


