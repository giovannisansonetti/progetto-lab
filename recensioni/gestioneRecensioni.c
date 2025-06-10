#include <stdio.h>
#include "..\ricerca\ricercaVideogioco.h"
#include "..\admin\videogioco.h"


// bisogna trasformarle in una funzione singola

void aggiungiRecensione(FILE *file){

    Videogioco_t vg;
    short int scelta;
    long offset = ricercaTitolo(file);

    if(offset != -1){
        printf("Videogioco trovato alla posizione %ld\n", offset); 
        fseek(file, offset, SEEK_SET);
        fread(&vg, sizeof(Videogioco_t), 1, file);

        do{
            printf("Inserisci un voto (0-5) \n");
            scanf("%d", &vg.recensioni[vg.numeroRecensioni].voto);
        }while (vg.recensioni[vg.numeroRecensioni].voto > 5 || vg.recensioni[vg.numeroRecensioni].voto < 0);

        printf("Inserisci una descrizione: \n");
        scanf("%s", vg.recensioni[vg.numeroRecensioni].descrizione);
        
        vg.numeroRecensioni++;

        fseek(file, offset, SEEK_SET);
        fwrite(&vg, sizeof(vg), 1, file);

        printf("\n\n Recensione inserita! \n\n");
        printf("------------------------------------------------------------\n");
    }

}

// problema: va ad alterare il nome e lo rende vuoto

void modificaRecensione(FILE *file){

    Videogioco_t vg;
    short int scelta;

    long offset = ricercaTitolo(file);

    if(offset != -1){
        printf("Videogioco trovato alla posizione %ld\n", offset); // debug
    }

    fseek(file, offset, SEEK_SET);

    fread(&vg, sizeof(Videogioco_t), 1, file);

    printf("Quale recensione vuoi modificare? \n");
    scanf("%d", &scelta);

    do{
        printf("Inserisci un voto (0-5) \n");
        scanf("%d", &vg.recensioni[scelta].voto);
    }while (vg.recensioni[scelta].voto > 5 || vg.recensioni[scelta].voto < 0);

    printf("Inserisci una descrizione: \n");
    scanf("%s", vg.recensioni[scelta].descrizione);


    fseek(file, offset, SEEK_SET);
    fwrite(&vg, sizeof(vg), 1, file);

    printf("\n\n Recensione inserita! \n\n");
    printf("------------------------------------------------------------\n");
}