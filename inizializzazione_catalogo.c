#include <stdio.h>
#include "admin/admin.h"

void inizializzaCatalogo(FILE *file) {
    
    fseek(file, 0, SEEK_END);
    long size = ftell(file);

    if (size > 0) {
        rewind(file);
        return; 
    }

    Videogioco_t giochi[20] = {
        {"hades", "supergiant games", "supergiant games", "action roguelike", 2020, 2, {"action", "roguelike"}, 0, {0}, 5},
        {"celeste", "matt makes games", "matt makes games", "platformer indie", 2018, 1, {"platformer"}, 0, {0}, 0},
        {"among us", "innersloth", "innersloth", "party multiplayer", 2018, 2, {"multiplayer", "social deduction"}, 0, {0}, 0},
        {"hollow knight", "team cherry", "team cherry", "metroidvania", 2017, 2, {"adventure", "metroidvania"}, 0, {0}, 0},
        {"ori and the will of the wisps", "moon studios", "moon studios", "platform adventure", 2020, 2, {"platformer", "adventure"}, 0, {0}, 0},
        {"death stranding", "sony", "kojima productions", "action strand game", 2019, 1, {"action"}, 0, {0}, 0},
        {"monster hunter: world", "capcom", "capcom", "action rpg", 2018, 1, {"rpg"}, 0, {0}, 0},
        {"persona 5 royal", "atlus", "atlus", "jrpg", 2020, 1, {"rpg"}, 0, {0}, 0},
        {"cuphead", "studio mdhr", "studio mdhr", "run and gun", 2017, 1, {"action"}, 0, {0}, 0},
        {"fall guys", "mediatonic", "mediatonic", "battle royale party game", 2020, 2, {"multiplayer", "party"}, 0, {0}, 0},
        {"the outer worlds", "obsidian entertainment", "private division", "sci-fi rpg", 2019, 1, {"rpg"}, 0, {0}, 0},
        {"disco elysium", "za/um", "za/um", "rpg detective", 2019, 1, {"rpg"}, 0, {0}, 0},
        {"streets of rage 4", "dotemu", "lizardcube", "beat 'em up", 2020, 1, {"action"}, 0, {0}, 0},
        {"ori and the blind forest", "moon studios", "microsoft studios", "platform adventure", 2015, 2, {"platformer", "adventure"}, 0, {0}, 0},
        {"rocket league", "psyonix", "psyonix", "vehicular soccer", 2015, 2, {"sports", "multiplayer"}, 0, {0}, 0},
        {"dead cells", "motion twin", "motion twin", "roguelike metroidvania", 2018, 2, {"action", "roguelike"}, 0, {0}, 0},
        {"control", "remedy entertainment", "505 games", "action-adventure", 2019, 1, {"action"}, 0, {0}, 0},
        {"valorant", "riot games", "riot games", "tactical fps", 2020, 1, {"shooter"}, 0, {0}, 0},
        {"ghost of tsushima", "sony", "sucker punch", "open world action", 2020, 2, {"action", "adventure"}, 0, {0}, 0},
        {"animal crossing: new horizons", "nintendo", "nintendo", "social simulation", 2020, 1, {"simulation"}, 0, {0}, 0}
    };


    fwrite(giochi, sizeof(Videogioco_t), 20, file);
    rewind(file);
    printf("Catalogo inizializzato con 20 videogiochi.\n");

}