#include <stdio.h>
#include "..\ricerca\ricercaVideogioco.h"
#include "..\admin\videogioco.h"

void aggiungiRecensione(FILE *file){

    Videogioco_t vg;
    int recensioni;
    short int scelta;
    long offset = ricercaTitolo(file);

    if(offset != -1){
        printf("Videogioco trovato alla posizione %ld\n", offset);
    }

    fseek(file, offset, SEEK_SET);

    fread(&vg, sizeof(Videogioco_t), 1, file);

    printf("Quante recensioni vuoi inserire? \n");
    scanf("%d", &recensioni);
  
    for (int i = 0; i < recensioni; i++) {
        do {
            printf("Voto (0-5): ");
            scanf("%d", &vg.recensioni[i].voto);
            
        } while (vg.recensioni[i].voto < 0 || vg.recensioni[i].voto > 5);
        
        printf("Vuoi inserire una descrizione a questa recensione? [1] Si | [0] No: ");
        scanf("%d", &scelta);

        if (scelta == 1) {
            printf("Descrizione recensione: ");
            scanf("%s", vg.recensioni[i].descrizione);
        }
    }   

    vg.numeroRecensioni += recensioni;
 
    fseek(file, offset, SEEK_SET);
    fwrite(&vg, sizeof(vg), 1, file);

    printf("\n\n Recensione inserita! \n\n");
    printf("------------------------------------------------------------\n");
   
}