#include <stdio.h>
#include "..\ricerca\ricercaVideogioco.h"
#include "..\admin\videogioco.h"

void acquista(FILE *file) {
    Videogioco_t vg;
    short int trovato = 0; 
    long offset = ricercaTitolo(file);

    if (offset != -1) {
        printf("Videogioco trovato alla posizione %ld\n", offset);

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

       
        fseek(file, offset, SEEK_SET);
        fwrite(&vg, sizeof(vg), 1, file);

        printf("\n------------------------------------------------------------\n");
    } else {
        printf("Videogioco non trovato.\n");
    }
}
