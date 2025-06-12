#define MAX_VIDEOGIOCHI 40
#define MAX_CHARS 100 

#include <stdio.h>
#include "Videogioco.h"
#include <stdlib.h>
#include <string.h>
#include "../ricerca/ricercaVideogioco.h"

void inserisciGioco(FILE *file){
    
    Videogioco_t vg;

    short int cont;
    short int nGeneri;

    do{
        printf("Inserisci il titolo del videogioco: \n");
        scanf(" %[^\n]", vg.titolo);
        printf("Inserisci l'editore del videogioco: \n");
        scanf(" %[^\n]", vg.editore);
        printf("Inserisci il nome dello sviluppatore videogioco: \n");
        scanf(" %[^\n]", vg.sviluppatore);
        printf("Inserisci una breve descrizione del gioco: \n");
        scanf(" %[^\n]", vg.descrizione);
        printf("Inserisci l'anno di pubblicazione del videogioco: \n");
        scanf(" %d", &vg.annoPubblicazione);

        printf("Inserisci il numero di generi \n");
        scanf("%d", &nGeneri);

        for(int i = 0; i < nGeneri; i++){
            printf("Inserisci il %d genere: ", i+1);
            scanf("%s", &vg.genere[i]);
        }

        vg.numeroRecensioni = 0;
        vg.numeroCopie = 0;

        vg.numeroGeneri = nGeneri;
        
        fseek(file, 0, SEEK_END);

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

            fseek(file, offset, SEEK_SET);
            fread(&vg, sizeof(Videogioco_t), 1, file);

            if(scelta == 1){
                printf("Modifica il titolo del videogioco: \n");
                scanf(" %[^\n]", vg.titolo);
                printf("Modifica l'editore del videogioco: \n");
                scanf(" %[^\n]", vg.editore);
                printf("Modifica il nome dello sviluppatore: \n");
                scanf(" %[^\n]", vg.sviluppatore);
                printf("Modifica la descrizione del gioco: \n");
                scanf(" %[^\n]", vg.descrizione);
                printf("Modifica l'anno di pubblicazione: \n");
                scanf("%d", &vg.annoPubblicazione);

                for(int i = 0; i < vg.numeroGeneri; i++){
                    printf("Modifica il genere numero %d \n", i+1);
                    scanf("%s", &vg.genere[i]);
                }
                
                vg.numeroCopie = vg.numeroCopie; // cosi non si auto sovrascrive

                fseek(file, offset, SEEK_SET);
                fwrite(&vg, sizeof(vg), 1, file);

                printf("\n\n Videogioco modificato correttamente \n\n");
                printf("------------------------------------------------------------\n");

            }
        }while(scelta != 0 && scelta != 1);
    }
}

void cancellaGioco(FILE *file){
    Videogioco_t vg;
    Videogioco_t vg_reset = {"" ,"" ,"", "", 0, 0, 0, 0, 0};

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

void ricercaParametri(FILE *file){
    system("cls");
    short int scelta;

    do{
        printf("\n===========================================\n");
        printf("         MENU RICERCA VIDEOGIOCO (ADMIN)\n");
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