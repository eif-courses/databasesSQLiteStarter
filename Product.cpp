//
// Created by Marius on 3/29/2021.
//

#include "Product.h"

Product::Product(const string &name, const string &description, double price) : name(name), description(description),
                                                                                price(price) {}

const string &Product::GetName() const {
  return name;
}

const string &Product::GetDescription() const {
  return description;
}

double Product::GetPrice() const {
  return price;
}
