#include "gestionevisitatore.c"
/**
 * @file gestionevisitatore.h
 * @brief Header con le dichiarazioni delle funzioni per la gestione dei videogiochi.
 */
#pragma once

/**
 * @brief Menu interattivo per la ricerca di videogiochi con diversi criteri.
 * 
 * La funzione presenta un menu che consente di scegliere tra varie modalità di ricerca:
 * per titolo, sviluppatore, editore, genere o anno di pubblicazione.
 * Esegue la funzione di ricerca corrispondente in base alla scelta dell'utente.
 * 
 * L'utente può tornare al menu principale selezionando l'opzione 6.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void ricercaGioco(FILE *file);


/**
 * @brief Permette all'utente di acquistare un videogioco aumentando il numero di copie vendute.
 * 
 * La funzione cerca un videogioco tramite titolo (chiamando `ricercaTitolo`),
 * se trovato, chiede all'utente se vuole acquistare il gioco.
 * Se l'utente conferma, incrementa il numero di copie vendute del videogioco
 * e aggiorna il record nel file binario.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void acquista(FILE *file);
 


 
