#include <stdio.h>
#include <stdlib.h>
#include "..\admin\Videogioco.h"

Videogioco_t ordinamentoCopie(FILE *file){
    // leggere l'intero file e salvare i blocchi in un array temporaneo di tipo Videogioco_t
    // ordinare con il selection sort per l'ordinamento copie
    // stampare l'array aggiornatoù
    rewind(file);

}

Videogioco_t ordinamentoVoti(FILE *file){
    // stessa cosa dell'ordinamento copie
    // ordinare in base alla media dei voti sui singoli videogiochi
}