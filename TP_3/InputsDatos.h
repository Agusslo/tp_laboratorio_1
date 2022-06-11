#ifndef INPUTSDATOS_H_
#define INPUTSDATOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/// @brief le pide al usuario que ingrese un número entero.
/// @param Recibe un puntero al espacio de memoria donde se copiará la string resultante.
/// @param Recibe una string de texto para notificar al usuario los datos solicitados.
/// @param Recibe una string de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param acepta un número entero como límite mínimo a respetar.
/// @param acepta un número entero como límite máximo a respetar.
/// @return Devuelve 0 si la string se devuelve correctamente, -1 si se produce un error.
int PedirEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/// @brief le pide al usuario que ingrese un flotante.
/// @param Recibe un puntero al espacio de memoria donde se copiará la string resultante.
/// @param Recibe una string de texto para notificar al usuario los datos solicitados.
/// @param Recibe una string de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param acepta un float como límite mínimo a respetar.
/// @param acepta un float como límite máximo a respetar.
/// @return Devuelve 0 si la string se devuelve correctamente, -1 si se produce un error.
int PedirFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);

/// @brief Pide al usuario el ingreso de un caracter.
/// @param Recibe una string de texto para informar al usuario el dato solicitado.
/// @return Devuelve el caracter ingresado.
char PedirCaracter(char[]);

/// @brief Pide al usuario que ingrese una string de caracteres.
/// @param Recibe una string de texto para notificar al usuario los datos solicitados.
/// @param Recibe una string de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param Recibe un puntero al espacio de memoria donde se copiará la string resultante.
/// @param acepta un entero que define el tamaño de la string.
/// @return Devuelve 0 si la string se devuelve correctamente, -1 si se produce un error.
int PedirString(char* mensaje, char* mensajeError, char* string, int lenght);

int PedirStringAlfaNumerico(char* mensaje, char* mensajeError, char* string, int lenght);

/// @brief Valida un numero entero en un rango especifico.
/// @param Recibe una string de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un numero entero que actua como limite minimo a respetar.
/// @param Recibe un numero entero que actua como limite maximo a respetar.
/// @param Recibe el numero entero a validar.
/// @return Devuelve el numero entero tras validar que es correcto.
int ValidarRangoEntero(char[], int, int, int);

int ValidarStringAlfaNumerico(char* string);

/// @brief Valida enteros en el rango especificado.
/// @param Recibe una string de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param acepta un número entero como límite mínimo a respetar.
/// @param acepta un número entero como límite máximo a respetar.
/// @param recibe el entero a validar.
/// @return Devuelve un número entero después de que la verificación sea correcta.
int ValidarRangoInversoEntero(char[], int, int, int);

/// @brief Valida números de coma flotante en el rango especificado.
/// @param Recibe una string de texto que notifica al usuario que los datos solicitados son incorrectos.
/// @param acepta un float como límite mínimo a respetar.
/// @param acepta un float como límite máximo a respetar.
/// @param Recibe un flotante para validación.
/// @return Devuelve un número de punto flotante después de que la verificación sea correcta.
float ValidarRangoFlotante(char[], float, float, float);

/// @brief Valida un numero flotante por fuera de un rango especifico.
/// @param Recibe una string de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe un numero flotante que actua como limite minimo a respetar.
/// @param Recibe un numero flotante que actua como limite maximo a respetar.
/// @param Recibe el numero flotante a validar.
/// @return Devuelve el numero flotante tras validar que es correcto.
float ValidarRangoInversoFlotante(char[], float, float, float);

/// @brief Valida un caracter en un rango especifico.
/// @param Recibe una string de texto para informar al usuario que el dato solicitado es incorrecto.
/// @param Recibe el caracter que actua como limite minimo a respetar.
/// @param Recibe el caracter que actua como limite maximo a respetar.
/// @param Recibe el caracter a validar.
/// @return Devuelve el caracter tras validar que es correcto.
char ValidarCaracter(char[], char, char, char);

/// @brief Convierte la primer letra de un string en mayuscula y el resto de caracteres a minuscula.
/// @param Recibe la string de caracteres a formatear.
void FormatearNombreCompleto(char string[]);

/// @brief Despliega una pregunta de "SI o NO" con el fin de confirmar o cancelar una accion.
/// @return Devuelve un entero en funcion de la eleccion realizada.
int ConfirmarCambios();

/// @brief Valida que todos los elementos de una string de texto sean letras (excluyendo caracteres del codigo ASCII extendido).
/// @param Recibe un puntero al espacio en memoria donde se copiara la string obtenida.
/// @return Devuelve 0 en caso de no encontrar fallas en la string y -1 en caso de encontrar un caracter erroneo.
int ValidarString(char* string);

/// @brief Lee una string de caracteres hasta haber encontrado un '\n' o hasta haber copiado en la string un maximo de "longitud-1" caracteres.
/// @param Recibe un puntero al espacio en memoria donde se copiara la string obtenida.
/// @param Recibe un numero entero que definira el tamaño de la string.
/// @return Devuelve 0 en caso de haber obtenido una string correctamente y -1 en caso de que haya ocurrido un error.
int myGetString(char* string, int lenght);

int isNumber(char* string, int limite);

int getInt(int* pResultado);

int isFloat(char* string, float limite);

int getFloat(float* pResultado);

#endif /* INPUTSDATOS_H_ */
