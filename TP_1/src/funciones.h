#include <stdio.h>
#include <stdlib.h>
/**
 * @fn float pedirNumero(char[])
 * @brief ingresar numero
 *
 * @param mensaje ultimo dato para ingresar
 * @return numero
 */
float pedirNumero(char mensaje []);
/**
 * @fn float calcularDebito(float)
 * @brief calcula debito - el descuento del 10%
 *
 * @param precio que se le descuenta
 * @return descuento (precio final con el descuento)
 */
float calcularDebito(float precio);
/**
 * @fn float calcularCredito(float)
 * @brief calcula credito + el aumento del 25%
 *
 * @param precio que se le aumenta
 * @return interes(precio final con el aumento)
 */
float calcularCredito(float precio);
/**
 * @fn float calcularBitcoin(float)
 * @brief pasa precio en pesos a bitcoin
 *
 * @param precio numero que se divide para sacar el precio
 * @return bitcoin(cambio pesos a moneda bitcoin
 */
float calcularBitcoin(float precio);
/**
 * @fn float calcularUnidad(float, float)
 * @brief calcula el precio por los kilometros(km)
 *
 * @param precio
 * @param x los km
 * @return precioUnidad precio de los kilometros * precio
 */
float calcularUnidad(float precio, float x);
/**
 * @fn float calcularDiferencia(float, float)
 * @brief diferencia de precio entre latam y aerolineas
 *
 * @param y = aerolineas
 * @param z = latam
 * @return diferencia
 */
float calcularDiferencia(float y, float z);
/**
 * @fn void mostrarInfo(float, float, float, float, float, float, float, float, float, float, float)
 * @brief muestra la informacion con los calculos ya hechos
 *
 * @param y = aerolineas
 * @param z = latam
 * @param tarjetaDebitoZ = tarjeta de debito
 * @param tarjetaCreditoZ = tarjeta credito
 * @param bitcoinZ = bitcoin
 * @param precioUnitarioZ = precio unitario de latam
 * @param tarjetaDebitoY = tarjeta debito
 * @param tarjetaCreditoY = tarjeta credito
 * @param bitcoinY = precio a bitcoin
 * @param precioUnitarioY = precio unitario en aerolineas
 * @param diferencia = diferencia de precio entre latam y aerolineas
 */
void mostrarInfo(float y, float z, float tarjetaDebitoZ,float tarjetaCreditoZ, float bitcoinZ,float precioUnitarioZ, float tarjetaDebitoY, float tarjetaCreditoY, float bitcoinY,float precioUnitarioY,float diferencia);
