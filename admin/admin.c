#include <stdio.h>
#include "gestioneCatalogo.h"

void adminMenu(FILE *file){

    int scelta;

    do{
        printf("[1] Inserisci un nuovo videogioco \n");
        printf("[2] Modifica un videogioco \n");
        printf("[3] Cancella un videogioco \n");
        printf("[4] Visualizza il catalogo \n");
        printf("[5] Torna al menu \n");

        scanf("%d", &scelta);
        switch(scelta){
            case 1: inserisciGioco(file); break;
            case 2: modificaGioco(file); break;
            case 3: cancellaGioco(file); break;
            case 4: visualizzaCatalogo(file); break;
        }

    }while(scelta != 5);
}

