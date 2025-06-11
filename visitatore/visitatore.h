#include "visitatore.c"
/**
 * @file visitatore.h
 * @brief Header con le dichiarazioni delle funzioni per il visitatore.
 */
#pragma once

/**
 * @brief Menu interattivo per il visitatore, con opzioni di acquisto, recensione e ricerca.
 * 
 * La funzione mostra un menu con le seguenti opzioni:
 * - Acquistare un videogioco
 * - Scrivere una recensione per un videogioco
 * - Ricercare un videogioco tramite parametri vari
 * - Visualizzare le recensioni di un videogioco
 * - Visualizzare il catalogo ordinato
 * - Tornare al menu principale
 * 
 * La funzione gestisce l'input dell'utente e richiama le funzioni appropriate.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void visitatoremenu(FILE *file);

