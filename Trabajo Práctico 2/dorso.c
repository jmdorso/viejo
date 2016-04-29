#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dorso.h"


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

/** \brief incializa todos los vectores con el estado en 0.
 *
 * \param ePersona vecPersona ingresa un array de n cantidad de personas para ser inicializado con el estado en 0.
 * \param ePersona auxVecPersona ingresa un array de n cantidad de personas para ser inicializado con el estado en 0.
 * \param int cantPersonas indica de cuantas variables ePersona es el array.
 * \return void
 *
 */

void inicVec(ePersona vecPersona[], ePersona auxVecPersona[], int cantPersonas)
{
    int i;
    for(i=0;i<cantPersonas;i++)
    {
        vecPersona[i].flagEstado=0;
        auxVecPersona[i].flagEstado=0;
    }

}

/** \brief Carga los campos de la nueva persona, verificando si hay lugar en el array,
 *  si coincide el dni con uno ya ingresado y se verifica si el rango de edad y dni son correctos. Si esto se cumple se guarda en el vector.
 * \param ePersona vecPersona ingresa un array de n cantidad de personas para ser cargado.
 * \param int cantPersonas indica de cuantas variables ePersona es el array.
 * \return void
 *
 */

 void cargarVecPersona(ePersona vecPersona[], int cantPersonas)
 {
     int flagPer=0,i,j;
     ePersona per;
     for (i=0;i<cantPersonas;i++)
     {
         if(vecPersona[i].flagEstado==0)
         {
             fflush(stdin);
             printf("Ingresar Nombre: ");
             gets(per.nombre);

             printf("Ingresar Edad: ");
             scanf("%d", &per.edad);
             while((per.edad<1) || (per.edad>125))
             {
                 printf("!!! ERROR !!! Edad no permitida, ingrese edad entre 1 y 125: ");
                 scanf("%d", &per.edad);
             }
             printf("Ingrese DNI: ");
             scanf("%d", &per.dni);
             while((per.dni<1000000) || (per.dni>99999999))
             {
                 printf("��� ERROR !!! DNI inexistente en el sistema. Reingrese: ");
                 scanf("%d", &per.dni);
             }
             //fflush(stdin);
             for(j=0;j<cantPersonas;j++)
             {
                 if(vecPersona[j].dni==per.dni)
                 {
                     printf("\n\t\tEl DNI ya fue ingresado. Imposible ingresar datos.\n\n");
                     system("pause");
                     break;
                 }
                 else
                 {
                     flagPer==1;
                     per.flagEstado=1;
                     vecPersona[i]=per;
                     printf("\n\t\t\tINGRESO EXITOSO!!!\n\n");
                     system("pause");
                     break;
                 }
             }
             break;
         }
     }
     if(i==cantPersonas && flagPer==0)
     {
         printf("\n\n\t\tNo hay espacio para mas personas:");
         printf("\n")
         system("pause");
     }

 }

 /** \brief elimina una persona, siendo buscada a traves del DNI, si el DNI ya fue ingresado se elimina, si este no se encunetra en el sistema se le informa
  * al usuario de lo sucedido
  * \param ePersona vecPersona es el array en el que se encuentra la persona persona a eliminar
  * \param int cantPersonas es el tama�o de este array
  * \return void
  *
  */

 void eliminarVecPersona(ePersona vecPersona[], int cantPersonas)
 {
     int i, flagPer=0, dni;
     printf("\nIngrese DNI de la persona que desea elminar: ");
     scanf("%d", &dni);
     for(i=0;i<cantPersonas;i++)
     {
         if((vecPersona[i].dni==dni) && (vecPersona[i].flagEstado==1))
         {
             vecPersona[i].flagEstado=0;
             vecPersona[i].dni=0;
             flagPer=1;
             printf("\n\t\tLa persona fue eliminada con exito!!!\n\n");
             system("pause");
             break;
         }
     }
     if((i==cantPersonas) && (flagPer==0))
     {
         printf("\n\tEl dni ingresado no existe o no fue ingresado en el vector.\n\n");
         system("pause");
     }
     fflush(stdin);
 }

 /** \brief ordena el array segun el nombre, con 2 criterios posible, y lo muestra de esta forma. Esto lo hace mediante un burbujeo y muestra a traves de un
  * printf ordenado, mediante el uso de tabulacion.
  * \param ePersona vecPersona es el array de las personas a ordenar
  * \param int cantPersonas es el tama�o del array
  * \param int criterio es el orden para listar el array, si es 1, se muestra desde la A a la Z, si es 0, de la Z a la A.
  * \return void
  *
  */

  void listarVecPersona(ePersona vecPersona[], int cantPersonas, int criterio)
  {
      int i, j;
      ePersona auxPer;
      system("cls");
      printf("\t\t Lista Ordenada por nombre\n");
      if(criterio==1)
      {
          for(i=0;i<cantPersonas-1;i++)
          {
              for(j=i+1;j<cantPersonas;j++)
              {
                  if(strcmp(vecPersona[i].nombre, vecPersona[j].nombre) > 0 && criterio ==1)
                  {
                      auxPer=vecPersona[i];
                      vecPersona[i]=vecPersona[j];
                      vecPersona[j]=auxPer;
                  }
                  else if(strcmp(vecPersona[i].nombre, vecPersona[j].nombre) < 0 && criterio ==0)
                  {
                      auxPer=vecPersona[i];
                      vecPersona[i]=vecPersona[j];
                      vecPersona[j]=auxPer;
                  }
              }
          }
      }
      for(i=0;i<cantPersonas;i++)
      {
        if(vecPersona[i].flagEstado==1)
        {
            printf("\n\nNombre: %s\t    Edad: %d\t  DNI: %d",vecPersona[i].nombre, vecPersona[i].edad, vecPersona[i].dni);
            printf("\n");
        }
      }
      printf("\n");
      system("pause");
      system("cls");
      fflush(stdin);
  }

/** \brief grafica mediante comparaciones de rangos en el campo de edad, los cuales toman sus valores mediante un for que recorre el array.
 * El grafico se muestra mediante printf y se acomoda mediante tabulaciones.
 * \param ePersona vecPersona es el array de tipo ePersona de donde se obtienen los datos a graficar
 * \param int cantPersonas es la capacidad del array
 * \return void
 *
 */

void graficar(ePersona vecPersona[], int cantPersonas)
{
    int i, max, menor=0, entre=0, mayor=0;
    for(i=0;i<cantPersonas;i++)
    {
        if(vecPersona[i].flagEstado!=0)
        {
            if(vecPersona[i].edad<=18)
            {
                menor++;
            }
            else
            {
                if((vecPersona[i].edad>18)&&(vecPersona[i].edad<=35))
                {
                    entre++;
                }
                else
                {
                    mayor++;
                }
            }
        }
    }
    if((menor>=entre)&&(menor>=mayor))
    {
        max=menor;
    }
    else
    {
        if((entre>=menor)&&(entre>=mayor))
        {
            max=entre;
        }
        else((mayor>=menor)&&(mayor>=entre));
        {
            max=mayor;
        }
    }
    for(i=max;i>0;i--)
    {
        if((i==menor)&&(i==entre)&&(i==mayor))
        {
            printf(" *\t  *\t  *\n");
            menor--;
            entre--;
            mayor--;
        }
        if((i==menor)&&(i==entre))
        {
            printf(" *\t  *\t  \n");
            menor--;
            entre--;
        }
        if((i==menor)&&(i==mayor))
        {
            printf(" *\t   \t  *\n");
            menor--;
            mayor--;
        }
        if((i==entre)&&(i==mayor))
        {
            printf("  \t  *\t  *\n");
            entre--;
            mayor--;
        }
        if(i==menor)
        {
            printf(" *\t   \t  \n");
            menor--;
        }
        if(i==entre)
        {
            printf("  \t   \t  *\n");
            entre--;
        }
        if(i==mayor)
        {
            printf("  \t   \t  *\n");
            mayor--;
        }
    }
    printf("<18\t19-35\t >35");
    printf("\n\n");
    system("pause");
}
