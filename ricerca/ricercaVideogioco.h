
#include "ricercaVideogioco.c"
/**
 * @file ricercaVideogioco.h
 * @brief Header con le dichiarazioni delle funzioni per la ricerca dei videogiochi
 */
#pragma once
/**
 * @brief Cerca un videogioco nel file binario in base al titolo parziale fornito dall'utente.
 * 
 * La funzione richiede all'utente di inserire una stringa di ricerca per il titolo del videogioco.
 * Scorre il file binario e confronta ogni titolo dei videogiochi con la stringa inserita,
 * utilizzando una ricerca parziale (substring).
 * 
 * Se viene trovato un videogioco corrispondente, stampa a video tutte le sue informazioni
 * (titolo, editore, sviluppatore, anno di pubblicazione, copie vendute, descrizione e generi)
 * e restituisce l'offset nel file dove è memorizzato il videogioco.
 * 
 * Se non viene trovato alcun videogioco corrispondente, mostra un messaggio di errore
 * e restituisce -1.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 * @return long L'offset (in byte) nel file del videogioco trovato, o -1 se non trovato.
 */
long ricercaTitolo(FILE *file);

/**
 * @brief Cerca e stampa i videogiochi di uno specifico sviluppatore.
 * 
 * La funzione chiede all'utente il nome dello sviluppatore,
 * quindi scorre il file binario per trovare e stampare tutti i videogiochi
 * prodotti da quello sviluppatore (ricerca parziale con strstr).
 * 
 * Se non viene trovato nessun videogioco corrispondente, stampa un messaggio di errore.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void ricercaSviluppatore(FILE *file);

/**
 * @brief Cerca e stampa i videogiochi prodotti da uno specifico editore.
 * 
 * La funzione chiede all'utente di inserire il nome di un editore,
 * quindi scorre il file binario per trovare e mostrare tutti i videogiochi
 * associati a quell’editore (ricerca parziale tramite strstr).
 * 
 * Se non viene trovato nessun videogioco con quell’editore, viene mostrato un messaggio di errore.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void ricercaEditore(FILE *file);

/**
 * @brief Cerca e stampa i videogiochi che appartengono a uno specifico genere.
 * 
 * La funzione chiede all'utente di inserire un genere,
 * quindi scorre il file binario e verifica se il genere è presente tra quelli del videogioco,
 * usando una ricerca parziale tramite strstr.
 * 
 * Se trova videogiochi con quel genere, li stampa; altrimenti mostra un messaggio di errore.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void ricercaGenere(FILE *file);

/**
 * @brief Cerca e stampa i videogiochi pubblicati in un anno specifico.
 * 
 * La funzione chiede all'utente di inserire un anno,
 * quindi scorre il file binario per trovare e mostrare tutti i videogiochi
 * con anno di pubblicazione uguale a quello inserito.
 * 
 * Se non viene trovato nessun videogioco di quell'anno, viene mostrato un messaggio di errore.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void ricercaAnno(FILE *file);

/**
 * @brief Visualizza a video il catalogo completo dei videogiochi.
 * 
 * La funzione legge dal file binario tutti i videogiochi e ne stampa
 * i dettagli completi: titolo, editore, sviluppatore, anno di pubblicazione,
 * copie vendute, descrizione, generi e tutte le recensioni con voto e descrizione.
 * 
 * Se un videogioco non ha recensioni, viene indicato con un messaggio specifico.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void visualizzaCatalogo(FILE *file);
