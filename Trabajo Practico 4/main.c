#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Avion.h"
#include "ArrayList.h"

void imprimirListaAvion(ArrayList* al);

int main()
{
    printf("\t\t|||| TRABAJO PRACTICO 4 |||| \n\n- Uso y Manejo de ArrayList\n\n");
    printf("1. Declaro los elementos y los muestro:");

    eAvion* av0 = nuevoAvion(120, "Airbus", "A320", 18, 220);
    eAvion* av1 = nuevoAvion(120, "Airbus", "A340", 18, 419);
    eAvion* av2 = nuevoAvion(120, "Airbus", "A380", 18, 656);
    eAvion* av3 = nuevoAvion(100, "Boeing", "747-8", 18, 467);
    eAvion* av4 = nuevoAvion(100, "Boeing", "777", 18, 550);
    eAvion* av5 = nuevoAvion(100, "Boeing", "737", 12, 180);
    eAvion* av6 = nuevoAvion(100, "Boeing", "787", 18, 463);
    eAvion* av7 = nuevoAvion(100, "Boeing", "757", 18, 289);
    eAvion* av8 = nuevoAvion(250, "Bombardier", "CRJ200", 12, 50);
    eAvion* av9 = nuevoAvion(50, "Embraer E-Jets", "190", 12, 100);
    ;

    printf("\n");
    imprimirAvion(av0);
    imprimirAvion(av1);
    imprimirAvion(av2);
    imprimirAvion(av3);
    imprimirAvion(av4);
    imprimirAvion(av5);
    imprimirAvion(av6);
    imprimirAvion(av7);
    imprimirAvion(av8);
    imprimirAvion(av9);
    printf("\n\n");
    printf("-----------------------------------------------\n");
    system("pause");

    printf("\n\n2. Cargo ArrayList y muestro contenido: [al_newArrayList && al_add]\n");
    ArrayList* lAvion = al_newArrayList();
    lAvion->add(lAvion, av0);
    lAvion->add(lAvion, av1);
    lAvion->add(lAvion, av2);
    lAvion->add(lAvion, av3);
    lAvion->add(lAvion, av4);
    lAvion->add(lAvion, av5);
    lAvion->add(lAvion, av6);
    lAvion->add(lAvion, av7);
    lAvion->add(lAvion, av8);
    lAvion->add(lAvion, av9);
    imprimirListaAvion(lAvion);
    printf("\n\n-2.1. Dimension del ArrayList [al_len]: %d\n\n", lAvion->len(lAvion));
    printf("-----------------------------------------------\n");
    system("pause");

    printf("\n3. Clonamos el Array para luego comparar el manejo de este: [al_clone]\n");
    ArrayList* lAvion2 = lAvion->clone(lAvion);
    printf("-----------------------------------------------\n");
    system("pause");
    system("cls");

    printf("4. Trabajamos sobre la lista clonada");
    printf("\n\n-4.1. Removemos 3 elementos: [al_remove]\n");
    lAvion->remove(lAvion, 0);
    lAvion->remove(lAvion, 2);
    lAvion->remove(lAvion, 5);
    imprimirListaAvion(lAvion);
    printf("\n\nDimension del ArrayList [al_len]: %d\n\n", lAvion->len(lAvion));
    printf("-----------------------------------------------\n");
    system("pause");

    printf("\n\n-4.2. Preguntamos si contiene 2 elementos: [al_contains]\n");
    printf("\nLa lista aun contiene el primer avion ingresado??\n");
        if(lAvion->contains(lAvion,av0))
        {
            printf("SI CONTIENE\n");
        }
        else
        {
            printf("NO CONTIENE\n");
        }
    printf("\nLa lista aun contiene el segundo avion ingresado??\n");
        if(lAvion->contains(lAvion,av1))
        {
            printf("SI CONTIENE\n");
        }
        else
        {
            printf("NO CONTIENE\n");
        }
    printf("-----------------------------------------------\n");
    system("pause");

    printf("\n\n-4.3. Agregamos nuevamente el primer avion en otro indice: [al_set]\n");
    lAvion->set(lAvion, 6, av0);
    imprimirListaAvion(lAvion);
    printf("\n\nDimension del ArrayList [al_len]: %d\n\n", lAvion->len(lAvion));
    printf("-----------------------------------------------\n");
    system("pause");

    printf("\n\n-4.4. Ordenamos por Capacidad: [al_sort]\n");
    lAvion->sort(lAvion, compararAvion, 0);
    imprimirListaAvion(lAvion);
    printf("\n\nDimension del ArrayList [al_len]: %d\n\n", lAvion->len(lAvion));
    printf("-----------------------------------------------\n");
    system("pause");
    system("cls");

    printf("5. Indice del Avion 1 (AIRBUS A320) y 3 (AIRBUS A380): [al_indexOf]\n");
    printf("\n-5.1.1. Segun Lista Original:");
    int index3 = lAvion2->indexOf(lAvion2, av0);
    int index4 = lAvion2->indexOf(lAvion2, av2);
    imprimirListaAvion(lAvion2);
    printf("\n\nIndice del Avion1 (AIRBUS A320): %d\nIndice del Avion3 (AIRBUS A380): %d", index3, index4);
    printf("\n\nDimension del ArrayList [al_len]: %d\n", lAvion2->len(lAvion2));
    printf("-----------------------------------------------\n");

    printf("\n-5.1.2 Segun Lista Trabajada:");
    int index1 = lAvion->indexOf(lAvion, av0);
    int index2 = lAvion->indexOf(lAvion, av2);
    imprimirListaAvion(lAvion);
    printf("\n\nIndice del Avion1 (AIRBUS A320): %d\nIndice del Avion3 (AIRBUS A380): %d", index1, index2);
    printf("\n\nDimension del ArrayList [al_len]: %d\n\n", lAvion->len(lAvion));
    printf("-----------------------------------------------\n");
    system("pause");
    system("cls");

    printf("6. Push del avion 9 (EMBRAER E-JETS 190) al indice 0: [al_push]\n");
    lAvion->push(lAvion, 0, av9);
    imprimirListaAvion(lAvion);
    printf("\n\nDimension del ArrayList [al_len]: %d\n\n", lAvion->len(lAvion));
    printf("-----------------------------------------------\n");
    system("pause");

    printf("\n\n7. Pop del avion 3 (AIRBUS A380) en el indice 1: [al_pop]\n");
    eAvion* aux = lAvion->pop(lAvion, 1);
    imprimirListaAvion(lAvion);
    printf("\n\nElemento POP: %s, %s\n\n", aux->marca, aux->modelo);
    printf("Dimension del ArrayList [al_len]: %d\n\n", lAvion->len(lAvion));
    printf("-----------------------------------------------\n");
    system("pause");
    system("cls");

    printf("8. Obtenemos la sublista de 3 elementos: [al_subList]\n\n");
    imprimirListaAvion(lAvion);
    printf("\n\n");
    printf("Dimension del ArrayList [al_len]: %d\n\n\nSublist:", lAvion->len(lAvion));
    ArrayList* subListaAvion = lAvion->subList(lAvion, 2, 5);
    imprimirListaAvion(subListaAvion);
    printf("\n\nDimension de la SubList [al_len]: %d\n\n", subListaAvion->len(subListaAvion));
    printf("-----------------------------------------------\n");
    system("pause");
    system("cls");

    printf("9. Ultima comparación entre ambos ArrayList:\n\n");
    printf("Lista Original:\n");
    imprimirListaAvion(lAvion2);
    printf("\n\nDimension del ArrayList [al_len]: %d\n\n", lAvion2->len(lAvion2));
    printf("\nLista Clonada y trabajada:\n");
    imprimirListaAvion(lAvion);
    printf("\n\nDimension del ArrayList [al_len]: %d\n\n", lAvion->len(lAvion));
    printf("-----------------------------------------------\n");
    system("pause");
    system("cls");

    printf("10. Limpiamos el array trabajado: [al_clear]");
    lAvion->clear(lAvion);
    imprimirListaAvion(lAvion);
    printf("\n\nDimension del ArrayList [al_len]: %d\n\n", lAvion->len(lAvion));
    printf("-----------------------------------------------\n");
    system("pause");

    printf("\n\n11. Preguntamos si esta vacio: [al_isEmpty]");
    printf("\n\n-El Array se encuentra vacio??\n\n");
    if(lAvion->isEmpty(lAvion))
    {
        printf("-Si esta vacio");
    }
    else
    {
        printf("-No esta vacio");
    }
    printf("\n\n-----------------------------------------------\n");
    system("pause");
    system("cls");

    printf("12. Hacemos lo mismo con el original: [al_isEmpty]\n\n");
    printf("Lista Original:\n");
    imprimirListaAvion(lAvion2);
    printf("\n\nDimension del ArrayList [al_len]: %d\n\n", lAvion2->len(lAvion2));
    printf("-El Array se encuentra vacio??\n\n");
    if(lAvion2->isEmpty(lAvion2))
    {
        printf("-Si esta vacio");
    }
    else
    {
        printf("-No esta vacio");
    }
    printf("\n\n-----------------------------------------------\n");
    system("pause");
    system("cls");

    printf("13. Limpiamos el array original y liberamos memoria (Ambos Arrays y elementos):\n\n[al_clear]");
    lAvion->clear(lAvion2);
    imprimirListaAvion(lAvion2);
    printf("\n\nDimension del ArrayList [al_len]: %d\n\n", lAvion2->len(lAvion2));
    free(av0);
    free(av1);
    free(av2);
    free(av3);
    free(av4);
    free(av5);
    free(av6);
    free(av7);
    free(av8);
    free(av9);
    lAvion->deleteArrayList(lAvion);
    lAvion2->deleteArrayList(lAvion2);
    printf("[al_deleteArrayList]\n[al_deleteArrayList]\n\n\tCOMPROBACION DEL ARRAYLIST TERMINADA.\n\n");
    system("pause");

    return 0;
}

void imprimirListaAvion(ArrayList* al)
{
  int i = 0;
  eAvion* avAux;

  for(i =0 ; i < al->len(al); i++)
  {
      avAux = al->get(al,i);
      imprimirAvion(avAux);
  }
}
