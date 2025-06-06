#include <stdio.h>
#include "gestionevisitatore.h"
#include "..\admin\gestioneCatalogo.h"

void visitatoremenu(FILE *file){
    int scelta;
    system("cls");
    do{
        printf("\n===========================================\n");
        printf("         MENU VISITATORE\n");
        printf("===========================================\n");
        printf("  [1] Ricerca e acquista un videogioco\n");
        printf("  [2] Scrivi una recensione\n");
        printf("  [3] Mostra catalogo \n");
        printf("  [4] Torna al menu \n");
        printf("-------------------------------------------\n");
        printf("Scegli un'opzione: ");

        scanf("%d", &scelta);
        
        switch(scelta){
            case 1: ricercaGioco(file); break;
            case 2: break;
            case 3: visualizzaCatalogo(file);
        }
    }while (scelta!=4);
}