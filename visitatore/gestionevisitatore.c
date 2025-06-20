#define MAX_CHARS 100
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../ricerca/ricercaVideogioco.h"
#include "..\ordinamento\ordinamento.h"


// Menu per l'acquisto di un videogioco
void acquista(FILE *file) {
    Videogioco_t vg;
    short int trovato = 0; 
    long offset = ricercaTitolo(file);

    if (offset != -1) {
        printf("Videogioco trovato alla posizione %ld\n", offset);

        // il puntatore si posiziona sull'offset ritornato da "ricercaTitolo" e legge la struttura esistente
        fseek(file, offset, SEEK_SET);
        fread(&vg, sizeof(Videogioco_t), 1, file);

        int scelta = 0;

        do {
            printf("Vuoi acquistare il seguente gioco? [1] Si | [0] No: ");
            scanf("%d", &scelta);

            if (scelta == 1) {
                printf("Gioco acquistato.\n");

                vg.numeroCopie++;
            }
        } while (scelta != 1 && scelta != 0);

        // ritorna all'offset iniziale e sovrascrive la struttura con il numero di copie aggiornato
        fseek(file, offset, SEEK_SET);
        fwrite(&vg, sizeof(vg), 1, file);

        printf("\n------------------------------------------------------------\n");

    }
}

void ricercaGioco(FILE *file){
    system("cls");
    short int scelta;

    do{
        printf("\n===========================================\n");
        printf("         MENU RICERCA VIDEOGIOCO\n");
        printf("===========================================\n");
        printf("  [1] Ricerca un videogioco per Titolo\n");
        printf("  [2] Ricerca i giochi prodotti da uno Sviluppatore\n");
        printf("  [3] Ricerca i giochi di un Editore\n");
        printf("  [4] Ricerca i giochi per Genere\n");
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

void ordinamentoScelta(FILE *file){
    system("cls");
    printf("Funzione ordinamento\n");  // DEBUG

    int scelta;

    do{
        printf("\n===========================================\n");
        printf("         CATALOGO ORDINATO\n");
        printf("===========================================\n");
        printf("Vuoi visionare il catalogo ordinato per: \n");
        printf("[1] Voto piu alto \n");
        printf("[2] Numero di copie vendute \n");
        printf("-------------------------------------------\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &scelta);

        switch (scelta){
            case 1: 
                ordinamentoVoti(file); 
                break;
            case 2: 
                ordinamentoCopie(file); 
                break;
            default:
                printf("Scelta non valida\n"); 
                break;
        }

    }while (scelta != 1 && scelta != 2);
}