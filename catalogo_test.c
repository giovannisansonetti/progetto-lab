#include "unity.h"
#include "unity_internals.h"
#include "admin/Videogioco.h"
#include "inizializzazione_catalogo.h"

void resetFile() {
    remove("catalogo.bin");
}

void setUp(void) {
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
    fflush(fp);

    // Controllo se la dimensione file è aumentata con i valori in input
    fseek(fp, 0, SEEK_END);
    long offset = ftell(fp); 
    TEST_ASSERT_TRUE(offset >= (21 * sizeof(Videogioco_t)));
}

void test_modificaGioco(void) {
    FILE *fp = fopen("catalogo.bin", "r+b");
    TEST_ASSERT_NOT_NULL(fp);

    Videogioco_t vg;
    strcpy(vg.titolo, "ModificaTest");
    vg.numeroCopie = 5;
    fseek(fp, 0, SEEK_SET);
    fwrite(&vg, sizeof(Videogioco_t), 1, fp);
    fflush(fp);

    // Simulo modifica direttamente nel file (bypassando scanf)
    long offset = 0;
    fseek(fp, offset, SEEK_SET);
    fread(&vg, sizeof(Videogioco_t), 1, fp);
    strcpy(vg.editore, "EditoreModificato");
    fseek(fp, offset, SEEK_SET);
    fwrite(&vg, sizeof(Videogioco_t), 1, fp);
    fflush(fp);

    // Rileggo e verifico modifica
    fseek(fp, offset, SEEK_SET);
    fread(&vg, sizeof(Videogioco_t), 1, fp);
    TEST_ASSERT_EQUAL_STRING("EditoreModificato", vg.editore);

    fclose(fp);
}

void test_cancellaGioco(void) {
    FILE *fp = fopen("catalogo.bin", "r+b");
    TEST_ASSERT_NOT_NULL(fp);

    Videogioco_t vg;
    strcpy(vg.titolo, "CancellaTest");
    vg.numeroCopie = 3;
    fseek(fp, 0, SEEK_SET);
    fwrite(&vg, sizeof(Videogioco_t), 1, fp);
    fflush(fp);

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

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_controlloFile);
    RUN_TEST(test_inizializzaCatalogo);
    RUN_TEST(test_esistenzaOffset);
}