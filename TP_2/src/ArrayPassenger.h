#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define limit 2000
#define tamHardcodeo 5
#define Empty 0
#define Full 1
typedef struct{
		int id;
		char name [51];
		char lastname[51];
		float price;
		char flycode[10];
		int typePassenger;
		int statusflight;
		int isEmpty;
	}Passenger;

//funciones obligatorias
int initPassengers( Passenger list[], int len);
int addPassengers( Passenger list[], int len, int id, char name[],char lastname[],float price,int typePassenger, char flycode [],int statusflight);
int findPassengersById( Passenger list[], int len ,int id);
int removePassenger( Passenger list[], int len ,int id);
int sortPassengers( Passenger list[], int len ,int order);
int printPassengers( Passenger list[], int len);
int sortPassengerByCode( Passenger list[], int len ,int order);


//funciones Agus
int agregarPasajero(Passenger list[], int size);
int buscarlibre(Passenger list[], int size);
int modificar(Passenger list[], int len);
void modificarPasajero( Passenger list[], int len ,int id);
int eliminarPasajero(Passenger list[], int len);
void mostrar(Passenger* pasajero);
int hardcodeo(Passenger list[],int len);
int ordenarPorApellido(Passenger list[],int len);
int ordenarPorcodigo(Passenger list[],int len);
int totalPrecio(Passenger list[],int len);
int promedioPrecios(Passenger list[],int len);
int cantPasajeros(Passenger list[],int len);
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int max);
int pedirFlotante(float* flotante, char* mensaje, char* mensajeError, float min, float max);
int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max);
