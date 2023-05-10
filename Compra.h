//
// Created by hola on 10/5/2023.
//

#ifndef INGSOFWATAREA_COMPRA_H
#define INGSOFWATAREA_COMPRA_H

#include <iostream>

using namespace std;

class Compra {
    int id;
    float total;

public:
    Compra(int _id, float _total) : id(_id), total(_total) {}

    virtual void mostrarDetalles() {
        cout << "ID de compra: " << id << endl;
        cout << "Total: $" << total << endl;
    }
};

#endif //INGSOFWATAREA_COMPRA_H
