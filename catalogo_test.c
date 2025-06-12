#include "unity.h"
#include "unity_internals.h"
#include "admin/Videogioco.h"
#include "inizializzazione_catalogo.h"

void resetFile() {
    remove("catalogo.bin");
}

void setUp(void) {
    // per fare un test pulito, il file catalogo viene rimosso
    resetFile();
}

void tearDown(void) {}

void test_controlloFile(void) {
    FILE *fp = fopen("catalogo.bin", "r+b");
    TEST_ASSERT_NOT_NULL(fp);
}

void test_inizializzaCatalogo(void) {
    FILE *fp = fopen("catalogo.bin", "r+b");
    if (!fp) {
        fp = fopen("catalogo.bin", "w+b");
    }
    inizializzaCatalogo(fp);
    
    TEST_ASSERT_NOT_NULL(fp);
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    TEST_ASSERT_EQUAL_INT(20 * sizeof(Videogioco_t), size); // controlla se ci sono 20 struct 
}

// controlla se esiste un offset per un videogioco cercato nel file

void test_esistenzaOffset(void) {
    FILE *fp = fopen("catalogo.bin", "rb");
    TEST_ASSERT_NOT_NULL(fp);

    int offset = ricercaTitolo(fp);
    TEST_ASSERT_TRUE(offset >= 0);  
}

void test_inserisciGioco(void) {
    FILE *fp = fopen("catalogo.bin", "r+b");
    TEST_ASSERT_NOT_NULL(fp);

    Videogioco_t vg;
    strcpy(vg.titolo, "GiocoTest");
    strcpy(vg.editore, "EditoreTest");

    vg.numeroCopie = 10;
    fseek(fp, 0, SEEK_END);
    fwrite(&vg, sizeof(Videogioco_t), 1, fp);

    // Controllo se la dimensione file è aumentata con i valori in input
    fseek(fp, 0, SEEK_END);
    long offset = ftell(fp); 
    TEST_ASSERT_TRUE(offset >= (21 * sizeof(Videogioco_t)));
}

void test_modificaGioco(void) {
    FILE *fp = fopen("catalogo.bin", "r+b");
    TEST_ASSERT_NOT_NULL(fp);

    Videogioco_t vg;
    strcpy(vg.titolo, "titolo");
    vg.numeroCopie = 5;

    fseek(fp, 0, SEEK_SET);
    fwrite(&vg, sizeof(Videogioco_t), 1, fp);

    fseek(fp, 0, SEEK_SET);
    fread(&vg, sizeof(Videogioco_t), 1, fp);

    strcpy(vg.editore, "editore");
    fseek(fp, 0, SEEK_SET);

    fwrite(&vg, sizeof(Videogioco_t), 1, fp);

    // Rileggo e verifico modifica
    fseek(fp, 0, SEEK_SET);
    fread(&vg, sizeof(Videogioco_t), 1, fp);

    TEST_ASSERT_EQUAL_STRING("editore", vg.editore);

}

void test_cancellaGioco(void) {
    FILE *fp = fopen("catalogo.bin", "r+b");
    TEST_ASSERT_NOT_NULL(fp);

    Videogioco_t vg;
    strcpy(vg.titolo, "CancellaTest");
    vg.numeroCopie = 3;
    fseek(fp, 0, SEEK_SET);
    fwrite(&vg, sizeof(Videogioco_t), 1, fp);

    // Cancello scrivendo struttura vuota
    Videogioco_t vg_reset = {0};
    fseek(fp, 0, SEEK_SET);
    fwrite(&vg_reset, sizeof(Videogioco_t), 1, fp);
    fflush(fp);

    // Controllo che titolo sia vuoto
    fseek(fp, 0, SEEK_SET);
    fread(&vg, sizeof(Videogioco_t), 1, fp);
    TEST_ASSERT_EQUAL_STRING("", vg.titolo);
    TEST_ASSERT_EQUAL_INT(0, vg.numeroCopie);

    fclose(fp);
}

void test_inserisciRecensioni(void) {
    FILE *fp = fopen("catalogo.bin", "r+b");
    TEST_ASSERT_NOT_NULL(fp);

    Videogioco_t vg;

    vg.numeroRecensioni = 1;
    strcpy(vg.recensioni[0].descrizione, "bello");
    vg.recensioni[0].voto = 5;

    fseek(fp, 0, SEEK_END); // posizioniamo il puntatore alla fine del file
    long offset = ftell(fp); 
    fwrite(&vg, sizeof(Videogioco_t), 1, fp);

    fseek(fp, offset, SEEK_SET); // ci riposizioniamo dove avevamo inserito il blocco

    Videogioco_t vg_lettura; // nuova struct che usiamo per la lettura del blocco

    fread(&vg_lettura, sizeof(Videogioco_t), 1, fp); 

    // controlla se il numero recensioni è 1
    TEST_ASSERT_EQUAL_INT(1, vg_lettura.numeroRecensioni);
    //controlla se il voto era quello inserito
    TEST_ASSERT_EQUAL_INT(5, vg_lettura.recensioni[0].voto);
    // controlla se la descrizione era quella di input
    TEST_ASSERT_EQUAL_STRING("bello", vg_lettura.recensioni[0].descrizione);
}


int main() {
    UNITY_BEGIN();
    RUN_TEST(test_controlloFile);
    RUN_TEST(test_inizializzaCatalogo);
    RUN_TEST(test_esistenzaOffset);
    RUN_TEST(test_inserisciGioco);
    RUN_TEST(test_modificaGioco);
    RUN_TEST(test_cancellaGioco);
    RUN_TEST(test_inserisciRecensioni);
}