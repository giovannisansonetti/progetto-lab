#include <stdio.h>
#include <stdlib.h>
#include "gestioneCatalogo.c"
/**
 * @file gestioneCatalogo.h
 * @brief Header con le dichiarazioni delle funzioni per la gestione del catalogo.
 */
#pragma once

/**
 * @brief Inserisce un nuovo videogioco nel file binario.
 * 
 * La funzione consente all'amministratore di inserire i dati di un videogioco:
 * - Titolo
 * - Editore
 * - Sviluppatore
 * - Descrizione
 * - Anno di pubblicazione (intero)
 * - Generi (uno o più)
 * 
 * Tutti i dati vengono salvati in un file binario aperto in scrittura o aggiornamento.
 * 
 * @param file Puntatore al file binario dove verranno salvati i dati del videogioco.
 */
void inserisciGioco(FILE *file);



/**
 * @brief Permette la modifica dei dati di un videogioco esistente nel file.
 * 
 * La funzione richiede all'amministratore di cercare un videogioco nel file binario.
 * Se il videogioco viene trovato, all'amministratore viene chiesto se desidera modificarne i dati.
 * In caso di conferma, è possibile aggiornare i seguenti campi:
 * - Titolo
 * - Editore
 * - Sviluppatore
 * - Descrizione
 * - Anno di pubblicazione (intero)
 * - Generi
 * 
 * Al termine della modifica, viene mostrato il messaggio "Gioco modificato correttamente!".
 * Se l'amministratore rifiuta di modificare, la funzione ritorna al menu precedente senza apportare modifiche.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void modificaGioco(FILE *file);

/**
 * @brief Cancella un videogioco dal file binario.
 * 
 * La funzione richiede all'amministratore di cercare un videogioco nel file.
 * Se il videogioco viene trovato, all'amministratore viene chiesto se desidera effettivamente cancellarlo.
 * Se confermato, il videogioco viene rimosso dal catalogo.
 * Se l'amministratore rifiuta, la funzione ritorna al menu precedente senza cancellare nulla.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void cancellaGioco(FILE *file);


/**
 * @brief Ricerca videogiochi nel file binario in base a diversi parametri.
 * 
 * La funzione permette di cercare videogiochi utilizzando uno dei seguenti criteri:
 * - Titolo: visualizza i dati del videogioco corrispondente al titolo inserito.
 * - Sviluppatore: visualizza tutti i videogiochi prodotti dallo sviluppatore indicato.
 * - Editore: visualizza tutti i videogiochi prodotti dall'editore indicato.
 * - Genere: visualizza tutti i videogiochi appartenenti al genere specificato.
 * - Anno di pubblicazione: visualizza tutti i videogiochi pubblicati nell'anno indicato.
 * 
 * Se non viene trovato nessun videogioco che corrisponde ai criteri di ricerca, viene mostrato un messaggio di errore appropriato.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void ricercaParametri(FILE *file);
