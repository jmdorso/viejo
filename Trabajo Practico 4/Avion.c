#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Avion.h"
#include "ArrayList.h"

/** \brief valida si los numeros se encuentran dentro de un rango
 * \param int x es el numero a validar
 * \param int inf es el limite inferior para validar
 * \param int sup es el limite superior para validar
 * \return si pertenece o no al rango el numero.
 *
 */

 int validarRangoInt(int x, int inf, int sup)
 {
    int esValido=0;
    if (x>=inf && x<=sup)
    {
        esValido= 1;
    }
 return esValido;
 }

 /** \brief
  *
  * \param
  * \param
  * \return
  *
  */

eAvion* nuevoAvion (int id, char marca[], char modelo[], float hsVuelo, int capacidad)
{
    eAvion* returnAux = NULL;
    eAvion* avion = malloc(sizeof(eAvion));

    if(avion != NULL)
    {
        avion->id = id;
        strcpy(avion->marca, marca);
        strcpy(avion->modelo, modelo);
        avion->hsVuelo = hsVuelo;
        avion->capacidad = capacidad;
        avion->flagEstado = 1;

        returnAux = avion;
    }

    return returnAux;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void imprimirAvion (eAvion* avion)
{

    if(avion->flagEstado == 1)
        {
            printf("\nMarca: %s\t\tModelo: %s\tCapacidad: %d",avion->marca, avion->modelo, avion->capacidad);
        }
}

int compararAvion (void* avion1, void* avion2)
{
    int returnAux = 0;

    if (((eAvion*)avion1)->capacidad > ((eAvion*)avion2)->capacidad)
    {
        returnAux = 1;
    }

    if (((eAvion*)avion1)->capacidad < ((eAvion*)avion2)->capacidad)
    {
        returnAux = -1;
    }

    return returnAux;
}


