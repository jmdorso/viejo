#include <stdio.h>
#include <stdlib.h>
#include "dorso.h"

int main()
{
  int opcion;
  float num1, num2, rdo;
  char seguir='s';

  do
    {
        system("cls");
        printf("Trabajo Practico n1. Calculadora\n\n");
        printf("Ingrese Primer Numero(A=x): ");
        scanf("%f", &num1);
        printf("Ingrese Segundo Numero(B=y): ");
        scanf("%f", &num2);
        printf("\n1. Suma(A+B): \n");
        printf("2. Resta(A-B): \n");
        printf("3. Division(A/B): \n");
        printf("4. Multiplicacion(A*B): \n");
        printf("5. Calcular el Factorial(A!)\n");
        printf("6. Calcular todas las operaciones\n");
        printf("7. Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        while(!validarRangoInt(opcion,1,7))
        {
         printf("\nError! Reingrese opcion: ");
         scanf("%d", &opcion);
        }
        switch(opcion)
        {
            case 1:
                    rdo=suma(num1, num2);
                    printf("\nEl resultado de la suma es de: %.2f\n\n", rdo);
                    break;
            case 2:
                    rdo=resta(num1, num2);
                    printf("\nEl resultado de la resta es de: %.2f\n\n", rdo);
                    break;
            case 3:
                    rdo=division(num1, num2);
                    while(num2==0 && seguir!='n' )
                    {
                        printf("\nMath Error! Imposible dividir por 0.");
                        seguir='n';
                        }
                    printf("\nEl resultado de la division es de: %.2f\n\n", rdo);
                    seguir='s';
                    break;
            case 4:
                    rdo=multiplicacion(num1, num2);
                    printf("\nEl resultado de la multiplicacion es de: %.2f\n\n", rdo);
                    break;
            case 5:
                    rdo=factorial(num1);
                    printf("\nEl %.f! tiene como resultado: %.2f\n\n", num1, rdo);
                    /*rdo=1;
                    for(float i=1;i<=num1;i++)
                    {
                    rdo=rdo*i;
                    }
                    printf("\nEl %.f! tiene como resultado: %.2f\n\n", num1, rdo);*/
                    break;
            case 6:
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
                    break;
            case 7:
                    seguir='n';
                    break;
        }
        system("pause");
    }while(seguir=='s');


    return 0;
}
