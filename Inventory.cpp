#include "Inventory.h"

Inventory::Inventory(DatabaseManager& db) : dbManager(db) {}

void Inventory::addItem(const std::string& itemName, int quantity) {
    dbManager.addItem(itemName, quantity);
}

void Inventory::removeItem(const std::string& itemName) {
    dbManager.removeItem(itemName);
}

void Inventory::updateItem(const std::string& itemName, int newQuantity) {
    dbManager.updateItem(itemName, newQuantity);
}

void Inventory::listItems() {
    dbManager.listItems();
}
