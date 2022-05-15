#include <stdio.h>
#include <stdlib.h>
#define ARRAYPASSENGER_H_
#define LLENO 1
#define VACIO 0
#define TAM 2000
#define TAMTIPOS 3
#define TAMVUELOS 4
#include <string.h>

typedef struct
{
	int id;
	char estadoVuelo[20];
}eStatusFlight;

typedef struct
{
	int id;
	char tipoPasajero[20];
}eTypePassenger;

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassengerId;
	int statusFlightId;
	int isEmpty;
}ePassenger;


//funciones obligatorias
/// @brief establece todos los arrays en vacios
///
/// @param list
/// @param tam
/// @return
int initPassengers(ePassenger list[], int tam);
/// @brief pide los datos al usuario
///
/// @param list
/// @param tam
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassengerId
/// @param flyCode
/// @param statusFlightId
/// @return
int addPassenger(ePassenger list[], int tam, int id, char name[], char lastName[], float price, int typePassengerId, char flyCode[], int statusFlightId);
/// @brief encuentra al pasajero por su id y devuelve su pocicion en el array
///
/// @param list
/// @param tam
/// @param id
/// @return
int findPassengerById(ePassenger list[], int tam,int id);
/// @brief remueve el pasajero por su id
///
/// @param list
/// @param tam
/// @return
int removePassenger(ePassenger list[], int tam);
/// @brief ordena alfabeticamente por apellido en ascendente y descendente
///
/// @param list
/// @param tam
/// @param order
/// @return
int sortPassengers(ePassenger list[],int tam, int order);
/// @brief imprime los datos del user
///
/// @param list
/// @param tam
/// @param Tipos
/// @param tamTipos
/// @param estadoVuelo
/// @param tamVuelo
/// @return
int printPassenger(ePassenger list[], int tam,eTypePassenger Tipos[],int tamTipos,eStatusFlight estadoVuelo[],int tamVuelo);
/// @brief ordenta los arrays en funcion de su codigo y estado de vuelo de manera ascendente y descendente
///
/// @param list
/// @param tam
/// @param order
/// @return
int sortPassengersByCode(ePassenger list[],int tam, int order);


//funciones de Agustin Lopez:)
/// @brief pide datos del pasajero
///
/// @param list
/// @param tam
/// @param contador
/// @returns
int pasajeros(ePassenger list[], int tam,int contador);
/// @brief establece un tipo de pasajero
///
/// @return
int tiposPasajeros(void);
/// @brief establece el estado del vuelo
///
/// @return
int estadoDelVuelo(void);
/// @brief modifica al pasajero segun su id
///
/// @param list
/// @param tam
void modificarPasajero(ePassenger list[],int tam);
/// @brief busca un espacio libre de los arrays
///
/// @param list
/// @param tam
/// @return
int buscarLibre(ePassenger list[], int tam);
/// @brief busca un espacio libre de los arrays
///
///
/// @param pasajero
/// @param tam
/// @return
int buscarEspacioLibre(ePassenger pasajero[], int tam);
/// @brief acumulador de todos los precios
///
/// @param list
/// @param tam
void totalYPromedio(ePassenger list[], int tam);
/// @brief es la carga forzada, introduce arrays de pasajeros previamente escritos
///
/// @param list
/// @param tam
void hardcoreo(ePassenger* list,int tam);
/// @brief muestra informacion en forma de menu
///
/// @param list
/// @param tam
/// @param Tipos
/// @param tamTipos
/// @param estadoVuelo
/// @param tamVuelo
/// @return
int informar(ePassenger list[], int tam,eTypePassenger Tipos[],int tamTipos,eStatusFlight estadoVuelo[],int tamVuelo);
/// @brief muestra un pasajero con su tipo de vuelo y su estado
///
/// @param list
/// @param estadoVuelo
/// @param Tipos
void mostrarConTipoYEstado(ePassenger list,eStatusFlight estadoVuelo[],eTypePassenger Tipos[]);
/// @brief imprime el tipo de pasajero dependiendo del caracter en funcion de la descripcion
///
/// @param pasajero
/// @param Tipos
/// @param tamTipos
/// @return
int printType(ePassenger pasajero,eTypePassenger Tipos[],int tamTipos);
/// @brief pasa carecter de vuelo a descripcion
///
/// @param pasajero
/// @param estadoVuelo
/// @param tamVuelo
/// @return
int printVuelo(ePassenger pasajero,eStatusFlight estadoVuelo[], int tamVuelo);
/// @brief muestra un pasajero solo
///
/// @param list
void mostrarUnPasajero(ePassenger list);
/// @brief muestra la lista de pasajeros
///
/// @param list
/// @param tam
void mostarListaPasajero(ePassenger list[], int tam);
