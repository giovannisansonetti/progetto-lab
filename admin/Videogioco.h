#define MAX_LEN 100
#define MAX_RECENSIONI 100

typedef struct {
    int voto;                    // Obbligatorio
    char descrizione[MAX_LEN];  // Opzionale
} Recensione_t;

typedef struct {
    char titolo[MAX_LEN];
    char editore[MAX_LEN];
    char sviluppatore[MAX_LEN];
    char descrizione[MAX_LEN];
    int annoPubblicazione;
    char genere[MAX_LEN];
    int numeroRecensioni;
    Recensione_t recensioni[MAX_RECENSIONI];
    int numeroCopie;
} Videogioco_t;