#include <stdio.h>
#include "gestionevisitatore.h"

void visitatoremenu (FILE *file){
    int scelta;
    
    do{
        printf("\n===========================================\n");
        printf("         MENU VISITATORE\n");
        printf("===========================================\n");
        printf("  [1] Consulta un videogioco\n");
        printf("  [2] Scrivi una recensione\n");
        printf("  [3] Mostra catalogo \n");
        printf("  [4] Torna al menu \n");
        printf("-------------------------------------------\n");
        printf("Scegli un'opzione: ");

        scanf("%d", &scelta);
        switch(scelta){
            case 1: ricercaGioco(file); break;
        }

    }while (scelta!=4);
}