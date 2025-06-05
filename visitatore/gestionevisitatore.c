#define MAX_CHARS 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ricerca/ricercaVideogioco.h"

void ricercaGioco(FILE *file){

    short int scelta;

    do{
        printf("\n===========================================\n");
        printf("         MENU RICERCA VIDEOGIOCO\n");
        printf("===========================================\n");
        printf("  [1] Ricerca per Titolo\n");
        printf("  [2] Ricerca per Sviluppatore\n");
        printf("  [3] Ricerca per Editore\n");
        printf("  [4] Ricerca per Genere\n");
        printf("  [5] Ricerca per Anno di Pubblicazione\n");
        printf("  [6] Torna al menu principale\n");
        printf("-------------------------------------------\n");
        printf("Seleziona un'opzione: ");
        scanf("%d", &scelta);

        switch (scelta){
            case 1: ricercaTitolo(file); break;
            case 2: ricercaSviluppatore(file); break;
            case 3: ricercaEditore(file); break;
            case 4: ricercaGenere(file); break;
            case 5: ricercaAnno(file); break;
        }

    }while (scelta != 6);
}