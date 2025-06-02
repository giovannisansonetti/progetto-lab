#include <stdio.h>
#include "admin/admin.h"

int main(){
    // init
    FILE *fp = fopen("catalogo.bin", "rb");

    if (!fp) {
        printf("Errore durante la creazione del file");
    }

    int input;

    do{
        printf("Benvenuto, seleziona un'opzione \n");
        printf("[1] Amministratore\n");
        printf("[2] Visitatore\n");
        scanf("%d", &input);

        switch(input){
            case 1: adminMenu(fp);
        }
    }while (input != 1 || input != 2);
}