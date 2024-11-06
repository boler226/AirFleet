#include "src/helpers/headers/SeederData.h"
#include "src/helpers/headers/DisplayMenu.h"
#include<windows.h>


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SeederData seeder;
    DisplayMenu display;

    seeder.SeedData().get();
    display.getMenu();
    return 0;
}
