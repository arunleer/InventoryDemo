#include "Item.h"

Item::Item(const std::string& name, int quantity) : name(name), quantity(quantity) {}

std::string Item::getName() const {
    return name;
}

int Item::getQuantity() const {
    return quantity;
}

void Item::setQuantity(int q) {
    quantity = q;
}
