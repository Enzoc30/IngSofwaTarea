//
// Created by hola on 10/5/2023.
//

#ifndef INGSOFWATAREA_COMPRA_H
#define INGSOFWATAREA_COMPRA_H

#include <iostream>

using namespace std;

class Compra {
    int id;
    string fecha;
    double monto;
    string proveedor;

public:
    Compra(int _id, double _total, string _fecha, string _proveedor ) {
        id = _id;
        monto = _total ;
        fecha = _fecha;
        proveedor = _proveedor;
    }

    virtual void mostrarDatos() {
        cout << "\tID de compra: " << id << endl;
        cout << "\tFecha: " << fecha << endl;
        cout << "\tProveedor: " << proveedor << endl;
        cout << "\tTotal: $" << monto << endl;
    }
};

#endif //INGSOFWATAREA_COMPRA_H
