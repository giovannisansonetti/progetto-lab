#pragma once
#include "ricercaVideogioco.c"

int ricercaTitolo(FILE *file);
void ricercaSviluppatore(FILE *file);
void ricercaEditore(FILE *file);
void ricercaGenere(FILE *file);
void ricercaAnno(FILE *file);
void ricercaRecensioni(FILE *file);
void visualizzaCatalogo(FILE *file);