#include "Inventory.h"

int main() {
    DatabaseManager dbManager("inventory.db");
    Inventory inventory(dbManager);

    inventory.addItem("Sword", 5);
    inventory.listItems();
    return 0;
}
