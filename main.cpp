#include "src/helpers/headers/SeederData.h"
#include "src/helpers/headers/DisplayMenu.h"

int main() {
    SeederData seeder;
    DisplayMenu display;

    seeder.SeedData().get();
    display.getMenu();
    return 0;
}
