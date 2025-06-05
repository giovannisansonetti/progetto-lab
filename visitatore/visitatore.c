#include <stdio.h>
#include "gestionevisitatore.h"

void visitatoremenu (FILE *file){
    
    int scelta;
    
    do{
        printf("[1] Ricerca il videogioco e inserisci una recensione \n");
        printf("[2] Ricerca il videogioco e acquistalo \n");
        printf("[3] Torna  al menu \n");
        scanf("%d", &scelta);
        switch(scelta){
            case 1: ricercagiocorec(file);break;
            case 2: ricercagiocoacq(file);break;
            
        }
        
    }while (scelta!=3);
}