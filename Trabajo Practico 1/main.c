#include <stdio.h>
#include <stdlib.h>
#include "dorso.h"

int main()
{
  int opcion, A=0, B=0;
  float num1, num2, rdo;
  char seguir='s';

  do
    {
        system("cls");
        printf("Trabajo Practico n1. Calculadora\n\n");
        printf("1. Ingrese Primer Numero(A=x): \n");
        printf("2. Ingrese Segundo Numero(B=y): \n");
        printf("3. Suma(A+B): \n");
        printf("4. Resta(A-B): \n");
        printf("5. Division(A/B): \n");
        printf("6. Multiplicacion(A*B): \n");
        printf("7. Calcular el Factorial(A!)\n");
        printf("8. Calcular todas las operaciones\n");
        printf("9. Salir\n\n");
        printf("Los numeros que fueron ingresados son los siguientes: A=%.2f y B=%.2f\n\n",num1,num2);
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);


        while(!validarRangoInt(opcion,1,9))
        {
         printf("\nError! Reingrese opcion: ");
         scanf("%d", &opcion);
        }
        switch(opcion)
        {
            case 1:
                    printf("Ingrese primer numero: ");
                    scanf("%f", &num1);
                    A=1;
                    break;
            case 2:
                    printf("Ingrese segundo numero: ");
                    scanf("%f", &num2);
                    B=1;
                    break;
            case 3:
                    if(A==0||B==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else
                        {
                        rdo=suma(num1, num2);
                        printf("\nEl resultado de la suma es de: %.2f\n\n", rdo);
                        }
                    break;
            case 4:
                    if(A==0||B==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else
                        {
                        rdo=resta(num1, num2);
                        printf("\nEl resultado de la resta es de: %.2f\n\n", rdo);
                        }
                    break;
            case 5:
                    if(A==0||B==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else
                        {
                        rdo=division(num1, num2);
                        while(num2==0 && seguir!='n' )
                            {
                            printf("\nMath Error! Imposible dividir por 0.");
                            seguir='n';
                            }
                        printf("\nEl resultado de la division es de: %.2f\n\n", rdo);
                        seguir='s';
                        }
                    break;
            case 6:
                    if(A==0||B==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else
                        {
                        rdo=multiplicacion(num1, num2);
                        printf("\nEl resultado de la multiplicacion es de: %.2f\n\n", rdo);
                        }
                    break;
            case 7:
                    if(A==0||B==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else
                        {
                        rdo=factorial(num1);
                        printf("\nEl %.f! tiene como resultado: %.2f\n\n", num1, rdo);
                        /*rdo=1;
                        for(float i=1;i<=num1;i++)
                        {
                        rdo=rdo*i;
                        }
                        printf("\nEl %.f! tiene como resultado: %.2f\n\n", num1, rdo);*/
                        }
                    break;
            case 8:
                    if(A==0||B==0)
                        {
                        printf("\nFalta Ingresar algun numero\n\n");
                        }
                    else
                        {
                        rdo=suma(num1, num2);
                        printf("\n\nEl resultado de la suma es de: %.2f\n", rdo);
                        rdo=resta(num1, num2);
                        printf("\nEl resultado de la resta es de: %.2f\n", rdo);
                        rdo=division(num1, num2);
                        while(num2==0 && seguir!='n' )
                            {
                            printf("\nMath Error! Imposible dividir por 0.");
                            seguir='n';
                            }
                        printf("\nEl resultado de la division es de: %.2f\n", rdo);
                        seguir='s';
                        rdo=multiplicacion(num1, num2);
                        printf("\nEl resultado de la multiplicacion es de: %.2f\n", rdo);
                        rdo=factorial(num1);
                        printf("\nEl %.f! tiene como resultado: %.2f\n\n", num1, rdo);
                        /*rdo=1;
                        for(float i=1;i<=num1;i++)
                        {
                        rdo=rdo*i;
                        }
                        printf("\nEl %.f! tiene como resultado: %.2f\n\n", num1, rdo);*/
                        }
                    break;
            case 9:
                    seguir='n';
                    break;
        }
        system("pause");
    }while(seguir=='s');

return 0;
}
