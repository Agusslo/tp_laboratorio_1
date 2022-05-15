/*
 Name        : TP 1
 Author      : Agustin Lopez
 Description :

1. Ingresar Kilómetros: ( km=x)

2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:

3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)

4. Informar Resultados

“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir

*/

#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main(void)
{
	setbuf(stdout, NULL);

	float x=0;
	int opcion;
	float y=0;
	float z=0;
	float tarjetaDebitoY=0;
	float tarjetaCreditoY=0;
	float bitcoinY=0;
	float precioUnidadY=0;
	float tarjetaDebitoZ=0;
	float tarjetaCreditoZ=0;
	float bitcoinZ=0;
	float precioUnidadZ=0;
	float diferencia=0;
	int flag3=0;


	do
	{
		printf("///menu de opciones///\n\n\n");
		printf("1-ingrese los kilometros\n");
		printf("2-ingrese precio de los vuelos\n");
		printf("3-calcular costos\n");
		printf("4-informar resultados\n");
		printf("5-carga forzada\n");
		printf("6-salir\n");

		scanf("%d",&opcion);
		switch(opcion)
		{
		case 1:
			x=pedirNumero("ingrese los kilometros");
		break;

		case 2:
			y=pedirNumero("ingrese precio Aereolineas");
			z=pedirNumero("ingrese precio Latam");
		break;

		case 3:
			if (x==0 || y==0 || z==0)
			{
				printf("no se ingreso los datos correspondientes\n");

			}
			else
			{
				flag3=1;
				tarjetaDebitoY=calcularDebito(y);
				tarjetaCreditoY=calcularCredito(y);
				bitcoinY=calcularBitcoin(y);
				precioUnidadY=calcularUnidad(x,y);
				tarjetaDebitoZ=calcularDebito(z);
				tarjetaCreditoZ=calcularCredito(z);
				bitcoinZ=calcularBitcoin(z);
				precioUnidadZ=calcularUnidad(x,z);
				diferencia=calcularDiferencia(y,z);
			}
			break;

			case 4:
			if(flag3==1)
			{

				mostrarInfo( y,  z,  tarjetaDebitoZ, tarjetaCreditoZ,  bitcoinZ, precioUnidadZ,  tarjetaDebitoY,  tarjetaCreditoY,  bitcoinY, precioUnidadY, diferencia);
			}
			else
			{
				printf("error calcule costos (opcion 3)");
			}

			break;

			case 5:
				x=7090;
				y=159339;
				z=162965;
				tarjetaDebitoY=calcularDebito(y);
				tarjetaCreditoY=calcularCredito(y);
				bitcoinY=calcularBitcoin(y);
				precioUnidadY=calcularUnidad(x,y);
				tarjetaDebitoZ=calcularDebito(z);
				tarjetaCreditoZ=calcularCredito(z);
				bitcoinZ=calcularBitcoin(z);
				precioUnidadZ=calcularUnidad(x,z);
				diferencia=calcularDiferencia(y,z);
				mostrarInfo(y,  z,  tarjetaDebitoZ, tarjetaCreditoZ,  bitcoinZ, precioUnidadZ,  tarjetaDebitoY,  tarjetaCreditoY,  bitcoinY, precioUnidadY, diferencia);
			break;
			case 6:
				printf("saliendo");
			break;

			default:
				printf("ingrese opcion valida");
			break;

			}
	}while (opcion !=6);

    return 0;
}
