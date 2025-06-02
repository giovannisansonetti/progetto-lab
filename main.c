#include <stdio.h>
#include "admin/admin.h"

int main(){
    // init
    FILE *fp = fopen("catalogo.bin", "r+b");
    if (!fp) {
        fp = fopen("catalogo.bin", "w+b");
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
    }while (input != 1 && input != 2);
}