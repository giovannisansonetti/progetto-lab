#include <stdio.h>
#include "gestionevisitatore.h"
#include "..\admin\gestioneCatalogo.h"

void visitatoremenu(FILE *file){
    int scelta;
    system("cls");
    
    do{
        printf("\n===========================================\n");
        printf("         MENU VISITATORE        \n");
        printf("===========================================\n");
        printf("  [1] Acquista un videogioco\n");
        printf("  [2] Scrivi una recensione\n");
        printf("  [3] Ricerca un gioco con parametri \n");
        printf("  [4] Mostra catalogo \n");
        printf("  [5] Torna al menu \n");
        printf("-------------------------------------------\n");
        printf("Scegli un'opzione: ");

        scanf("%d", &scelta);
        
        switch(scelta){
            case 1: acquista(file);
            case 2: break;
            case 3: ricercaGioco(file); break;
            case 4: visualizzaCatalogo(file);
        }
        
    }while (scelta!=5);
}