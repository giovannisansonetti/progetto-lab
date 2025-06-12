#include <stdio.h>
#include "..\ricerca\ricercaVideogioco.h"
#include "..\admin\videogioco.h"

// aggiungi una recensione ad un videogioco esistente 

void gestioneRecensioni(FILE *file){

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
        scanf(" %[^\n]", vg.recensioni[vg.numeroRecensioni].descrizione);
        
        vg.numeroRecensioni++;

        fseek(file, offset, SEEK_SET);
        fwrite(&vg, sizeof(vg), 1, file);

        printf("\n\n Recensione inserita! \n\n");
        printf("------------------------------------------------------------\n");
    }
}

// stampa tutte le recensioni di un gioco cercato, assieme alla media dei voti

void visioneRecensioni(FILE *file){
    Videogioco_t vg;
    short int trovato = 0;
    long offset;
    rewind(file);
    
    char titoloInput[MAX_CHARS];

    printf("Inserisci il titolo del gioco che vuoi cercare: \n");
    scanf(" %[^\n]", titoloInput);

    while(fread(&vg, sizeof(Videogioco_t), 1, file)){
        if(strstr(vg.titolo, titoloInput)){
            trovato = 1;
            offset = ftell(file) - sizeof(Videogioco_t); // sottraggo la struttura videogioco perchè dopo l'fread il puntatore si trova al record successivo
            int voti = 0;
            
            printf("Titolo: %s\n");
            if(vg.numeroRecensioni > 0){
                for (int i = 0; i < vg.numeroRecensioni; i++) {
                    printf("   -----------------------------------------------------------\n");
                    printf("    Recensione #%d\n", i);
                    printf("    Voto        : %d / 5\n", vg.recensioni[i].voto);
                    printf("    Descrizione : %s\n", vg.recensioni[i].descrizione);
                    voti += vg.recensioni[i].voto;
                }
                float media = (float)voti / vg.numeroRecensioni;

                printf("   -----------------------------------------------------------\n");
                printf("    Media voti  : %.2f / 5\n", media);
                break;
            }
        }
    }
    if(trovato == 0){
        printf("Nessun videogioco trovato con quel nome \n");
    }

    system("pause");
}


