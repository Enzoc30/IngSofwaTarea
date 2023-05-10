//
// Created by hola on 10/5/2023.
//

#ifndef INGSOFWATAREA_PRODUCT_H
#define INGSOFWATAREA_PRODUCT_H

#include <iostream>
using namespace std;


struct Product{
    string nombre;
    double precio;
    int stock;

    Product() = default;

    Product(string name, double price , int stock){
        nombre = name ;
        precio = price;
        this->stock = stock;
    }

    ~Product() = default;
};


#endif //INGSOFWATAREA_PRODUCT_H
