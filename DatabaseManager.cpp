#include "DatabaseManager.h"
#include <iostream>

DatabaseManager::DatabaseManager(const std::string& databaseFilename) {
    sqlite3_open(databaseFilename.c_str(), &db);
    const char* createTableSQL = "CREATE TABLE IF NOT EXISTS Inventory (Name TEXT PRIMARY KEY, Quantity INT)";
    sqlite3_exec(db, createTableSQL, nullptr, nullptr, nullptr);
}

DatabaseManager::~DatabaseManager() {
    sqlite3_close(db);
}

bool DatabaseManager::addItem(const std::string& itemName, int quantity) {
    std::string insertSQL = "INSERT OR IGNORE INTO Inventory (Name, Quantity) VALUES (?, ?)";
    sqlite3_stmt* statement;
    sqlite3_prepare_v2(db, insertSQL.c_str(), -1, &statement, nullptr);
    sqlite3_bind_text(statement, 1, itemName.c_str(), -1, nullptr);
    sqlite3_bind_int(statement, 2, quantity);
    sqlite3_step(statement);
    sqlite3_finalize(statement);
    return sqlite3_changes(db) > 0;
}

bool DatabaseManager::removeItem(const std::string& itemName) {
    std::string removeSQL = "DELETE FROM Inventory WHERE Name = ?";
    sqlite3_stmt* statement;
    sqlite3_prepare_v2(db, removeSQL.c_str(), -1, &statement, nullptr);
    sqlite3_bind_text(statement, 1, itemName.c_str(), -1, nullptr);
    sqlite3_step(statement);
    sqlite3_finalize(statement);
    return sqlite3_changes(db) > 0;
}

bool DatabaseManager::updateItem(const std::string& itemName, int newQuantity) {
    std::string updateSQL = "UPDATE Inventory SET Quantity = ? WHERE Name = ?";
    sqlite3_stmt* statement;
    sqlite3_prepare_v2(db, updateSQL.c_str(), -1, &statement, nullptr);
    sqlite3_bind_int(statement, 1, newQuantity);
    sqlite3_bind_text(statement, 2, itemName.c_str(), -1, nullptr);
    sqlite3_step(statement);
    sqlite3_finalize(statement);
    return sqlite3_changes(db) > 0;
}

void DatabaseManager::listItems() {
    const char* selectSQL = "SELECT Name, Quantity FROM Inventory";
    sqlite3_stmt* statement;
    if (sqlite3_prepare_v2(db, selectSQL, -1, &statement, nullptr) == SQLITE_OK) {
        while (sqlite3_step(statement) == SQLITE_ROW) {
            std::string name = reinterpret_cast<const char*>(sqlite3_column_text(statement, 0));
            int quantity = sqlite3_column_int(statement, 1);
            std::cout << name << ": " << quantity << std::endl;
        }
    }
    sqlite3_finalize(statement);
}
