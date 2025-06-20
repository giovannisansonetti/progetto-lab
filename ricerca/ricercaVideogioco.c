#include <stdio.h>
#include <stdlib.h>
#include "../admin/Videogioco.h"
#include <string.h>

#define MAX_CHARS 100

// ricerca un gioco con input il titolo, ritorna un offset (la posizione del blocco contentente il gioco cercato) 

long ricercaTitolo(FILE *file){
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
            printf("Matching trovato \n");
            offset = ftell(file) - sizeof(Videogioco_t); // sottraggo la struttura videogioco perchè dopo l'fread il puntatore si trova al record successivo
            printf(" Titolo:                  %s\n", vg.titolo);
            printf(" Editore:                 %s\n", vg.editore);
            printf(" Sviluppatore:            %s\n", vg.sviluppatore);
            printf(" Anno Pubblicazione:      %d\n", vg.annoPubblicazione);
            printf(" Copie Vendute:           %d\n", vg.numeroCopie);
            printf(" Descrizione:             %s\n", vg.descrizione);
            printf(" Genere/i:                ");

            for(int i = 0; i < vg.numeroGeneri; i++){
                
                printf("%s, ", vg.genere[i]);
            }
            break;
        }
    }
    if(trovato == 0){
        printf("Nessun videogioco trovato con quel nome");
        return -1;
    }

    return offset;
}

// stampa la lista di tutti i videogiochi che sono stati prodotti da uno sviluppatore 
void ricercaSviluppatore(FILE *file){
    Videogioco_t vg;
    char sviluppatoreInput[MAX_CHARS];
    short int trovato = 0;

    printf("Inserisci il nome dello sviluppatore da ricercare: \n");
    scanf("%s", sviluppatoreInput);
    printf("************ Ecco i videogiochi prodotti dallo sviluppatore: %s ************ \n ", sviluppatoreInput);
    rewind(file);

    while(fread(&vg, sizeof(Videogioco_t), 1, file)){
        if(strstr(vg.sviluppatore, sviluppatoreInput)){
            trovato = 1;
            printf("- %s\n", vg.titolo);
        }
    }

    if(trovato == 0){
        printf("Nessun videogioco prodotto da %s \n", sviluppatoreInput);
    }
    system("pause");
}

// stampa la lista di tutti i videogiochi che sono stati prodotti da un editore 

void ricercaEditore(FILE *file){
    Videogioco_t vg;
    char editoreInput[MAX_CHARS];
    short int trovato = 0;

    printf("Inserisci un editore da cercare: \n");
    scanf("%[^\n] ", editoreInput);
    printf("************ Ecco i videogiochi prodotti dallo sviluppatore: %s ************\n ", editoreInput);
    rewind(file);

    while(fread(&vg, sizeof(Videogioco_t), 1, file)){
        if(strstr(vg.editore, editoreInput)){
            trovato = 1;
            printf("- %s\n", vg.titolo);
        }
    }

    if(trovato == 0){
        printf("Nessun editore trovato \n"); 
    }

    system("pause");

}

// stampa la lista di tutti i videogiochi che hanno il genere cercato

void ricercaGenere(FILE *file){
    Videogioco_t vg;
    char genereInput[MAX_CHARS];
    short int trovato = 0;

    printf("Inserisci un genere da cercare: \n");
    scanf("%[^\n] ", genereInput);
    printf("************ Ecco i videogiochi con il genere cercato ************ \n");
    rewind(file);

    while(fread(&vg, sizeof(Videogioco_t), 1, file)){

        for(int i = 0; i < vg.numeroGeneri; i++){
            if(strstr(vg.genere[i], genereInput)){
            trovato = 1;
            printf("- %s \n", vg.titolo);
            }   
        }
    }

    if(trovato == 0){
        printf("Nessun videogioco trovato con quel genere \n"); 
    }
    system("pause");
}


// stampa la lista di tutti i videogiochi prodotti nell'anno cercato 

void ricercaAnno(FILE *file){
    Videogioco_t vg;

    short int annoInput;
    short int trovato = 0;

    printf("Inserisci un anno: \n");
    scanf("%d", &annoInput);
    printf("************ Ecco i videogiochi che sono usciti nel %d ************\n", annoInput);
    rewind(file);

    while(fread(&vg, sizeof(Videogioco_t), 1, file)){
        if(vg.annoPubblicazione == annoInput){
            trovato = 1;
            printf("- %s\n", vg.titolo);
        }
    }

    if(trovato == 0){
        printf("Nessun gioco prodotto nell'anno %d \n", annoInput); 
    }
    system("pause");
}


// funzione per gli amministratori per visualizzare l'intero catalogo e le recensioni 

void visualizzaCatalogo(FILE *file){
    Videogioco_t vg;
    rewind(file);

    printf("\n==================== CATALOGO VIDEOGIOCHI ====================\n\n");

    while (fread(&vg, sizeof(Videogioco_t), 1, file) == 1) {
        printf(" Titolo:                  %s\n", vg.titolo);
        printf(" Editore:                 %s\n", vg.editore);
        printf(" Sviluppatore:            %s\n", vg.sviluppatore);
        printf(" Anno Pubblicazione:      %d\n", vg.annoPubblicazione);
        printf(" Copie Vendute:           %d\n", vg.numeroCopie);
        printf(" Descrizione:             %s\n", vg.descrizione);
        printf(" Genere/i:                ");

        for(int i = 0; i < vg.numeroGeneri; i++){
            
            printf("%s, ", vg.genere[i]);
        }

        printf("\n Recensioni:");

        if (vg.numeroRecensioni == 0) {
            printf(" Nessuna recensione disponibile.\n");

        } else {
            for (int i = 0; i < vg.numeroRecensioni; i++) {
                printf("   -----------------------------------------------------------\n");
                printf("    Recensione #%d\n", i);
                printf("    Voto        : %d / 5\n", vg.recensioni[i].voto);
                printf("    Descrizione : %s\n", vg.recensioni[i].descrizione);
                // aggiungere la media 
            }
        }

        printf("=================================================================\n\n");
    }
    system("pause");
}