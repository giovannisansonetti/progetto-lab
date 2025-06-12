#include <stdio.h>
#include <stdlib.h>
#include "..\admin\Videogioco.h"

#define MAX_VIDEOGIOCHI 40 

void ordinamentoCopie(FILE *file){

    rewind(file);

    Videogioco_t vg[MAX_VIDEOGIOCHI]; // array statico per contenere i videogiochi letti nel file
    int nVideogiochi = 0;

    // legge tutti i record dal file binario e li salva nell'array vg[]

    while(fread(&vg[nVideogiochi], sizeof(Videogioco_t), 1, file)== 1){
        nVideogiochi++;
    }
    
    for(int i = 0; i < nVideogiochi; i++){
        int max_idx = i; // 

        for (int j = i + 1; j < nVideogiochi; j++) {
            if (vg[j].numeroCopie > vg[max_idx].numeroCopie) {
                max_idx = j;
            }
        }

        Videogioco_t temp = vg[i];
        vg[i] = vg[max_idx];
        vg[max_idx] = temp;
    }

    printf("Ecco la lista ordinata di videogiochi: \n");

    for(int i = 0; i < nVideogiochi; i++){
        if(vg[i].numeroCopie > 0) {
            printf("Videogioco: %s \n", vg[i].titolo);
            printf("Numero copie: %d \n", vg[i].numeroCopie);
        }
    }
}

void ordinamentoVoti(FILE *file){
    rewind(file);

    Videogioco_t vg[MAX_VIDEOGIOCHI];
    float medie[MAX_VIDEOGIOCHI];

    int nVideogiochi = 0;

    while(fread(&vg[nVideogiochi], sizeof(Videogioco_t), 1, file)== 1){
        nVideogiochi++;
    }

    // calcolo la media con un ciclo for, per accedere ai singoli valori della struttura recensioni
    
    for (int i = 0; i < nVideogiochi; i++) {
        int somma = 0;
        int count = 0;
        for (int j = 0; j < vg[i].numeroRecensioni; j++) {
            somma += vg[i].recensioni[j].voto;
            count++; 
        }
        if(count > 0){
            medie[i] = (float)somma / count; 
        }
    }

    // Ordina i videogiochi in base alla media dei voti (selection sort)
    for (int i = 0; i < nVideogiochi - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < nVideogiochi; j++) {
            if (medie[j] > medie[max_idx]) {
                max_idx = j;
            }
        }

        float temp_media = medie[i];
        medie[i] = medie[max_idx];
        medie[max_idx] = temp_media;

       
        Videogioco_t temp = vg[i];
        vg[i] = vg[max_idx];
        vg[max_idx] = temp;
    }
    printf("Ecco la lista ordinata di videogiochi in base alla media dei voti:\n");

    for (int i = 0; i < nVideogiochi; i++) {
        if(vg[i].numeroRecensioni > 0 ){
            printf("Videogioco: %s\n", vg[i].titolo);
            printf("Media voti: %.2f\n", medie[i]);
        }
    }
}