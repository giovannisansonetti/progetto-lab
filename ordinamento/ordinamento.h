#include "ordinamento.c"
/**
 * @file ordinamento.h
 * @brief Header con le dichiarazioni delle funzioni per l'ordinamento dei videogiochi.
 */
#pragma once

/**
 * @brief Ordina e visualizza la lista dei videogiochi in base al numero di copie disponibili.
 * 
 * La funzione legge tutti i videogiochi dal file binario, li carica in un array,
 * li ordina in ordine decrescente rispetto al numero di copie disponibili,
 * e infine stampa la lista ordinata.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void ordinamentoCopie(FILE *file);



/**
 * @brief Ordina e visualizza la lista dei videogiochi in base alla media dei voti delle recensioni.
 * 
 * La funzione legge tutti i videogiochi dal file binario, li carica in un array,
 * li ordina in ordine decrescente rispetto alla media del voto presente nelle recensioni
 * (assumendo che venga considerato un voto specifico per ogni gioco),
 * e infine stampa la lista ordinata.
 * 
 * @param file Puntatore al file binario contenente i dati dei videogiochi.
 */
void ordinamentoVoti(FILE *file);

