#include "InputsDatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getFloat(float* pResultado)
{
	int retornoo;
	char bufferString[50];
	retornoo = -1;
	if(pResultado != NULL && myGetString(bufferString, sizeof(bufferString)) == 0 && isFloat(bufferString, sizeof(bufferString)))
	{
		retornoo = 0;
		*pResultado = atof(bufferString);
	}
	return retornoo;
}

int isFloat(char* string, float limite)
{
	int retornoo;
	int flagPunto;
	flagPunto = 0;
	retornoo = -1;
	if(string != NULL && limite > 0)
	{
		retornoo = 1;
		for(int i=0; i<limite && string[i] !='\0'; i++)
		{
			if(i==0 && (string[i] == '+' || string[i] == '-'))
			{
				continue;
			}
			if(string[i] > '9' || string[i] < '0')
			{
				if(string[i] == '.' && flagPunto == 0)
				{
					flagPunto = 1;
					continue;
				}
				retornoo = 0;
				break;
			}
		}
	}

	return retornoo;
}

int getInt(int* pResultado)
{
	int retornoo;
	char bufferString[50];
	retornoo = -1;
	if(pResultado != NULL && myGetString(bufferString, sizeof(bufferString)) == 0 && isNumber(bufferString, sizeof(bufferString)))
	{
		retornoo = 0;
		*pResultado = atoi(bufferString);
	}
	return retornoo;
}

int isNumber(char* string, int limite)
{
	int retornoo;
	retornoo = -1;
	if(string != NULL && limite > 0)
	{
		retornoo = 1;
		for(int i=0; i<limite && string[i] !='\0'; i++)
		{
			if(i==0 && (string[i] == '+' || string[i] == '-'))
			{
				continue;
			}
			if(string[i] > '9' || string[i] < '0')
			{
				retornoo = 0;
				break;
			}
		}
	}

	return retornoo;
}

int myGetString(char* string, int lenght)
{
	int retornoo;
	char bufferString[4096];
	retornoo = -1;
	if(string != NULL && lenght > 0)
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
				strncpy(string, bufferString, lenght);
				retornoo = 0;
			}
		}
	}
	return retornoo;
}

int PedirEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int retornoo;
	int bufferInt;
	retornoo = -1;
	printf("%s\n", mensaje);
	while(retornoo != 0)
	{
		if(getInt(&bufferInt) == 0 && bufferInt > minimo && bufferInt < maximo)
		{
			retornoo = 0;
			*pResultado = bufferInt;
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retornoo;
}

int PedirFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo)
{
	int retornoo;
	float bufferFloat;
	retornoo = -1;
	printf("%s\n", mensaje);
	while(retornoo != 0)
	{
		if(getFloat(&bufferFloat) == 0 && bufferFloat > minimo && bufferFloat < maximo)
		{
			retornoo = 0;
			*pResultado = bufferFloat;
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retornoo;
}

char PedirCaracter(char mensaje[])
{
	char caracter;
	printf("%s\n", mensaje);
	fflush(stdin);
	scanf("%c", &caracter);
	return caracter;
}

int PedirStringAlfaNumerico(char* mensaje, char* mensajeError, char* string, int lenght)
{
	int retornoo;
	char bufferString[lenght];
	retornoo = -1;
	printf("%s\n", mensaje);
	while(retornoo != 0)
	{
		if(myGetString(bufferString, sizeof(bufferString)) == 0 && ValidarStringAlfaNumerico(bufferString) == 0)
		{
			retornoo = 0;
			strncpy(string, bufferString, lenght);
			strupr(string);
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retornoo;
}

int PedirString(char* mensaje, char* mensajeError, char* string, int lenght)
{
	int retorno;
	char bufferString[lenght];
	retorno = -1;
	printf("%s\n", mensaje);
	while(retorno != 0)
	{
		if(myGetString(bufferString, sizeof(bufferString)) == 0 && ValidarString(bufferString) == 0)
		{
			retorno = 0;
			strncpy(string, bufferString, lenght);
		}
		else
		{
			printf("%s\n", mensajeError);
		}
	}

	return retorno;
}

int ValidarString(char* string)
{
	int retornoo;
	retornoo = 0;
	for(int i=0;i<strlen(string);i++)
	{
		if(!isalpha(string[i]))
		{
			retornoo = -1;
			break;
		}
	}
	return retornoo;
}

int ValidarStringAlfaNumerico(char* string)
{
	int retornoo;
	int flagAlpha;
	int flagNum;
	flagAlpha = 0;
	flagNum = 0;
	retornoo = 0;

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
				retornoo = -1;
				break;
			}
		}
	}
	if(flagAlpha == 0 || flagNum == 0)
	{
		retornoo = -1;
	}
	return retornoo;
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

void FormatearNombreCompleto(char string[])
{
	int size;
	int i;

	size = strlen(string);
	strlwr(string);

	for(i=0; i<size; i++)
	{
		if(string[i-1] == 32 || i==0)
		{
			string[i] = toupper(string[i]);
		}
	}

}

int confirmCambios()
{
	int cambioRealizado;
	char confirm[3];

	cambioRealizado = 0;
	PedirString(" SI o NO", "ERROR, Intentelo de nuevo (SI o NO)", confirm, 3);
	strupr(confirm);
	while(strcmp(confirm, "SI") != 0 && strcmp(confirm, "NO") != 0)
	{
		PedirString("ERROR, Intentelo de nuevo (SI o NO)", "ERROR, Intentelo de nuevo (SI o NO)", confirm, 3);
		strupr(confirm);
	}
	if(strcmp(confirm, "SI") == 0)
	{
		cambioRealizado = 1;
	}

	return cambioRealizado;
}
