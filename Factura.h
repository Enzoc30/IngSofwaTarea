//
// Created by hola on 10/5/2023.
//

#ifndef INGSOFWATAREA_FACTURA_H
#define INGSOFWATAREA_FACTURA_H

#include <iostream>
#include "Compra.h"
using namespace std;

class Factura : public Compra{
private:
    string nombreProveedor;
    string tipoFactura;
    string numeroFactura;

public:
    Factura(int _id, float _total, string _nombreProveedor) : Compra(_id, _total), nombreProveedor(_nombreProveedor) {}
    void mostrarDetalles() {
        cout << " ============== Factura ==============" << endl;
        Compra::mostrarDetalles();
        cout << "\tNumero de Factura:    " << nombreProveedor << endl;
        cout << "\tNombre del proveedor:    " << nombreProveedor << endl;
        cout << "\tTipo de Factura:    " << nombreProveedor << endl;
        cout << " =====================================" << endl;

    }
};

#endif //INGSOFWATAREA_FACTURA_H
