#include <stdio.h>
#include <stdlib.h>
#include "..\admin\Videogioco.h"

#define MAX_VIDEOGIOCHI 100

void ordinamentoCopie(FILE *file){
    // leggere l'intero file e salvare i blocchi in un array temporaneo di tipo Videogioco_t
    // ordinare con il selection sort per l'ordinamento copie
    // stampare l'array aggiornatoù

    rewind(file);

    Videogioco_t vg[MAX_VIDEOGIOCHI];
    int nVideogiochi = 0;

    while(fread(&vg[nVideogiochi], sizeof(Videogioco_t), 1, file)== 1){
        nVideogiochi++;
    }
    
    for(int i = 0; i < nVideogiochi; i++){
        int max_idx = i;

        for (int j = i + 1; j < nVideogiochi; j++) {
            if (vg[j].numeroCopie > vg[max_idx].numeroCopie) {
                max_idx = j;
            }

            Videogioco_t temp = vg[i];
            vg[i] = vg[max_idx];
            vg[max_idx] = temp;
        }
    }

    printf("Ecco la lista ordinata di videogiochi: \n");

    for(int i = 0; i < nVideogiochi; i++){
        printf("Videogioco: %s \n", vg[i].titolo);
        printf("Numero copie: %d \n", vg[i].numeroCopie);
    }
}

void ordinamentoVoti(FILE *file){
    // stessa cosa dell'ordinamento copie
    // ordinare in base alla media dei voti sui singoli videogiochi
    rewind(file);

    Videogioco_t vg[MAX_VIDEOGIOCHI];
    int nVideogiochi = 0;

    while(fread(&vg[nVideogiochi], sizeof(Videogioco_t), 1, file)== 1){
        nVideogiochi++;
    }
    
    for(int i = 0; i < nVideogiochi; i++){
        int max_idx = i;

        for (int j = i + 1; j < nVideogiochi; j++) {
            if (vg[j].recensioni[i].voto > vg[max_idx].recensioni[i].voto) {
                max_idx = j;
            }

            Videogioco_t temp = vg[i];
            vg[i] = vg[max_idx];
            vg[max_idx] = temp;
        }
    }

    printf("Ecco la lista ordinata di videogiochi in base ai voti: \n");

    for(int i = 0; i < nVideogiochi; i++){
        printf("Videogioco: %s \n", vg[i].titolo);
        printf("Voto: %d \n", vg[i].recensioni[i].voto);
    }
}