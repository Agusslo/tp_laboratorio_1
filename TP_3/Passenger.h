#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	int estadoVuelo;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametrosTxt(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoStr, char* tipoPasajeroStr, char* estadoStr);
Passenger* Passenger_requestData(int lastId);

void Passenger_delete(Passenger* this);

void Passenger_listOne(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstado(Passenger* this,int estado);
int Passenger_getEstado(Passenger* this,int* estado);

int Passenger_compareByID(void* p1, void* p2);
int Passenger_compareByName(void* p1, void* p2);
int Passenger_compareByLastName(void* p1, void* p2);
int Passenger_compareByPrice(void* p1, void* p2);
int Passenger_compareByFlyCode(void* p1, void* p2);
int Passenger_compareByTypePassenger(void* p1, void* p2);
int Passenger_compareByStatusFlight(void* p1, void* p2);

int Passenger_changeTipoPasajeroToInt(char* tipoPasajero);
int Passenger_showTipoPasajero(char* tipoPasajero, int numberTipoPasajero);

int Passenger_changeEstadoVueloToInt(char* estadoVuelo);
int Passenger_showEstadoVuelo(char* estadoVuelo, int numberEstadoVuelo);

#endif /* PASSENGER_H_ */
