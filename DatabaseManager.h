#include <string>
#include <sqlite3.h>

class DatabaseManager {
public:
    DatabaseManager(const std::string& databaseFilename);
    ~DatabaseManager();
    
    bool addItem(const std::string& itemName, int quantity);
    bool removeItem(const std::string& itemName);
    bool updateItem(const std::string& itemName, int newQuantity);
    void listItems();
    
private:
    sqlite3* db;
};
