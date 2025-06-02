#define MAX_VIDEOGIOCHI 100
#define MAX_CHARS 100 

#include <stdio.h>
#include "Videogioco.h"

void inserisciGioco(FILE *file){
    
    Videogioco_t vg;

    short int cont;
    short int numRecensioni;

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
        printf("Inserisci il numero di recensioni che vuoi inserire\n");
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
        
        fwrite(&vg, sizeof(Videogioco_t), 1, file);
        do{
            printf("Videogioco inserito! Vuoi aggiungere un altro gioco? [1] Si [0] No \n");
            scanf("%d>", &cont);
        }while (cont != 1 && cont != 0);

    }while (cont != 0);
}


void modificaGioco(FILE *file){
    Videogioco_t vg;
    char titolo[MAX_CHARS];
    printf("Inserisci il titolo del gioco che vuoi cancellare: \n")
    scanf("%s", titolo);
    
    while (fread(&vg, sizeof(Videogioco_t), 1, file) == 1){
        if(titolo == vg.titolo){

        }else{
            printf("Nessun titolo corrispondente ");
        }
    }
}

void cancellaGioco(FILE *file){
    Videogioco_t vg;
    char titolo[MAX_CHARS];
    printf("Inserisci il titolo del gioco che vuoi cancellare: \n")
    scanf("%s", titolo);
    
    while (fread(&vg, sizeof(Videogioco_t), 1, file) == 1){
        if(titolo == vg.titolo){

        }else{
            printf("Nessun titolo corrispondente ");
        }
    }

}

void visualizzaCatalogo(FILE *file){
    Videogioco_t vg;
    printf("Ecco il catalogo dei videogiochi presenti: \n");
    while (fread(&vg, sizeof(Videogioco_t), 1, file) == 1)
	{
        printf("Titolo: %s\nEditore: %s\nSviluppatore: %s\nDescrizione: %s\nAnno di pubblicazione: %d\n" , vg.titolo, vg.editore, vg.sviluppatore, vg.descrizione, vg.annoPubblicazione);
        printf("Recensioni:\n");

        for(int i = 0; i < vg.numeroRecensioni; i++){
            printf("Voto: %d \n", vg.recensioni[i].voto);
            printf("Descrizione: %s\n", vg.recensioni[i].descrizione);
        }
	}


    // bisogna implementare l'ordinamento in ordine di giudizio medio o di copie vendute
}