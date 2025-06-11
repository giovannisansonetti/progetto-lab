#include <stdio.h>
#include "gestioneCatalogo.h"
#include "..\ricerca\ricercaVideogioco.h"
#include "..\recensioni\gestioneRecensioni.h"

void adminMenu(FILE *file){
    system("cls");
    int scelta;

    do{
        printf("\n===========================================\n");
        printf("         MENU ADMIN\n");
        printf("===========================================\n");
        printf("[1] Inserisci un nuovo videogioco \n");
        printf("[2] Modifica un videogioco \n");
        printf("[3] Cancella un videogioco \n");
        printf("[4] Ricerca un videogioco (per parametri) \n");
        printf("[5] Visiona le recensioni di un gioco \n");
        printf("[6] Torna al menu \n");
        printf("-------------------------------------------\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1: inserisciGioco(file); break;
            case 2: modificaGioco(file); break;
            case 3: cancellaGioco(file); break;
            case 4: ricercaParametri(file); break;
            case 5: visioneRecensioni(file); break;
        }
    }while(scelta != 6);
}

