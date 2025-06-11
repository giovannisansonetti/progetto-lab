#include "gestioneRecensioni.c"
/**
 * @file gestioneRecensioni.h
 * @brief Header con le dichiarazioni delle funzioni per la gestione delle recensioni.
 */
#pragma once
/**
 * @brief Visualizza tutte le recensioni di un videogioco dato il titolo.
 * 
 * La funzione richiede all'utente di inserire il titolo di un videogioco.
 * Cerca nel file binario il videogioco corrispondente (con ricerca parziale sul titolo).
 * Se trovato, stampa tutte le recensioni associate, con voto e descrizione,
 * e calcola la media dei voti.
 * Se non viene trovato alcun videogioco con quel titolo, viene mostrato un messaggio di errore.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void visioneRecensioni(FILE *file);

/**
 * @brief Permette di aggiungere una recensione a un videogioco esistente.
 * 
 * La funzione cerca un videogioco nel file binario tramite la funzione `ricercaTitolo()`.
 * Se il videogioco viene trovato, permette all'utente di inserire un voto (da 0 a 5)
 * e una descrizione per la recensione.
 * La recensione viene aggiunta all'array delle recensioni del videogioco,
 * il numero di recensioni viene aggiornato, e i dati vengono salvati sul file.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void gestioneRecensioni(FILE *file);
