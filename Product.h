//
// Created by Marius on 3/29/2021.
//

#ifndef DATABASESSQLITESTARTER_PRODUCT_H
#define DATABASESSQLITESTARTER_PRODUCT_H
#include <iostream>
using namespace std;
class Product {
private:
  string name;
  string description;
  double price;
public:
  Product(const string &name, const string &description, double price);

  const string &GetName() const;

  const string &GetDescription() const;

  double GetPrice() const;


};


#endif //DATABASESSQLITESTARTER_PRODUCT_H
