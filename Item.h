#include <string>

class Item {
public:
    Item(const std::string& name, int quantity);
    std::string getName() const;
    int getQuantity() const;
    void setQuantity(int q);

private:
    std::string name;
    int quantity;
};
