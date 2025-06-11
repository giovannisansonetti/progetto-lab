#include <stdio.h>
#include "..\ricerca\ricercaVideogioco.h"
#include "..\admin\videogioco.h"


// bisogna trasformarle in una funzione singola

void gestioneRecensioni(FILE *file){

    Videogioco_t vg;
    short int scelta;

    long offset = ricercaTitolo(file);

    if(offset != -1){

        do{ 
            printf("Vuoi aggiungere o modificare una recensione? \n"); 
            printf("[1] Aggiungi \n"); 
            printf("[2] Modifica \n"); 
            printf("[3] Esci \n");

            scanf("%d", &scelta);

            if(scelta == 1){
                printf("Videogioco trovato alla posizione %ld\n", offset); 
                fseek(file, offset, SEEK_SET);
                fread(&vg, sizeof(Videogioco_t), 1, file);

                do{
                    printf("Inserisci un voto (0-5) \n");
                    scanf("%d", &vg.recensioni[vg.numeroRecensioni].voto);
                }while (vg.recensioni[vg.numeroRecensioni].voto > 5 || vg.recensioni[vg.numeroRecensioni].voto < 0);

                printf("Inserisci una descrizione: \n");
                scanf(" %[^\n]", vg.recensioni[vg.numeroRecensioni].descrizione);
                
                vg.numeroRecensioni++;

                fseek(file, offset, SEEK_SET);
                fwrite(&vg, sizeof(vg), 1, file);

                printf("\n\n Recensione inserita! \n\n");
                printf("------------------------------------------------------------\n");
            }

            if(scelta == 2){

                short int modificaRecensione;

                fseek(file, offset, SEEK_SET);

                fread(&vg, sizeof(Videogioco_t), 1, file);

                printf("Quale recensione vuoi modificare? \n");
                scanf("%d", &modificaRecensione);

                do{
                    printf("Inserisci un voto (0-5) \n");
                    scanf("%d", &vg.recensioni[modificaRecensione].voto);
                }while (vg.recensioni[modificaRecensione].voto > 5 || vg.recensioni[modificaRecensione].voto < 0);

                printf("Inserisci una descrizione: \n");
                scanf(" %[^\n]", vg.recensioni[modificaRecensione].descrizione);


                fseek(file, offset, SEEK_SET);
                fwrite(&vg, sizeof(vg), 1, file);

                printf("\n\n Recensione inserita! \n\n");
                printf("------------------------------------------------------------\n");

            }

        } while (scelta != 3);
    }
}

