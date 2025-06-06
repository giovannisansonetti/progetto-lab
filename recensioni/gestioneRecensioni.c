#include <stdio.h>
#include "..\ricerca\ricercaVideogioco.h"
#include "..\admin\videogioco.h"

void aggiungiRecensione(FILE *file){
   Videogioco_t vg;
    int recensioni;
    short int trovato = 0; // sentinella
    long offset = ricercaTitolo(file);
    if(offset != -1){
        printf("Videogioco trovato alla posizione %ld\n", offset);
        short int scelta = 0;

    }
    printf("quanti recensioni vuoi inserire?");
    scanf("%d",&recensioni);
  

    
    for (int i = 0; i < recensioni; i++) {
            do {
                printf("Voto (0-5): ");
                scanf("%d", &vg.recensioni[i].voto);
                printf("Inserisci una descrizione alla tua recensione");
                scanf("%s",vg.recensioni[i].descrizione);
            } while (vg.recensioni[i].voto < 0 || vg.recensioni[i].voto > 5);

        }   vg.numeroRecensioni+=recensioni;
    

    fseek(file, offset, SEEK_SET);
    fwrite(&vg, sizeof(vg), 1, file);
    printf("\n\n Recensione inserita!");
    printf("------------------------------------------------------------\n");
   
}