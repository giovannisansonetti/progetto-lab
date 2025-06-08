#include <stdio.h>
#include "gestionevisitatore.h"
#include "..\ricerca\ricercaVideogioco.h"
#include "..\recensioni\gestioneRecensioni.h"
#include "..\ordinamento\ordinamento.h"


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
        printf("  [5] Mostra catalogo ordinato \n");
        printf("  [6] Torna al menu \n");
        printf("-------------------------------------------\n");
        printf("Scegli un'opzione: ");

        scanf("%d", &scelta);
        
        switch(scelta){
            case 1: acquista(file); break;
            case 2: aggiungiRecensione(file); break;
            case 3: ricercaGioco(file); break;
            case 4: visualizzaCatalogo(file); break;
            case 5: ordinamentoVoti(file); break;
            default: break;
        }

    }while (scelta!=5);
}