#include "InputsDatos.h"
#include <stdio.h>
#include <stdlib.h>

int getFloat(float* pResultado)
{
	int retorna;
	char bufferString[50];
	retorna = -1;
	if(pResultado != NULL && myGetString(bufferString, sizeof(bufferString)) == 0 && isFloat(bufferString, sizeof(bufferString)))
	{
		retorna = 0;
		*pResultado = atof(bufferString);
	}
	return retorna;
}

int isFloat(char* cadena, float limite)
{
	int retorna;
	int flagPunto;
	flagPunto = 0;
	retorna = -1;
	if(cadena != NULL && limite > 0)
	{
		retorna = 1;
		for(int i=0; i<limite && cadena[i] !='\0'; i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				if(cadena[i] == '.' && flagPunto == 0)
				{
					flagPunto = 1;
					continue;
				}
				retorna = 0;
				break;
			}
		}
	}

	return retorna;
}

int getInt(int* pResultado)
{
	int retorna;
	char bufferString[50];
	retorna = -1;
	if(pResultado != NULL && myGetString(bufferString, sizeof(bufferString)) == 0 && isNumber(bufferString, sizeof(bufferString)))
	{
		retorna = 0;
		*pResultado = atoi(bufferString);
	}
	return retorna;
}

int isNumber(char* cadena, int limite)
{
	int retorna;
	retorna = -1;
	if(cadena != NULL && limite > 0)
	{
		retorna = 1;
		for(int i=0; i<limite && cadena[i] !='\0'; i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorna = 0;
				break;
			}
		}
	}

	return retorna;
}

int myGetString(char* cadena, int lenght)
{
	int retorna;
	char bufferString[4096];
	retorna = -1;
	if(cadena != NULL && lenght > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL && bufferString[0] != '\n')
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= lenght)
			{
				strncpy(cadena, bufferString, lenght);
				retorna = 0;
			}
		}
	}
	return retorna;
}

int PedirEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retorna;
	int bufferInt;
	retorna = -1;
	printf("%s\n", mensaje);
	while(retorna != 0)
	{
		if(getInt(&bufferInt) == 0 && bufferInt > minimo && bufferInt < maximo)
		{
			retorna = 0;
			*pResultado = bufferInt;
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retorna;
}

int PedirFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo)
{
	int retorna;
	float bufferFloat;
	retorna = -1;
	printf("%s\n", mensaje);
	while(retorna != 0)
	{
		if(getFloat(&bufferFloat) == 0 && bufferFloat > minimo && bufferFloat < maximo)
		{
			retorna = 0;
			*pResultado = bufferFloat;
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retorna;
}

char PedirCaracter(char mensaje[])
{
	char caracter;
	printf("%s\n", mensaje);
	fflush(stdin);
	scanf("%c", &caracter);
	return caracter;
}

int PedirStringAlfaNumerico(char* mensaje, char* mensajeError, char* cadena, int lenght)
{
	int retorna;
	char bufferString[lenght];
	retorna = -1;
	printf("%s\n", mensaje);
	while(retorna != 0)
	{
		if(myGetString(bufferString, sizeof(bufferString)) == 0 && ValidarStringAlfaNumerico(bufferString) == 0)
		{
			retorna = 0;
			strncpy(cadena, bufferString, lenght);
			strupr(cadena);
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retorna;
}

int PedirString(char* mensaje, char* mensajeError, char* cadena, int lenght)
{
	int retorna;
	char bufferString[lenght];
	retorna = -1;
	printf("%s\n", mensaje);
	while(retorna != 0)
	{
		if(myGetString(bufferString, sizeof(bufferString)) == 0 && ValidarString(bufferString) == 0)
		{
			retorna = 0;
			strncpy(cadena, bufferString, lenght);
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retorna;
}

int ValidarString(char* string)
{
	int retorna;
	retorna = 0;
	for(int i=0;i<strlen(string);i++)
	{
		if(!isalpha(string[i]))
		{
			retorna = -1;
			break;
		}
	}
	return retorna;
}

int ValidarStringAlfaNumerico(char* string)
{
	int retorna;
	int flagAlpha;
	int flagNum;
	flagAlpha = 0;
	flagNum = 0;
	retorna = 0;

	for(int i=0;i<strlen(string);i++)
	{
		if(isalpha(string[i]))
		{
			flagAlpha = 1;
		}
		else
		{
			if(isdigit(string[i]))
			{
				flagNum = 1;
			}
			else
			{
				retorna = -1;
				break;
			}
		}
	}
	if(flagAlpha == 0 || flagNum == 0)
	{
		retorna = -1;
	}
	return retorna;
}

char ValidarCaracter(char mensajeError[], char limiteInferior, char limiteSuperior, char caracter)
{
	while(caracter > limiteInferior && caracter < limiteSuperior)
	{
		printf("%s\n", mensajeError);
		fflush(stdin);
		scanf("%c", &caracter);
	}
	return caracter;
}

void FormatearNombreCompleto(char cadena[])
{
	int size;
	int i;

	size = strlen(cadena);
	strlwr(cadena);

	for(i=0; i<size; i++)
	{
		if(cadena[i-1] == 32 || i==0)
		{
			cadena[i] = toupper(cadena[i]);
		}
	}

}

int confirmCambios()
{
	int cambio;
	char confirm[3];

	cambio = 0;
	PedirString(" (SI o NO)", "ERROR! Intentelo de nuevo (SI o NO)", confirm, 3);
	strupr(confirm);
	while(strcmp(confirm, "SI") != 0 && strcmp(confirm, "NO") != 0)
	{
		PedirString("ERROR! Intentelo de nuevo (SI o NO)", "ERROR! Intentelo de nuevo (SI o NO)", confirm, 3);
		strupr(confirm);
	}
	if(strcmp(confirm, "SI") == 0)
	{
		cambio = 1;
	}

	return cambio;
}
