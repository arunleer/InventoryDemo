#include "DatabaseManager.h"
#include <vector>

class Inventory {
public:
    Inventory(DatabaseManager& db);
    void addItem(const std::string& itemName, int quantity);
    void removeItem(const std::string& itemName);
    void updateItem(const std::string& itemName, int newQuantity);
    void listItems();

private:
    DatabaseManager& dbManager;
};
