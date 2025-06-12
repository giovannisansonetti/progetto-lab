#include <stdio.h>
#include <stdbool.h>

#include "admin/admin.h"
#include "visitatore/visitatore.h"
#include "inizializzazione_catalogo.h"

int main(){
    // init
    FILE *fp = fopen("catalogo.bin", "r+b");
    
    if (!fp) {
        fp = fopen("catalogo.bin", "w+b");
        inizializzaCatalogo(fp);
    }

    int input;

    do{
        printf("\n===========================================\n");
        printf("         MENU PRINCIPALE\n");
        printf("===========================================\n");
        printf("  [1] Amministratore\n");
        printf("  [2] Visitatore\n");
        printf("-------------------------------------------\n");
        printf("Scegli un'opzione: ");
        scanf("%d", &input);

        switch(input){
            case 1: adminMenu(fp); break;
            case 2: visitatoremenu(fp); break;
        }
    }while (true);
    
}

