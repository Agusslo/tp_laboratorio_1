#include "Passenger.h"
#include "InputsDatos.h"
#define ClaseEconomica "1"
#define ClaseExclusiva "2"
#define PrimeraClase "3"
#define EstadoAterrizaje "1"
#define EstatusDemora "2"
#define EstatusEnHora "3"
#define EstatusEnVuelo "4"

Passenger* Passenger_new()
{
	Passenger* auxPasajero = NULL;
	auxPasajero = (Passenger*) malloc(sizeof(Passenger));
	return auxPasajero;
}

Passenger* Passenger_newParametrosTxt(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoStr, char* tipoPasajeroStr, char* estadoStr)
{
	Passenger* pPasajero = NULL;
	int idAuxiliar;
	float precioAuxiliar;
	int tipoPasajeroAuxiliar;
	int estadoAuxiliar;
	int flag = 0;
	pPasajero = Passenger_new();
	if(pPasajero != NULL)
	{
		if(Passenger_changeEstadoVueloToInt(estadoStr)==1 &&
		   Passenger_changeTipoPasajeroToInt(tipoPasajeroStr)==1 &&
		   isNumber(idStr, sizeof(idStr))==1 &&
		   isNumber(tipoPasajeroStr, sizeof(tipoPasajeroStr))==1 &&
		   isNumber(estadoStr, sizeof(estadoStr))==1 &&
		   isFloat(precioStr, sizeof(precioStr))==1)
		{
			idAuxiliar = atoi(idStr);
			tipoPasajeroAuxiliar = atoi(tipoPasajeroStr);
			estadoAuxiliar = atoi(estadoStr);
			precioAuxiliar = atof(precioStr);

			if(Passenger_setId(pPasajero, idAuxiliar)==0 &&
			   Passenger_setNombre(pPasajero, nombreStr)==0 &&
			   Passenger_setApellido(pPasajero, apellidoStr)==0 &&
			   Passenger_setPrecio(pPasajero, precioAuxiliar)==0 &&
			   Passenger_setCodigoVuelo(pPasajero, codigoStr)==0 &&
			   Passenger_setTipoPasajero(pPasajero, tipoPasajeroAuxiliar)==0 &&
			   Passenger_setEstado(pPasajero, estadoAuxiliar)==0)
			{
				flag = 1;
			}
		}
		if(flag == 0)
		{
			Passenger_delete(pPasajero);
			pPasajero = NULL;
		}
	}

	return pPasajero;
}

Passenger* Passenger_requestData(int lastId)
{
	Passenger* unPasajero;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	int estadoVuelo;
	unPasajero = Passenger_new();
	if(unPasajero != NULL)
	{
		if(PedirString("Ingrese su nombre:", "ERROR! Ingrese un nombre real", nombre, sizeof(nombre))==0 &&
		   PedirString("Ingrese su apellido:", "ERROR! Ingrese un apellido real", apellido, sizeof(apellido))==0 &&
		   PedirFlotante(&precio, "Ingrese el precio del pasaje:", "ERROR! Ingrese un precio valido:", 0, 999999999)==0 &&
		   PedirStringAlfaNumerico("Ingrese su codigo de vuelo:", "ERROR! Ingrese un codigo valido:", codigoVuelo, sizeof(codigoVuelo))==0 &&
		   PedirEntero(&tipoPasajero, "Elija el tipo de pasajero correspondiente:\n1.Economy Class.\n2.Executive Class.\n3.FirstClass.",
				   "ERROR! Ingrese una opcion valida.\n1.Economy Class.\n2.Executive Class.\n3.FirstClass.", 0, 4)==0 &&
		   PedirEntero(&estadoVuelo, "Elija el estado del vuelo correspondiente:\n1.Aterrizado.\n2.Demorado.\n3.En horario.\n4.En vuelo.",
				   "ERROR! Ingrese una opcion valida.\n1.Aterrizado.\n2.Demorado.\n3.En horario.\n4.En vuelo.", 0, 5)==0)
		{
			id = lastId + 1;
			if(Passenger_setId(unPasajero, id)!=0 ||
			   Passenger_setNombre(unPasajero, nombre)!=0 ||
			   Passenger_setApellido(unPasajero, apellido)!=0 ||
			   Passenger_setPrecio(unPasajero, precio)!=0 ||
			   Passenger_setCodigoVuelo(unPasajero, codigoVuelo)!=0 ||
			   Passenger_setTipoPasajero(unPasajero, tipoPasajero)!=0 ||
			   Passenger_setEstado(unPasajero, estadoVuelo)!=0)
			{
				Passenger_delete(unPasajero);
				unPasajero = NULL;
			}
		}
	}

	return unPasajero;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_compareByID(void* p1, void* p2)
{
	int id1;
	int id2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	int comparar;

	comparar = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getId(pasajero1, &id1);
	Passenger_getId(pasajero2, &id2);

	if(id1 > id2)
	{
		comparar = 1;
	}
	else
	{
		if(id1 < id2)
		{
			comparar = -1;
		}
	}

	return comparar;
}

int Passenger_compareByName(void* p1, void* p2)
{
	int comparacion;
	char nombre1[50];
	char nombre2[50];
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getNombre(pasajero1, nombre1);
	Passenger_getNombre(pasajero2, nombre2);

	comparacion = strcmp(nombre1, nombre2);
	if(comparacion < 0)
	{
		comparacion = -1;
	}
	else
	{
		if(comparacion > 0)
		{
			comparacion = 1;
		}
	}
	return comparacion;
}

int Passenger_compareByLastName(void* p1, void* p2)
{
	int comparacion;
	char apellido1[50];
	char apellido2[50];
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getApellido(pasajero1, apellido1);
	Passenger_getApellido(pasajero2, apellido2);

	comparacion = strcmp(apellido1, apellido2);
	if(comparacion < 0)
	{
		comparacion = -1;
	}
	else
	{
		if(comparacion > 0)
		{
			comparacion = 1;
		}
	}
	return comparacion;
}

int Passenger_compareByPrice(void* p1, void* p2)
{
	float price1;
	float price2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	int comparar;

	comparar = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getPrecio(pasajero1, &price1);
	Passenger_getPrecio(pasajero2, &price2);

	if(price1 > price2)
	{
		comparar = 1;
	}
	else
	{
		if(price1 < price2)
		{
			comparar = -1;
		}
	}

	return comparar;
}

int Passenger_compareByFlyCode(void* p1, void* p2)
{
	int comparacion;
	char codigoVuelo1[50];
	char codigoVuelo2[50];
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getCodigoVuelo(pasajero1, codigoVuelo1);
	Passenger_getCodigoVuelo(pasajero2, codigoVuelo2);

	comparacion = strcmp(codigoVuelo1, codigoVuelo2);
	if(comparacion < 0)
	{
		comparacion = -1;
	}
	else
	{
		if(comparacion > 0)
		{
			comparacion = 1;
		}
	}
	return comparacion;
}

int Passenger_compareByTypePassenger(void* p1, void* p2)
{
	int tipoPasajero1;
	int tipoPasajero2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	int comparar;

	comparar = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getTipoPasajero(pasajero1, &tipoPasajero1);
	Passenger_getTipoPasajero(pasajero2, &tipoPasajero2);

	if(tipoPasajero1 > tipoPasajero2)
	{
		comparar = 1;
	}
	else
	{
		if(tipoPasajero1 < tipoPasajero2)
		{
			comparar = -1;
		}
	}

	return comparar;
}
int Passenger_compareByStatusFlight(void* p1, void* p2)
{
	int estadoVuelo1;
	int estadoVuelo2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	int comparar;

	comparar = 0;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	Passenger_getEstado(pasajero1, &estadoVuelo1);
	Passenger_getEstado(pasajero2, &estadoVuelo2);

	if(estadoVuelo1 > estadoVuelo2)
	{
		comparar = 1;
	}
	else
	{
		if(estadoVuelo1 < estadoVuelo2)
		{
			comparar = -1;
		}
	}

	return comparar;
}

void Passenger_listOne(Passenger* this)
{
	char tipoPasajeroAuxiliar[50];
	char estadoVueloAuxiliar[50];
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	int estadoVuelo;

	if(Passenger_getId(this, &id)==0 &&
	   Passenger_getNombre(this, nombre)==0 &&
	   Passenger_getApellido(this, apellido)==0 &&
	   Passenger_getPrecio(this, &precio)==0 &&
	   Passenger_getCodigoVuelo(this, codigoVuelo)==0 &&
	   Passenger_getTipoPasajero(this, &tipoPasajero)==0 &&
	   Passenger_getEstado(this, &estadoVuelo)==0 &&
	   Passenger_showTipoPasajero(tipoPasajeroAuxiliar, tipoPasajero)==1 &&
	   Passenger_showEstadoVuelo(estadoVueloAuxiliar, estadoVuelo)==1)
	{
		printf("||%8d||%16s||%16s||%16.2f||%15s||%16s||%16s||\n",
				id,
				nombre,
				apellido,
				precio,
				codigoVuelo,
				tipoPasajeroAuxiliar,
				estadoVueloAuxiliar);
	}
	else
	{
		printf("No se pudo mostrar al pasajero.\n");
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retornoo = -1;

	if(this != NULL && id > 0)
	{
		retornoo = 0;
		this->id = id;
	}
	return retornoo;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retornooo = -1;

	if(this != NULL && id != NULL)
	{
		retornooo = 0;
		*id = this->id;
	}
	return retornooo;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retornooo = -1;

	if(this != NULL && nombre != NULL)
	{
		retornooo = 0;
		strcpy(this->nombre, nombre);
	}
	return retornooo;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retornooo = -1;

	if(this != NULL && nombre != NULL)
	{
		retornooo = 0;
		strcpy(nombre, this->nombre);
	}
	return retornooo;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retornooo = -1;

	if(this != NULL && apellido != NULL)
	{
		retornooo = 0;
		strcpy(this->apellido, apellido);
	}
	return retornooo;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retornooo = -1;

	if(this != NULL && apellido != NULL)
	{
		retornooo = 0;
		strcpy(apellido, this->apellido);
	}
	return retornooo;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retornooo = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		retornooo = 0;
		strcpy(this->codigoVuelo, codigoVuelo);
	}
	return retornooo;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retornooo = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		retornooo = 0;
		strcpy(codigoVuelo, this->codigoVuelo);
	}
	return retornooo;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retornooo = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		retornooo = 0;
		this->tipoPasajero = tipoPasajero;
	}
	return retornooo;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retornooo = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		retornooo = 0;
		*tipoPasajero = this->tipoPasajero;
	}
	return retornooo;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retornooo = -1;

	if(this != NULL && precio > 0)
	{
		retornooo = 0;
		this->precio = precio;
	}
	return retornooo;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retornooo = -1;

	if(this != NULL && precio != NULL)
	{
		retornooo = 0;
		*precio = this->precio;
	}
	return retornooo;
}


int Passenger_setEstado(Passenger* this,int estado)
{
	int retornooo = -1;

	if(this != NULL && estado > 0)
	{
		retornooo = 0;
		this->estadoVuelo = estado;
	}
	return retornooo;
}

int Passenger_getEstado(Passenger* this,int* estado)
{
	int retornooo = -1;

	if(this != NULL && estado != NULL)
	{
		retornooo = 0;
		*estado = this->estadoVuelo;
	}
	return retornooo;
}

int Passenger_changeTipoPasajeroToInt(char* tipoPasajero)
{
	int retornooo = -1;
	if(tipoPasajero != NULL)
	{
		retornooo = 0;
		if(strcmp(tipoPasajero, "FirstClass")==0)
		{
			strcpy(tipoPasajero, PrimeraClase);
			retornooo = 1;
		}
		else
		{
			if(strcmp(tipoPasajero, "ExecutiveClass")==0)
			{
				strcpy(tipoPasajero, ClaseExclusiva);
				retornooo = 1;
			}
			else
			{
				strcpy(tipoPasajero, ClaseEconomica);
				retornooo = 1;
			}
		}
	}
	return retornooo;
}

int Passenger_showTipoPasajero(char* tipoPasajero, int numeroTipoPasajero)
{
	int retornooo = -1;
	if(tipoPasajero != NULL && numeroTipoPasajero > 0)
	{
		retornooo = 0;
		switch(numeroTipoPasajero)
		{
			case 1:
				strcpy(tipoPasajero, "EconomyClass");
				retornooo = 1;
				break;
			case 2:
				strcpy(tipoPasajero, "ExecutiveClass");
				retornooo = 1;
				break;
			case 3:
				strcpy(tipoPasajero, "FirstClass");
				retornooo = 1;
				break;
		}
	}
	return retornooo;
}

int Passenger_changeEstadoVueloToInt(char* estadoVuelo)
{
	int retornoo = -1;
	if(estadoVuelo != NULL)
	{
		retornoo = 0;
		if(strcmp(estadoVuelo, "Aterrizado")==0)
		{
			strcpy(estadoVuelo, EstadoAterrizaje);
			retornoo = 1;
		}
		else
		{
			if(strcmp(estadoVuelo, "En Horario")==0)
			{
				strcpy(estadoVuelo, EstatusEnHora);
				retornoo = 1;
			}
			else
			{
				if(strcmp(estadoVuelo, "En Vuelo")==0)
				{
					strcpy(estadoVuelo, EstatusEnVuelo);
					retornoo = 1;
				}
				else
				{
					strcpy(estadoVuelo, EstatusDemora);
					retornoo = 1;
				}
			}
		}
	}
	return retornoo;
}

int Passenger_showEstadoVuelo(char* estadoVuelo, int numeroEstadoVuelo)
{
	int retornoo = -1;
	if(estadoVuelo != NULL && numeroEstadoVuelo > 0)
	{
		retornoo = 0;
		switch(numeroEstadoVuelo)
		{
			case 1:
				strcpy(estadoVuelo, "Aterrizado");
				retornoo = 1;
				break;
			case 2:
				strcpy(estadoVuelo, "Demorado");
				retornoo = 1;
				break;
			case 3:
				strcpy(estadoVuelo, "En Horario");
				retornoo = 1;
				break;
			case 4:
				strcpy(estadoVuelo, "En Vuelo");
				retornoo = 1;
				break;
		}
	}
	return retornoo;
}
