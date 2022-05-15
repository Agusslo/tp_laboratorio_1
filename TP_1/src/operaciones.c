#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

float pedirNumero(char mensaje [])
{

	float numero;
	printf("%s",mensaje);
	scanf("%f",&numero);
	while(numero<1)

	{
		printf("error ingrese un numero valido");
		fflush(stdin);
		scanf("%f",&numero);
	}
	return numero;
}

float calcularDebito(float precio)
{
	float descuento;
	descuento=precio-(precio*10/100);
	return descuento;
}
float calcularCredito(float precio)
{
	float interes;
	interes=precio+(precio*25/100);
	return interes;
}
float calcularBitcoin(float precio)
{
	float bitcoin;
	bitcoin=precio/4606954.55;
	return bitcoin;
}
float calcularUnidad(float precio, float x)
{
	float precioUnidad;
	precioUnidad=precio/x;
	return precioUnidad;
}
float calcularDiferencia(float y, float z)
{
	float diferencia;
	if(y<z)
	{
		diferencia=y-z;
	}
	else
	{
		diferencia=z-y;
	}
	return diferencia;

}

void mostrarInfo(float y, float z, float tarjetaDebitoZ,float tarjetaCreditoZ, float bitcoinZ,float precioUnitarioZ, float tarjetaDebitoY, float tarjetaCreditoY, float bitcoinY,float precioUnitarioY,float diferencia)
{
	 printf ("*** precio Latam:%.2f ***\n\n**",z);//latam:||
	 printf("Precio con tarjeta de débito: %.2f \n",tarjetaDebitoZ);//a) Precio con tarjeta de débito:
	 printf("Precio con tarjeta de crédito: %.2f \n",tarjetaCreditoZ);//B)Precio con tarjeta de crédito:
	 printf("Precio pagando con bitcoin : %f \n",bitcoinZ);//c) Precio pagando con bitcoin :
	 printf("Precio Unitario : %.2f \n",precioUnitarioZ);//d) Precio unitario:
	 printf("*** precio Aereolineas:%.2f ***\n\n",y);//Aerolíneas:
	 printf("Precio con tarjeta de débito:%.2f \n", tarjetaDebitoY);//a) Precio con tarjeta de débito: r
	 printf("Precio con tarjeta de crédito:%.2f \n",tarjetaCreditoY);//b) Precio con tarjeta de crédito: r
	 printf("Precio pagando con bitcoin :%f \n",bitcoinY);//c) Precio pagando con bitcoin :
	 printf("el precio unitario es:%.2f \n",precioUnitarioY);//d) Precio unitario:
	 printf("la diferencia de precio es :%.2f",diferencia);
}
