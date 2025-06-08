#define MAX_VIDEOGIOCHI 100
#define MAX_CHARS 100 

#include <stdio.h>
#include "Videogioco.h"
#include <stdlib.h>
#include <string.h>
#include "../ricerca/ricercaVideogioco.h"

void inserisciGioco(FILE *file){
    
    Videogioco_t vg;

    short int cont;

    do{
        printf("Inserisci il titolo del videogioco: \n");
        scanf("%s", vg.titolo);
        printf("Inserisci l'editore del videogioco: \n");
        scanf("%s", vg.editore);
        printf("Inserisci il nome dello sviluppatore videogioco: \n");
        scanf("%s", vg.sviluppatore);
        printf("Inserisci una breve descrizione del gioco: \n");
        scanf("%s", vg.descrizione);
        printf("Inserisci l'anno di pubblicazione del videogioco: \n");
        scanf("%d", &vg.annoPubblicazione);
        printf("Inserisci il genere del videogioco: \n");
        scanf("%s", vg.genere);

        /*printf("Inserisci il numero di recensioni che vuoi inserire\n");
        scanf("%d", &vg.numeroRecensioni);

        for (int i = 0; i < vg.numeroRecensioni; i++) {
            do {
                printf("Voto (0-5): ");
                scanf("%d", &vg.recensioni[i].voto);
            } while (vg.recensioni[i].voto < 0 || vg.recensioni[i].voto > 5);

            int scelta;
            
            printf("Vuoi inserire una descrizione? [1] Si | [0] No: ");
            scanf("%d", &scelta);
            if (scelta == 1) {
                printf("Descrizione recensione: ");
                scanf("%s", vg.recensioni[i].descrizione);
            }
        }

        vg.numeroCopie = 0;
        */ 
       
        if (fwrite(&vg, sizeof(Videogioco_t), 1, file) != 1) {
            printf("Errore nella scrittura del file!\n");
        } else {
            printf("Videogioco salvato correttamente.\n");
        }

        do{
            printf("Vuoi aggiungere un altro gioco? [1] Si [0] No \n");
            scanf("%d", &cont);
        }while (cont != 1 && cont != 0);

    }while (cont != 0);
}


void modificaGioco(FILE *file){
    Videogioco_t vg;
    
    short int trovato = 0; // sentinella
    long offset = ricercaTitolo(file);
    if(offset != -1){
        printf("Videogioco trovato alla posizione %ld\n", offset);
        short int scelta = 0;
        do{
            printf("Modificare i dati? [1] Si [0] No \n");
            scanf("%d", &scelta);
            if(scelta == 1){
                printf("Modifica il titolo del videogioco: \n");
                scanf("%s", vg.titolo);
                printf("Modifica l'editore del videogioco: \n");
                scanf("%s", vg.editore);
                printf("Modifica il nome dello sviluppatore videogioco: \n");
                scanf("%s", vg.sviluppatore);
                printf("Modifica una breve descrizione del gioco: \n");
                scanf("%s", vg.descrizione);
                printf("Modifica l'anno di pubblicazione del videogioco: \n");
                scanf("%d", &vg.annoPubblicazione);
                printf("Modifica il genere del videogioco: \n");
                scanf("%s", vg.genere);
                printf("Modifica il numero di recensioni che vuoi inserire\n");
                scanf("%d", &vg.numeroRecensioni);
                vg.numeroCopie = vg.numeroCopie; // cosi non si auto sovrascrive

                fseek(file, offset, SEEK_SET);
                fwrite(&vg, sizeof(vg), 1, file);
                printf("\n\n Videogioco rimosso!");
                printf("------------------------------------------------------------\n");

            }
        }while(scelta != 0 && scelta != 1);
    }
}

void cancellaGioco(FILE *file){
    Videogioco_t vg;
    Videogioco_t vg_reset = {"" ,"" ,"", "", 0, "", 0, 0, 0};

    short int trovato = 0; // sentinella
    long offset = ricercaTitolo(file);
    int scelta;

    if(offset != -1){
        do{
            printf("Sei sicuro di voler cancellare il videogioco dal catalogo? [1] Si [0] No \n");
            scanf("%d", &scelta);
            if(scelta == 1){
                vg = vg_reset;
                fseek(file, offset, SEEK_SET);
                fwrite(&vg, sizeof(vg), 1, file);
                printf("Videogioco rimosso! \n");
            }
        }while(scelta != 0 && scelta != 1);
    }
}

void visualizzaCatalogo(FILE *file){
    Videogioco_t vg;

    rewind(file);

    printf("\n==================== CATALOGO VIDEOGIOCHI ====================\n\n");

    while (fread(&vg, sizeof(Videogioco_t), 1, file) == 1) {

        printf("-----------------------------------------------------------------\n");
        printf(" GIOCO ");
        printf("-----------------------------------------------------------------\n");
        printf(" Titolo:                  %s\n", vg.titolo);
        printf(" Editore:                 %s\n", vg.editore);
        printf(" Sviluppatore:            %s\n", vg.sviluppatore);
        printf(" Anno Pubblicazione:      %d\n", vg.annoPubblicazione);
        printf(" Copie Vendute:           %d\n", vg.numeroCopie);
        printf(" Descrizione:             %s\n", vg.descrizione);

        printf("\n Numero di Recensioni: %d\n", vg.numeroRecensioni);

        if (vg.numeroRecensioni == 0) {
            printf("   Nessuna recensione disponibile.\n");

        } else {
            for (int i = 0; i < vg.numeroRecensioni; i++) {
                printf("   -----------------------------------------------------------\n");
                printf("    Recensione #%d\n", i + 1);
                printf("    Voto        : %d / 5\n", vg.recensioni[i].voto);
                printf("    Descrizione : %s\n", vg.recensioni[i].descrizione);
            }
        }

        printf("=================================================================\n\n");
    }
    system("pause");
}