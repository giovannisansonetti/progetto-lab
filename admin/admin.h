#pragma once
/**
 * @file admin.h
 * @brief Header con le dichiarazioni delle funzioni per'admin.
 */
#include "admin.c"

/**
 * @brief Visualizza il menu amministratore e gestisce le operazioni sui videogiochi.
 * 
 * La funzione mostra un menu con le seguenti opzioni per l'amministratore:
 * 1. Inserimento di un nuovo videogioco
 * 2. Modifica di un videogioco esistente
 * 3. Cancellazione di un videogioco
 * 4. Ricerca di un videogioco per parametri
 * 5. Visualizzazione delle recensioni di un videogioco
 * 6. Uscita dal menu amministratore
 * 
 * L'amministratore può scegliere una voce e la funzione richiama la corrispondente
 * funzione di gestione passando il puntatore al file binario contenente i dati.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void adminMenu(FILE *file);


