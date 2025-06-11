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

    fclose(fp);
}


int main() {
    UNITY_BEGIN();
    RUN_TEST(test_controlloFile);
    RUN_TEST(test_inizializzaCatalogo);
    RUN_TEST(test_esistenzaOffset);
}