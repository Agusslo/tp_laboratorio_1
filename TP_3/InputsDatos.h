#ifndef INPUTSDATOS_H_
#define INPUTSDATOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief Solicita al usuario que ingrese un número entero.
/// @param recibe un puntero al espacio de memoria donde se copiará la cadena resultante.
/// @param Recibe una cadena de texto para notificar al usuario los datos solicitados.
/// @param Recibe una cadena de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param acepta un número entero como límite mínimo a respetar.
/// @param acepta un número entero como límite máximo a respetar.
/// @return Devuelve 0 si la cadena se devuelve correctamente, -1 si se produce un error.
int PedirEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/// @brief le pide al usuario que ingrese un flotante.
/// @param recibe un puntero al espacio de memoria donde se copiará la cadena resultante.
/// @param Recibe una cadena de texto para notificar al usuario los datos solicitados.
/// @param Recibe una cadena de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param acepta un float como límite mínimo a respetar.
/// @param acepta un float como límite máximo a respetar.
/// @return Devuelve 0 si la cadena se devuelve correctamente, -1 si se produce un error.
int PedirFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);

/// @brief Pide al usuario el ingreso de un caracter.
/// @param Recibe una cadena de texto para informar al usuario el dato solicitado.
/// @return Devuelve el caracter ingresado.
char PedirCaracter(char[]);

/// @brief Pide al usuario que ingrese una cadena de caracteres.
/// @param Recibe una cadena de texto para notificar al usuario los datos solicitados.
/// @param Recibe una cadena de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param Recibe un puntero al espacio de memoria donde se copiará la cadena resultante.
/// @param acepta un entero que define el tamaño de la cadena.
/// @return Devuelve 0 si la cadena se devuelve correctamente, -1 si se produce un error.
int PedirString(char* mensaje, char* mensajeError, char* cadena, int lenght);

int PedirStringAlfaNumerico(char* mensaje, char* mensajeError, char* cadena, int lenght);

/// @brief Valida un numero entero en un rango especifico.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un numero entero que actua como limite minimo a respetar.
/// @param Recibe un numero entero que actua como limite maximo a respetar.
/// @param Recibe el numero entero a validar.
/// @return Devuelve el numero entero tras validar que es correcto.
int ValidarRangoEntero(char[], int, int, int);

int ValidarStringAlfaNumerico(char* string);

/// @brief Valida enteros en el rango especificado.
/// @param Recibe una cadena de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param acepta un número entero como límite mínimo a respetar.
/// @param acepta un número entero como límite máximo a respetar.
/// @param recibe el entero a validar.
/// @return Devuelve un número entero después de que la verificación sea correcta.
int ValidarRangoInversoEntero(char[], int, int, int);

/// @brief Valida números de coma flotante en el rango especificado.
/// @param Recibe una cadena de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param acepta un float como límite mínimo a respetar.
/// @param acepta un float como límite máximo a respetar.
/// @param Recibe un flotante para validación.
/// @return Devuelve un número de punto flotante después de que la verificación sea correcta.
float ValidarRangoFlotante(char[], float, float, float);

/// @brief Valida enteros en el rango especificado.
/// @param Recibe una cadena de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param acepta un número entero como límite mínimo a respetar.
/// @param acepta un número entero como límite máximo a respetar.
/// @param recibe el entero a validar.
/// @return Devuelve un número entero después de que la verificación sea correcta.
float ValidarRangoInversoFlotante(char[], float, float, float);

/// @brief Valida un caracter en un rango especifico.
/// @param Recibe una cadena de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe el caracter que actua como limite minimo a respetar.
/// @param Recibe el caracter que actua como limite maximo a respetar.
/// @param Recibe el caracter a validar.
/// @return Devuelve el caracter tras validar que es correcto.
char ValidarCaracter(char[], char, char, char);

/// @brief Convierte la primer letra de un string en mayuscula y el resto de caracteres a minuscula.
/// @param Recibe la cadena de caracteres a formatear.
void FormatearNombreCompleto(char cadena[]);

/// @brief Despliega una pregunta de "SI o NO" con el fin de confirmar o cancelar una accion.
/// @return Devuelve un entero en funcion de la eleccion realizada.
int ConfirmarCambios();

/// @brief Valida que todos los elementos de una cadena de texto sean letras (excluyendo caracteres del codigo ASCII extendido).
/// @param Recibe un puntero al espacio en memoria donde se copiara la cadena obtenida.
/// @return Devuelve 0 en caso de no encontrar fallas en la cadena y -1 en caso de encontrar un caracter erroneo.
int ValidarString(char* string);

/// @brief lee la cadena hasta que se encuentra '\n' o hasta que se copian como máximo caracteres de "longitud-1" en la cadena.
/// @param Recibe un puntero al espacio de memoria donde se copiará la cadena resultante.
/// @param acepta un entero que define el tamaño de la cadena.
/// @return Devuelve 0 si la cadena se devuelve correctamente, -1 si se produce un error.
int myGetString(char* cadena, int lenght);

int isNumber(char* cadena, int limite);

int getInt(int* pResultado);

int isFloat(char* cadena, float limite);

int getFloat(float* pResultado);

#endif /* INPUTSDATOS_H_ */
